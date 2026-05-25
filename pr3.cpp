//Ашинская С.В., РГБО-01-25, Вариант №2

#include <iostream>
#include <cmath>
using namespace std;

// Задание 1. Минимальное из 10 чисел (цикл while)
void MinOfTenNumbers()
{
    int i = 1;
    double num, minVal;
    
    cout << "Введите число 1: ";
    cin >> minVal;
    
    while (i < 10)
    {
        i++;
        cout << "Введите число " << i << ": ";
        cin >> num;
        if (num < minVal)
            minVal = num;
    }
    
    cout << "Минимальное число: " << minVal << endl;
}

// Задание 2. Числа Фибоначчи (цикл for)
void FibonacciSequence()
{
    int n;
    cout << "Введите количество чисел Фибоначчи: ";
    cin >> n;
    
    if (n <= 0)
    {
        cout << "Ошибка ввода" << endl;
        return;
    }
    
    int a = 1, b = 1;
    
    if (n >= 1)
        cout << a << " ";
    if (n >= 2)
        cout << b << " ";
    
    for (int i = 3; i <= n; i++)
    {
        int next = a + b;
        cout << next << " ";
        a = b;
        b = next;
    }
    cout << endl;
}

// Задание 3. Таблица функции F = 5*cos(3x) + 6*sqrt(x^2 - 5x + 4)
void FunctionTable()
{
    double start, end, step;
    cout << "Введите начало диапазона x: ";
    cin >> start;
    cout << "Введите конец диапазона x: ";
    cin >> end;
    cout << "Введите шаг: ";
    cin >> step;
    
    double x = start;
    while (x <= end + 0.0000001)
    {
        double podKornem = x * x - 5 * x + 4;
        
        if (podKornem < 0)
        {
            cout << "x = " << x << " : функция не определена" << endl;
        }
        else
        {
            double F = 5 * cos(3 * x) + 6 * sqrt(podKornem);
            cout << "x = " << x << " : F = " << F << endl;
        }
        
        x = x + step;
    }
}

// Задание 4. Произведение (cos1+...+cos i)/(sin1+...+sin i)
void ProductOfCosSin()
{
    int n;
    cout << "Введите n: ";
    cin >> n;
    
    double proizvedenie = 1.0;
    double sumCos = 0.0;
    double sumSin = 0.0;
    
    for (int i = 1; i <= n; i++)
    {
        sumCos = sumCos + cos(i);
        sumSin = sumSin + sin(i);
        
        if (sumSin == 0)
        {
            cout << "Ошибка: деление на ноль" << endl;
            return;
        }
        
        proizvedenie = proizvedenie * (sumCos / sumSin);
    }
    
    cout << "Результат: " << proizvedenie << endl;
}

// Задание 5. Сумма делителей каждого числа от 50 до 70
void SumOfDivisors()
{
    for (int chislo = 50; chislo <= 70; chislo++)
    {
        int sumDel = 0;
        
        for (int d = 1; d <= chislo; d++)
        {
            if (chislo % d == 0)
                sumDel = sumDel + d;
        }
        
        cout << "Число " << chislo << " : сумма делителей = " << sumDel << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int funcSelect = 0;
    
    for (;;)
    {
        cout << "\n1. Минимальное из 10 чисел\n";
        cout << "2. Числа Фибоначчи\n";
        cout << "3. Таблица значений функции\n";
        cout << "4. Произведение сумм cos и sin\n";
        cout << "5. Сумма делителей чисел от 50 до 70\n";
        cout << "Выберите задание (0 для выхода): \n";
        cin >> funcSelect;
        
        switch (funcSelect) {
        case 1:
            MinOfTenNumbers();
            break;
        case 2:
            FibonacciSequence();
            break;
        case 3:
            FunctionTable();
            break;
        case 4:
            ProductOfCosSin();
            break;
        case 5:
            SumOfDivisors();
            break;
        case 0:
            return 0;
        default:
            cout << "Неверный выбор" << endl;
        }
    }
}