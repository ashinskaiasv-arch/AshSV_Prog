// Ашинская Светлана Викторовна, РГБО-01-25, В2.
#include <iostream>
#include <cmath>
#include <string>
#include <limits>
using namespace std;

bool UserInput(string input) {
    if (input.empty()) return false;

    try {
        size_t pos;
        stoi(input, &pos);
        return pos == input.length();
    }
    catch (...) {
        return false;
    }
}

void task1() {
    // Задание 1: Проверить, есть ли среди трех чисел хотя бы одна пара равных
    double a, b, c;
    cout << "Введите три числа: ";
    cin >> a >> b >> c;
    
    int result = (a == b) || (b == c) || (a == c) ? 1 : 0;
    cout << (result ? "Есть хотя бы одна пара равных чисел" : "Нет ни одной пары равных чисел") << endl;
}

void task2() {
    // Задание 2: Найти среднее число в двух тройках чисел и их среднее арифметическое
    double a1, b1, c1;  // первая тройка
    double a2, b2, c2;  // вторая тройка
    
    cout << "Введите первую тройку чисел (через пробел): ";
    cin >> a1 >> b1 >> c1;
    
    cout << "Введите вторую тройку чисел (через пробел): ";
    cin >> a2 >> b2 >> c2;
    
    // Находим среднее число в первой тройке
    double min1 = (a1 < b1) ? ((a1 < c1) ? a1 : c1) : ((b1 < c1) ? b1 : c1);
    double max1 = (a1 > b1) ? ((a1 > c1) ? a1 : c1) : ((b1 > c1) ? b1 : c1);
    double middle1 = (a1 != min1 && a1 != max1) ? a1 : ((b1 != min1 && b1 != max1) ? b1 : c1);
    
    // Находим среднее число во второй тройке
    double min2 = (a2 < b2) ? ((a2 < c2) ? a2 : c2) : ((b2 < c2) ? b2 : c2);
    double max2 = (a2 > b2) ? ((a2 > c2) ? a2 : c2) : ((b2 > c2) ? b2 : c2);
    double middle2 = (a2 != min2 && a2 != max2) ? a2 : ((b2 != min2 && b2 != max2) ? b2 : c2);
    
    // Находим среднее арифметическое средних чисел
    double average = (middle1 + middle2) / 2.0;
    
    cout << "Среднее число в первой тройке: " << middle1 << endl;
    cout << "Среднее число во второй тройке: " << middle2 << endl;
    cout << "Среднее арифметическое средних чисел: " << average << endl;
}

void task3() {
    // Задание 3: По номеру месяца вывести название месяца
    int month;
    cout << "Введите номер месяца (1-12): ";
    cin >> month;

    switch (month) { 
        case 1: 
            cout << "Январь" << endl; 
            break; 
        case 2:
            cout << "Февраль" << endl;
            break; 
        case 3: 
            cout << "Март" << endl; 
            break;
        case 4: 
            cout << "Апрель" << endl; 
            break; 
        case 5:
            cout << "Май" << endl;
            break; 
        case 6: 
            cout << "Июнь" << endl; 
            break; 
        case 7: 
            cout << "Июль" << endl; 
            break; 
        case 8:
            cout << "Август" << endl;
            break; 
        case 9: 
            cout << "Сентябрь" << endl; 
            break;
        case 10: 
            cout << "Октябрь" << endl; 
            break; 
        case 11:
            cout << "Ноябрь" << endl;
            break; 
        case 12: 
            cout << "Декабрь" << endl; 
            break; 
        default:
            cout << "Ошибка! Введите корректный номер месяца (1-12)" << endl;
    }
}

void task4() {
    // Задание 4: Правильно просклонять слово "год" в зависимости от возраста
    int n;
    
    cout << "Введите возраст (от 1 до 99): ";
    cin >> n;
    
    // Проверяем корректность ввода
    if (n < 1 || n > 99) {
        cout << "Ошибка: возраст должен быть от 1 до 99" << endl;
        return;
    }
    
    // Определяем последнюю цифру и исключения для 11-14
    int lastDigit = n % 10;
    bool isTeenException = (n % 100 >= 11) && (n % 100 <= 14);
    
    // Выбираем правильное слово с помощью тернарных операторов
    string word = isTeenException ? "лет" :
                  (lastDigit == 1) ? "год" :
                  (lastDigit >= 2 && lastDigit <= 4) ? "года" : "лет";
    
    // Выводим результат
    cout << "Мне " << n << " " << word << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int funcSelect = 0;
    
    for (;;) {
        cout << "\n========================================" << endl;
        cout << "Task 1. Проверить наличие пары равных чисел среди трех" << endl;
        cout << "Task 2. Найти среднее число в двух тройках чисел" << endl;
        cout << "Task 3. Определить название месяца по номеру" << endl;
        cout << "Task 4. Правильно просклонять слово 'год' для возраста" << endl;
        cout << "========================================" << endl;
        cout << "Введите номер нужной функции или 0, чтобы закрыть программу: ";
        cin >> funcSelect;
        
        // Очистка буфера ввода на случай ошибочного ввода
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Неверный ввод. Пожалуйста, введите число." << endl;
            continue;
        }
        
        switch (funcSelect) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;    
            case 0:
                cout << "Программа завершена." << endl;
                return 0;
            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    }
    return 0;
}