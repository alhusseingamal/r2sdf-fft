// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_fft_top.h for the primary calling header

#include "Vtb_fft_top__pch.h"

VL_ATTR_COLD void Vtb_fft_top___024root___eval_static(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___eval_static\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb_fft_top__DOT__clk__0 
        = vlSelfRef.tb_fft_top__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_fft_top__DOT__reset_n__0 
        = vlSelfRef.tb_fft_top__DOT__reset_n;
}

VL_ATTR_COLD void Vtb_fft_top___024root___eval_initial__TOP(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___eval_initial__TOP\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_fft_top__DOT__cycle_count = 1U;
    vlSelfRef.tb_fft_top__DOT__total_output_count = 0U;
    vlSelfRef.tb_fft_top__DOT__valid_output_count = 0U;
    vlSelfRef.tb_fft_top__DOT__sqnr_total_outputs = 0U;
    vlSelfRef.tb_fft_top__DOT__sqnr_valid_count = 0U;
    vlSelfRef.tb_fft_top__DOT__sig_pwr = 0.0;
    vlSelfRef.tb_fft_top__DOT__noise_pwr = 0.0;
    VL_READMEM_N(true, 32, 4, 0, "/mnt/data1/DV/projects/fft/data/stimulus/twiddle.hex"s
                 ,  &(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 32, 4, 0, "/mnt/data1/DV/projects/fft/data/stimulus/twiddle.hex"s
                 ,  &(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 32, 4, 0, "/mnt/data1/DV/projects/fft/data/stimulus/twiddle.hex"s
                 ,  &(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vtb_fft_top___024root___eval_final(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___eval_final\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_fft_top___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_fft_top___024root___eval_phase__stl(Vtb_fft_top___024root* vlSelf);

VL_ATTR_COLD void Vtb_fft_top___024root___eval_settle(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___eval_settle\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb_fft_top___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("tb/tb_fft_top.v", 3, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vtb_fft_top___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vtb_fft_top___024root___eval_triggers__stl(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___eval_triggers__stl\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_fft_top___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vtb_fft_top___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_fft_top___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_fft_top___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_fft_top___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vtb_fft_top___024root___stl_sequent__TOP__0(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___stl_sequent__TOP__0\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__lookahead_addr 
        = (3U & ((IData)(1U) + (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr)));
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__lookahead_addr 
        = (1U & ((IData)(1U) + (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr)));
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
        = vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
        [(3U & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter))];
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
        = (0x0001ffffU & ((IData)(1U) + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                         - VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__in_real)))));
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
        = (0x0001ffffU & ((IData)(1U) + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                         - VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__in_imag)))));
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
        = vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
        [(2U & VL_SHIFTL_III(2,2,32, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter), 1U))];
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
        = (0x0001ffffU & ((IData)(1U) + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                         - VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_real)))));
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
        = (0x0001ffffU & ((IData)(1U) + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                         - VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_imag)))));
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
        = (0x0001ffffU & ((IData)(1U) + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                         - VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_real)))));
    vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
        = (0x0001ffffU & ((IData)(1U) + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                         - VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_imag)))));
}

VL_ATTR_COLD void Vtb_fft_top___024root____Vm_traceActivitySetAll(Vtb_fft_top___024root* vlSelf);

