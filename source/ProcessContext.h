//
// Created by ismael on 31/08/23.
//

#ifndef SO1_T1_PROCESSCONTEXT_H
#define SO1_T1_PROCESSCONTEXT_H
#include <array>
#include "Register.h"

class ProcessContext {
public:
    ProcessContext();

    std::array<Register, 6> getGeneralRegisters() const;
    Register getPC() const;
    Register getSP() const;
    Register getST() const;

    void setGeneralRegisters(const std::array<Register, 6>& newGeneralRegisters);
    void setPC(const Register& newPC);
    void setSP(const Register& newSP);
    void setST(const Register& newST);
private:
    std::array<Register, 6> generalRegisters;
    Register programCounter;
    Register stackPointer;
    Register statusRegister;
};


#endif //SO1_T1_PROCESSCONTEXT_H
