#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    system("chcp 1251>nul"); 

    double suma; // сума покупки
    cout << "Введіть суму покупки: ";
    cin >> suma;

    double znyzhka = 0; 

    if (suma > 1000)
        znyzhka = 5;
    else if (suma > 500)
        znyzhka = 3;

    if (znyzhka > 0) {
        cout << "Вам надається знижка в " << znyzhka << "%" << endl;
        double suma_z_znyzhkoiu = suma - (suma * znyzhka / 100);
        cout << fixed << setprecision(2); // два знаки після коми
        cout << "Сума з урахуванням знижки: " << suma_z_znyzhkoiu << " грн." << endl;
    } else {
        cout << "Знижка не надається." << endl;
        cout << "Сума до сплати: " << fixed << setprecision(2) << suma << " грн." << endl;
    }

    return 0;
}
