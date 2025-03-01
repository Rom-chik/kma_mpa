#pragma once //developed by Roman Antoshchuk on 06.02.2024
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
using std::cout;
using std::endl;
int toRPN();
int fromRPN();
int calcRPN();

inline bool is_operand(const char& c) {
    return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'z'));
}
inline bool is_operator(const char& c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}