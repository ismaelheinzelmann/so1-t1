//
// Created by ismael on 29/08/23.
//

#include <array>
#include "Register.cpp"
using namespace std;
namespace components{
    class ProcessContext{
    public:
        ProcessContext(){
            generalRegisters = std::array<Register, 6>();
            programCounter = Register();
            stackPointer = Register();
            statusRegister = Register();
        };

        std::array<Register, 6> getGeneralRegisters(){
            return generalRegisters;
        }

        Register getPC(){
            return programCounter;
        }

        Register getSP(){
            return stackPointer;
        }

        Register getST(){
            return statusRegister;
        }

        void setGeneralRegisters(std::array<Register, 6> newGeneralRegisters){
            generalRegisters = newGeneralRegisters;
        }

        void setPC(Register newPC){
            programCounter = newPC;
        }

        void setSP(Register newSP){
            stackPointer = newSP;
        }

        void setST(Register newST){
            statusRegister = newST;
        }

    private:
        std::array<Register, 6> generalRegisters;
        Register programCounter;
        Register stackPointer;
        Register statusRegister;
    };
}