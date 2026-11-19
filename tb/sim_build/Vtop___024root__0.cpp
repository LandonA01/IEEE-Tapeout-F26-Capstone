// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop___024root___eval_sample(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_sample\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
bool Vtop___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 1> &in);
void Vtop___024root___ico_comb__TOP__0(Vtop___024root* vlSelf);

bool Vtop___024root___eval_ico(Vtop___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VicoExecute;
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (::IData)((::IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        {
            // Inlined CFunc: _eval_body__ico
            if ((((1ULL & vlSelfRef.__VicoTriggered[0U])) != 0ULL)) {
                Vtop___024root___ico_comb__TOP__0(vlSelf);
            }
        }
    }
    return (__VicoExecute);
}

bool Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vtop___024root___eval_inact(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_inact\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vtop___024root___eval_obs(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_obs\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vtop___024root___eval_react(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_react\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vtop___024root___eval_postponed(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_postponed\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool Vtop___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((::IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024root___ico_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.alu__DOT__ALUSrc = vlSelfRef.__VprimaryPorts.ALUSrc;
    vlSelfRef.alu__DOT__ALU_src2 = vlSelfRef.__VprimaryPorts.ALU_src2;
    vlSelfRef.alu__DOT__ALU_src1 = vlSelfRef.__VprimaryPorts.ALU_src1;
    vlSelfRef.alu__DOT__ALUOp = vlSelfRef.__VprimaryPorts.ALUOp;
    vlSelfRef.alu__DOT__Carry = vlSelfRef.__VprimaryPorts.Carry;
    vlSelfRef.alu__DOT__ALUResult = 0U;
    vlSelfRef.alu__DOT__ALUCarryOut = 0U;
    if ((0U == (::IData)(vlSelfRef.alu__DOT__ALUOp))) {
        vlSelfRef.alu__DOT__ALUResult = (0x000000ffU 
                                         & ((::IData)(vlSelfRef.alu__DOT__ALU_src1) 
                                            + (::IData)(vlSelfRef.alu__DOT__ALU_src2)));
        vlSelfRef.alu__DOT__ALUCarryOut = (1U & (((::IData)(vlSelfRef.alu__DOT__ALU_src1) 
                                                  + (::IData)(vlSelfRef.alu__DOT__ALU_src2)) 
                                                 >> 8U));
    } else if ((1U == (::IData)(vlSelfRef.alu__DOT__ALUOp))) {
        vlSelfRef.alu__DOT__ALUResult = (0x000000ffU 
                                         & ((::IData)(1U) 
                                            + ((::IData)(vlSelfRef.alu__DOT__ALU_src1) 
                                               + (~ (::IData)(vlSelfRef.alu__DOT__ALU_src2)))));
        vlSelfRef.alu__DOT__ALUCarryOut = (1U & (((::IData)(1U) 
                                                  + 
                                                  ((::IData)(vlSelfRef.alu__DOT__ALU_src1) 
                                                   + 
                                                   (0x000000ffU 
                                                    & (~ (::IData)(vlSelfRef.alu__DOT__ALU_src2))))) 
                                                 >> 8U));
    } else {
        if ((2U == (::IData)(vlSelfRef.alu__DOT__ALUOp))) {
            vlSelfRef.alu__DOT__ALUResult = ((::IData)(vlSelfRef.alu__DOT__ALU_src1) 
                                             | (::IData)(vlSelfRef.alu__DOT__ALU_src2));
        } else if ((3U == (::IData)(vlSelfRef.alu__DOT__ALUOp))) {
            vlSelfRef.alu__DOT__ALUResult = ((::IData)(vlSelfRef.alu__DOT__ALU_src1) 
                                             ^ (::IData)(vlSelfRef.alu__DOT__ALU_src2));
        } else if ((4U == (::IData)(vlSelfRef.alu__DOT__ALUOp))) {
            vlSelfRef.alu__DOT__ALUResult = (0x000000ffU 
                                             & (((::IData)(vlSelfRef.alu__DOT__ALU_src1) 
                                                 + (::IData)(vlSelfRef.alu__DOT__ALU_src2)) 
                                                + (::IData)(vlSelfRef.alu__DOT__Carry)));
        } else if ((5U == (::IData)(vlSelfRef.alu__DOT__ALUOp))) {
            vlSelfRef.alu__DOT__ALUResult = (0x000000ffU 
                                             & ((::IData)(vlSelfRef.alu__DOT__ALU_src1) 
                                                << 1U));
        } else if ((6U == (::IData)(vlSelfRef.alu__DOT__ALUOp))) {
            vlSelfRef.alu__DOT__ALUResult = vlSelfRef.alu__DOT__ALU_src2;
        }
        if ((2U != (::IData)(vlSelfRef.alu__DOT__ALUOp))) {
            if ((3U != (::IData)(vlSelfRef.alu__DOT__ALUOp))) {
                if ((4U == (::IData)(vlSelfRef.alu__DOT__ALUOp))) {
                    vlSelfRef.alu__DOT__ALUCarryOut 
                        = (1U & ((((::IData)(vlSelfRef.alu__DOT__ALU_src1) 
                                   + (::IData)(vlSelfRef.alu__DOT__ALU_src2)) 
                                  + (::IData)(vlSelfRef.alu__DOT__Carry)) 
                                 >> 8U));
                } else if ((5U == (::IData)(vlSelfRef.alu__DOT__ALUOp))) {
                    vlSelfRef.alu__DOT__ALUCarryOut 
                        = (1U & ((::IData)(vlSelfRef.alu__DOT__ALU_src1) 
                                 >> 7U));
                }
            }
        }
    }
    vlSelfRef.__VprimaryPorts.ALUResult = vlSelfRef.alu__DOT__ALUResult;
    vlSelfRef.__VprimaryPorts.ALUCarryOut = vlSelfRef.alu__DOT__ALUCarryOut;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.ALUSrc 
                      & 0xfeU)))) {
        Verilated::overWidthError("ALUSrc");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.Carry 
                      & 0xfeU)))) {
        Verilated::overWidthError("Carry");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.ALUOp 
                      & 0xf8U)))) {
        Verilated::overWidthError("ALUOp");
    }
}
#endif  // VL_DEBUG
