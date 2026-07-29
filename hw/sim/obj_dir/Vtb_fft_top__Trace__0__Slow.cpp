// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_fft_top__Syms.h"


VL_ATTR_COLD void Vtb_fft_top___024root__trace_init_sub__TOP__0(Vtb_fft_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root__trace_init_sub__TOP__0\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("tb_fft_top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+211,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+211,0,"F",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+213,0,"CLK_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+214,0,"ONE_FP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+193,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"reset_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"valid_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+18,0,"in_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+19,0,"in_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+117,0,"valid_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+118,0,"out_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+119,0,"out_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+94,0,"bit_reverse__Vstatic__b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+95,0,"bit_reverse__Vstatic__rev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+20,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+21,0,"reset_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+211,0,"M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("input_mem", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+22+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("golden_real", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declDouble(c+30+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("golden_imag", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declDouble(c+46+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, true,(i+0));
    }
    tracep->popPrefix();
    tracep->declBus(c+62,0,"fd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+63,0,"cycle_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+64,0,"total_output_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+65,0,"valid_output_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+66,0,"sqnr_total_outputs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+67,0,"sqnr_valid_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+96,0,"frame_offset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+97,0,"local_bin_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+98,0,"golden_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declDouble(c+99,0,"expected_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+101,0,"expected_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+103,0,"hw_real_float",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+105,0,"hw_imag_float",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+107,0,"err_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+109,0,"err_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+68,0,"sig_pwr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+70,0,"noise_pwr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+111,0,"sqnr_val_db",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+211,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+211,0,"F",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+193,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"reset_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+18,0,"in_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+19,0,"in_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+117,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+118,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+119,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+215,0,"NUM_STAGES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+194,0,"stage_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+196,0,"stage_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+198,0,"stage_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("stage_gen[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("stage_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+211,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+211,0,"F",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+216,0,"STAGE_INDEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+193,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"reset_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+18,0,"in_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+19,0,"in_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+184,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+120,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+121,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+217,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+122,0,"counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+168,0,"buffer_out_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+169,0,"buffer_out_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+199,0,"flush_real_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+200,0,"flush_imag_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+201,0,"fill_real_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+202,0,"fill_imag_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+123,0,"select_counter_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+124,0,"twiddle_real_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+125,0,"twiddle_imag_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+126,0,"rom_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+203,0,"a_bf_real_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+204,0,"a_bf_imag_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+84,0,"b_bf_real_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+85,0,"b_bf_imag_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("bf", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+211,0,"F",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"a_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+169,0,"a_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+18,0,"b_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+19,0,"b_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+124,0,"twiddle_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+125,0,"twiddle_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+203,0,"aout_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+204,0,"aout_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+84,0,"bout_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+85,0,"bout_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+205,0,"diff_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+206,0,"diff_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"a_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+169,0,"a_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+18,0,"b_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+19,0,"b_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+203,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+204,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+207,0,"sum_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBus(c+208,0,"sum_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->popPrefix();
    tracep->pushPrefix("mult", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+211,0,"F",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+205,0,"a_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+206,0,"a_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+124,0,"b_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+125,0,"b_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+84,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+85,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+86,0,"p_rr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+87,0,"p_ii",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"p_ri",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+89,0,"p_ir",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+90,0,"sum_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+92,0,"sum_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->popPrefix();
    tracep->pushPrefix("sub", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"a_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+169,0,"a_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+18,0,"b_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+19,0,"b_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+205,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+206,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+209,0,"diff_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBus(c+210,0,"diff_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("queue", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+217,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+193,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"reset_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+201,0,"in_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+202,0,"in_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+168,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+169,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("gen_depth_n", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("mem_real", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+170+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("mem_imag", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+174+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+218,0,"PTR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+185,0,"ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+186,0,"lookahead_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("stage_twiddles", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+211,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+126,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+124,0,"twiddle_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+125,0,"twiddle_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("rom_data", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+1+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+127,0,"current_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("stage_gen[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("stage_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+211,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+211,0,"F",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+219,0,"STAGE_INDEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+193,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"reset_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+184,0,"en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+120,0,"in_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+121,0,"in_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+128,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+129,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+130,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+218,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+131,0,"counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+178,0,"buffer_out_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+179,0,"buffer_out_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+150,0,"flush_real_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+151,0,"flush_imag_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+156,0,"fill_real_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+157,0,"fill_imag_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+132,0,"select_counter_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+133,0,"twiddle_real_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+134,0,"twiddle_imag_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+135,0,"rom_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+152,0,"a_bf_real_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+153,0,"a_bf_imag_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+158,0,"b_bf_real_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+159,0,"b_bf_imag_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("bf", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+211,0,"F",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+178,0,"a_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+179,0,"a_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+120,0,"b_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+121,0,"b_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+133,0,"twiddle_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+134,0,"twiddle_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+152,0,"aout_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+153,0,"aout_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+158,0,"bout_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+159,0,"bout_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+189,0,"diff_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+190,0,"diff_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+178,0,"a_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+179,0,"a_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+120,0,"b_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+121,0,"b_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+152,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+153,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+154,0,"sum_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBus(c+155,0,"sum_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->popPrefix();
    tracep->pushPrefix("mult", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+211,0,"F",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+189,0,"a_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+190,0,"a_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+133,0,"b_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+134,0,"b_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+158,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+159,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+160,0,"p_rr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+161,0,"p_ii",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+162,0,"p_ri",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+163,0,"p_ir",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+164,0,"sum_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+166,0,"sum_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->popPrefix();
    tracep->pushPrefix("sub", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+178,0,"a_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+179,0,"a_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+120,0,"b_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+121,0,"b_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+189,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+190,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+191,0,"diff_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBus(c+192,0,"diff_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("queue", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+218,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+193,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"reset_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+184,0,"en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+156,0,"in_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+157,0,"in_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+178,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+179,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("gen_depth_n", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("mem_real", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+180+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("mem_imag", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+182+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+219,0,"PTR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+187,0,"ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+188,0,"lookahead_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("stage_twiddles", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+211,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+135,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+133,0,"twiddle_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+134,0,"twiddle_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("rom_data", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+5+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+136,0,"current_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("stage_gen[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("stage_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+211,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+211,0,"F",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+218,0,"STAGE_INDEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+193,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"reset_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+128,0,"en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+129,0,"in_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+130,0,"in_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+117,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+118,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+119,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+219,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+137,0,"counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+138,0,"buffer_out_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+139,0,"buffer_out_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+140,0,"flush_real_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+141,0,"flush_imag_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+72,0,"fill_real_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+73,0,"fill_imag_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+137,0,"select_counter_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+9,0,"twiddle_real_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+10,0,"twiddle_imag_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+220,0,"rom_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+142,0,"a_bf_real_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+143,0,"a_bf_imag_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+74,0,"b_bf_real_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+75,0,"b_bf_imag_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("bf", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+211,0,"F",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+138,0,"a_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+139,0,"a_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+129,0,"b_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+130,0,"b_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+9,0,"twiddle_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+10,0,"twiddle_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+142,0,"aout_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+143,0,"aout_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+74,0,"bout_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+75,0,"bout_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+144,0,"diff_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+145,0,"diff_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+138,0,"a_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+139,0,"a_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+129,0,"b_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+130,0,"b_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+142,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+143,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+146,0,"sum_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBus(c+147,0,"sum_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->popPrefix();
    tracep->pushPrefix("mult", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+211,0,"F",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+144,0,"a_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+145,0,"a_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+9,0,"b_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+10,0,"b_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+74,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+75,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+76,0,"p_rr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+77,0,"p_ii",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+78,0,"p_ri",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+79,0,"p_ir",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+80,0,"sum_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+82,0,"sum_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->popPrefix();
    tracep->pushPrefix("sub", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+138,0,"a_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+139,0,"a_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+129,0,"b_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+130,0,"b_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+144,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+145,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+148,0,"diff_real",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBus(c+149,0,"diff_imag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("queue", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+219,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+193,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"reset_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+128,0,"en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+72,0,"in_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+73,0,"in_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+138,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+139,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("stage_twiddles", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+212,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+211,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+220,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+9,0,"twiddle_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+10,0,"twiddle_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("rom_data", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+11+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+15,0,"current_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declDouble(c+113,0,"real_float",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+115,0,"imag_float",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_fft_top___024root__trace_init_top(Vtb_fft_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root__trace_init_top\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_fft_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_fft_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb_fft_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_fft_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_fft_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_fft_top___024root__trace_register(Vtb_fft_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root__trace_register\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtb_fft_top___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vtb_fft_top___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vtb_fft_top___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vtb_fft_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_fft_top___024root__trace_const_0_sub_0(Vtb_fft_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_fft_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root__trace_const_0\n"); );
    // Body
    Vtb_fft_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_fft_top___024root*>(voidSelf);
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtb_fft_top___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_fft_top___024root__trace_const_0_sub_0(Vtb_fft_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root__trace_const_0_sub_0\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+211,(8U),32);
    bufp->fullIData(oldp+212,(0x00000010U),32);
    bufp->fullIData(oldp+213,(0x00000014U),32);
    bufp->fullSData(oldp+214,(0x0100U),16);
    bufp->fullIData(oldp+215,(3U),32);
    bufp->fullIData(oldp+216,(0U),32);
    bufp->fullIData(oldp+217,(4U),32);
    bufp->fullIData(oldp+218,(2U),32);
    bufp->fullIData(oldp+219,(1U),32);
    bufp->fullCData(oldp+220,(0U),2);
}

VL_ATTR_COLD void Vtb_fft_top___024root__trace_full_0_sub_0(Vtb_fft_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_fft_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root__trace_full_0\n"); );
    // Body
    Vtb_fft_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_fft_top___024root*>(voidSelf);
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtb_fft_top___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_fft_top___024root__trace_full_0_sub_0(Vtb_fft_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root__trace_full_0_sub_0\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+1,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[0]),32);
    bufp->fullIData(oldp+2,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[1]),32);
    bufp->fullIData(oldp+3,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[2]),32);
    bufp->fullIData(oldp+4,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[3]),32);
    bufp->fullIData(oldp+5,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[0]),32);
    bufp->fullIData(oldp+6,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[1]),32);
    bufp->fullIData(oldp+7,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[2]),32);
    bufp->fullIData(oldp+8,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[3]),32);
    bufp->fullSData(oldp+9,((vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
                             [0U] >> 0x00000010U)),16);
    bufp->fullSData(oldp+10,((0x0000ffffU & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
                              [0U])),16);
    bufp->fullIData(oldp+11,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[0]),32);
    bufp->fullIData(oldp+12,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[1]),32);
    bufp->fullIData(oldp+13,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[2]),32);
    bufp->fullIData(oldp+14,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[3]),32);
    bufp->fullIData(oldp+15,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
                             [0U]),32);
    bufp->fullBit(oldp+16,(vlSelfRef.tb_fft_top__DOT__reset_n));
    bufp->fullBit(oldp+17,(vlSelfRef.tb_fft_top__DOT__valid_in));
    bufp->fullSData(oldp+18,(vlSelfRef.tb_fft_top__DOT__in_real),16);
    bufp->fullSData(oldp+19,(vlSelfRef.tb_fft_top__DOT__in_imag),16);
    bufp->fullIData(oldp+20,(vlSelfRef.tb_fft_top__DOT__i),32);
    bufp->fullIData(oldp+21,(vlSelfRef.tb_fft_top__DOT__reset_done),32);
    bufp->fullSData(oldp+22,(vlSelfRef.tb_fft_top__DOT__input_mem[0]),16);
    bufp->fullSData(oldp+23,(vlSelfRef.tb_fft_top__DOT__input_mem[1]),16);
    bufp->fullSData(oldp+24,(vlSelfRef.tb_fft_top__DOT__input_mem[2]),16);
    bufp->fullSData(oldp+25,(vlSelfRef.tb_fft_top__DOT__input_mem[3]),16);
    bufp->fullSData(oldp+26,(vlSelfRef.tb_fft_top__DOT__input_mem[4]),16);
    bufp->fullSData(oldp+27,(vlSelfRef.tb_fft_top__DOT__input_mem[5]),16);
    bufp->fullSData(oldp+28,(vlSelfRef.tb_fft_top__DOT__input_mem[6]),16);
    bufp->fullSData(oldp+29,(vlSelfRef.tb_fft_top__DOT__input_mem[7]),16);
    bufp->fullDouble(oldp+30,(vlSelfRef.tb_fft_top__DOT__golden_real[0]));
    bufp->fullDouble(oldp+32,(vlSelfRef.tb_fft_top__DOT__golden_real[1]));
    bufp->fullDouble(oldp+34,(vlSelfRef.tb_fft_top__DOT__golden_real[2]));
    bufp->fullDouble(oldp+36,(vlSelfRef.tb_fft_top__DOT__golden_real[3]));
    bufp->fullDouble(oldp+38,(vlSelfRef.tb_fft_top__DOT__golden_real[4]));
    bufp->fullDouble(oldp+40,(vlSelfRef.tb_fft_top__DOT__golden_real[5]));
    bufp->fullDouble(oldp+42,(vlSelfRef.tb_fft_top__DOT__golden_real[6]));
    bufp->fullDouble(oldp+44,(vlSelfRef.tb_fft_top__DOT__golden_real[7]));
    bufp->fullDouble(oldp+46,(vlSelfRef.tb_fft_top__DOT__golden_imag[0]));
    bufp->fullDouble(oldp+48,(vlSelfRef.tb_fft_top__DOT__golden_imag[1]));
    bufp->fullDouble(oldp+50,(vlSelfRef.tb_fft_top__DOT__golden_imag[2]));
    bufp->fullDouble(oldp+52,(vlSelfRef.tb_fft_top__DOT__golden_imag[3]));
    bufp->fullDouble(oldp+54,(vlSelfRef.tb_fft_top__DOT__golden_imag[4]));
    bufp->fullDouble(oldp+56,(vlSelfRef.tb_fft_top__DOT__golden_imag[5]));
    bufp->fullDouble(oldp+58,(vlSelfRef.tb_fft_top__DOT__golden_imag[6]));
    bufp->fullDouble(oldp+60,(vlSelfRef.tb_fft_top__DOT__golden_imag[7]));
    bufp->fullIData(oldp+62,(vlSelfRef.tb_fft_top__DOT__fd),32);
    bufp->fullIData(oldp+63,(vlSelfRef.tb_fft_top__DOT__cycle_count),32);
    bufp->fullIData(oldp+64,(vlSelfRef.tb_fft_top__DOT__total_output_count),32);
    bufp->fullIData(oldp+65,(vlSelfRef.tb_fft_top__DOT__valid_output_count),32);
    bufp->fullIData(oldp+66,(vlSelfRef.tb_fft_top__DOT__sqnr_total_outputs),32);
    bufp->fullIData(oldp+67,(vlSelfRef.tb_fft_top__DOT__sqnr_valid_count),32);
    bufp->fullDouble(oldp+68,(vlSelfRef.tb_fft_top__DOT__sig_pwr));
    bufp->fullDouble(oldp+70,(vlSelfRef.tb_fft_top__DOT__noise_pwr));
    bufp->fullSData(oldp+72,((0x0000ffffU & ((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__counter)
                                              ? (IData)(
                                                        (0x0000000001ffffffULL 
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
                                                            >> 8U)))
                                              : (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_real)))),16);
    bufp->fullSData(oldp+73,((0x0000ffffU & ((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__counter)
                                              ? (IData)(
                                                        (0x0000000001ffffffULL 
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
                                                            >> 8U)))
                                              : (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_imag)))),16);
    bufp->fullSData(oldp+74,((0x0000ffffU & (IData)(
                                                    (0x0000000001ffffffULL 
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
                                                        >> 8U))))),16);
    bufp->fullSData(oldp+75,((0x0000ffffU & (IData)(
                                                    (0x0000000001ffffffULL 
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
                                                        >> 8U))))),16);
    bufp->fullIData(oldp+76,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                           (0x0000ffffU 
                                                            & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                               >> 1U))), 
                                         VL_EXTENDS_II(32,16, 
                                                       (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
                                                        [0U] 
                                                        >> 0x00000010U)))),32);
    bufp->fullIData(oldp+77,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                           (0x0000ffffU 
                                                            & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                               >> 1U))), 
                                         VL_EXTENDS_II(32,16, 
                                                       (0x0000ffffU 
                                                        & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
                                                        [0U])))),32);
    bufp->fullIData(oldp+78,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                           (0x0000ffffU 
                                                            & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                               >> 1U))), 
                                         VL_EXTENDS_II(32,16, 
                                                       (0x0000ffffU 
                                                        & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
                                                        [0U])))),32);
    bufp->fullIData(oldp+79,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                           (0x0000ffffU 
                                                            & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                               >> 1U))), 
                                         VL_EXTENDS_II(32,16, 
                                                       (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
                                                        [0U] 
                                                        >> 0x00000010U)))),32);
    bufp->fullQData(oldp+80,((0x00000001ffffffffULL 
                              & (0x0000000000000080ULL 
                                 + (VL_EXTENDS_QI(33,32, 
                                                  VL_MULS_III(32, 
                                                              VL_EXTENDS_II(32,16, 
                                                                            (0x0000ffffU 
                                                                             & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                                                >> 1U))), 
                                                              VL_EXTENDS_II(32,16, 
                                                                            (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
                                                                             [0U] 
                                                                             >> 0x00000010U)))) 
                                    - VL_EXTENDS_QI(33,32, 
                                                    VL_MULS_III(32, 
                                                                VL_EXTENDS_II(32,16, 
                                                                              (0x0000ffffU 
                                                                               & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                                                >> 1U))), 
                                                                VL_EXTENDS_II(32,16, 
                                                                              (0x0000ffffU 
                                                                               & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
                                                                               [0U])))))))),33);
    bufp->fullQData(oldp+82,((0x00000001ffffffffULL 
                              & (0x0000000000000080ULL 
                                 + (VL_EXTENDS_QI(33,32, 
                                                  VL_MULS_III(32, 
                                                              VL_EXTENDS_II(32,16, 
                                                                            (0x0000ffffU 
                                                                             & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                                                >> 1U))), 
                                                              VL_EXTENDS_II(32,16, 
                                                                            (0x0000ffffU 
                                                                             & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
                                                                             [0U])))) 
                                    + VL_EXTENDS_QI(33,32, 
                                                    VL_MULS_III(32, 
                                                                VL_EXTENDS_II(32,16, 
                                                                              (0x0000ffffU 
                                                                               & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                                                >> 1U))), 
                                                                VL_EXTENDS_II(32,16, 
                                                                              (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
                                                                               [0U] 
                                                                               >> 0x00000010U)))))))),33);
    bufp->fullSData(oldp+84,((0x0000ffffU & (IData)(
                                                    (0x0000000001ffffffULL 
                                                     & ((0x0000000000000080ULL 
                                                         + 
                                                         (VL_EXTENDS_QI(33,32, 
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
                                                        >> 8U))))),16);
    bufp->fullSData(oldp+85,((0x0000ffffU & (IData)(
                                                    (0x0000000001ffffffULL 
                                                     & ((0x0000000000000080ULL 
                                                         + 
                                                         (VL_EXTENDS_QI(33,32, 
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
                                                        >> 8U))))),16);
    bufp->fullIData(oldp+86,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                           (0x0000ffffU 
                                                            & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                               >> 1U))), 
                                         VL_EXTENDS_II(32,16, 
                                                       (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
                                                        >> 0x00000010U)))),32);
    bufp->fullIData(oldp+87,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                           (0x0000ffffU 
                                                            & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                               >> 1U))), 
                                         VL_EXTENDS_II(32,16, 
                                                       (0x0000ffffU 
                                                        & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val)))),32);
    bufp->fullIData(oldp+88,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                           (0x0000ffffU 
                                                            & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                               >> 1U))), 
                                         VL_EXTENDS_II(32,16, 
                                                       (0x0000ffffU 
                                                        & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val)))),32);
    bufp->fullIData(oldp+89,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                           (0x0000ffffU 
                                                            & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                               >> 1U))), 
                                         VL_EXTENDS_II(32,16, 
                                                       (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
                                                        >> 0x00000010U)))),32);
    bufp->fullQData(oldp+90,((0x00000001ffffffffULL 
                              & (0x0000000000000080ULL 
                                 + (VL_EXTENDS_QI(33,32, 
                                                  VL_MULS_III(32, 
                                                              VL_EXTENDS_II(32,16, 
                                                                            (0x0000ffffU 
                                                                             & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                                                >> 1U))), 
                                                              VL_EXTENDS_II(32,16, 
                                                                            (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
                                                                             >> 0x00000010U)))) 
                                    - VL_EXTENDS_QI(33,32, 
                                                    VL_MULS_III(32, 
                                                                VL_EXTENDS_II(32,16, 
                                                                              (0x0000ffffU 
                                                                               & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                                                >> 1U))), 
                                                                VL_EXTENDS_II(32,16, 
                                                                              (0x0000ffffU 
                                                                               & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val)))))))),33);
    bufp->fullQData(oldp+92,((0x00000001ffffffffULL 
                              & (0x0000000000000080ULL 
                                 + (VL_EXTENDS_QI(33,32, 
                                                  VL_MULS_III(32, 
                                                              VL_EXTENDS_II(32,16, 
                                                                            (0x0000ffffU 
                                                                             & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                                                >> 1U))), 
                                                              VL_EXTENDS_II(32,16, 
                                                                            (0x0000ffffU 
                                                                             & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val)))) 
                                    + VL_EXTENDS_QI(33,32, 
                                                    VL_MULS_III(32, 
                                                                VL_EXTENDS_II(32,16, 
                                                                              (0x0000ffffU 
                                                                               & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                                                >> 1U))), 
                                                                VL_EXTENDS_II(32,16, 
                                                                              (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
                                                                               >> 0x00000010U)))))))),33);
    bufp->fullIData(oldp+94,(vlSelfRef.tb_fft_top__DOT__bit_reverse__Vstatic__b),32);
    bufp->fullIData(oldp+95,(vlSelfRef.tb_fft_top__DOT__bit_reverse__Vstatic__rev),32);
    bufp->fullIData(oldp+96,(vlSelfRef.tb_fft_top__DOT__frame_offset),32);
    bufp->fullIData(oldp+97,(vlSelfRef.tb_fft_top__DOT__local_bin_idx),32);
    bufp->fullIData(oldp+98,(vlSelfRef.tb_fft_top__DOT__golden_idx),32);
    bufp->fullDouble(oldp+99,(vlSelfRef.tb_fft_top__DOT__expected_real));
    bufp->fullDouble(oldp+101,(vlSelfRef.tb_fft_top__DOT__expected_imag));
    bufp->fullDouble(oldp+103,(vlSelfRef.tb_fft_top__DOT__hw_real_float));
    bufp->fullDouble(oldp+105,(vlSelfRef.tb_fft_top__DOT__hw_imag_float));
    bufp->fullDouble(oldp+107,(vlSelfRef.tb_fft_top__DOT__err_r));
    bufp->fullDouble(oldp+109,(vlSelfRef.tb_fft_top__DOT__err_i));
    bufp->fullDouble(oldp+111,(vlSelfRef.tb_fft_top__DOT__sqnr_val_db));
    bufp->fullDouble(oldp+113,(vlSelfRef.tb_fft_top__DOT__unnamedblk1__DOT__real_float));
    bufp->fullDouble(oldp+115,(vlSelfRef.tb_fft_top__DOT__unnamedblk1__DOT__imag_float));
    bufp->fullBit(oldp+117,(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__valid_out));
    bufp->fullSData(oldp+118,(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__out_real),16);
    bufp->fullSData(oldp+119,(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__out_imag),16);
    bufp->fullSData(oldp+120,(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_real),16);
    bufp->fullSData(oldp+121,(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_imag),16);
    bufp->fullCData(oldp+122,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter),3);
    bufp->fullBit(oldp+123,((1U & ((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter) 
                                   >> 2U))));
    bufp->fullSData(oldp+124,((vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
                               >> 0x00000010U)),16);
    bufp->fullSData(oldp+125,((0x0000ffffU & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val)),16);
    bufp->fullCData(oldp+126,((3U & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter))),2);
    bufp->fullIData(oldp+127,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val),32);
    bufp->fullBit(oldp+128,(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__valid_out));
    bufp->fullSData(oldp+129,(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_real),16);
    bufp->fullSData(oldp+130,(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_imag),16);
    bufp->fullCData(oldp+131,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter),2);
    bufp->fullBit(oldp+132,((1U & ((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter) 
                                   >> 1U))));
    bufp->fullSData(oldp+133,((vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
                               >> 0x00000010U)),16);
    bufp->fullSData(oldp+134,((0x0000ffffU & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val)),16);
    bufp->fullCData(oldp+135,((2U & VL_SHIFTL_III(2,2,32, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter), 1U))),2);
    bufp->fullIData(oldp+136,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val),32);
    bufp->fullBit(oldp+137,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__counter));
    bufp->fullSData(oldp+138,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_real),16);
    bufp->fullSData(oldp+139,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_imag),16);
    bufp->fullSData(oldp+140,((0x0000ffffU & ((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__counter)
                                               ? (0x0000ffffU 
                                                  & (((IData)(1U) 
                                                      + 
                                                      (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                                       + 
                                                       VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_real)))) 
                                                     >> 1U))
                                               : (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_real)))),16);
    bufp->fullSData(oldp+141,((0x0000ffffU & ((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__counter)
                                               ? (0x0000ffffU 
                                                  & (((IData)(1U) 
                                                      + 
                                                      (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                                       + 
                                                       VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_imag)))) 
                                                     >> 1U))
                                               : (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_imag)))),16);
    bufp->fullSData(oldp+142,((0x0000ffffU & (((IData)(1U) 
                                               + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                                  + 
                                                  VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_real)))) 
                                              >> 1U))),16);
    bufp->fullSData(oldp+143,((0x0000ffffU & (((IData)(1U) 
                                               + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                                  + 
                                                  VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_imag)))) 
                                              >> 1U))),16);
    bufp->fullSData(oldp+144,((0x0000ffffU & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                              >> 1U))),16);
    bufp->fullSData(oldp+145,((0x0000ffffU & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                              >> 1U))),16);
    bufp->fullIData(oldp+146,((0x0001ffffU & ((IData)(1U) 
                                              + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                                 + 
                                                 VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_real)))))),17);
    bufp->fullIData(oldp+147,((0x0001ffffU & ((IData)(1U) 
                                              + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                                 + 
                                                 VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_imag)))))),17);
    bufp->fullIData(oldp+148,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real),17);
    bufp->fullIData(oldp+149,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag),17);
    bufp->fullSData(oldp+150,((0x0000ffffU & ((2U & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter))
                                               ? (0x0000ffffU 
                                                  & (((IData)(1U) 
                                                      + 
                                                      (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                                       + 
                                                       VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_real)))) 
                                                     >> 1U))
                                               : (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_real)))),16);
    bufp->fullSData(oldp+151,((0x0000ffffU & ((2U & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter))
                                               ? (0x0000ffffU 
                                                  & (((IData)(1U) 
                                                      + 
                                                      (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                                       + 
                                                       VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_imag)))) 
                                                     >> 1U))
                                               : (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_imag)))),16);
    bufp->fullSData(oldp+152,((0x0000ffffU & (((IData)(1U) 
                                               + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                                  + 
                                                  VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_real)))) 
                                              >> 1U))),16);
    bufp->fullSData(oldp+153,((0x0000ffffU & (((IData)(1U) 
                                               + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                                  + 
                                                  VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_imag)))) 
                                              >> 1U))),16);
    bufp->fullIData(oldp+154,((0x0001ffffU & ((IData)(1U) 
                                              + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                                 + 
                                                 VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_real)))))),17);
    bufp->fullIData(oldp+155,((0x0001ffffU & ((IData)(1U) 
                                              + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                                 + 
                                                 VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_imag)))))),17);
    bufp->fullSData(oldp+156,((0x0000ffffU & ((2U & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter))
                                               ? (IData)(
                                                         (0x0000000001ffffffULL 
                                                          & ((0x0000000000000080ULL 
                                                              + 
                                                              (VL_EXTENDS_QI(33,32, 
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
                                                             >> 8U)))
                                               : (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_real)))),16);
    bufp->fullSData(oldp+157,((0x0000ffffU & ((2U & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter))
                                               ? (IData)(
                                                         (0x0000000001ffffffULL 
                                                          & ((0x0000000000000080ULL 
                                                              + 
                                                              (VL_EXTENDS_QI(33,32, 
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
                                                             >> 8U)))
                                               : (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_imag)))),16);
    bufp->fullSData(oldp+158,((0x0000ffffU & (IData)(
                                                     (0x0000000001ffffffULL 
                                                      & ((0x0000000000000080ULL 
                                                          + 
                                                          (VL_EXTENDS_QI(33,32, 
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
                                                         >> 8U))))),16);
    bufp->fullSData(oldp+159,((0x0000ffffU & (IData)(
                                                     (0x0000000001ffffffULL 
                                                      & ((0x0000000000000080ULL 
                                                          + 
                                                          (VL_EXTENDS_QI(33,32, 
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
                                                         >> 8U))))),16);
    bufp->fullIData(oldp+160,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                            (0x0000ffffU 
                                                             & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                                >> 1U))), 
                                          VL_EXTENDS_II(32,16, 
                                                        (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
                                                         >> 0x00000010U)))),32);
    bufp->fullIData(oldp+161,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                            (0x0000ffffU 
                                                             & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                                >> 1U))), 
                                          VL_EXTENDS_II(32,16, 
                                                        (0x0000ffffU 
                                                         & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val)))),32);
    bufp->fullIData(oldp+162,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                            (0x0000ffffU 
                                                             & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                                >> 1U))), 
                                          VL_EXTENDS_II(32,16, 
                                                        (0x0000ffffU 
                                                         & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val)))),32);
    bufp->fullIData(oldp+163,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                            (0x0000ffffU 
                                                             & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                                >> 1U))), 
                                          VL_EXTENDS_II(32,16, 
                                                        (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
                                                         >> 0x00000010U)))),32);
    bufp->fullQData(oldp+164,((0x00000001ffffffffULL 
                               & (0x0000000000000080ULL 
                                  + (VL_EXTENDS_QI(33,32, 
                                                   VL_MULS_III(32, 
                                                               VL_EXTENDS_II(32,16, 
                                                                             (0x0000ffffU 
                                                                              & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                                                >> 1U))), 
                                                               VL_EXTENDS_II(32,16, 
                                                                             (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
                                                                              >> 0x00000010U)))) 
                                     - VL_EXTENDS_QI(33,32, 
                                                     VL_MULS_III(32, 
                                                                 VL_EXTENDS_II(32,16, 
                                                                               (0x0000ffffU 
                                                                                & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                                                >> 1U))), 
                                                                 VL_EXTENDS_II(32,16, 
                                                                               (0x0000ffffU 
                                                                                & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val)))))))),33);
    bufp->fullQData(oldp+166,((0x00000001ffffffffULL 
                               & (0x0000000000000080ULL 
                                  + (VL_EXTENDS_QI(33,32, 
                                                   VL_MULS_III(32, 
                                                               VL_EXTENDS_II(32,16, 
                                                                             (0x0000ffffU 
                                                                              & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                                                >> 1U))), 
                                                               VL_EXTENDS_II(32,16, 
                                                                             (0x0000ffffU 
                                                                              & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val)))) 
                                     + VL_EXTENDS_QI(33,32, 
                                                     VL_MULS_III(32, 
                                                                 VL_EXTENDS_II(32,16, 
                                                                               (0x0000ffffU 
                                                                                & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                                                >> 1U))), 
                                                                 VL_EXTENDS_II(32,16, 
                                                                               (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
                                                                                >> 0x00000010U)))))))),33);
    bufp->fullSData(oldp+168,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_real),16);
    bufp->fullSData(oldp+169,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_imag),16);
    bufp->fullSData(oldp+170,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real[0]),16);
    bufp->fullSData(oldp+171,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real[1]),16);
    bufp->fullSData(oldp+172,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real[2]),16);
    bufp->fullSData(oldp+173,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real[3]),16);
    bufp->fullSData(oldp+174,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag[0]),16);
    bufp->fullSData(oldp+175,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag[1]),16);
    bufp->fullSData(oldp+176,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag[2]),16);
    bufp->fullSData(oldp+177,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag[3]),16);
    bufp->fullSData(oldp+178,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_real),16);
    bufp->fullSData(oldp+179,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_imag),16);
    bufp->fullSData(oldp+180,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real[0]),16);
    bufp->fullSData(oldp+181,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real[1]),16);
    bufp->fullSData(oldp+182,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag[0]),16);
    bufp->fullSData(oldp+183,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag[1]),16);
    bufp->fullBit(oldp+184,(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__valid_out));
    bufp->fullCData(oldp+185,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr),2);
    bufp->fullCData(oldp+186,((3U & ((IData)(1U) + (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr)))),2);
    bufp->fullBit(oldp+187,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr));
    bufp->fullBit(oldp+188,((1U & ((IData)(1U) + (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr)))));
    bufp->fullSData(oldp+189,((0x0000ffffU & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                              >> 1U))),16);
    bufp->fullSData(oldp+190,((0x0000ffffU & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                              >> 1U))),16);
    bufp->fullIData(oldp+191,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real),17);
    bufp->fullIData(oldp+192,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag),17);
    bufp->fullBit(oldp+193,(vlSelfRef.tb_fft_top__DOT__clk));
    bufp->fullQData(oldp+194,((((QData)((IData)((((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__out_real) 
                                                  << 0x00000010U) 
                                                 | (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_real)))) 
                                << 0x00000020U) | (QData)((IData)(
                                                                  (((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_real) 
                                                                    << 0x00000010U) 
                                                                   | (IData)(vlSelfRef.tb_fft_top__DOT__in_real)))))),64);
    bufp->fullQData(oldp+196,((((QData)((IData)((((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__out_imag) 
                                                  << 0x00000010U) 
                                                 | (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_imag)))) 
                                << 0x00000020U) | (QData)((IData)(
                                                                  (((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_imag) 
                                                                    << 0x00000010U) 
                                                                   | (IData)(vlSelfRef.tb_fft_top__DOT__in_imag)))))),64);
    bufp->fullCData(oldp+198,(((((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__valid_out) 
                                 << 3U) | ((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__valid_out) 
                                           << 2U)) 
                               | (((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__valid_out) 
                                   << 1U) | (IData)(vlSelfRef.tb_fft_top__DOT__valid_in)))),4);
    bufp->fullSData(oldp+199,((0x0000ffffU & ((4U & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter))
                                               ? (0x0000ffffU 
                                                  & (((IData)(1U) 
                                                      + 
                                                      (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                                       + 
                                                       VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__in_real)))) 
                                                     >> 1U))
                                               : (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_real)))),16);
    bufp->fullSData(oldp+200,((0x0000ffffU & ((4U & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter))
                                               ? (0x0000ffffU 
                                                  & (((IData)(1U) 
                                                      + 
                                                      (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                                       + 
                                                       VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__in_imag)))) 
                                                     >> 1U))
                                               : (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_imag)))),16);
    bufp->fullSData(oldp+201,((0x0000ffffU & ((4U & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter))
                                               ? (IData)(
                                                         (0x0000000001ffffffULL 
                                                          & ((0x0000000000000080ULL 
                                                              + 
                                                              (VL_EXTENDS_QI(33,32, 
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
                                                             >> 8U)))
                                               : (IData)(vlSelfRef.tb_fft_top__DOT__in_real)))),16);
    bufp->fullSData(oldp+202,((0x0000ffffU & ((4U & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter))
                                               ? (IData)(
                                                         (0x0000000001ffffffULL 
                                                          & ((0x0000000000000080ULL 
                                                              + 
                                                              (VL_EXTENDS_QI(33,32, 
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
                                                             >> 8U)))
                                               : (IData)(vlSelfRef.tb_fft_top__DOT__in_imag)))),16);
    bufp->fullSData(oldp+203,((0x0000ffffU & (((IData)(1U) 
                                               + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                                  + 
                                                  VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__in_real)))) 
                                              >> 1U))),16);
    bufp->fullSData(oldp+204,((0x0000ffffU & (((IData)(1U) 
                                               + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                                  + 
                                                  VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__in_imag)))) 
                                              >> 1U))),16);
    bufp->fullSData(oldp+205,((0x0000ffffU & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                              >> 1U))),16);
    bufp->fullSData(oldp+206,((0x0000ffffU & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                              >> 1U))),16);
    bufp->fullIData(oldp+207,((0x0001ffffU & ((IData)(1U) 
                                              + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                                 + 
                                                 VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__in_real)))))),17);
    bufp->fullIData(oldp+208,((0x0001ffffU & ((IData)(1U) 
                                              + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                                 + 
                                                 VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__in_imag)))))),17);
    bufp->fullIData(oldp+209,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real),17);
    bufp->fullIData(oldp+210,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag),17);
}
