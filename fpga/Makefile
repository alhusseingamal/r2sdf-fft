TOPLEVEL = top_level

SRC_DIR = ../rtl/

VERILOG_FILES = \
	$(SRC_DIR)/complex_adder.v \
	$(SRC_DIR)/complex_subtractor.v \
	$(SRC_DIR)/complex_multiplier.v \
	$(SRC_DIR)/butterfly.v \
	$(SRC_DIR)/circular_buffer.v \
	$(SRC_DIR)/twiddle_rom.v \
	$(SRC_DIR)/sdf_stage.v \
	$(SRC_DIR)/sdf_stage_d4.v \
	$(SRC_DIR)/sdf_stage_d2.v \
	$(SRC_DIR)/sdf_stage_d1.v \
	$(SRC_DIR)/top_level.v




PCF = LatticeiCE40HX8K.pcf

DEVICE = hx8k

PACKAGE = ct256

YOSYS=yosys

NEXTPNR=nextpnr-ice40

MHZ=104



BUILD_DIR = build

LOGS_DIR = $(BUILD_DIR)/logs



LIBPYTHON_LOC = $(shell cocotb-config --libpython)

COCOTB_TEST_MODULES = testbench

COCOTB_TOPLEVEL = top_level

TOPLEVEL_LANG ?= verilog

SIM ?= icarus

SIM_BUILD = sim_build

COCOTB_RESULTS_FILE ?= results.xml

COCOTB_HDL_TIMEUNIT ?= 1ns

COCOTB_HDL_TIMEPRECISION ?= 1ps



CMD_BIN := iverilog



ifdef ICARUS_BIN_DIR
CMD := $(shell :; command -v $(ICARUS_BIN_DIR)/$(CMD_BIN) 2>/dev/null)
else
# auto-detect bin dir from system path
CMD := $(shell :; command -v $(CMD_BIN) 2>/dev/null)
endif



ifeq (, $(CMD))
$(error Unable to locate command >$(CMD_BIN)<)
else
ICARUS_BIN_DIR := $(shell dirname $(CMD))
export ICARUS_BIN_DIR
endif



COMPILE_ARGS += -f $(SIM_BUILD)/cmds.f



all: $(BUILD_DIR)/$(TOPLEVEL).rpt $(BUILD_DIR)/$(TOPLEVEL).bin



synth: $(BUILD_DIR)/$(TOPLEVEL).json



pnr: $(BUILD_DIR)/$(TOPLEVEL).asc



$(BUILD_DIR)/$(TOPLEVEL).json: $(VERILOG_FILES) | $(BUILD_DIR)
	$(YOSYS) -q \
		-L "$(LOGS_DIR)/$(TOPLEVEL)_yosys.log" \
		-e 'Driver-driver conflict' \
		-p "read_verilog -I$(SRC_DIR) -defer $(VERILOG_FILES)" \
		-p "hierarchy -top $(TOPLEVEL)" \
		-p "flatten" \
		-p "synth_ice40 ${YOSYS_OPTIONS} -json $@"
	@cat "$(LOGS_DIR)/$(TOPLEVEL)_yosys.log" | grep "Number of cells:"
	@echo "FPGA (HX8K) maximum available number of cells: 7680"



$(BUILD_DIR)/$(TOPLEVEL).asc: $(BUILD_DIR)/$(TOPLEVEL).json $(PCF) | $(LOGS_DIR)
	$(NEXTPNR) -q \
		--timing-allow-fail \
		--seed 22 \
		--$(DEVICE) --package $(PACKAGE) \
		--freq $(MHZ) \
		-l "$(LOGS_DIR)/$(TOPLEVEL)_nextpnr.log" \
		--json $< --pcf $(PCF) --pcf-allow-unconstrained --asc $@
	@cat "$(LOGS_DIR)/$(TOPLEVEL)_nextpnr.log" | grep "ICESTORM_LC:"



$(BUILD_DIR)/$(TOPLEVEL).bin: $(BUILD_DIR)/$(TOPLEVEL).asc
	icepack $< $@



$(BUILD_DIR)/$(TOPLEVEL).rpt: $(BUILD_DIR)/$(TOPLEVEL).asc | $(LOGS_DIR)
	icetime -d $(DEVICE) -mtr $@ $< -r "$(LOGS_DIR)/$(TOPLEVEL)_icetime.log"



