//Ашинская Светлана Викторовна, РГБО-01-25
// check_functions.h

#include <iostream>
#include <string>
#include <cstring>
#include <limits>

// Функция проверки корректности ввода числа
bool UserInputInt(std::string input, int MinValue, int MaxValue){
    if (input.empty()) return false;
    
    size_t start = (input[0] == '-') ? 1 : 0;
    for (size_t i = start; i < input.length(); i++) {
        if (!isdigit(input[i])) return false;
    }
    
    try {
        int value = std::stoi(input);
        return (value >= MinValue && value <= MaxValue);
    } catch (...) {
        return false;
    }
}

// Функция ввода числа с повторением запроса до корректного ввода
int EnterInt(std::string label, int MinValue = std::numeric_limits<int>::min(),
    int MaxValue = std::numeric_limits<int>::max()) {
    std::string raw_input;
    std::cout << std::endl << label;
    std::getline(std::cin, raw_input);
    while (!UserInputInt(raw_input, MinValue, MaxValue)) {
        std::cout << label;
        std::getline(std::cin, raw_input);
    }
    
    return stoi(raw_input);
}

// Функция проверки корректности ввода непустой строки типа string
bool UserInputStr(std::string input) {
    return !input.empty();
}

// Функция ввода строки с повторением запроса до корректного ввода
std::string EnterString(std::string label) {
    std::string raw_input;
    std::cout << std::endl << label;
    std::getline(std::cin, raw_input);
    while (!UserInputStr(raw_input)) {
        std::cout << label;
        std::getline(std::cin, raw_input);
    }
    return raw_input;
}

// Функция проверки корректности ввода непустой строки типа char[]
bool UserInputArrChar(const char str[]) {
    return str != nullptr && strlen(str) > 0;
}

// Функция ввода строки с повторением запроса до корректного ввода
void EnterArrChar(const char label[], char output[], size_t size) {
    std::cout << std::endl << label;
    std::cin.getline(output, size);
    while (strlen(output) == 0) {
        std::cout << label;
        std::cin.getline(output, size);
    }
}