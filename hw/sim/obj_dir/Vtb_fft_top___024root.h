// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_fft_top.h for the primary calling header

#ifndef VERILATED_VTB_FFT_TOP___024ROOT_H_
#define VERILATED_VTB_FFT_TOP___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_fft_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_fft_top___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_fft_top__DOT__clk;
        CData/*0:0*/ tb_fft_top__DOT__reset_n;
        CData/*0:0*/ tb_fft_top__DOT__valid_in;
        CData/*0:0*/ tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__valid_out;
        CData/*0:0*/ tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__valid_out;
        CData/*0:0*/ tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__valid_out;
        CData/*2:0*/ tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter;
        CData/*1:0*/ tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr;
        CData/*1:0*/ tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__lookahead_addr;
        CData/*1:0*/ tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter;
        CData/*0:0*/ tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr;
        CData/*0:0*/ tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__lookahead_addr;
        CData/*0:0*/ tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__counter;
        CData/*2:0*/ __Vdly__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter;
        CData/*1:0*/ __Vdly__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter;
        CData/*0:0*/ __Vdly__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__counter;
        CData/*1:0*/ __VdlyDim0__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0;
        CData/*0:0*/ __VdlySet__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0;
        CData/*1:0*/ __VdlyDim0__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0;
        CData/*0:0*/ __VdlySet__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0;
        CData/*0:0*/ __VdlyDim0__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0;
        CData/*0:0*/ __VdlySet__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0;
        CData/*0:0*/ __VdlyDim0__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0;
        CData/*0:0*/ __VdlySet__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_fft_top__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_fft_top__DOT__reset_n__0;
        SData/*15:0*/ tb_fft_top__DOT__in_real;
        SData/*15:0*/ tb_fft_top__DOT__in_imag;
        SData/*15:0*/ tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_imag;
        SData/*15:0*/ tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_real;
        SData/*15:0*/ tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_imag;
        SData/*15:0*/ tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_real;
        SData/*15:0*/ tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__out_imag;
        SData/*15:0*/ tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__out_real;
        SData/*15:0*/ tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_real;
        SData/*15:0*/ tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_imag;
        SData/*15:0*/ tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_real;
        SData/*15:0*/ tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_imag;
        SData/*15:0*/ tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_real;
        SData/*15:0*/ tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_imag;
        SData/*15:0*/ __VdlyVal__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0;
        SData/*15:0*/ __VdlyVal__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0;
        SData/*15:0*/ __VdlyVal__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0;
        SData/*15:0*/ __VdlyVal__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0;
        IData/*31:0*/ tb_fft_top__DOT__bit_reverse__Vstatic__b;
        IData/*31:0*/ tb_fft_top__DOT__bit_reverse__Vstatic__rev;
        IData/*31:0*/ tb_fft_top__DOT__i;
        IData/*31:0*/ tb_fft_top__DOT__reset_done;
        IData/*31:0*/ tb_fft_top__DOT__fd;
        IData/*31:0*/ tb_fft_top__DOT__cycle_count;
        IData/*31:0*/ tb_fft_top__DOT__total_output_count;
        IData/*31:0*/ tb_fft_top__DOT__valid_output_count;
        IData/*31:0*/ tb_fft_top__DOT__sqnr_total_outputs;
        IData/*31:0*/ tb_fft_top__DOT__sqnr_valid_count;
        IData/*31:0*/ tb_fft_top__DOT__frame_offset;
        IData/*31:0*/ tb_fft_top__DOT__local_bin_idx;
        IData/*31:0*/ tb_fft_top__DOT__golden_idx;
        IData/*31:0*/ tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val;
        IData/*16:0*/ tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real;
        IData/*16:0*/ tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag;
        IData/*31:0*/ tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val;
        IData/*16:0*/ tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real;
        IData/*16:0*/ tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag;
    };
    struct {
        IData/*16:0*/ tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real;
        IData/*16:0*/ tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<SData/*15:0*/, 8> tb_fft_top__DOT__input_mem;
        VlUnpacked<SData/*15:0*/, 4> tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real;
        VlUnpacked<SData/*15:0*/, 4> tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag;
        VlUnpacked<IData/*31:0*/, 4> tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data;
        VlUnpacked<SData/*15:0*/, 2> tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real;
        VlUnpacked<SData/*15:0*/, 2> tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag;
        VlUnpacked<IData/*31:0*/, 4> tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data;
        VlUnpacked<IData/*31:0*/, 4> tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
        VlUnpacked<CData/*0:0*/, 10> __Vm_traceActivity;
    };
    double tb_fft_top__DOT__expected_real;
    double tb_fft_top__DOT__expected_imag;
    double tb_fft_top__DOT__hw_real_float;
    double tb_fft_top__DOT__hw_imag_float;
    double tb_fft_top__DOT__err_r;
    double tb_fft_top__DOT__err_i;
    double tb_fft_top__DOT__sig_pwr;
    double tb_fft_top__DOT__noise_pwr;
    double tb_fft_top__DOT__sqnr_val_db;
    double tb_fft_top__DOT__unnamedblk1__DOT__real_float;
    double tb_fft_top__DOT__unnamedblk1__DOT__imag_float;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h475dd34b__0;
    VlUnpacked<double, 8> tb_fft_top__DOT__golden_real;
    VlUnpacked<double, 8> tb_fft_top__DOT__golden_imag;

    // INTERNAL VARIABLES
    Vtb_fft_top__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_fft_top___024root(Vtb_fft_top__Syms* symsp, const char* namep);
    ~Vtb_fft_top___024root();
    VL_UNCOPYABLE(Vtb_fft_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
