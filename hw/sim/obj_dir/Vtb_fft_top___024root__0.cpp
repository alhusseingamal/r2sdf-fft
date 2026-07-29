// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_fft_top.h for the primary calling header

#include "Vtb_fft_top__pch.h"

VL_ATTR_COLD void Vtb_fft_top___024root___eval_initial__TOP(Vtb_fft_top___024root* vlSelf);
VlCoroutine Vtb_fft_top___024root___eval_initial__TOP__Vtiming__0(Vtb_fft_top___024root* vlSelf);
VlCoroutine Vtb_fft_top___024root___eval_initial__TOP__Vtiming__1(Vtb_fft_top___024root* vlSelf);

void Vtb_fft_top___024root___eval_initial(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___eval_initial\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_fft_top___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vtb_fft_top___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_fft_top___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VlCoroutine Vtb_fft_top___024root___eval_initial__TOP__Vtiming__0(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_fft_top__DOT__clk = 0U;
    while (true) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                             nullptr, 
                                             "tb/tb_fft_top.v", 
                                             34);
        vlSelfRef.tb_fft_top__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb_fft_top__DOT__clk)));
    }
    co_return;}

VlCoroutine Vtb_fft_top___024root___eval_initial__TOP__Vtiming__1(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_READMEM_N(true, 16, 8, 0, "/mnt/data1/DV/projects/fft/data/stimulus/input_stream.hex"s
                 ,  &(vlSelfRef.tb_fft_top__DOT__input_mem)
                 , 0, ~0ULL);
    vlSelfRef.tb_fft_top__DOT__fd = VL_FOPEN_NN("/mnt/data1/DV/projects/fft/data/golden/expected_output.txt"s
                                                , "r"s);
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.tb_fft_top__DOT__fd)))) {
        VL_WRITEF_NX("WARNING: Could not open golden output file!\n",0);
    }
    (void)VL_FSCANF_INX(vlSelfRef.tb_fft_top__DOT__fd,"%f %f\n",0,
                        64,&(vlSelfRef.tb_fft_top__DOT__golden_real
                             [0U]),64,&(vlSelfRef.tb_fft_top__DOT__golden_imag
                                        [0U])) ;
    (void)VL_FSCANF_INX(vlSelfRef.tb_fft_top__DOT__fd,"%f %f\n",0,
                        64,&(vlSelfRef.tb_fft_top__DOT__golden_real
                             [1U]),64,&(vlSelfRef.tb_fft_top__DOT__golden_imag
                                        [1U])) ;
    (void)VL_FSCANF_INX(vlSelfRef.tb_fft_top__DOT__fd,"%f %f\n",0,
                        64,&(vlSelfRef.tb_fft_top__DOT__golden_real
                             [2U]),64,&(vlSelfRef.tb_fft_top__DOT__golden_imag
                                        [2U])) ;
    (void)VL_FSCANF_INX(vlSelfRef.tb_fft_top__DOT__fd,"%f %f\n",0,
                        64,&(vlSelfRef.tb_fft_top__DOT__golden_real
                             [3U]),64,&(vlSelfRef.tb_fft_top__DOT__golden_imag
                                        [3U])) ;
    (void)VL_FSCANF_INX(vlSelfRef.tb_fft_top__DOT__fd,"%f %f\n",0,
                        64,&(vlSelfRef.tb_fft_top__DOT__golden_real
                             [4U]),64,&(vlSelfRef.tb_fft_top__DOT__golden_imag
                                        [4U])) ;
    (void)VL_FSCANF_INX(vlSelfRef.tb_fft_top__DOT__fd,"%f %f\n",0,
                        64,&(vlSelfRef.tb_fft_top__DOT__golden_real
                             [5U]),64,&(vlSelfRef.tb_fft_top__DOT__golden_imag
                                        [5U])) ;
    (void)VL_FSCANF_INX(vlSelfRef.tb_fft_top__DOT__fd,"%f %f\n",0,
                        64,&(vlSelfRef.tb_fft_top__DOT__golden_real
                             [6U]),64,&(vlSelfRef.tb_fft_top__DOT__golden_imag
                                        [6U])) ;
    (void)VL_FSCANF_INX(vlSelfRef.tb_fft_top__DOT__fd,"%f %f\n",0,
                        64,&(vlSelfRef.tb_fft_top__DOT__golden_real
                             [7U]),64,&(vlSelfRef.tb_fft_top__DOT__golden_imag
                                        [7U])) ;
    vlSelfRef.tb_fft_top__DOT__i = 8U;
    VL_FCLOSE_I(vlSelfRef.tb_fft_top__DOT__fd); vlSelfRef.tb_fft_top__DOT__reset_n = 0U;
    vlSelfRef.tb_fft_top__DOT__reset_done = 0U;
    vlSelfRef.tb_fft_top__DOT__valid_in = 0U;
    vlSelfRef.tb_fft_top__DOT__in_real = 0U;
    vlSelfRef.tb_fft_top__DOT__in_imag = 0U;
    vlSymsp->_vm_contextp__->dumpfile("fft_n8.vcd"s);
    vlSymsp->_traceDumpOpen();
    co_await vlSelfRef.__VdlySched.delay(0x00000000000061a8ULL, 
                                         nullptr, "tb/tb_fft_top.v", 
                                         89);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fft_top__DOT__reset_n = 1U;
    vlSelfRef.tb_fft_top__DOT__reset_done = 1U;
    VL_WRITEF_NX("--- Starting N=8 FFT Injection ---\n",0);
    vlSelfRef.tb_fft_top__DOT__i = 0U;
    while (VL_GTS_III(32, 8U, vlSelfRef.tb_fft_top__DOT__i)) {
        co_await vlSelfRef.__VtrigSched_h475dd34b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_fft_top.clk)", 
                                                             "tb/tb_fft_top.v", 
                                                             96);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.tb_fft_top__DOT__valid_in = 1U;
        vlSelfRef.tb_fft_top__DOT__in_real = vlSelfRef.tb_fft_top__DOT__input_mem
            [(7U & vlSelfRef.tb_fft_top__DOT__i)];
        vlSelfRef.tb_fft_top__DOT__in_imag = 0U;
        vlSelfRef.tb_fft_top__DOT__i = ((IData)(1U) 
                                        + vlSelfRef.tb_fft_top__DOT__i);
    }
    vlSelfRef.tb_fft_top__DOT__i = 0U;
    while (VL_GTS_III(32, 0x0000000aU, vlSelfRef.tb_fft_top__DOT__i)) {
        co_await vlSelfRef.__VtrigSched_h475dd34b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_fft_top.clk)", 
                                                             "tb/tb_fft_top.v", 
                                                             106);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.tb_fft_top__DOT__valid_in = 1U;
        vlSelfRef.tb_fft_top__DOT__in_real = 0U;
        vlSelfRef.tb_fft_top__DOT__in_imag = 0U;
        vlSelfRef.tb_fft_top__DOT__i = ((IData)(1U) 
                                        + vlSelfRef.tb_fft_top__DOT__i);
    }
    co_await vlSelfRef.__VtrigSched_h475dd34b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fft_top.clk)", 
                                                         "tb/tb_fft_top.v", 
                                                         113);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fft_top__DOT__valid_in = 0U;
    VL_WRITEF_NX("--- Simulation Complete ---\n",0);
    VL_FINISH_MT("tb/tb_fft_top.v", 118, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_return;}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_fft_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtb_fft_top___024root___eval_triggers__act(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___eval_triggers__act\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                      << 2U) 
                                                     | ((((~ (IData)(vlSelfRef.tb_fft_top__DOT__reset_n)) 
                                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_fft_top__DOT__reset_n__0)) 
                                                         << 1U) 
                                                        | ((IData)(vlSelfRef.tb_fft_top__DOT__clk) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_fft_top__DOT__clk__0)))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_fft_top__DOT__clk__0 
        = vlSelfRef.tb_fft_top__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_fft_top__DOT__reset_n__0 
        = vlSelfRef.tb_fft_top__DOT__reset_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_fft_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vtb_fft_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtb_fft_top___024root___act_comb__TOP__0(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___act_comb__TOP__0\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
        = (0x0001ffffU & ((IData)(1U) + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                         - VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__in_real)))));
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
        = (0x0001ffffU & ((IData)(1U) + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                         - VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__in_imag)))));
}

