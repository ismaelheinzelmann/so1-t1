//
// Created by ismael on 31/08/23.
//

#include "ProcessContext.h"

ProcessContext::ProcessContext() {
    generalRegisters = std::array<Register, 6>();
    programCounter = Register();
    stackPointer = Register();
    statusRegister = Register();
}

std::array<Register, 6> ProcessContext::getGeneralRegisters() const {
    return generalRegisters;
}

Register ProcessContext::getPC() const {
    return programCounter;
}

Register ProcessContext::getSP() const {
    return stackPointer;
}

Register ProcessContext::getST() const {
    return statusRegister;
}

void ProcessContext::setGeneralRegisters(const std::array<Register, 6>& newGeneralRegisters) {
    generalRegisters = newGeneralRegisters;
}

void ProcessContext::setPC(const Register& newPC) {
    programCounter = newPC;
}

void ProcessContext::setSP(const Register& newSP) {
    stackPointer = newSP;
}

void ProcessContext::setST(const Register& newST) {
    statusRegister = newST;
}

