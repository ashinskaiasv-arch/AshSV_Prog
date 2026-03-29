//Ашинская Светлана Викторовна, РГБО-01-25\
// Составить программу, которая в зависимости от порядкового номера дня месяца 
//(1, 2, …, 12) выводит на экран его название (январь, февраль, …, декабрь).
              
#include<iostream>
using namespace std; 

int main() {
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
            cout << "Декабрь" << endl;
            break; 
        case 12: 
            cout << "Март" << endl; 
            break; 
        
        default: // Если ни один кейс не сработал 
            cout << "Введите корректный номер месяца(1-12)" << endl; }
            return 0;
}