void Vtb_fft_top___024root___eval_act(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___eval_act\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((5ULL & vlSelfRef.__VactTriggered[0U])) {
        Vtb_fft_top___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

void Vtb_fft_top___024root___nba_sequent__TOP__0(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___nba_sequent__TOP__0\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter 
        = vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter;
    vlSelfRef.__Vdly__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter 
        = vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter;
    vlSelfRef.__Vdly__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__counter 
        = vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__counter;
    if (vlSelfRef.tb_fft_top__DOT__reset_n) {
        if (vlSelfRef.tb_fft_top__DOT__valid_in) {
            vlSelfRef.__Vdly__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter)));
        }
        if (vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__valid_out) {
            vlSelfRef.__Vdly__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter)));
        }
        if (vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__valid_out) {
            vlSelfRef.__Vdly__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__counter 
                = (1U & ((IData)(1U) + (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__counter)));
        }
    } else {
        vlSelfRef.__Vdly__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter = 0U;
        vlSelfRef.__Vdly__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter = 0U;
        vlSelfRef.__Vdly__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__counter = 0U;
    }
}

void Vtb_fft_top___024root___nba_sequent__TOP__1(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___nba_sequent__TOP__1\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vfunc_tb_fft_top__DOT__bit_reverse__0__Vfuncout;
    __Vfunc_tb_fft_top__DOT__bit_reverse__0__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_fft_top__DOT__bit_reverse__0__val;
    __Vfunc_tb_fft_top__DOT__bit_reverse__0__val = 0;
    IData/*31:0*/ __Vfunc_tb_fft_top__DOT__bit_reverse__0__num_bits;
    __Vfunc_tb_fft_top__DOT__bit_reverse__0__num_bits = 0;
    IData/*31:0*/ __Vdly__tb_fft_top__DOT__sqnr_valid_count;
    __Vdly__tb_fft_top__DOT__sqnr_valid_count = 0;
    // Body
    vlSelfRef.__VdlySet__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0 = 0U;
    vlSelfRef.__VdlySet__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0 = 0U;
    vlSelfRef.__VdlySet__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0 = 0U;
    vlSelfRef.__VdlySet__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0 = 0U;
    __Vdly__tb_fft_top__DOT__sqnr_valid_count = vlSelfRef.tb_fft_top__DOT__sqnr_valid_count;
    if (vlSelfRef.tb_fft_top__DOT__valid_in) {
        if ((4U & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter))) {
            vlSelfRef.__VdlyVal__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0 
                = (0x0000ffffU & (IData)((0x0000000001ffffffULL 
                                          & ((0x0000000000000080ULL 
                                              + (VL_EXTENDS_QI(33,32, 
                                                               VL_MULS_III(32, 
                                                                           VL_EXTENDS_II(32,16, 
                                                                                (0x0000ffffU 
                                                                                & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                                                >> 1U))), 
                                                                           VL_EXTENDS_II(32,16, 
                                                                                (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
                                                                                >> 0x00000010U)))) 
                                                 - 
                                                 VL_EXTENDS_QI(33,32, 
                                                               VL_MULS_III(32, 
                                                                           VL_EXTENDS_II(32,16, 
                                                                                (0x0000ffffU 
                                                                                & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                                                >> 1U))), 
                                                                           VL_EXTENDS_II(32,16, 
                                                                                (0x0000ffffU 
                                                                                & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val)))))) 
                                             >> 8U))));
            vlSelfRef.__VdlyVal__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0 
                = (0x0000ffffU & (IData)((0x0000000001ffffffULL 
                                          & ((0x0000000000000080ULL 
                                              + (VL_EXTENDS_QI(33,32, 
                                                               VL_MULS_III(32, 
                                                                           VL_EXTENDS_II(32,16, 
                                                                                (0x0000ffffU 
                                                                                & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                                                >> 1U))), 
                                                                           VL_EXTENDS_II(32,16, 
                                                                                (0x0000ffffU 
                                                                                & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val)))) 
                                                 + 
                                                 VL_EXTENDS_QI(33,32, 
                                                               VL_MULS_III(32, 
                                                                           VL_EXTENDS_II(32,16, 
                                                                                (0x0000ffffU 
                                                                                & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                                                >> 1U))), 
                                                                           VL_EXTENDS_II(32,16, 
                                                                                (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
                                                                                >> 0x00000010U)))))) 
                                             >> 8U))));
        } else {
            vlSelfRef.__VdlyVal__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0 
                = (0x0000ffffU & (IData)(vlSelfRef.tb_fft_top__DOT__in_real));
            vlSelfRef.__VdlyVal__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0 
                = (0x0000ffffU & (IData)(vlSelfRef.tb_fft_top__DOT__in_imag));
        }
        vlSelfRef.__VdlyDim0__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0 
            = (3U & ((IData)(1U) + (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr)));
        vlSelfRef.__VdlySet__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0 = 1U;
        vlSelfRef.__VdlyDim0__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0 
            = (3U & ((IData)(1U) + (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr)));
        vlSelfRef.__VdlySet__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0 = 1U;
    }
    if (vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__valid_out) {
        if ((2U & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter))) {
            vlSelfRef.__VdlyVal__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0 
                = (0x0000ffffU & (IData)((0x0000000001ffffffULL 
                                          & ((0x0000000000000080ULL 
                                              + (VL_EXTENDS_QI(33,32, 
                                                               VL_MULS_III(32, 
                                                                           VL_EXTENDS_II(32,16, 
                                                                                (0x0000ffffU 
                                                                                & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                                                >> 1U))), 
                                                                           VL_EXTENDS_II(32,16, 
                                                                                (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
                                                                                >> 0x00000010U)))) 
                                                 - 
                                                 VL_EXTENDS_QI(33,32, 
                                                               VL_MULS_III(32, 
                                                                           VL_EXTENDS_II(32,16, 
                                                                                (0x0000ffffU 
                                                                                & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                                                >> 1U))), 
                                                                           VL_EXTENDS_II(32,16, 
                                                                                (0x0000ffffU 
                                                                                & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val)))))) 
                                             >> 8U))));
            vlSelfRef.__VdlyVal__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0 
                = (0x0000ffffU & (IData)((0x0000000001ffffffULL 
                                          & ((0x0000000000000080ULL 
                                              + (VL_EXTENDS_QI(33,32, 
                                                               VL_MULS_III(32, 
                                                                           VL_EXTENDS_II(32,16, 
                                                                                (0x0000ffffU 
                                                                                & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                                                >> 1U))), 
                                                                           VL_EXTENDS_II(32,16, 
                                                                                (0x0000ffffU 
                                                                                & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val)))) 
                                                 + 
                                                 VL_EXTENDS_QI(33,32, 
                                                               VL_MULS_III(32, 
                                                                           VL_EXTENDS_II(32,16, 
                                                                                (0x0000ffffU 
                                                                                & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                                                >> 1U))), 
                                                                           VL_EXTENDS_II(32,16, 
                                                                                (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
                                                                                >> 0x00000010U)))))) 
                                             >> 8U))));
        } else {
            vlSelfRef.__VdlyVal__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0 
                = (0x0000ffffU & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_real));
            vlSelfRef.__VdlyVal__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0 
                = (0x0000ffffU & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_imag));
        }
        vlSelfRef.__VdlyDim0__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0 
            = (1U & ((IData)(1U) + (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr)));
        vlSelfRef.__VdlySet__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0 = 1U;
        vlSelfRef.__VdlyDim0__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0 
            = (1U & ((IData)(1U) + (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr)));
        vlSelfRef.__VdlySet__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0 = 1U;
    }
    if ((1U == vlSelfRef.tb_fft_top__DOT__reset_done)) {
        if (vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__valid_out) {
            vlSelfRef.tb_fft_top__DOT__unnamedblk1__DOT__real_float 
                = (VL_ISTOR_D_I(16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__out_real)) 
                   / 256.0);
            vlSelfRef.tb_fft_top__DOT__unnamedblk1__DOT__imag_float 
                = (VL_ISTOR_D_I(16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__out_imag)) 
                   / 256.0);
            vlSelfRef.tb_fft_top__DOT__unnamedblk1__DOT__real_float 
                = (8.0 * vlSelfRef.tb_fft_top__DOT__unnamedblk1__DOT__real_float);
            vlSelfRef.tb_fft_top__DOT__unnamedblk1__DOT__imag_float 
                = (8.0 * vlSelfRef.tb_fft_top__DOT__unnamedblk1__DOT__imag_float);
            if (VL_LTES_III(32, 7U, vlSelfRef.tb_fft_top__DOT__total_output_count)) {
                VL_WRITEF_NX("Time %0t | Cycle %0d | y[%0d]: Real = %f, Imag = %f\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,32,vlSelfRef.tb_fft_top__DOT__cycle_count,
                             32,vlSelfRef.tb_fft_top__DOT__valid_output_count,
                             64,vlSelfRef.tb_fft_top__DOT__unnamedblk1__DOT__real_float,
                             64,vlSelfRef.tb_fft_top__DOT__unnamedblk1__DOT__imag_float);
                vlSelfRef.tb_fft_top__DOT__valid_output_count 
                    = ((IData)(1U) + vlSelfRef.tb_fft_top__DOT__valid_output_count);
            } else {
                VL_WRITEF_NX("Time %0t | Cycle %0d | Flush Output: Real = %f, Imag = %f\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,32,vlSelfRef.tb_fft_top__DOT__cycle_count,
                             64,vlSelfRef.tb_fft_top__DOT__unnamedblk1__DOT__real_float,
                             64,vlSelfRef.tb_fft_top__DOT__unnamedblk1__DOT__imag_float);
            }
            vlSelfRef.tb_fft_top__DOT__total_output_count 
                = ((IData)(1U) + vlSelfRef.tb_fft_top__DOT__total_output_count);
        }
        vlSelfRef.tb_fft_top__DOT__cycle_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_fft_top__DOT__cycle_count);
    }
    if (((1U == vlSelfRef.tb_fft_top__DOT__reset_done) 
         & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__valid_out))) {
        if (VL_UNLIKELY(((VL_LTES_III(32, 7U, vlSelfRef.tb_fft_top__DOT__sqnr_total_outputs) 
                          & VL_GTS_III(32, 8U, vlSelfRef.tb_fft_top__DOT__sqnr_valid_count))))) {
            vlSelfRef.tb_fft_top__DOT__hw_real_float 
                = (8.0 * (VL_ISTOR_D_I(16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__out_real)) 
                          / 256.0));
            vlSelfRef.tb_fft_top__DOT__hw_imag_float 
                = (8.0 * (VL_ISTOR_D_I(16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__out_imag)) 
                          / 256.0));
            vlSelfRef.tb_fft_top__DOT__frame_offset 
                = VL_MULS_III(32, (IData)(8U), VL_DIVS_III(32, vlSelfRef.tb_fft_top__DOT__sqnr_valid_count, (IData)(8U)));
            __Vfunc_tb_fft_top__DOT__bit_reverse__0__num_bits = 3U;
            __Vfunc_tb_fft_top__DOT__bit_reverse__0__val 
                = VL_MODDIVS_III(32, vlSelfRef.tb_fft_top__DOT__sqnr_valid_count, (IData)(8U));
            vlSelfRef.tb_fft_top__DOT__bit_reverse__Vstatic__rev = 0U;
            vlSelfRef.tb_fft_top__DOT__bit_reverse__Vstatic__b = 0U;
            while (VL_LTS_III(32, vlSelfRef.tb_fft_top__DOT__bit_reverse__Vstatic__b, __Vfunc_tb_fft_top__DOT__bit_reverse__0__num_bits)) {
                vlSelfRef.tb_fft_top__DOT__bit_reverse__Vstatic__rev 
                    = (VL_SHIFTL_III(32,32,32, vlSelfRef.tb_fft_top__DOT__bit_reverse__Vstatic__rev, 1U) 
                       | (1U & VL_SHIFTR_III(32,32,32, __Vfunc_tb_fft_top__DOT__bit_reverse__0__val, vlSelfRef.tb_fft_top__DOT__bit_reverse__Vstatic__b)));
                vlSelfRef.tb_fft_top__DOT__bit_reverse__Vstatic__b 
                    = ((IData)(1U) + vlSelfRef.tb_fft_top__DOT__bit_reverse__Vstatic__b);
            }
            __Vfunc_tb_fft_top__DOT__bit_reverse__0__Vfuncout 
                = vlSelfRef.tb_fft_top__DOT__bit_reverse__Vstatic__rev;
            vlSelfRef.tb_fft_top__DOT__local_bin_idx 
                = __Vfunc_tb_fft_top__DOT__bit_reverse__0__Vfuncout;
            vlSelfRef.tb_fft_top__DOT__golden_idx = 
                (vlSelfRef.tb_fft_top__DOT__frame_offset 
                 + vlSelfRef.tb_fft_top__DOT__local_bin_idx);
            vlSelfRef.tb_fft_top__DOT__expected_real 
                = vlSelfRef.tb_fft_top__DOT__golden_real
                [(7U & vlSelfRef.tb_fft_top__DOT__golden_idx)];
            vlSelfRef.tb_fft_top__DOT__expected_imag 
                = vlSelfRef.tb_fft_top__DOT__golden_imag
                [(7U & vlSelfRef.tb_fft_top__DOT__golden_idx)];
            VL_WRITEF_NX("\ngolden_real = %f, golden_imag = %f\n",0,
                         64,vlSelfRef.tb_fft_top__DOT__expected_real,
                         64,vlSelfRef.tb_fft_top__DOT__expected_imag);
            vlSelfRef.tb_fft_top__DOT__err_r = (vlSelfRef.tb_fft_top__DOT__expected_real 
                                                - vlSelfRef.tb_fft_top__DOT__hw_real_float);
            vlSelfRef.tb_fft_top__DOT__err_i = (vlSelfRef.tb_fft_top__DOT__expected_imag 
                                                - vlSelfRef.tb_fft_top__DOT__hw_imag_float);
            vlSelfRef.tb_fft_top__DOT__sig_pwr = (vlSelfRef.tb_fft_top__DOT__sig_pwr 
                                                  + 
                                                  (pow(vlSelfRef.tb_fft_top__DOT__expected_real,2.0) 
                                                   + 
                                                   pow(vlSelfRef.tb_fft_top__DOT__expected_imag,2.0)));
            vlSelfRef.tb_fft_top__DOT__noise_pwr = 
                (vlSelfRef.tb_fft_top__DOT__noise_pwr 
                 + (pow(vlSelfRef.tb_fft_top__DOT__err_r,2.0) 
                    + pow(vlSelfRef.tb_fft_top__DOT__err_i,2.0)));
            __Vdly__tb_fft_top__DOT__sqnr_valid_count 
                = ((IData)(1U) + vlSelfRef.tb_fft_top__DOT__sqnr_valid_count);
            if ((7U == vlSelfRef.tb_fft_top__DOT__sqnr_valid_count)) {
                if ((vlSelfRef.tb_fft_top__DOT__noise_pwr 
                     > 0.0)) {
                    vlSelfRef.tb_fft_top__DOT__sqnr_val_db 
                        = (10.0 * log10((vlSelfRef.tb_fft_top__DOT__sig_pwr 
                                         / vlSelfRef.tb_fft_top__DOT__noise_pwr)));
                    VL_WRITEF_NX("\n========================================\nFINAL SQNR OVER 8 SAMPLES: %f dB\n========================================\n\n",0,
                                 64,vlSelfRef.tb_fft_top__DOT__sqnr_val_db);
                } else {
                    VL_WRITEF_NX("\n========================================\nFINAL SQNR OVER 8 SAMPLES: INFINITY\n========================================\n\n",0);
                }
            }
        }
        vlSelfRef.tb_fft_top__DOT__sqnr_total_outputs 
            = ((IData)(1U) + vlSelfRef.tb_fft_top__DOT__sqnr_total_outputs);
    }
    vlSelfRef.tb_fft_top__DOT__sqnr_valid_count = __Vdly__tb_fft_top__DOT__sqnr_valid_count;
}

