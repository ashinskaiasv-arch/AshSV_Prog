
// Ашинская С.В., РГБО-01-25, Вариант №2

#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

// Функция проверки корректности ввода числа
bool UserInput(string input) {
    if (input.empty()) return false;
    for (char c : input) {
        if (c < '0' || c > '9') return false;
    }
    return true;
}

// Функция ввода числа с повторением запроса до корректного ввода
int EnterNumber(string label) {
    string raw_input;
    int number;
    while (true) {
        cout << label;
        getline(cin, raw_input);
        if (UserInput(raw_input)) {
            number = stoi(raw_input);
            return number;
        }
        cout << "Ошибка: введите целое число.\n";
    }
}

// Функция проверки корректности ввода непустой строки типа string
bool UserInputStr(string input) {
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
    return !input.empty();
}

// Функция ввода строки с повторением запроса до корректного ввода (для string)
string EnterString(string label) {
    string raw_input;
    cout << label;
    getline(cin, raw_input);

    while (!UserInputStr(raw_input)) {
        cout << "Ошибка: строка не может быть пустой или состоять только из пробелов.\n";
        cout << label;
        getline(cin, raw_input);
    }
    return raw_input;
}

// Функция проверки корректности ввода непустой строки типа char[]
bool UserInputArrChar(const char str[]) {
    const char *p = str;
    while (*p != '\0') {
        if (*p != ' ') return true;
        p++;
    }
    return false;
}

// Функция ввода строки с повторением запроса до корректного ввода (для char[])
void EnterArrChar(const char label[], char output[], size_t size) {
    cout << label;
    cin.getline(output, size);

    while (!UserInputArrChar(output)) {
        cout << "Ошибка: строка не может быть пустой или состоять только из пробелов.\n";
        cout << label;
        cin.getline(output, size);
    }
}

// ЗАДАНИЕ 1
// Вводится строка произвольного текста, затем вводится произвольный символ.
// Найти все вхождения этого символа в строку (вывести индексы элементов строки,
// которые являются этим символом). Если данного символа нет в строке, вывести -1.
// Структура: символьный массив (C-строка)
// Механизм: работа с указателями (без использования стандартных функций)
void problem1() {
    cout << "\n=== ЗАДАНИЕ 1 ===\n";
    cout << "Найти все вхождения заданного символа в строку.\n\n";

    char str[256];
    char ch;

    EnterArrChar("Введите строку: ", str, 256);

    cout << "Введите символ для поиска: ";
    cin.get(ch);
    cin.ignore();

    // Работа с указателями
    char* ptr = str;
    int index = 0;
    bool found = false;

    cout << "Индексы вхождения символа '" << ch << "': ";
    while (*ptr != '\0') {
        if (*ptr == ch) {
            cout << index << " ";
            found = true;
        }
        ptr++;
        index++;
    }

    if (!found) {
        cout << "-1";
    }
    cout << endl;
}

// ЗАДАНИЕ 2
// Вводится строка символов. Удвоить все пробелы. Вывести преобразованную строку.
// Структура: class string
// Механизм: посимвольный перебор (без использования функций, кроме size())

void problem2() {
    cout << "\n=== ЗАДАНИЕ 2 ===\n";
    cout << "Удвоить все пробелы в строке.\n\n";

    string s = EnterString("Введите строку: ");

    string result;
    for (size_t i = 0; i < s.size(); i++) {
        result += s[i];
        if (s[i] == ' ') {
            result += ' ';
        }
    }

    cout << "Результат: " << result << endl;
}

// ЗАДАНИЕ 3
// С клавиатуры вводится строка символов, представляющая из себя произвольное
// арифметическое выражение. Проверить баланс открывающихся и закрывающихся
// скобок. Вывести каких скобок больше, если баланс не соблюден.
// Предусмотреть вариант, когда скобки в выражении отсутствуют.
// Структура: символьный массив (C-строка)
// Механизм: посимвольный перебор (без использования функций, кроме strlen)