report-info: $(BUILD_DIR)/$(TOPLEVEL).rpt $(LOGS_DIR)/$(TOPLEVEL)_nextpnr.log $(LOGS_DIR)/$(TOPLEVEL)_yosys.log
	@cat "$(LOGS_DIR)/$(TOPLEVEL)_yosys.log" | grep "Number of cells:"
	@cat "$(LOGS_DIR)/$(TOPLEVEL)_nextpnr.log" | grep "ICESTORM_LC:"
	@cat "$(LOGS_DIR)/$(TOPLEVEL)_icetime.log" | grep "Total path delay:"



prog: $(BUILD_DIR)/$(TOPLEVEL).bin $(BUILD_DIR)/$(TOPLEVEL).rpt
	iceprog -S $<



prog-flash: $(BUILD_DIR)/$(TOPLEVEL).bin $(BUILD_DIR)/$(TOPLEVEL).rpt
	iceprog $<



traces.fst: sim



# Locate the ice40 library models dynamically relative to your system path
ICE40_CELLS_SIM = $(shell dirname $(shell which yosys))/../share/yosys/ice40/cells_sim.v



sim: $(VERILOG_FILES) | $(SIM_BUILD)
	@echo $(CMD)
	@echo "+timescale+$(COCOTB_HDL_TIMEUNIT)/$(COCOTB_HDL_TIMEPRECISION)" > $(SIM_BUILD)/cmds.f
	$(CMD) -Wall -s top_level -o $(SIM_BUILD)/sim.vvp -g2012 $(COMPILE_ARGS) $(VERILOG_FILES) $(ICE40_CELLS_SIM)
	export PYTHONPATH=$(PWD)/tests:$$PYTHONPATH; \
	COCOTB_TEST_MODULES=$(COCOTB_TEST_MODULES) COCOTB_TOPLEVEL=$(COCOTB_TOPLEVEL) TOPLEVEL_LANG=$(TOPLEVEL_LANG) \
	$(ICARUS_BIN_DIR)/vvp -M $(shell cocotb-config --lib-dir) -m $(shell cocotb-config --lib-name vpi icarus) $(SIM_BUILD)/sim.vvp -fst



waveform: traces.fst
	gtkwave -a plotConfigs/traces_gtkw.sav traces.fst



$(SIM_BUILD):
	mkdir -p $@



$(BUILD_DIR):
	mkdir -p $@



$(LOGS_DIR):
	mkdir -p $@



clean:
	-rm -rf $(BUILD_DIR) $(SIM_BUILD)
	-rm -f results.xml traces.fst
	-rm -R ./__pycache__
	-rm -rf obj_dir





# --- Seed Sweeping Extension ---
# SEEDS = 11 14 18 27 33 38 41 47 52 58 64 69 74 81 88 93 107 111 13579 987654321
SEEDS = 2 3 5 6 7 9 10 19 22 30 44 56 62 73 85 97 102 1000 2026 783242394
SWEEP_DIR = $(BUILD_DIR)/seed_sweep



seed-sweep: $(BUILD_DIR)/$(TOPLEVEL).json | $(BUILD_DIR)
	@mkdir -p $(SWEEP_DIR)
	@echo "=================================================="
	@echo " Starting Seed Sweep for Seeds: $(SEEDS)"
	@echo "=================================================="
	@for seed in $(SEEDS); do \
		echo -n "Running Seed $$seed... " ; \
		$(NEXTPNR) -q \
			--$(DEVICE) --package $(PACKAGE) \
			--freq $(MHZ) \
			--seed $$seed \
			--json $< --pcf $(PCF) --pcf-allow-unconstrained --asc $(SWEEP_DIR)/sweep_$$seed.asc ; \
		if [ $$? -eq 0 ]; then \
			echo -n "PnR Done -> " ; \
			icetime -d $(DEVICE) -mtr $(SWEEP_DIR)/sweep_$$seed.rpt $(SWEEP_DIR)/sweep_$$seed.asc \

			| grep "Timing estimate" | sed 's/\/\/ //'; \
		else \
			echo "PnR Failed!"; \
		fi \
	done
	@echo "=================================================="
	@echo "Sweep Complete. Reports saved in $(SWEEP_DIR)/"



.SECONDARY:
.PHONY: all synth pnr prog prog-flash sim waveform report-info clean seed-sweep $(BUILD_DIR) $(LOGS_DIR)









# --- Appended Yosys Tcl Commands ---
yosys-tcl-flow:
	$(YOSYS) -p '\
		read_verilog -sv src/*.v; \
		hierarchy -top top_level; \
		proc; opt; \
		flatten; \
		opt_expr; \
		opt_merge -share_all; \
		synth_ice40 -top top_level -abc2; \
		write_json top.json \
	'