void Vtb_fft_top___024root___nba_sequent__TOP__2(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___nba_sequent__TOP__2\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__valid_out 
        = ((IData)(vlSelfRef.tb_fft_top__DOT__reset_n) 
           && (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__valid_out));
    if (vlSelfRef.tb_fft_top__DOT__reset_n) {
        if (vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__valid_out) {
            if (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__counter) {
                vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__out_real 
                    = (0x0000ffffU & (0x0000ffffU & 
                                      (((IData)(1U) 
                                        + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                           + VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_real)))) 
                                       >> 1U)));
                vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__out_imag 
                    = (0x0000ffffU & (0x0000ffffU & 
                                      (((IData)(1U) 
                                        + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                           + VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_imag)))) 
                                       >> 1U)));
                vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_real 
                    = (0x0000ffffU & (IData)((0x0000000001ffffffULL 
                                              & ((0x0000000000000080ULL 
                                                  + 
                                                  (VL_EXTENDS_QI(33,32, 
                                                                 VL_MULS_III(32, 
                                                                             VL_EXTENDS_II(32,16, 
                                                                                (0x0000ffffU 
                                                                                & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                                                >> 1U))), 
                                                                             VL_EXTENDS_II(32,16, 
                                                                                (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
                                                                                [0U] 
                                                                                >> 0x00000010U)))) 
                                                   - 
                                                   VL_EXTENDS_QI(33,32, 
                                                                 VL_MULS_III(32, 
                                                                             VL_EXTENDS_II(32,16, 
                                                                                (0x0000ffffU 
                                                                                & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                                                >> 1U))), 
                                                                             VL_EXTENDS_II(32,16, 
                                                                                (0x0000ffffU 
                                                                                & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
                                                                                [0U])))))) 
                                                 >> 8U))));
                vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_imag 
                    = (0x0000ffffU & (IData)((0x0000000001ffffffULL 
                                              & ((0x0000000000000080ULL 
                                                  + 
                                                  (VL_EXTENDS_QI(33,32, 
                                                                 VL_MULS_III(32, 
                                                                             VL_EXTENDS_II(32,16, 
                                                                                (0x0000ffffU 
                                                                                & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                                                >> 1U))), 
                                                                             VL_EXTENDS_II(32,16, 
                                                                                (0x0000ffffU 
                                                                                & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
                                                                                [0U])))) 
                                                   + 
                                                   VL_EXTENDS_QI(33,32, 
                                                                 VL_MULS_III(32, 
                                                                             VL_EXTENDS_II(32,16, 
                                                                                (0x0000ffffU 
                                                                                & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                                                >> 1U))), 
                                                                             VL_EXTENDS_II(32,16, 
                                                                                (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
                                                                                [0U] 
                                                                                >> 0x00000010U)))))) 
                                                 >> 8U))));
            } else {
                vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__out_real 
                    = (0x0000ffffU & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_real));
                vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__out_imag 
                    = (0x0000ffffU & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_imag));
                vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_real 
                    = (0x0000ffffU & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_real));
                vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_imag 
                    = (0x0000ffffU & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_imag));
            }
        }
        if (vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__valid_out) {
            if ((2U & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter))) {
                vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_real 
                    = (0x0000ffffU & (0x0000ffffU & 
                                      (((IData)(1U) 
                                        + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                           + VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_real)))) 
                                       >> 1U)));
                vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_imag 
                    = (0x0000ffffU & (0x0000ffffU & 
                                      (((IData)(1U) 
                                        + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                           + VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_imag)))) 
                                       >> 1U)));
            } else {
                vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_real 
                    = (0x0000ffffU & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_real));
                vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_imag 
                    = (0x0000ffffU & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_imag));
            }
        }
        if (vlSelfRef.tb_fft_top__DOT__valid_in) {
            if ((4U & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter))) {
                vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_real 
                    = (0x0000ffffU & (0x0000ffffU & 
                                      (((IData)(1U) 
                                        + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                           + VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__in_real)))) 
                                       >> 1U)));
                vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_imag 
                    = (0x0000ffffU & (0x0000ffffU & 
                                      (((IData)(1U) 
                                        + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                           + VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__in_imag)))) 
                                       >> 1U)));
            } else {
                vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_real 
                    = (0x0000ffffU & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_real));
                vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_imag 
                    = (0x0000ffffU & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_imag));
            }
        }
    } else {
        vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__out_real = 0U;
        vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__out_imag = 0U;
        vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_real = 0U;
        vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_imag = 0U;
        vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_real = 0U;
        vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_imag = 0U;
        vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_real = 0U;
        vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_imag = 0U;
    }
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__counter 
        = vlSelfRef.__Vdly__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__counter;
    vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__valid_out 
        = ((IData)(vlSelfRef.tb_fft_top__DOT__reset_n) 
           && (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__valid_out));
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter 
        = vlSelfRef.__Vdly__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter;
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
        = (0x0001ffffU & ((IData)(1U) + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                         - VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_real)))));
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
        = (0x0001ffffU & ((IData)(1U) + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                         - VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_imag)))));
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
        = vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
        [(2U & VL_SHIFTL_III(2,2,32, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter), 1U))];
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter 
        = vlSelfRef.__Vdly__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter;
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
        = vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
        [(3U & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter))];
}

