// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"

extern const VlVarTableEntry Vtop___024root__VpiVarTable0[];
extern const VlVarTableEntry Vtop___024root__VpiVarTable1[];
extern const VlVarTableEntry Vtop___024root__VpiVarTable2[];
extern const void* const Vtop___024root__VpiParamPtrs0[];
extern const VlScopeTableEntry Vtop__Syms__VpiScopeTable[];
extern const VlHierTableEntry Vtop__Syms__VpiHierTable[];


// VPI VARIABLE/SCOPE TABLES
#if defined(__GNUC__)
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Winvalid-offsetof"
#endif
static const int32_t Vtop__Syms__VpiVarDims[] = {
    2, 0,
    7, 0,
    31, 0,
};
extern const VlVarTableEntry Vtop___024root__VpiVarTable0[] = {
    {"ALUCarryOut", offsetof(Vtop___024root, __VprimaryPorts.ALUCarryOut), nullptr, (VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY), VLVT_UINT8, 0, 0},
    {"ALUOp", offsetof(Vtop___024root, __VprimaryPorts.ALUOp), &Vtop__Syms__VpiVarDims[0], (VLVD_IN|VLVF_PUB_RW), VLVT_UINT8, 0, 1},
    {"ALUResult", offsetof(Vtop___024root, __VprimaryPorts.ALUResult), &Vtop__Syms__VpiVarDims[2], (VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY), VLVT_UINT8, 0, 1},
    {"ALUSrc", offsetof(Vtop___024root, __VprimaryPorts.ALUSrc), nullptr, (VLVD_IN|VLVF_PUB_RW), VLVT_UINT8, 0, 0},
    {"ALU_src1", offsetof(Vtop___024root, __VprimaryPorts.ALU_src1), &Vtop__Syms__VpiVarDims[2], (VLVD_IN|VLVF_PUB_RW), VLVT_UINT8, 0, 1},
    {"ALU_src2", offsetof(Vtop___024root, __VprimaryPorts.ALU_src2), &Vtop__Syms__VpiVarDims[2], (VLVD_IN|VLVF_PUB_RW), VLVT_UINT8, 0, 1},
    {"Carry", offsetof(Vtop___024root, __VprimaryPorts.Carry), nullptr, (VLVD_IN|VLVF_PUB_RW), VLVT_UINT8, 0, 0},
};
extern const VlVarTableEntry Vtop___024root__VpiVarTable1[] = {
    {"ALUCarryOut", offsetof(Vtop___024root, alu__DOT__ALUCarryOut), nullptr, (VLVD_NODIR|VLVF_PUB_RW), VLVT_UINT8, 0, 0},
    {"ALUOp", offsetof(Vtop___024root, alu__DOT__ALUOp), &Vtop__Syms__VpiVarDims[0], (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY), VLVT_UINT8, 0, 1},
    {"ALUResult", offsetof(Vtop___024root, alu__DOT__ALUResult), &Vtop__Syms__VpiVarDims[2], (VLVD_NODIR|VLVF_PUB_RW), VLVT_UINT8, 0, 1},
    {"ALUSrc", offsetof(Vtop___024root, alu__DOT__ALUSrc), nullptr, (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY), VLVT_UINT8, 0, 0},
    {"ALU_src1", offsetof(Vtop___024root, alu__DOT__ALU_src1), &Vtop__Syms__VpiVarDims[2], (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY), VLVT_UINT8, 0, 1},
    {"ALU_src2", offsetof(Vtop___024root, alu__DOT__ALU_src2), &Vtop__Syms__VpiVarDims[2], (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY), VLVT_UINT8, 0, 1},
    {"Carry", offsetof(Vtop___024root, alu__DOT__Carry), nullptr, (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY), VLVT_UINT8, 0, 0},
};
extern const VlVarTableEntry Vtop___024root__VpiVarTable2[] = {
    {"DATA_WIDTH", 0, &Vtop__Syms__VpiVarDims[4], (VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED|VLVF_BITVAR), VLVT_UINT32, 0, 1},
};
extern const void* const Vtop___024root__VpiParamPtrs0[] = {
    &Vtop___024root::alu__DOT__DATA_WIDTH,
};
extern const VlScopeTableEntry Vtop__Syms__VpiScopeTable[] = {
    {offsetof(Vtop__Syms, __Vscopep_TOP), "TOP", "TOP", "<null>", 0, 0, VerilatedScope::SCOPE_OTHER},
    {offsetof(Vtop__Syms, __Vscopep_alu), "", "alu", "alu", 1, -9, VerilatedScope::SCOPE_MODULE},
};
extern const VlHierTableEntry Vtop__Syms__VpiHierTable[] = {
    {0, offsetof(Vtop__Syms, __Vscopep_alu)},
};
#if defined(__GNUC__)
# pragma GCC diagnostic pop
#endif

void Vtop__Syms__ctor(Vtop__Syms* vlSymsp, const char* namep) {
    // Setup top module instance
    VL_INPLACE_CONSTRUCT(vlSymsp->vlInst.TOP, vlSymsp, namep);
    // Check resources
    Verilated::stackCheck(18);
    // Setup names of the model and of its top module instances
    vlSymsp->__Vm_topNames[0] = vlSymsp->name();
    vlSymsp->__Vm_topNames[1] = vlSymsp->__Vm_isRoot ? Verilated::catName(vlSymsp->name(), "alu") : vlSymsp->name();
    // Setup sub module instances
    // Configure time unit / time precision
    vlSymsp->_vm_contextp__->timeunit(-9);
    vlSymsp->_vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup scopes
    VerilatedScope::scopesConstructFromTable(Vtop__Syms__VpiScopeTable, 2, vlSymsp, vlSymsp->__Vm_topNames);
    // Set up scope hierarchy
    vlSymsp->__Vhier.addFromTable(Vtop__Syms__VpiHierTable, 1, vlSymsp);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    vlSymsp->__Vscopep_TOP->varsInsertFromTable(Vtop___024root__VpiVarTable0, 7, &(vlSymsp->vlInst.TOP));
    vlSymsp->__Vscopep_alu->varsInsertFromTable(Vtop___024root__VpiVarTable1, 7, &(vlSymsp->vlInst.TOP));
    vlSymsp->__Vscopep_alu->paramsInsertFromTable(Vtop___024root__VpiVarTable2, 1, Vtop___024root__VpiParamPtrs0);
}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, Vtop* modelp, const char* namep, bool isRoot)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    , __Vm_isRoot{isRoot}
    , __Vm_didInit{modelp->m_didInit}
{
    Vtop__Syms__ctor(this, namep);
}

void Vtop__Syms__dtor(Vtop__Syms* vlSymsp) {
    // Tear down scope hierarchy
    vlSymsp->__Vhier.removeFromTable(Vtop__Syms__VpiHierTable, 1, vlSymsp);
    // Clear keys from hierarchy map after values have been removed
    vlSymsp->__Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete vlSymsp->__Vscopep_TOP, vlSymsp->__Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete vlSymsp->__Vscopep_alu, vlSymsp->__Vscopep_alu = nullptr);
    // Tear down sub module instances
    // Tear down top module instance
    VL_INPLACE_DESTRUCT(vlSymsp->vlInst.TOP);
}

Vtop__Syms::~Vtop__Syms() {
    Vtop__Syms__dtor(this);
}
