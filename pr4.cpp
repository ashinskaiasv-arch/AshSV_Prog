//Ашинская С.В., РГБО-01-25, Вариант №2

#include <iostream>
#include <map>
#include <string>
#include <ctime>

using namespace std;

// ==================== ЗАДАНИЕ 1 ====================
void task1() {
    cout << "\n=== ЗАДАНИЕ 1 ===\n";
    
    int number;
    cout << "Введите шестизначное число: ";
    cin >> number;
    
    if (number < 100000 || number > 999999) {
        cout << "Ошибка: число должно быть шестизначным!\n";
        return;
    }
    
    int digits[6];
    int temp = number;
    for (int i = 5; i >= 0; i--) {
        digits[i] = temp % 10;
        temp /= 10;
    }
    
    cout << "Массив цифр: ";
    for (int digit : digits) {
        cout << digit << " ";
    }
    cout << endl;
}

// ==================== ЗАДАНИЕ 2 ====================
void task2() {
    cout << "\n=== ЗАДАНИЕ 2 ===\n";
    
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Ошибка: размер массива должен быть положительным!\n";
        return;
    }
    
    int* A = new int[n];
    
    cout << "Введите " << n << " элементов массива:\n";
    for (int i = 0; i < n; i++) {
        cout << "A[" << i << "] = ";
        cin >> A[i];
    }
    
    int maxLen = 0;
    int currentLen = 0;
    
    for (int i = 0; i < n; i++) {
        if (A[i] == 0) {
            currentLen++;
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        } else {
            currentLen = 0;
        }
    }
    
    cout << "\nИсходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    
    cout << "Длина самой длинной последовательности нулей: " << maxLen << endl;
    
    delete[] A;
}

// ==================== ЗАДАНИЕ 3 ====================
void task3() {
    cout << "\n=== ЗАДАНИЕ 3 ===\n";
    
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Ошибка: размер массива должен быть положительным!\n";
        return;
    }
    
    int* D = new int[n];
    
    cout << "Введите " << n << " элементов массива:\n";
    int* ptr = D;
    int i = 0;
    while (i < n) {
        cout << "D[" << i << "] = ";
        cin >> *(ptr + i);
        i++;
    }
    
    cout << "\nИсходный массив: ";
    ptr = D;
    i = 0;
    while (i < n) {
        cout << *(ptr + i) << " ";
        i++;
    }
    cout << endl;
    
    int k, direction;
    cout << "\nВведите количество позиций для сдвига: ";
    cin >> k;
    cout << "Направление (1 - влево, 2 - вправо): ";
    cin >> direction;
    
    if (direction != 1 && direction != 2) {
        cout << "Ошибка: направление должно быть 1 или 2!\n";
        delete[] D;
        return;
    }
    
    k = k % n;
    if (k == 0) {
        cout << "\nМассив не изменился\n";
        delete[] D;
        return;
    }
    
    int* temp = new int[n];
    ptr = D;
    
    if (direction == 1) {
        i = 0;
        while (i < n) {
            *(temp + i) = *(ptr + (i + k) % n);
            i++;
        }
    } else {
        i = 0;
        while (i < n) {
            *(temp + i) = *(ptr + (i - k + n) % n);
            i++;
        }
    }
    
    i = 0;
    while (i < n) {
        *(ptr + i) = *(temp + i);
        i++;
    }
    
    cout << "\nМассив после сдвига: ";
    ptr = D;
    i = 0;
    while (i < n) {
        cout << *(ptr + i) << " ";
        i++;
    }
    cout << endl;
    
    delete[] D;
    delete[] temp;
}

// ==================== ГЛАВНОЕ МЕНЮ  ====================
int main() {
    struct MenuItem {
        string title;
        void (*action)();
    };
    
    map<int, MenuItem> menu = {
        {1, {"Problem 1", task1}},
        {2, {"Problem 2", task2}},
        {3, {"Problem 3", task3}}
    };
    
    int choice = 0;
    
    while (true) {
        cout << "\nМеню:" << endl;
        
        for (const auto& item : menu) {
            cout << "Task " << item.first << ". " << item.second.title << endl;
        }
        cout << "0. Выход" << endl;
        
        cout << "Введите номер пункта: ";
        cin >> choice;
        
        if (choice == 0) {
            cout << "@ 2026 Ашинская С.В." << endl;
            break;
        }
        
        cout << endl;
        
        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            cout << "Некорректный ввод.";
        }
        
        cout << endl;
    }
    
    return 0;
}