void Vtb_fft_top___024root___nba_sequent__TOP__3(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___nba_sequent__TOP__3\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__valid_out) {
        vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_real 
            = vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real
            [vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr];
        vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_imag 
            = vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag
            [vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr];
    }
    if (vlSelfRef.tb_fft_top__DOT__valid_in) {
        vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_real 
            = vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real
            [(3U & ((IData)(2U) + (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr)))];
        vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_imag 
            = vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag
            [(3U & ((IData)(2U) + (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr)))];
    }
    if (vlSelfRef.__VdlySet__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0) {
        vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real[vlSelfRef.__VdlyDim0__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0] 
            = vlSelfRef.__VdlyVal__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0;
    }
    if (vlSelfRef.__VdlySet__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0) {
        vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag[vlSelfRef.__VdlyDim0__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0] 
            = vlSelfRef.__VdlyVal__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0;
    }
    if (vlSelfRef.__VdlySet__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0) {
        vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real[vlSelfRef.__VdlyDim0__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0] 
            = vlSelfRef.__VdlyVal__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0;
    }
    if (vlSelfRef.__VdlySet__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0) {
        vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag[vlSelfRef.__VdlyDim0__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0] 
            = vlSelfRef.__VdlyVal__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0;
    }
}

void Vtb_fft_top___024root___nba_sequent__TOP__4(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___nba_sequent__TOP__4\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb_fft_top__DOT__reset_n) {
        if (vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__valid_out) {
            vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr 
                = vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__lookahead_addr;
        }
        if (vlSelfRef.tb_fft_top__DOT__valid_in) {
            vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr 
                = vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__lookahead_addr;
        }
    } else {
        vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr = 0U;
        vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr = 0U;
    }
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__lookahead_addr 
        = (1U & ((IData)(1U) + (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr)));
    vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__valid_out 
        = ((IData)(vlSelfRef.tb_fft_top__DOT__reset_n) 
           && (IData)(vlSelfRef.tb_fft_top__DOT__valid_in));
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__lookahead_addr 
        = (3U & ((IData)(1U) + (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr)));
}