void problem3() {
    cout << "\n=== ЗАДАНИЕ 3 ===\n";
    cout << "Проверить баланс скобок в арифметическом выражении.\n\n";

    char expr[256];
    EnterArrChar("Введите арифметическое выражение: ", expr, 256);

    int roundOpen = 0, roundClose = 0;   // ()
    int squareOpen = 0, squareClose = 0; // []
    int curlyOpen = 0, curlyClose = 0;   // {}

    for (int i = 0; expr[i] != '\0'; i++) {
        switch (expr[i]) {
            case '(': roundOpen++; break;
            case ')': roundClose++; break;
            case '[': squareOpen++; break;
            case ']': squareClose++; break;
            case '{': curlyOpen++; break;
            case '}': curlyClose++; break;
        }
    }

    int totalOpen = roundOpen + squareOpen + curlyOpen;
    int totalClose = roundClose + squareClose + curlyClose;

    if (totalOpen == 0 && totalClose == 0) {
        cout << "Скобки в выражении отсутствуют.\n";
    }
    else if (roundOpen == roundClose && squareOpen == squareClose && curlyOpen == curlyClose) {
        cout << "Баланс скобок соблюдён.\n";
    }
    else {
        cout << "Баланс скобок НЕ соблюдён.\n";

        if (roundOpen > roundClose)
            cout << "Круглых открывающих скобок больше на " << roundOpen - roundClose << endl;
        else if (roundClose > roundOpen)
            cout << "Круглых закрывающих скобок больше на " << roundClose - roundOpen << endl;

        if (squareOpen > squareClose)
            cout << "Квадратных открывающих скобок больше на " << squareOpen - squareClose << endl;
        else if (squareClose > squareOpen)
            cout << "Квадратных закрывающих скобок больше на " << squareClose - squareOpen << endl;

        if (curlyOpen > curlyClose)
            cout << "Фигурных открывающих скобок больше на " << curlyOpen - curlyClose << endl;
        else if (curlyClose > curlyOpen)
            cout << "Фигурных закрывающих скобок больше на " << curlyClose - curlyOpen << endl;
    }
}

// ЗАДАНИЕ 4
// Вводится строка символов, которые разделены на слова. Пробелы являются
// разделителями между словами, причём слова могут разделяться более чем одним
// пробелом, в начале и конце строки пробелы также допускаются.
// Вывести на экран самое короткое слово. Если таких слов несколько, вывести одно.
// Структура: class string
// Механизм: обязательное использование функций класса string
void problem4() {
    cout << "\n=== ЗАДАНИЕ 4 ===\n";
    cout << "Найти самое короткое слово в строке.\n\n";

    string s = EnterString("Введите строку со словами: ");

    string shortest;
    bool firstWord = true;
    size_t pos = 0;
    size_t len = s.length();

    while (pos < len) {
        while (pos < len && s[pos] == ' ') pos++;
        if (pos >= len) break;

        size_t start = pos;
        while (pos < len && s[pos] != ' ') pos++;

        string word = s.substr(start, pos - start);

        if (firstWord || word.length() < shortest.length()) {
            shortest = word;
            firstWord = false;
        }
    }

    if (firstWord) {
        cout << "В строке нет слов.\n";
    } else {
        cout << "Самое короткое слово: \"" << shortest << "\" (длина: " << shortest.length() << ")\n";
    }
}

