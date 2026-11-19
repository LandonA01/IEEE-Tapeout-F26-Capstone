SIM ?= verilator
TOPLEVEL_LANG = verilog

VERILOG_SOURCES = $(CURDIR)/../rtl/alu.sv
COCOTB_TOPLEVEL = alu
COCOTB_TEST_MODULES = alu_tb

EXTRA_ARGS += -Wno-CASEINCOMPLETE


include $(shell cocotb-config --makefiles)/Makefile.sim
