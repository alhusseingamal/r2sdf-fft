// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_fft_top__Syms.h"


void Vtb_fft_top___024root__trace_chg_0_sub_0(Vtb_fft_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_fft_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root__trace_chg_0\n"); );
    // Body
    Vtb_fft_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_fft_top___024root*>(voidSelf);
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtb_fft_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_fft_top___024root__trace_chg_0_sub_0(Vtb_fft_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root__trace_chg_0_sub_0\n"); );
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[0]),32);
        bufp->chgIData(oldp+1,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[1]),32);
        bufp->chgIData(oldp+2,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[2]),32);
        bufp->chgIData(oldp+3,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[3]),32);
        bufp->chgIData(oldp+4,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[0]),32);
        bufp->chgIData(oldp+5,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[1]),32);
        bufp->chgIData(oldp+6,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[2]),32);
        bufp->chgIData(oldp+7,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[3]),32);
        bufp->chgSData(oldp+8,((vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
                                [0U] >> 0x00000010U)),16);
        bufp->chgSData(oldp+9,((0x0000ffffU & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
                                [0U])),16);
        bufp->chgIData(oldp+10,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[0]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[1]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[2]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data[3]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
                                [0U]),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+15,(vlSelfRef.tb_fft_top__DOT__reset_n));
        bufp->chgBit(oldp+16,(vlSelfRef.tb_fft_top__DOT__valid_in));
        bufp->chgSData(oldp+17,(vlSelfRef.tb_fft_top__DOT__in_real),16);
        bufp->chgSData(oldp+18,(vlSelfRef.tb_fft_top__DOT__in_imag),16);
        bufp->chgIData(oldp+19,(vlSelfRef.tb_fft_top__DOT__i),32);
        bufp->chgIData(oldp+20,(vlSelfRef.tb_fft_top__DOT__reset_done),32);
        bufp->chgSData(oldp+21,(vlSelfRef.tb_fft_top__DOT__input_mem[0]),16);
        bufp->chgSData(oldp+22,(vlSelfRef.tb_fft_top__DOT__input_mem[1]),16);
        bufp->chgSData(oldp+23,(vlSelfRef.tb_fft_top__DOT__input_mem[2]),16);
        bufp->chgSData(oldp+24,(vlSelfRef.tb_fft_top__DOT__input_mem[3]),16);
        bufp->chgSData(oldp+25,(vlSelfRef.tb_fft_top__DOT__input_mem[4]),16);
        bufp->chgSData(oldp+26,(vlSelfRef.tb_fft_top__DOT__input_mem[5]),16);
        bufp->chgSData(oldp+27,(vlSelfRef.tb_fft_top__DOT__input_mem[6]),16);
        bufp->chgSData(oldp+28,(vlSelfRef.tb_fft_top__DOT__input_mem[7]),16);
        bufp->chgDouble(oldp+29,(vlSelfRef.tb_fft_top__DOT__golden_real[0]));
        bufp->chgDouble(oldp+31,(vlSelfRef.tb_fft_top__DOT__golden_real[1]));
        bufp->chgDouble(oldp+33,(vlSelfRef.tb_fft_top__DOT__golden_real[2]));
        bufp->chgDouble(oldp+35,(vlSelfRef.tb_fft_top__DOT__golden_real[3]));
        bufp->chgDouble(oldp+37,(vlSelfRef.tb_fft_top__DOT__golden_real[4]));
        bufp->chgDouble(oldp+39,(vlSelfRef.tb_fft_top__DOT__golden_real[5]));
        bufp->chgDouble(oldp+41,(vlSelfRef.tb_fft_top__DOT__golden_real[6]));
        bufp->chgDouble(oldp+43,(vlSelfRef.tb_fft_top__DOT__golden_real[7]));
        bufp->chgDouble(oldp+45,(vlSelfRef.tb_fft_top__DOT__golden_imag[0]));
        bufp->chgDouble(oldp+47,(vlSelfRef.tb_fft_top__DOT__golden_imag[1]));
        bufp->chgDouble(oldp+49,(vlSelfRef.tb_fft_top__DOT__golden_imag[2]));
        bufp->chgDouble(oldp+51,(vlSelfRef.tb_fft_top__DOT__golden_imag[3]));
        bufp->chgDouble(oldp+53,(vlSelfRef.tb_fft_top__DOT__golden_imag[4]));
        bufp->chgDouble(oldp+55,(vlSelfRef.tb_fft_top__DOT__golden_imag[5]));
        bufp->chgDouble(oldp+57,(vlSelfRef.tb_fft_top__DOT__golden_imag[6]));
        bufp->chgDouble(oldp+59,(vlSelfRef.tb_fft_top__DOT__golden_imag[7]));
        bufp->chgIData(oldp+61,(vlSelfRef.tb_fft_top__DOT__fd),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [4U])))) {
        bufp->chgIData(oldp+62,(vlSelfRef.tb_fft_top__DOT__cycle_count),32);
        bufp->chgIData(oldp+63,(vlSelfRef.tb_fft_top__DOT__total_output_count),32);
        bufp->chgIData(oldp+64,(vlSelfRef.tb_fft_top__DOT__valid_output_count),32);
        bufp->chgIData(oldp+65,(vlSelfRef.tb_fft_top__DOT__sqnr_total_outputs),32);
        bufp->chgIData(oldp+66,(vlSelfRef.tb_fft_top__DOT__sqnr_valid_count),32);
        bufp->chgDouble(oldp+67,(vlSelfRef.tb_fft_top__DOT__sig_pwr));
        bufp->chgDouble(oldp+69,(vlSelfRef.tb_fft_top__DOT__noise_pwr));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [5U])))) {
        bufp->chgSData(oldp+71,((0x0000ffffU & ((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__counter)
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
        bufp->chgSData(oldp+72,((0x0000ffffU & ((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__counter)
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
        bufp->chgSData(oldp+73,((0x0000ffffU & (IData)(
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
        bufp->chgSData(oldp+74,((0x0000ffffU & (IData)(
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
        bufp->chgIData(oldp+75,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                              (0x0000ffffU 
                                                               & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                                  >> 1U))), 
                                            VL_EXTENDS_II(32,16, 
                                                          (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
                                                           [0U] 
                                                           >> 0x00000010U)))),32);
        bufp->chgIData(oldp+76,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                              (0x0000ffffU 
                                                               & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                                  >> 1U))), 
                                            VL_EXTENDS_II(32,16, 
                                                          (0x0000ffffU 
                                                           & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
                                                           [0U])))),32);
        bufp->chgIData(oldp+77,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                              (0x0000ffffU 
                                                               & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                                  >> 1U))), 
                                            VL_EXTENDS_II(32,16, 
                                                          (0x0000ffffU 
                                                           & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
                                                           [0U])))),32);
        bufp->chgIData(oldp+78,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                              (0x0000ffffU 
                                                               & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                                  >> 1U))), 
                                            VL_EXTENDS_II(32,16, 
                                                          (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__rom_data
                                                           [0U] 
                                                           >> 0x00000010U)))),32);
        bufp->chgQData(oldp+79,((0x00000001ffffffffULL 
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
        bufp->chgQData(oldp+81,((0x00000001ffffffffULL 
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
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity
                       [3U] | vlSelfRef.__Vm_traceActivity
                       [5U]) | vlSelfRef.__Vm_traceActivity
                      [9U])))) {
        bufp->chgSData(oldp+83,((0x0000ffffU & (IData)(
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
        bufp->chgSData(oldp+84,((0x0000ffffU & (IData)(
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
        bufp->chgIData(oldp+85,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                              (0x0000ffffU 
                                                               & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                                  >> 1U))), 
                                            VL_EXTENDS_II(32,16, 
                                                          (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
                                                           >> 0x00000010U)))),32);
        bufp->chgIData(oldp+86,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                              (0x0000ffffU 
                                                               & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                                  >> 1U))), 
                                            VL_EXTENDS_II(32,16, 
                                                          (0x0000ffffU 
                                                           & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val)))),32);
        bufp->chgIData(oldp+87,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                              (0x0000ffffU 
                                                               & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                                  >> 1U))), 
                                            VL_EXTENDS_II(32,16, 
                                                          (0x0000ffffU 
                                                           & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val)))),32);
        bufp->chgIData(oldp+88,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                              (0x0000ffffU 
                                                               & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                                  >> 1U))), 
                                            VL_EXTENDS_II(32,16, 
                                                          (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
                                                           >> 0x00000010U)))),32);
        bufp->chgQData(oldp+89,((0x00000001ffffffffULL 
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
        bufp->chgQData(oldp+91,((0x00000001ffffffffULL 
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
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgIData(oldp+93,(vlSelfRef.tb_fft_top__DOT__bit_reverse__Vstatic__b),32);
        bufp->chgIData(oldp+94,(vlSelfRef.tb_fft_top__DOT__bit_reverse__Vstatic__rev),32);
        bufp->chgIData(oldp+95,(vlSelfRef.tb_fft_top__DOT__frame_offset),32);
        bufp->chgIData(oldp+96,(vlSelfRef.tb_fft_top__DOT__local_bin_idx),32);
        bufp->chgIData(oldp+97,(vlSelfRef.tb_fft_top__DOT__golden_idx),32);
        bufp->chgDouble(oldp+98,(vlSelfRef.tb_fft_top__DOT__expected_real));
        bufp->chgDouble(oldp+100,(vlSelfRef.tb_fft_top__DOT__expected_imag));
        bufp->chgDouble(oldp+102,(vlSelfRef.tb_fft_top__DOT__hw_real_float));
        bufp->chgDouble(oldp+104,(vlSelfRef.tb_fft_top__DOT__hw_imag_float));
        bufp->chgDouble(oldp+106,(vlSelfRef.tb_fft_top__DOT__err_r));
        bufp->chgDouble(oldp+108,(vlSelfRef.tb_fft_top__DOT__err_i));
        bufp->chgDouble(oldp+110,(vlSelfRef.tb_fft_top__DOT__sqnr_val_db));
        bufp->chgDouble(oldp+112,(vlSelfRef.tb_fft_top__DOT__unnamedblk1__DOT__real_float));
        bufp->chgDouble(oldp+114,(vlSelfRef.tb_fft_top__DOT__unnamedblk1__DOT__imag_float));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[5U]))) {
        bufp->chgBit(oldp+116,(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__valid_out));
        bufp->chgSData(oldp+117,(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__out_real),16);
        bufp->chgSData(oldp+118,(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__out_imag),16);
        bufp->chgSData(oldp+119,(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_real),16);
        bufp->chgSData(oldp+120,(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_imag),16);
        bufp->chgCData(oldp+121,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter),3);
        bufp->chgBit(oldp+122,((1U & ((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter) 
                                      >> 2U))));
        bufp->chgSData(oldp+123,((vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
                                  >> 0x00000010U)),16);
        bufp->chgSData(oldp+124,((0x0000ffffU & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val)),16);
        bufp->chgCData(oldp+125,((3U & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter))),2);
        bufp->chgIData(oldp+126,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val),32);
        bufp->chgBit(oldp+127,(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__valid_out));
        bufp->chgSData(oldp+128,(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_real),16);
        bufp->chgSData(oldp+129,(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_imag),16);
        bufp->chgCData(oldp+130,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter),2);
        bufp->chgBit(oldp+131,((1U & ((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter) 
                                      >> 1U))));
        bufp->chgSData(oldp+132,((vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
                                  >> 0x00000010U)),16);
        bufp->chgSData(oldp+133,((0x0000ffffU & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val)),16);
        bufp->chgCData(oldp+134,((2U & VL_SHIFTL_III(2,2,32, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter), 1U))),2);
        bufp->chgIData(oldp+135,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val),32);
        bufp->chgBit(oldp+136,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__counter));
        bufp->chgSData(oldp+137,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_real),16);
        bufp->chgSData(oldp+138,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_imag),16);
        bufp->chgSData(oldp+139,((0x0000ffffU & ((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__counter)
                                                  ? 
                                                 (0x0000ffffU 
                                                  & (((IData)(1U) 
                                                      + 
                                                      (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                                       + 
                                                       VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_real)))) 
                                                     >> 1U))
                                                  : (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_real)))),16);
        bufp->chgSData(oldp+140,((0x0000ffffU & ((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__counter)
                                                  ? 
                                                 (0x0000ffffU 
                                                  & (((IData)(1U) 
                                                      + 
                                                      (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                                       + 
                                                       VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_imag)))) 
                                                     >> 1U))
                                                  : (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_imag)))),16);
        bufp->chgSData(oldp+141,((0x0000ffffU & (((IData)(1U) 
                                                  + 
                                                  (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                                   + 
                                                   VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_real)))) 
                                                 >> 1U))),16);
        bufp->chgSData(oldp+142,((0x0000ffffU & (((IData)(1U) 
                                                  + 
                                                  (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                                   + 
                                                   VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_imag)))) 
                                                 >> 1U))),16);
        bufp->chgSData(oldp+143,((0x0000ffffU & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                 >> 1U))),16);
        bufp->chgSData(oldp+144,((0x0000ffffU & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                 >> 1U))),16);
        bufp->chgIData(oldp+145,((0x0001ffffU & ((IData)(1U) 
                                                 + 
                                                 (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                                  + 
                                                  VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_real)))))),17);
        bufp->chgIData(oldp+146,((0x0001ffffU & ((IData)(1U) 
                                                 + 
                                                 (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                                  + 
                                                  VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_imag)))))),17);
        bufp->chgIData(oldp+147,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real),17);
        bufp->chgIData(oldp+148,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__2__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag),17);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[5U] 
                      | vlSelfRef.__Vm_traceActivity
                      [6U])))) {
        bufp->chgSData(oldp+149,((0x0000ffffU & ((2U 
                                                  & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter))
                                                  ? 
                                                 (0x0000ffffU 
                                                  & (((IData)(1U) 
                                                      + 
                                                      (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                                       + 
                                                       VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_real)))) 
                                                     >> 1U))
                                                  : (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_real)))),16);
        bufp->chgSData(oldp+150,((0x0000ffffU & ((2U 
                                                  & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter))
                                                  ? 
                                                 (0x0000ffffU 
                                                  & (((IData)(1U) 
                                                      + 
                                                      (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                                       + 
                                                       VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_imag)))) 
                                                     >> 1U))
                                                  : (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_imag)))),16);
        bufp->chgSData(oldp+151,((0x0000ffffU & (((IData)(1U) 
                                                  + 
                                                  (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                                   + 
                                                   VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_real)))) 
                                                 >> 1U))),16);
        bufp->chgSData(oldp+152,((0x0000ffffU & (((IData)(1U) 
                                                  + 
                                                  (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                                   + 
                                                   VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_imag)))) 
                                                 >> 1U))),16);
        bufp->chgIData(oldp+153,((0x0001ffffU & ((IData)(1U) 
                                                 + 
                                                 (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                                  + 
                                                  VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_real)))))),17);
        bufp->chgIData(oldp+154,((0x0001ffffU & ((IData)(1U) 
                                                 + 
                                                 (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                                  + 
                                                  VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_imag)))))),17);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[5U] 
                      | vlSelfRef.__Vm_traceActivity
                      [8U])))) {
        bufp->chgSData(oldp+155,((0x0000ffffU & ((2U 
                                                  & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter))
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
        bufp->chgSData(oldp+156,((0x0000ffffU & ((2U 
                                                  & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__counter))
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
        bufp->chgSData(oldp+157,((0x0000ffffU & (IData)(
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
        bufp->chgSData(oldp+158,((0x0000ffffU & (IData)(
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
        bufp->chgIData(oldp+159,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                               (0x0000ffffU 
                                                                & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                                   >> 1U))), 
                                             VL_EXTENDS_II(32,16, 
                                                           (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
                                                            >> 0x00000010U)))),32);
        bufp->chgIData(oldp+160,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                               (0x0000ffffU 
                                                                & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                                   >> 1U))), 
                                             VL_EXTENDS_II(32,16, 
                                                           (0x0000ffffU 
                                                            & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val)))),32);
        bufp->chgIData(oldp+161,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                               (0x0000ffffU 
                                                                & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                                   >> 1U))), 
                                             VL_EXTENDS_II(32,16, 
                                                           (0x0000ffffU 
                                                            & vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val)))),32);
        bufp->chgIData(oldp+162,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                               (0x0000ffffU 
                                                                & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                                   >> 1U))), 
                                             VL_EXTENDS_II(32,16, 
                                                           (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__stage_twiddles__DOT__current_val 
                                                            >> 0x00000010U)))),32);
        bufp->chgQData(oldp+163,((0x00000001ffffffffULL 
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
        bufp->chgQData(oldp+165,((0x00000001ffffffffULL 
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
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[6U]))) {
        bufp->chgSData(oldp+167,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_real),16);
        bufp->chgSData(oldp+168,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_imag),16);
        bufp->chgSData(oldp+169,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real[0]),16);
        bufp->chgSData(oldp+170,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real[1]),16);
        bufp->chgSData(oldp+171,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real[2]),16);
        bufp->chgSData(oldp+172,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real[3]),16);
        bufp->chgSData(oldp+173,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag[0]),16);
        bufp->chgSData(oldp+174,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag[1]),16);
        bufp->chgSData(oldp+175,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag[2]),16);
        bufp->chgSData(oldp+176,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag[3]),16);
        bufp->chgSData(oldp+177,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_real),16);
        bufp->chgSData(oldp+178,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__buffer_out_imag),16);
        bufp->chgSData(oldp+179,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real[0]),16);
        bufp->chgSData(oldp+180,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_real[1]),16);
        bufp->chgSData(oldp+181,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag[0]),16);
        bufp->chgSData(oldp+182,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__mem_imag[1]),16);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[7U]))) {
        bufp->chgBit(oldp+183,(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__valid_out));
        bufp->chgCData(oldp+184,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr),2);
        bufp->chgCData(oldp+185,((3U & ((IData)(1U) 
                                        + (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr)))),2);
        bufp->chgBit(oldp+186,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr));
        bufp->chgBit(oldp+187,((1U & ((IData)(1U) + (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__queue__DOT__gen_depth_n__DOT__ptr)))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[8U]))) {
        bufp->chgSData(oldp+188,((0x0000ffffU & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                                 >> 1U))),16);
        bufp->chgSData(oldp+189,((0x0000ffffU & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                                 >> 1U))),16);
        bufp->chgIData(oldp+190,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real),17);
        bufp->chgIData(oldp+191,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__1__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag),17);
    }
    bufp->chgBit(oldp+192,(vlSelfRef.tb_fft_top__DOT__clk));
    bufp->chgQData(oldp+193,((((QData)((IData)((((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__out_real) 
                                                 << 0x00000010U) 
                                                | (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_real)))) 
                               << 0x00000020U) | (QData)((IData)(
                                                                 (((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_real) 
                                                                   << 0x00000010U) 
                                                                  | (IData)(vlSelfRef.tb_fft_top__DOT__in_real)))))),64);
    bufp->chgQData(oldp+195,((((QData)((IData)((((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__out_imag) 
                                                 << 0x00000010U) 
                                                | (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__out_imag)))) 
                               << 0x00000020U) | (QData)((IData)(
                                                                 (((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__out_imag) 
                                                                   << 0x00000010U) 
                                                                  | (IData)(vlSelfRef.tb_fft_top__DOT__in_imag)))))),64);
    bufp->chgCData(oldp+197,(((((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__2__KET____DOT__stage_inst__valid_out) 
                                << 3U) | ((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__1__KET____DOT__stage_inst__valid_out) 
                                          << 2U)) | 
                              (((IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT____Vcellout__stage_gen__BRA__0__KET____DOT__stage_inst__valid_out) 
                                << 1U) | (IData)(vlSelfRef.tb_fft_top__DOT__valid_in)))),4);
    bufp->chgSData(oldp+198,((0x0000ffffU & ((4U & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter))
                                              ? (0x0000ffffU 
                                                 & (((IData)(1U) 
                                                     + 
                                                     (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                                      + 
                                                      VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__in_real)))) 
                                                    >> 1U))
                                              : (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_real)))),16);
    bufp->chgSData(oldp+199,((0x0000ffffU & ((4U & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter))
                                              ? (0x0000ffffU 
                                                 & (((IData)(1U) 
                                                     + 
                                                     (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                                      + 
                                                      VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__in_imag)))) 
                                                    >> 1U))
                                              : (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_imag)))),16);
    bufp->chgSData(oldp+200,((0x0000ffffU & ((4U & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter))
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
    bufp->chgSData(oldp+201,((0x0000ffffU & ((4U & (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__counter))
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
    bufp->chgSData(oldp+202,((0x0000ffffU & (((IData)(1U) 
                                              + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                                 + 
                                                 VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__in_real)))) 
                                             >> 1U))),16);
    bufp->chgSData(oldp+203,((0x0000ffffU & (((IData)(1U) 
                                              + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                                 + 
                                                 VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__in_imag)))) 
                                             >> 1U))),16);
    bufp->chgSData(oldp+204,((0x0000ffffU & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real 
                                             >> 1U))),16);
    bufp->chgSData(oldp+205,((0x0000ffffU & (vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag 
                                             >> 1U))),16);
    bufp->chgIData(oldp+206,((0x0001ffffU & ((IData)(1U) 
                                             + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_real)) 
                                                + VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__in_real)))))),17);
    bufp->chgIData(oldp+207,((0x0001ffffU & ((IData)(1U) 
                                             + (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__buffer_out_imag)) 
                                                + VL_EXTENDS_II(17,16, (IData)(vlSelfRef.tb_fft_top__DOT__in_imag)))))),17);
    bufp->chgIData(oldp+208,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_real),17);
    bufp->chgIData(oldp+209,(vlSelfRef.tb_fft_top__DOT__dut__DOT__stage_gen__BRA__0__KET____DOT__stage_inst__DOT__bf__DOT__sub__DOT__diff_imag),17);
}

void Vtb_fft_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fft_top___024root__trace_cleanup\n"); );
    // Body
    Vtb_fft_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_fft_top___024root*>(voidSelf);
    Vtb_fft_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[8U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[9U] = 0U;
}
