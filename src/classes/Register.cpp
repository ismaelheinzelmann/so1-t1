//
// Created by ismael on 29/08/23.
//
#include <array>
namespace components{
    class Register {
    public:
        Register() {
            content = std::array<unsigned char, 8>();
        }

        std::array<unsigned char, 8> getContent() {
            return content;
        }

        void setContent(std::array<unsigned char, 8> newContent) {
            content = newContent;
        }

    private:
        std::array<unsigned char, 8> content;
    };
}
