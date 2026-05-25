//Ашинская С.В. РГБО-01-25, Вариант №2

#include <iostream>
#include <cmath>  
#include <string> 
#include <map>     

using namespace std;


// Функции проверки ввода

bool isValidInput(string input) {
    if (input.empty()) return false;
    for (char c : input) {
        if (c < '0' || c > '9') return false;
    }
    return true;
}

int EnterNumber(string label) {
    string input;
    int value;
    while (true) {
        cout << label;
        cin >> input;
        if (isValidInput(input)) {
            value = stoi(input);
            return value;
        } else {
            cout << "Ошибка: введите число" << endl;
        }
    }
}


// ЗАДАНИЕ 1
void problem1() {
    cout << "\n=== ЗАДАНИЕ 1 ===\n";
    cout << "Сумма и количество отрицательных элементов каждой строки\n";
    
    const int rows = 4;
    const int cols = 5;
    
    int matrix[rows][cols] = {
        {3, -5, 2, -1, 7},
        {-2, 4, -3, 6, -8},
        {1, -4, -2, 5, 9},
        {-7, -1, 3, -2, -6}
    };
    
    cout << "\nМатрица:\n";
    for (auto &row : matrix) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
    
    cout << "\nРезультаты (строка | сумма | количество):\n";
    int rowIndex = 0;
    for (auto &row : matrix) {
        int sumNeg = 0;
        int countNeg = 0;
        for (int val : row) {
            if (val < 0) {
                sumNeg += val;
                countNeg++;
            }
        }
        cout << "Строка " << rowIndex << "\t| " << sumNeg << "\t| " << countNeg << endl;
        rowIndex++;
    }
}


// ЗАДАНИЕ 2

void problem2() {
    cout << "\n=== ЗАДАНИЕ 2 ===\n";
    cout << "Поиск строки с максимальным средним арифметическим\n";
    
    int n, m;
    cout << "Введите количество строк n: ";
    cin >> n;
    cout << "Введите количество столбцов m: ";
    cin >> m;
    
    double matrix[100][100];
    
    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; i++) {
        cout << "Строка " << i << ": ";
        for (int j = 0; j < m; j++) {
            double* p = &matrix[i][j];
            cin >> *p;
        }
    }
    
    cout << "\nВведенная матрица:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << *(*(matrix + i) + j) << "\t";
        }
        cout << endl;
    }
    
    int bestRow = 0;
    double maxAverage = -1e9;
    int i = 0;
    
    while (i < n) {
        double sum = 0;
        int j = 0;
        while (j < m) {
            sum += *(*(matrix + i) + j);
            j++;
        }
        double average = sum / m;
        cout << "Строка " << i << ", среднее = " << average << endl;
        
        if (average > maxAverage) {
            maxAverage = average;
            bestRow = i;
        }
        i++;
    }
    
    cout << "\nСтрока с максимальным средним: " << bestRow << endl;
    cout << "Значение среднего: " << maxAverage << endl;
}


// ЗАДАНИЕ 3

bool checkRookMove(int x1, int y1, int x2, int y2, int board[8][8]) {
    if (x1 == x2) {
        int step = (y2 > y1) ? 1 : -1;
        for (int y = y1 + step; y != y2; y += step) {
            if (board[x1][y] != 0) return false;
        }
        return true;
    }
    else if (y1 == y2) {
        int step = (x2 > x1) ? 1 : -1;
        for (int x = x1 + step; x != x2; x += step) {
            if (board[x][y1] != 0) return false;
        }
        return true;
    }
    return false;
}

bool checkBishopMove(int x1, int y1, int x2, int y2, int board[8][8]) {
    if (abs(x2 - x1) == abs(y2 - y1)) {
        int stepX = (x2 > x1) ? 1 : -1;
        int stepY = (y2 > y1) ? 1 : -1;
        int x = x1 + stepX;
        int y = y1 + stepY;
        while (x != x2) {
            if (board[x][y] != 0) return false;
            x += stepX;
            y += stepY;
        }
        return true;
    }
    return false;
}

void problem3() {
    cout << "\n=== ЗАДАНИЕ 3 ===\n";
    cout << "Шахматный матч: проверка допустимости хода фигуры\n";
    
    int board[8][8];
    
    cout << "\nЗаполните шахматную доску (8x8):\n";
    cout << "0 - пусто, 1 - белая фигура, 2 - черная фигура\n";
    for (int i = 0; i < 8; i++) {
        cout << "Строка " << i << " (8 чисел через пробел): ";
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }
    
    cout << "\nШахматная доска:\n";
    cout << "  0 1 2 3 4 5 6 7\n";
    for (int i = 0; i < 8; i++) {
        cout << i << " ";
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    
    int x1, y1, x2, y2;
    int figureType;
    
    cout << "\nВведите координаты начальной позиции (строка столбец): ";
    cin >> x1 >> y1;
    cout << "Введите координаты конечной позиции (строка столбец): ";
    cin >> x2 >> y2;
    cout << "Выберите фигуру (1-ладья, 2-слон): ";
    cin >> figureType;
    
    if (x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 || x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7) {
        cout << "Ошибка: координаты должны быть от 0 до 7\n";
        return;
    }
    
    if (board[x1][y1] == 0) {
        cout << "Ошибка: в начальной позиции нет фигуры\n";
        return;
    }
    
    bool valid = false;
    if (figureType == 1) {
        valid = checkRookMove(x1, y1, x2, y2, board);
        cout << "Ход ладьи " << (valid ? "допустим" : "недопустим") << endl;
    }
    else if (figureType == 2) {
        valid = checkBishopMove(x1, y1, x2, y2, board);
        cout << "Ход слона " << (valid ? "допустим" : "недопустим") << endl;
    }
    else {
        cout << "Ошибка: неизвестный тип фигуры (1 или 2)\n";
    }
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
        {3, {"Problem 3", problem3}}
    };
    
    int choice = 0;
    
    while (true) {
        cout << "\nМеню:" << endl;
        
        for (const auto& item : menu) {
            cout << "Task " << item.first << ". " << item.second.title << endl;
        }
        
        cout << "0. Выход" << endl;
        
        choice = EnterNumber("Введите номер пункта: ");
        
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