void Vtb_fft_top___024root___nba_comb__TOP__0(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___nba_comb__TOP__0\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
        = (0x0001ffffU & ((IData)(1U) + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                         - VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_real)))));
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
        = (0x0001ffffU & ((IData)(1U) + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                         - VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_imag)))));
}

void Vtb_fft_top___024root___eval_nba(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___eval_nba\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_fft_top___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_fft_top___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_fft_top___024root___nba_sequent__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_fft_top___024root___nba_sequent__TOP__3(vlSelf);
        vlSelfRef.__Vm_traceActivity[6U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_fft_top___024root___nba_sequent__TOP__4(vlSelf);
        vlSelfRef.__Vm_traceActivity[7U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_fft_top___024root___nba_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[8U] = 1U;
    }
    if ((5ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_fft_top___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[9U] = 1U;
    }
}

void Vtb_fft_top___024root___timing_commit(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___timing_commit\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered[0U]))) {
        vlSelfRef.__VtrigSched_h475dd34b__0.commit(
                                                   "@(posedge tb_fft_top.clk)");
    }
}

void Vtb_fft_top___024root___timing_resume(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___timing_resume\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h475dd34b__0.resume(
                                                   "@(posedge tb_fft_top.clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_fft_top___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_fft_top___024root___eval_phase__act(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___eval_phase__act\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_fft_top___024root___eval_triggers__act(vlSelf);
    Vtb_fft_top___024root___timing_commit(vlSelf);
    Vtb_fft_top___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_fft_top___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        Vtb_fft_top___024root___timing_resume(vlSelf);
        Vtb_fft_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vtb_fft_top___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_fft_top___024root___eval_phase__nba(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___eval_phase__nba\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_fft_top___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb_fft_top___024root___eval_nba(vlSelf);
        Vtb_fft_top___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb_fft_top___024root___eval(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___eval\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_fft_top___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("tb/tb_fft_top.v", 3, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb_fft_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("tb/tb_fft_top.v", 3, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vtb_fft_top___024root___eval_phase__act(vlSelf));
    } while (Vtb_fft_top___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vtb_fft_top___024root___eval_debug_assertions(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___eval_debug_assertions\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
