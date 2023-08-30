//
// Created by ismael on 30/08/23.
//

#ifndef PROCESSCONTEXT_H
#define PROCESSCONTEXT_H
#include <array>
#include "Register.h"

namespace components {

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

} // namespace components

#endif //PROCESSCONTEXT_H
