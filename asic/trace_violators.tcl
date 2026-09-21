# trace_violators.tcl
#
# Backward-traces a list of violating driver instances (from a max
# fanout / max slew / max cap report) up through combinational logic
# to the flip-flop (or top-level port) that actually originates the
# signal, and prints the RTL net name at the root.
#
# Usage (batch mode, no interaction needed):
#   1. Edit db_path / list_path below.
#   2. openroad -no_init -exit trace_violators.tcl
#
# Usage (interactive, inside the `openroad` shell):
#   source trace_violators.tcl
#   read_db top_level.odb   ;# if not already loaded
#   set block [[[ord::get_db] getChip] getBlock]
#   batch_trace_from_file "violators.txt"
#   ;# or for a single instance:
#   trace_to_root "_04989_"

# ==================== EDIT THESE TWO LINES ====================
set db_path   "/home/alhussein/openlane2/designs/top/runs/RUN_2026-09-21_21-02-21/final/odb/top_level.odb"
set list_path "/home/alhussein/openlane2/designs/top/debug/slew_top_filtered.txt"
# ================================================================

proc inst_is_sequential {inst} {
    set master [$inst getMaster]
    set master_name [$master getName]

    # Primary check: does it have a pin literally named CLK (or CLK1/GCLK,
    # seen on some scan/clock-gate variants)?
    foreach iterm [$inst getITerms] {
        set pin_name [$iterm getName]
        if {[regexp -nocase {^(clk|clk1|gclk)$} $pin_name]} {
            return 1
        }
    }

    # Backup checks, in case a cell type genuinely has no CLK pin name
    # (unlikely in sky130_fd_sc_hd, but harmless to keep as a fallback).
    if {[catch {set is_seq [$master isSequential]}] == 0 && $is_seq} {
        return 1
    }
    if {[regexp -nocase {__(df|dl|sdf|edf)} $master_name]} {
        return 1
    }
    return 0
}

proc trace_to_root {inst_name {max_depth 40}} {
    set block [[[ord::get_db] getChip] getBlock]
    set curr_inst [$block findInst $inst_name]

    if {$curr_inst eq "NULL" || $curr_inst eq ""} {
        puts "ERROR: Instance $inst_name not found."
        return
    }

    set path [list]
    set depth 0
    set root_reason ""

    while {$curr_inst ne "NULL" && $curr_inst ne "" && $depth < $max_depth} {
        incr depth
        set master_name [[$curr_inst getMaster] getName]
        set cur_name [$curr_inst getName]
        lappend path "$cur_name ($master_name)"

        if {[inst_is_sequential $curr_inst]} {
            set root_reason "sequential cell (has a CLK pin)"
            break
        }

        # Collect every non-power/clock INPUT pin on this cell. For a
        # simple buffer there's exactly one (A), so this is unambiguous.
        # For a multi-input gate (nand4, mux2, ...) there can be several
        # real candidates -- we follow the first one found and flag it,
        # since which branch is "the" cause of the violation depends on
        # which input you care about, not something the tool can infer.
        set candidates [list]
        foreach iterm [$curr_inst getITerms] {
            if {[$iterm getIoType] eq "INPUT"} {
                set pin_name [$iterm getName]
                if {[regexp -nocase {^(vpb|vnb|vgnd|vpwr|clk|clk1|gclk|clock|reset_b|set_b|scd|sce)$} $pin_name]} {
                    continue
                }
                set candidate_net [$iterm getNet]
                if {$candidate_net ne "NULL" && $candidate_net ne ""} {
                    lappend candidates $candidate_net
                }
            }
        }

        if {[llength $candidates] == 0} {
            set root_reason "no connected non-power/clock input found"
            break
        }
        if {[llength $candidates] > 1} {
            lappend path "  \[note: $cur_name has [llength $candidates] real input pins -- following the first]"
        }
        set in_net [lindex $candidates 0]

        # Stop at a top-level port.
        set bterms [$in_net getBTerms]
        if {[llength $bterms] > 0} {
            set port_name [[lindex $bterms 0] getName]
            lappend path "PORT: $port_name"
            set root_reason "top-level port"
            break
        }

        # Find the driver instance on this net.
        set next_inst "NULL"
        foreach driver [$in_net getITerms] {
            if {[$driver getIoType] eq "OUTPUT"} {
                set next_inst [$driver getInst]
                break
            }
        }

        if {$next_inst eq "NULL" || $next_inst eq ""} {
            lappend path "\[No driver found on net: [$in_net getName]\]"
            set root_reason "undriven net"
            break
        }

        set curr_inst $next_inst
    }

    if {$depth >= $max_depth} {
        set root_reason "hit max_depth ($max_depth) without reaching a flop/port -- raise max_depth if this looks truncated"
    }

    # Collect RTL-visible net name(s) at the root cell (its OUTPUT pins).
    set rtl_nets [list]
    if {$curr_inst ne "NULL" && $curr_inst ne ""} {
        foreach iterm [$curr_inst getITerms] {
            if {[$iterm getIoType] eq "OUTPUT"} {
                set net [$iterm getNet]
                if {$net ne "NULL" && $net ne ""} {
                    lappend rtl_nets [$net getName]
                }
            }
        }
    }

    puts "------------------------------------------------------------"
    puts "TRACE ($inst_name): [join $path { <- }]"
    puts "STOPPED BECAUSE: $root_reason"
    if {$curr_inst ne "NULL" && $curr_inst ne ""} {
        puts "ROOT CELL : [$curr_inst getName] ([[$curr_inst getMaster] getName])"
        puts "ROOT NETS : [join $rtl_nets {, }]"
    }
    puts "------------------------------------------------------------"
    flush stdout
}

