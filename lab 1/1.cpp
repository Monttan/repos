#include <iostream>
#include <string>
 
using namespace std;
 
bool isIcecreamSandwich(const string &sandwich)					// (Не парність масиву не є перешкодою для даної функції)
{
	int lenght = sandwich.length();
	if ((lenght < 3) || (sandwich[0] == sandwich[lenght / 2]))			// Перевірка довжини сендвічу та наявність начинки
	{															
		return false;
	}
 
	int index = 0;
 
	while (index < lenght / 2)									// Перевірка симетричності половинок сендвічу 
	{
		if (sandwich[index] == sandwich[(lenght - 1) - index] && 
			sandwich[(lenght - 1) - index] == sandwich[0])			// Шар покриву повинен складатися тільки з
		{													// першого символу
			++index;
			continue;
		}
		else if(sandwich[index] == sandwich[lenght / 2] && 
			sandwich[(lenght - 1) - index] == sandwich[lenght / 2])	// Попередження перевірки шару начинки
		{
			break;
		}
		else													// Межа половинок з "начинкою" та "покриттям" 
		{													// сендвіча не симетрична (та/або неоднорідна)
			return false;
		}
	}
 
	while (index < lenght / 2)									// Перевірка начинки
	{
		if (sandwich[index] == sandwich[lenght / 2] && 
			sandwich[(lenght - 1) - index] == sandwich[lenght / 2])	// Шар "начинки" повинен складатися тільки з
		{													// символу з центру сендвіча
			++index;
			continue;
		}
		else
		{
			return false;
		}
	}
	
	return true;
}		
 
 
void testIsIcecreamSandwich() {
	std::cout << (isIcecreamSandwich("CDC") == true) << "\n";
	std::cout << (isIcecreamSandwich("hhhhhhhhmhhhhhhhh") == true) << "\n";
 
	std::cout << (isIcecreamSandwich("yyyyymmmmmmmmyyyyy") == true) << "\n";
	std::cout << (isIcecreamSandwich("3&&3") == true) << "\n";
 
	std::cout << (isIcecreamSandwich("AABBBAA") == true) << "\n";
 
 
	std::cout << (isIcecreamSandwich("A") == false) << "\n";
	std::cout << (isIcecreamSandwich("AA") == false) << "\n";
	std::cout << (isIcecreamSandwich("BBBBB") == false) << "\n";
 
	std::cout << (isIcecreamSandwich("AAABB") == false) << "\n";
	std::cout << (isIcecreamSandwich("AAACCCAA") == false) << "\n";
	std::cout << (isIcecreamSandwich("AACCCAAA") == false) << "\n";
 
	std::cout << (isIcecreamSandwich("AACDCAA") == false) << "\n";
	std::cout << (isIcecreamSandwich("AACDCDCAA") == false) << "\n";
	std::cout << (isIcecreamSandwich("AAKACDDDCKAAA") == false) << "\n";
 
 
	std::cout << (isIcecreamSandwich("AAABAABBBAABAAA") == false) << "\n";
}
 
int main()
{	
	//testIsIcecreamSandwich();
	string sandwich;
	cin >> sandwich;
 
	cout << isIcecreamSandwich(sandwich);
}