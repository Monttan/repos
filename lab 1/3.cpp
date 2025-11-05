#include <iostream>
using namespace std;
 
int main()
{
    cout << "Enter the number of the month (number from 1 to 12): ";
    int mounth;
    cin >> mounth; 
        
    while (mounth > 12 || mounth <= 0)                                          // Спочатку перевіряємо на правильність введення місяця
        {   
            cout << "Oops, that input is invalid. Please try again.\n";         // Виконуємо введеня поки не буде відповідати умові
            cout << "Enter the number of the month (number from 1 to 12): ";
            cin >> mounth;
            cin.clear();                                                        // Повертаємо cin в 'звичайний' режим роботи
            cin.ignore(32767,'\n');
        }
         
    if (mounth == 12 || mounth == 1 || mounth == 2)                             // Виводимо пору року відповідно до місяця
             cout << "Your season is winter.\n";
    if (mounth >= 3 && mounth <= 5)
             cout << "Your season is spring.\n";
    if (mounth >= 6 && mounth <= 8)
             cout << "Your season is summer.\n";
    if (mounth >= 9 && mounth <= 11)
             cout << "Your season is autumn.\n";
    
    return 0;
}