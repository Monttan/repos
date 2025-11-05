// 1 завдання
 	#include <iostream>
 	#include <locale>
 	using namespace std;
 	
 	double calculation(int distance, int price, double consumption) {
 	return ((consumption / 100) * distance * price) * 2;
 	}
 	
 	int main(){
 	setlocale(LC_CTYPE, "ukr");
 	int distance, price;
 	double consumption;
 	
 	cout << "Відстань до дачі (км): ";
 	cin >> distance;
 	cout << "Витрати бензину (літрів на 100 км пробігу): ";
 	cin >> consumption;
 	cout << "Ціна літра бензину (грн.): ";
 	cin >> price;
 	cout << "Поїздка на дачу і назад обійдеться в " << calculation(distance, price, consumption) << " грн";
 	
 	return 0;
 	}