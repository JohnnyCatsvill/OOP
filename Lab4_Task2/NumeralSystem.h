#pragma once

#include <string>

std::string dec2hex(uint32_t i);
uint32_t hex2dec(std::string i);

bool isNumber(std::string& number);
bool isHexNumber(std::string& number);