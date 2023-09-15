//
// Created by ismael on 29/08/23.
//
#include <array>
#include "../headers/Register.h"

Register::Register() {
    content = std::array<unsigned char, 8>();
}

std::array<unsigned char, 8> Register::getContent() const {
    return content;
}

std::array<unsigned char, 8> content;

void Register::setContent(const std::array<unsigned char, 8> &newContent) {
    content = newContent;
}
