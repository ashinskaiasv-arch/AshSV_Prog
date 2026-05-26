//Ашинская Светлана Викторовна, РГБО-01-25\
// main_project.cpp

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <math.h>
#include "check_functions.h"
#include "main_functions.h"

// ПРОТОТИПЫ ФУНКЦИЙ (только тех, которых нет в main_functions.h)
void process(std::string &str, int wordNum, std::string &result);
void process(char *str, int wordNum);

void problem1(){
    std::string s = EnterString("\nВведите исходную строку\n");
    int wordNum = EnterInt("Введите номер слова для поиска: ", 1, 100);
    
    std::string foundWord;
    process(s, wordNum, foundWord);
    
    std::cout << "\nИсходная строка (string): " << s << std::endl;
    if (foundWord.empty()) {
        std::cout << "Слово с номером " << wordNum << " не найдено" << std::endl;
    } else {
        std::cout << "Слово с номером " << wordNum << ": " << foundWord << std::endl;
    }
    
    char str[500];
    std::cout << "\nВведите исходную строку (char*): ";
    std::cin.getline(str, 500);
    while (strlen(str) == 0) {
        std::cout << "Введите исходную строку (char*): ";
        std::cin.getline(str, 500);
    }
    
    int delWordNum = EnterInt("Введите номер слова для удаления: ", 1, 100);
    char str_copy[500];
    strcpy(str_copy, str);
    
    process(str, delWordNum);
    
    std::cout << "\nИсходная строка (char*): " << str_copy << std::endl;
    std::cout << "После удаления слова: " << str << std::endl;
}

void problem2(){
    std::string s1 = EnterString("\nВведите 1-ю исходную строку\n");
    int wordNum = EnterInt("Введите номер слова для поиска: ", 1, 100);
    
    std::string foundWord;
    namespace_string1::process(s1, wordNum, foundWord);
    
    std::cout << "\nИсходная строка (StringOps1): " << s1 << std::endl;
    if (foundWord.empty()) {
        std::cout << "Слово с номером " << wordNum << " не найдено" << std::endl;
    } else {
        std::cout << "Слово с номером " << wordNum << ": " << foundWord << std::endl;
    }
    
    std::string s2 = EnterString("\nВведите 2-ю исходную строку\n");
    int delWordNum = EnterInt("Введите номер слова для удаления: ", 1, 100);
    std::string original = s2;
    
    namespace_string2::process(s2, delWordNum);
    
    std::cout << "\nИсходная строка (StringOps2): " << original << std::endl;
    std::cout << "После удаления слова: " << s2 << std::endl;
}

void problem3(){
    srand(time(0));
    int number = EnterInt("Введите размер массива: ", 1, 1000);
    
    int* intArr = new int[number];
    std::cout << "\nМассив int: ";
    for (int i = 0; i < number; i++) {
        intArr[i] = rand() % 101 - 50;
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;
    
    int minPosInt = findMinPositive(intArr, number);
    if (minPosInt != 0) {
        std::cout << "Минимальный положительный элемент (int): " << minPosInt << std::endl;
    } else {
        std::cout << "Положительных элементов в массиве int нет" << std::endl;
    }
    
    double* doubleArr = new double[number];
    std::cout << "\nМассив double: ";
    for (int i = 0; i < number; i++) {
        doubleArr[i] = -50.0 + (double)rand() / RAND_MAX * 100.0;
        std::cout << doubleArr[i] << " ";
    }
    std::cout << std::endl;
    
    double minPosDouble = findMinPositive(doubleArr, number);
    if (minPosDouble > 1e-10) {
        std::cout << "Минимальный положительный элемент (double): " << minPosDouble << std::endl;
    } else {
        std::cout << "Положительных элементов в массиве double нет" << std::endl;
    }
    
    delete[] intArr;
    delete[] doubleArr;
}

void problem4(){
    int n = EnterInt("Введите номер числа Фибоначчи: ", 0, 40);
    int result = fibonacci(n);
    std::cout << "F(" << n << ") = " << result << std::endl;
}

void problem5(){
    srand(time(0));
    int length = EnterInt("Введите размер массива: ", 1, 1000);
    
    int* arr = new int[length];
    std::cout << "\nИсходный массив: ";
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 101 - 50;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    int positiveCount;
    countPositiveNumbers(arr, length, positiveCount);
    
    std::cout << "Количество положительных элементов: " << positiveCount << std::endl;
    
    delete[] arr;
}

struct MenuItem {
    std::string title;
    void (*action)();
};

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    
    std::map<int, MenuItem> menu = {
        {1, {"Problem 1", problem1}},
        {2, {"Problem 2", problem2}},
        {3, {"Problem 3", problem3}},
        {4, {"Problem 4", problem4}},
        {5, {"Problem 5", problem5}},
    };
    
    int choice = 0;
    
    while (true) {
        std::cout << "\nМеню:\n";
        
        for (const auto& item : menu) {
            std::cout << "Task " << item.first << ". "
                      << item.second.title << std::endl;
        }
        
        std::cout << "0. Выход\n";
        
        choice = EnterInt("Введите номер пункта: ", 0, 5);
        
        if (choice == 0) {
            std::cout << "@ 2026 FIO\n";
            break;
        }
        
        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            std::cout << "Некорректный ввод.";
        }
    }
    
    return 0;
}