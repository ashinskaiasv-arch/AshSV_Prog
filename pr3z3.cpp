//Ашинская Светлана Викторовна, РГБО-01-25
//. Написать программу для вычисления и вывода на экран таблицы значений функции

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x_start, x_end, step;
    
    // Ввод диапазона и шага
    cout << "Введите начальное значение x: ";
    cin >> x_start;
    cout << "Введите конечное значение x: ";
    cin >> x_end;
    cout << "Введите шаг: ";
    cin >> step;

    cout << "\nТаблица значений функции F = 5cos(3x) + 6√(x² – 5x + 4)\n";
    cout << "-----------------------------------------\n";
    cout << "|     x     |       F(x)       |\n";
    cout << "-----------------------------------------\n";

    for (double x = x_start; x <= x_end; x += step) {
        double discriminant = x * x - 5 * x + 4; // Выражение под корнем

        if (discriminant < 0) {
            // Если подкоренное выражение отрицательно — функция не определена
            cout << "| " << x << " | функция не определена |\n";
        } else {
            // Вычисляем значение функции
            double cos_part = 5 * cos(3 * x);
            double sqrt_part = 6 * sqrt(discriminant);
            double F = cos_part + sqrt_part;

            cout << "| " << x << " | " << F << " |\n";
        }
    }

    cout << "-----------------------------------------\n";
    return 0;
}