// ЗАДАНИЕ 5
// Вводится строка символов, которые разделены на слова. Пробелы являются
// разделителями между словами, причём слова могут разделяться более чем одним
// пробелом, в начале и конце строки пробелы также допускаются.
// Удалить слово с заданным номером, сохраняя пробелы до и после слова.
// Номер слова вводится. Если такого номера нет, оставить строку без изменения.
// Структура: символьный массив (C-строка)
// Механизм: обязательное использование функций библиотеки cstring
void problem5() {
    cout << "\n=== ЗАДАНИЕ 5 ===\n";
    cout << "Удалить слово с заданным номером (сохраняя пробелы).\n\n";

    char str[512];
    EnterArrChar("Введите строку со словами: ", str, 512);

    int wordNum = EnterNumber("Введите номер слова для удаления: ");

    // Считаем количество слов
    char temp[512];
    strcpy(temp, str);
    int wordCount = 0;
    char* token = strtok(temp, " ");
    while (token != nullptr) {
        wordCount++;
        token = strtok(nullptr, " ");
    }

    if (wordNum < 1 || wordNum > wordCount) {
        cout << "Слова с номером " << wordNum << " не существует. Строка не изменена.\n";
        cout << "Результат: " << str << endl;
        return;
    }

    // Формируем результат, пропуская нужное слово
    char result[1024] = "";
    int currentWord = 1;
    int i = 0;
    int resIdx = 0;
    bool inWord = false;

    while (str[i] != '\0') {
        if (str[i] != ' ') {
            if (!inWord) {
                inWord = true;
                if (currentWord == wordNum) {
                    // Пропускаем всё слово
                    while (str[i] != '\0' && str[i] != ' ') i++;
                    currentWord++;
                    inWord = false;
                    continue;
                } else {
                    currentWord++;
                }
            }
            result[resIdx++] = str[i];
        } else {
            result[resIdx++] = str[i];
            inWord = false;
        }
        i++;
    }
    result[resIdx] = '\0';

    cout << "Результат: " << result << endl;
}

// ЗАДАНИЕ 6
// Вводится строка символов, которые разделены на слова. Пробелы являются
// разделителями между словами. Во втором слове, если оно есть, поменять местами
// первый символ с последним. Вывести преобразованную строку.
// Структура: class string
// Механизм: работа со строкой как с коллекцией с использованием функций класса string
void problem6() {
    cout << "\n=== ЗАДАНИЕ 6 ===\n";
    cout << "Во втором слове поменять местами первый и последний символы.\n\n";

    string s = EnterString("Введите строку со словами: ");

    // Находим второе слово
    size_t wordCount = 0;
    size_t pos = 0;
    size_t wordStart = 0, wordEnd = 0;
    bool foundSecond = false;

    while (pos < s.length() && !foundSecond) {
        while (pos < s.length() && s[pos] == ' ') pos++;
        if (pos >= s.length()) break;

        wordCount++;
        wordStart = pos;

        while (pos < s.length() && s[pos] != ' ') pos++;
        wordEnd = pos;

        if (wordCount == 2) {
            foundSecond = true;
        }
    }

    if (!foundSecond) {
        cout << "В строке нет второго слова. Строка не изменена.\n";
        cout << "Результат: " << s << endl;
        return;
    }

    // Меняем местами первый и последний символы второго слова
    string result = s;
    if (wordEnd - wordStart > 1) {
        swap(result[wordStart], result[wordEnd - 1]);
    }

    cout << "Результат: " << result << endl;
}

struct MenuItem {
    string title;
    void (*action)();
};

int main() {
    setlocale(LC_ALL, "Russian");

    map<int, MenuItem> menu = {
        {1, {"Problem 1", problem1}},
        {2, {"Problem 2", problem2}},
        {3, {"Problem 3", problem3}},
        {4, {"Problem 4", problem4}},
        {5, {"Problem 5", problem5}},
        {6, {"Problem 6", problem6}},
    };

    int choice = 0;

    while (true) {
        cout << "\n========================================\n";
        cout << "ПРАКТИЧЕСКАЯ РАБОТА №6 - ВАРИАНТ №2\n";
        cout << "========================================\n";

        for (const auto& item : menu) {
            cout << "Task " << item.first << ". " << item.second.title << endl;
        }
        cout << "0. Exit\n";
        cout << "----------------------------------------\n";

        choice = EnterNumber("Enter number: ");

        if (choice == 0) {
            cout << "\n(c) 2026 [Your Surname]\n";
            break;
        }

        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            cout << "Invalid input." << endl;
        }

        cout << "\nPress Enter to continue...";
        cin.get();
    }

    return 0;
}