VL_ATTR_COLD void Vtb_fft_top___024root___eval_stl(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___eval_stl\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtb_fft_top___024root___stl_sequent__TOP__0(vlSelf);
        Vtb_fft_top___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool Vtb_fft_top___024root___eval_phase__stl(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___eval_phase__stl\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_fft_top___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vtb_fft_top___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtb_fft_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtb_fft_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_fft_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_fft_top___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_fft_top.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge tb_fft_top.reset_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_fft_top___024root____Vm_traceActivitySetAll(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root____Vm_traceActivitySetAll\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
    vlSelfRef.__Vm_traceActivity[6U] = 1U;
    vlSelfRef.__Vm_traceActivity[7U] = 1U;
    vlSelfRef.__Vm_traceActivity[8U] = 1U;
    vlSelfRef.__Vm_traceActivity[9U] = 1U;
}

VL_ATTR_COLD void Vtb_fft_top___024root___ctor_var_reset(Vtb_fft_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root___ctor_var_reset\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_fft_top__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2900564201358303623ull);
    vlSelf->tb_fft_top__DOT__reset_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13809689757837332537ull);
    vlSelf->tb_fft_top__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7624346602472745253ull);
    vlSelf->tb_fft_top__DOT__in_real = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5798016022995609048ull);
    vlSelf->tb_fft_top__DOT__in_imag = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1473018603723085895ull);
    vlSelf->tb_fft_top__DOT__bit_reverse__Vstatic__b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14164074064030246112ull);
    vlSelf->tb_fft_top__DOT__bit_reverse__Vstatic__rev = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4418060231831065642ull);
    vlSelf->tb_fft_top__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15518157996440581537ull);
    vlSelf->tb_fft_top__DOT__reset_done = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8044111152918086546ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_fft_top__DOT__input_mem[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7618878522458543033ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_fft_top__DOT__golden_real[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_fft_top__DOT__golden_imag[__Vi0] = 0;
    }
    vlSelf->tb_fft_top__DOT__fd = 0;
    vlSelf->tb_fft_top__DOT__cycle_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4057833453575029987ull);
    vlSelf->tb_fft_top__DOT__total_output_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15944080916347226309ull);
    vlSelf->tb_fft_top__DOT__valid_output_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12146525859177150835ull);
    vlSelf->tb_fft_top__DOT__sqnr_total_outputs = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 212188870481160774ull);
    vlSelf->tb_fft_top__DOT__sqnr_valid_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12057907577022672150ull);
    vlSelf->tb_fft_top__DOT__frame_offset = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 37575044481246283ull);
    vlSelf->tb_fft_top__DOT__local_bin_idx = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18332012344099474228ull);
    vlSelf->tb_fft_top__DOT__golden_idx = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5634643672770481385ull);
    vlSelf->tb_fft_top__DOT__expected_real = 0;
    vlSelf->tb_fft_top__DOT__expected_imag = 0;
    vlSelf->tb_fft_top__DOT__hw_real_float = 0;
    vlSelf->tb_fft_top__DOT__hw_imag_float = 0;
    vlSelf->tb_fft_top__DOT__err_r = 0;
    vlSelf->tb_fft_top__DOT__err_i = 0;
    vlSelf->tb_fft_top__DOT__sig_pwr = 0;
    vlSelf->tb_fft_top__DOT__noise_pwr = 0;
    vlSelf->tb_fft_top__DOT__sqnr_val_db = 0;
    vlSelf->tb_fft_top__DOT__unnamedblk1__DOT__real_float = 0;
    vlSelf->tb_fft_top__DOT__unnamedblk1__DOT__imag_float = 0;
    vlSelf->tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_imag = 0;
    vlSelf->tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_real = 0;
    vlSelf->tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__valid_out = 0;
    vlSelf->tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_imag = 0;
    vlSelf->tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_real = 0;
    vlSelf->tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__valid_out = 0;
    vlSelf->tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__out_imag = 0;
    vlSelf->tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__out_real = 0;
    vlSelf->tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__valid_out = 0;
    vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17830176706602144189ull);
    vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_real = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7888851781036089996ull);
    vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_imag = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11734999238631769324ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12554021034391573155ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9666103279428664266ull);
    }
    vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5814730396428505684ull);
    vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__lookahead_addr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6956399224699116109ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 304307958181082965ull);
    }
    vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2495288233309854379ull);
    vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 7929021185582910118ull);
    vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 11891960245576588049ull);
    vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6314952979095000317ull);
    vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_real = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11133403582496741448ull);
    vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_imag = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2270105392344686058ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12961629212778182852ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6727099917546863569ull);
    }
    vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15265950728035263293ull);
    vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__lookahead_addr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6952852578884790553ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17586114005811238532ull);
    }
    vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16272628108056404599ull);
    vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 17695174278859408519ull);
    vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 3026967501786159194ull);
    vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__counter = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3400651938073891122ull);
    vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_real = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1504595610002411758ull);
    vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_imag = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15435049526901186709ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13837459785783962238ull);
    }
    vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 3059327739226224508ull);
    vlSelf->tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 11015333980364839444ull);
    vlSelf->__Vdly__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter = 0;
    vlSelf->__Vdly__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter = 0;
    vlSelf->__Vdly__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__counter = 0;
    vlSelf->__VdlyVal__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0 = 0;
    vlSelf->__VdlyDim0__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0 = 0;
    vlSelf->__VdlySet__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0 = 0;
    vlSelf->__VdlyVal__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0 = 0;
    vlSelf->__VdlyDim0__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0 = 0;
    vlSelf->__VdlySet__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0 = 0;
    vlSelf->__VdlyVal__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0 = 0;
    vlSelf->__VdlyDim0__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0 = 0;
    vlSelf->__VdlySet__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real__v0 = 0;
    vlSelf->__VdlyVal__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0 = 0;
    vlSelf->__VdlyDim0__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0 = 0;
    vlSelf->__VdlySet__tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag__v0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb_fft_top__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_fft_top__DOT__reset_n__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
