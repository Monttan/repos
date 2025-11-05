// 3 завдання
 
#include <iostream>
#include <string>
#include <array>
#include <algorithm>
 
#include <cstdlib> // для функцій rand() і srand()
#include <ctime> // для функції time()
 
int getRandomNumber( int min, int max )
{
	static const double fraction = 1.0 / ( static_cast< double >( RAND_MAX ) + 1.0 );
	// Рівномірно розподіляємо рандомне число в нашому діапазоні
	return static_cast< int >( rand() * fraction * ( max - min + 1 ) + min );
}
 
int getUserNumber()
{
	int result = 0;
 
	while ( true )
	{
		std::cout << "Enter number from 0 up to 999\n";
		if ( std::cin >> result && result > -1 && result < 1000 )
		{
			break;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore( 32767, '\n' );
		}
	}
 
	std::cin.ignore( 32767, '\n' );
 
	return result;
}
 
std::array<int, 3> getNumberArray( int aNumber )
{
	std::array<int, 3> result;
 
	for ( int counter = 0; counter < 3; ++counter )
	{
		result[ counter ] = aNumber % 10;
		aNumber /= 10;
	}
 
	return std::move( result );
}
 
bool processUserNumber( int aNumberNeeded, int aUserNumber )
{
	bool isGuessed = false;
	int guessedNumbers = 0;
	int numbersOnEqualPlaces = 0;
	std::array<int, 3> neededNumberArray = getNumberArray( aNumberNeeded );
	std::array<int, 3> userNumberArray = getNumberArray( aUserNumber );
 
	for ( int counter = 0; counter < 3; ++counter )
	{
		int userNumberPart = userNumberArray[ counter ];
 
		auto it = std::find( neededNumberArray.begin(), neededNumberArray.end(), userNumberPart );
 
		if (  it != neededNumberArray.end() )
		{
			++guessedNumbers;
 
			if ( neededNumberArray[ counter ] == userNumberPart )
			{
				++numbersOnEqualPlaces;
			}
		}
	}
 
	std::cout << "You have guessed: " << guessedNumbers << ". Numbers on equal places: " << numbersOnEqualPlaces << ".\n";
 
	isGuessed = guessedNumbers == 3 && numbersOnEqualPlaces == 3;
 
	return isGuessed;
}
 
 
int main()
{
	srand( static_cast< unsigned int >( time( 0 ) ) );
 
	bool numberIsGuessed = false;
	int numberNeeded = getRandomNumber( 0, 999 );
 
	std::cout << "The number needed: " << numberNeeded << "\n"; // для зручності
 
	while ( !numberIsGuessed )
	{
		int userNumber = getUserNumber();
		numberIsGuessed = processUserNumber( numberNeeded, userNumber );
	}
 
	std::cout << "You have guessed the number!!!" << std::endl;
 
	return 0;
}