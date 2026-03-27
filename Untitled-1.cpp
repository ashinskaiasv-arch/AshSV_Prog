//Ашинская Светлана Викторовна РГБО-01-25
//Задание 1. Вычислить расстояние между двумя точками с координатами (х1, у1) и (х2, у2).Координаты точек вводятся с клавиатуры. 
#include <iostream>
#include <cmath>
using namespace std; 
int main() {
    double x1, y1, x2, y2;
    
    cin >> x1 >> y1 >> x2 >> y2;  // Все 4 числа вводятся через пробел
    
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    
    cout << "Расстояние = " << distance << std::endl;
    
    return 0; }