//Ашинская Светлана Викторовена, РГБО-01-25
// main_functions.h

#include <iostream>
#include <string>
#include <cstring>

// ФУНКЦИЯ 1 (string &) - Возвращает слово с заданным номером
void process(std::string &str, int wordNum, std::string &result) {
    if (str.empty()) {
        result = "";
        return;
    }
    
    std::string temp = str;
    std::string words[100];
    int wordCount = 0;
    
    temp += ' ';
    std::string currentWord = "";
    
    for (size_t i = 0; i < temp.length(); i++) {
        if (temp[i] != ' ') {
            currentWord += temp[i];
        } else if (!currentWord.empty()) {
            words[wordCount++] = currentWord;
            currentWord = "";
        }
    }
    
    if (wordNum >= 1 && wordNum <= wordCount) {
        result = words[wordNum - 1];
    } else {
        result = "";
    }
}

// ФУНКЦИЯ 2 (char *) - Удаляет слово с заданным номером
void process(char *str, int wordNum) {
    if (str == nullptr || strlen(str) == 0) return;
    
    std::string words[100];
    int wordCount = 0;
    
    std::string temp(str);
    temp += ' ';
    std::string currentWord = "";
    
    for (size_t i = 0; i < temp.length(); i++) {
        if (temp[i] != ' ') {
            currentWord += temp[i];
        } else if (!currentWord.empty()) {
            words[wordCount++] = currentWord;
            currentWord = "";
        }
    }
    
    if (wordNum < 1 || wordNum > wordCount) {
        return;
    }
    
    std::string result = "";
    for (int i = 0; i < wordCount; i++) {
        if (i != wordNum - 1) {
            if (!result.empty()) result += " ";
            result += words[i];
        }
    }
    
    strcpy(str, result.c_str());
}

// ПРОСТРАНСТВО ИМЕН 1
namespace namespace_string1
{
    // Возвращает слово с заданным номером
    void process(std::string &str, int wordNum, std::string &result) {
        if (str.empty()) {
            result = "";
            return;
        }
        
        std::string temp = str;
        std::string words[100];
        int wordCount = 0;
        
        temp += ' ';
        std::string currentWord = "";
        
        for (size_t i = 0; i < temp.length(); i++) {
            if (temp[i] != ' ') {
                currentWord += temp[i];
            } else if (!currentWord.empty()) {
                words[wordCount++] = currentWord;
                currentWord = "";
            }
        }
        
        if (wordNum >= 1 && wordNum <= wordCount) {
            result = words[wordNum - 1];
        } else {
            result = "";
        }
    }
}

// ПРОСТРАНСТВО ИМЕН 2
namespace namespace_string2
{
    // Удаляет слово с заданным номером
    void process(std::string &str, int wordNum) {
        if (str.empty()) return;
        
        std::string words[100];
        int wordCount = 0;
        
        std::string temp = str + ' ';
        std::string currentWord = "";
        
        for (size_t i = 0; i < temp.length(); i++) {
            if (temp[i] != ' ') {
                currentWord += temp[i];
            } else if (!currentWord.empty()) {
                words[wordCount++] = currentWord;
                currentWord = "";
            }
        }
        
        if (wordNum < 1 || wordNum > wordCount) {
            return;
        }
        
        std::string result = "";
        for (int i = 0; i < wordCount; i++) {
            if (i != wordNum - 1) {
                if (!result.empty()) result += " ";
                result += words[i];
            }
        }
        
        str = result;
    }
}

// Рекурсивная функция для вычисления n-го числа Фибоначчи
int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Шаблонная функция для поиска минимального положительного элемента
template <typename T>
T findMinPositive(T* arr, int size) {
    T minPositive = 0;
    bool found = false;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            if (!found || arr[i] < minPositive) {
                minPositive = arr[i];
                found = true;
            }
        }
    }
    
    return found ? minPositive : 0;
}

// Функция для подсчета положительных чисел с лямбдой
void countPositiveNumbers(int* arr, int size, int& result) {
    auto count_divisors = [](int x) {
        return x > 0;
    };
    
    result = 0;
    for (int i = 0; i < size; i++) {
        if (count_divisors(arr[i])) {
            result++;
        }
    }
}