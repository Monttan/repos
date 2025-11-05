#include <iostream>
using namespace std;

int chusla();

int main() {	
    system("chcp 1251>nul");
    chusla();
    return 0;
}

int chusla() {
    int a, b, c, d;

    cout << "Введіть число a: ";
    cin >> a;
    cout << "Введіть число b: ";
    cin >> b;
    cout << "Введіть число c: ";
    cin >> c;
    cout << "Введіть число d: ";
    cin >> d;

    if (a < 0 || b < 0 || c < 0 || d < 0) {
        cout << "Ви ввели від’ємні числа. Будь ласка, введіть ще раз.\n\n";
        return chusla(); // рекурсивний повтор
    } else {
        int min = a;
        if (b < min) min = b;
        if (c < min) min = c;
        if (d < min) min = d;

        cout << "Найменше число: " << min << endl;
    }

    return 0;
}
