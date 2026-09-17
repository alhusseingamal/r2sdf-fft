# ==============================================================================
# Variables & Tool Setup
# ==============================================================================
VERILATOR = verilator
OMIT_WARNINGS = -Wno-UNUSEDSIGNAL -Wno-UNUSEDPARAM -Wno-TIMESCALEMOD -Wno-EOFNEWLINE -Wno-GENUNNAMED -Wno-WIDTHEXPAND -Wno-WIDTHTRUNC
FLAGS = --binary -j 0 -Wall --Wpedantic $(OMIT_WARNINGS) --trace --timescale 1ps/1ps

LENIENT_WARNINGS = -Wno-lint -Wno-style -Wno-fatal
FLAGS_LENIENT = --binary -j 0 -Wall --Wpedantic -Wno-lint -Wno-style -Wno-fatal --trace --timescale 1ps/1ps

# Project Directories
RTL_DIR = rtl
INC_DIR = $(RTL_DIR)
TB_DIR  = tb
SIM_DIR = sim
WAVE_DIR = config/gtkwave

# Source Files (Recursively find all .v files in RTL, and include all TB files)
RTL_SOURCES = $(shell find $(RTL_DIR) -name '*.v')
TB_SOURCES  = $(wildcard $(TB_DIR)/*.v)
SOURCES     = $(RTL_SOURCES) $(TB_SOURCES)

# Target Module Configuration
# The top module to compile and run. Defaults to 'top_level_tb'.
# Override from CLI: make all TOP=bf_tb
TOP ?= tb_fft_top

# Output Artifacts
DUMP_FILE = $(SIM_DIR)/dump.vcd
SAVE_FILE = $(WAVE_DIR)/$(TOP)_view.gtkw

# Verilator specific flags (Includes the header directory and sets build dir)
VERILATOR_FLAGS = $(FLAGS) -I$(INC_DIR) --top-module $(TOP) --Mdir $(SIM_DIR)/obj_dir

# ==============================================================================
# Targets
# ==============================================================================
.PHONY: all compile run lint wave clean

# Default target: compile, run, and open waveforms
all: run wave

# Compile the design using Verilator
compile:
	@mkdir -p $(SIM_DIR) $(TB_DIR)
	@echo "Compiling $(TOP) and all sub-modules..."
	$(VERILATOR) $(VERILATOR_FLAGS) $(SOURCES)

# Parses all files and checks syntax without generating a simulation binary or requiring a top module
syntax:
	@echo "Checking syntax across all files..."
	$(VERILATOR) --lint-only -I$(INC_DIR) $(LENIENT_WARNINGS) -Wno-MULTITOP $(SOURCES)

# Run the compiled executable to generate the VCD dump
run: compile
	@echo "Running simulation..."
	@cd $(SIM_DIR) && ./obj_dir/V$(TOP)

# Linting: checks code for errors and bad practices without compiling a binary
lint:
	$(VERILATOR) --lint-only -Wall $(OMIT_WARNINGS) -I$(INC_DIR) --top-module $(TOP) $(SOURCES)

# Display the results using GTKWave
wave:
	unset LD_LIBRARY_PATH; \
	if [ -f $(SAVE_FILE) ]; then \
		gtkwave $(DUMP_FILE) $(SAVE_FILE); \
	else \
		gtkwave $(DUMP_FILE); \
	fi

# Clean up all generated files
clean:
	rm -rf $(SIM_DIR) logs results dump.vcd