proc batch_trace_violators {inst_list} {
    set i 0
    set n [llength $inst_list]
    foreach inst $inst_list {
        incr i
        set clean_inst [lindex [split $inst "/"] 0]
        if {[catch {trace_to_root $clean_inst} err]} {
            puts "ERROR tracing $clean_inst: $err"
            flush stdout
        }
        if {$i % 25 == 0} {
            puts "... progress: $i / $n"
            flush stdout
        }
    }
}

# Reads a plain-text file with one instance (or instance/pin) name per
# line -- exactly what extract_violators.py produces -- and traces each.
proc batch_trace_from_file {path} {
    set f [open $path r]
    set inst_list [list]
    while {[gets $f line] >= 0} {
        set line [string trim $line]
        if {$line eq "" || [string index $line 0] eq "#"} {
            continue
        }
        lappend inst_list $line
    }
    close $f
    puts "Tracing [llength $inst_list] instances from $path ..."
    flush stdout
    batch_trace_violators $inst_list
}

# ---------------------------------------------------------------------
# Batch-mode entry point: runs automatically as soon as this file is
# sourced/executed, using the db_path/list_path variables set above.
# If you're sourcing this interactively and don't want it to run yet,
# just leave db_path as the REPLACE_WITH_... placeholder and call
# batch_trace_from_file / trace_to_root yourself once ready.
#
# Every puts below is followed by an explicit `flush stdout` -- when
# output is redirected to a file instead of a terminal, Tcl block-
# buffers it, so if something crashes mid-run (rather than exiting
# cleanly) you can lose everything that hadn't been flushed yet. The
# flushes and the catch/error handling below make sure you see exactly
# how far it got even if it does crash.
# ---------------------------------------------------------------------
puts "trace_violators.tcl starting, db_path=$db_path list_path=$list_path"
flush stdout

if {$db_path ne "REPLACE_WITH_YOUR_ODB_PATH"} {
    if {![file exists $db_path]} {
        puts "ERROR: db_path does not exist: $db_path"
        flush stdout
        exit 1
    }
    if {![file exists $list_path]} {
        puts "ERROR: list_path does not exist: $list_path"
        flush stdout
        exit 1
    }

    puts "Loading $db_path ..."
    flush stdout
    if {[catch {read_db $db_path} err]} {
        puts "ERROR during read_db: $err"
        flush stdout
        exit 1
    }
    puts "read_db succeeded."
    flush stdout

    if {[catch {set block [[[ord::get_db] getChip] getBlock]} err]} {
        puts "ERROR getting block: $err"
        flush stdout
        exit 1
    }
    puts "Block loaded, starting traces ..."
    flush stdout

    if {[catch {batch_trace_from_file $list_path} err]} {
        puts "ERROR during batch_trace_from_file: $err"
        flush stdout
        exit 1
    }

    puts "DONE: all traces completed."
    flush stdout
} else {
    puts "db_path/list_path still set to placeholders -- edit the top of this script, or call batch_trace_from_file/trace_to_root manually."
    flush stdout
}
