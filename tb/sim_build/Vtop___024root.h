// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:

    // TOP LEVEL PORTS
    union {
        struct {
            VL_IN8(ALUSrc,0,0);
            VL_IN8(Carry,0,0);
            VL_IN8(ALUOp,2,0);
            VL_IN8(ALU_src1,7,0);
            VL_IN8(ALU_src2,7,0);
            VL_OUT8(ALUCarryOut,0,0);
            VL_OUT8(ALUResult,7,0);
        } __VprimaryPorts;
    };

    // TRIVIALLY CONSTRUCTIBLE STATE
    ::CData/*0:0*/ alu__DOT__ALUSrc;
    ::CData/*0:0*/ alu__DOT__Carry;
    ::CData/*2:0*/ alu__DOT__ALUOp;
    ::CData/*7:0*/ alu__DOT__ALU_src1;
    ::CData/*7:0*/ alu__DOT__ALU_src2;
    ::CData/*0:0*/ alu__DOT__ALUCarryOut;
    ::CData/*7:0*/ alu__DOT__ALUResult;
    ::VlUnpacked<::QData/*63:0*/, 1> __VstlTriggered;
    ::VlUnpacked<::QData/*63:0*/, 1> __VicoTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static const ::IData/*31:0*/ alu__DOT__DATA_WIDTH;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);
    VL_UNMOVABLE(Vtop___024root);

    // INTERNAL METHODS
};


#endif  // guard
