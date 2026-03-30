#include <iostream>
#include <cmath>
#include <string>  // Добавлено для std::string
using namespace std;

void task1() {
    double a, b, c;
    cout << "Введите три числа: ";
    cin >> a >> b >> c;
    
    int result = (a == b) || (b == c) || (a == c) ? 1 : 0;
    cout << (result ? "Есть хотя бы одна пара равных чисел" : "Нет ни одной пары равных чисел") << endl;
}

void task2() {
    double a1, b1, c1;
    double a2, b2, c2;
    
    cout << "Введите первую тройку чисел (через пробел): ";
    cin >> a1 >> b1 >> c1;
    
    cout << "Введите вторую тройку чисел (через пробел): ";
    cin >> a2 >> b2 >> c2;
    
    double min1 = (a1 < b1) ? ((a1 < c1) ? a1 : c1) : ((b1 < c1) ? b1 : c1);
    double max1 = (a1 > b1) ? ((a1 > c1) ? a1 : c1) : ((b1 > c1) ? b1 : c1);
    double middle1 = (a1 != min1 && a1 != max1) ? a1 : ((b1 != min1 && b1 != max1) ? b1 : c1);
    
    double min2 = (a2 < b2) ? ((a2 < c2) ? a2 : c2) : ((b2 < c2) ? b2 : c2);
    double max2 = (a2 > b2) ? ((a2 > c2) ? a2 : c2) : ((b2 > c2) ? b2 : c2);
    double middle2 = (a2 != min2 && a2 != max2) ? a2 : ((b2 != min2 && b2 != max2) ? b2 : c2);
    
    double average = (middle1 + middle2) / 2.0;
    
    cout << "Среднее число в первой тройке: " << middle1 << endl;
    cout << "Среднее число во второй тройке: " << middle2 << endl;
    cout << "Среднее арифметическое средних чисел: " << average << endl;
}

void task3() {
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
            cout << "Ноябрь" << endl;  // Исправлено: было "Декабрь"
            break; 
        case 12: 
            cout << "Декабрь" << endl;  // Исправлено: было "Март"
            break; 
        default:
            cout << "Введите корректный номер месяца(1-12)" << endl;
    }
}

void task4() {
    int n;
    
    cout << "Введите возраст (от 1 до 99): ";
    cin >> n;
    
    if (n < 1 || n > 99) {
        cout << "Ошибка: возраст должен быть от 1 до 99" << endl;
        return;
    }
    
    int lastDigit = n % 10;
    bool isTeenException = (n % 100 >= 11) && (n % 100 <= 14);
    
    string word = isTeenException ? "лет" :
                  (lastDigit == 1) ? "год" :
                  (lastDigit >= 2 && lastDigit <= 4) ? "года" : "лет";
    
    cout << "мне " << n << " " << word << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int funcSelect = 0;
    for (;;) {
        cout << "\nTask 1. Сравнение чисел\n";
        cout << "Task 2. Сравнение чисел тройки\n";
        cout << "Task 3. Определение месяца\n";
        cout << "Task 4. Фраза n лет\n";
        cout << "Please enter the number of the desired function or 0 if you want to close the app: \n";
        cin >> funcSelect;

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