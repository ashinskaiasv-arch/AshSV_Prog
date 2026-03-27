//Ашинская Светлана Викторовна, РГБО-01-25
//Задание 5. Написать программу, которая запрашивает у пользователя номер дня недели и 
//выводит соответствующее название. В случае, если пользователь укажет недопустимое 
//число, программа должна вывести сообщение «Ошибка ввода данных». Для решения 
//задания используется оператор switch-case. 

#include <iostream>
using namespace std;
int main() {
    int day_of_the_week; 
    cin >>  day_of_the_week; 
    switch(day_of_the_week) {
        case 1: 
            cout << "Понедельник" << endl;
            break;
        case 2:
            cout << "Вторник" << endl;
            break;
        case 3:
            cout << "Среда" << endl;
            break;
        case 4: 
            cout << "Четверг" << endl;
            break;
        case 5:
            cout << "Пятница" << endl;
            break;
        case 6:
            cout << "Суббота" << endl;
            break;
        case 7: 
            cout << "Воскресенье" << endl;
            break;
        default:
            cout << "Ошибка ввода данных" << endl;
    }
    return 0;
}