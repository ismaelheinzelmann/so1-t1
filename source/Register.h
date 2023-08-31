//
// Created by ismael on 30/08/23.
//

#ifndef REGISTER_H
#define REGISTER_H

#include <array>

class Register {
public:
    Register();

    std::array<unsigned char, 8> getContent() const;

    void setContent(const std::array<unsigned char, 8> &newContent);

private:
    std::array<unsigned char, 8> content;
};


#endif //REGISTER_H
