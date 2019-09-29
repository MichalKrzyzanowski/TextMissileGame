/// <summary>
/// Author: Michal K.
/// Login: C00240696
/// Date: 29/09/19
/// </summary>

#include <iostream>

enum WarHead { EXPLOSIVE = 1, NUCLEAR };

typedef struct Position
{
	int x;
	int y;

	void print()
	{
		std::cout << x << y << "\n";
	}

}Coordinates;

typedef struct Enemy
{
	Coordinates coordinates;

}Target;

struct Missile
{
	WarHead payload;

	Coordinates coordinates;

	Target target;

	bool armed;

	void arm() { (armed ? armed = false : armed = true); };

	void update()
	{
		coordinates.x += 1;
		coordinates.y += 2;
	}

};


/// <summary>
/// main game funtion
/// </summary>
/// <returns></returns>
int main()
{
	Enemy enemy;
	enemy.coordinates.x = 10;
	enemy.coordinates.y = 15;

	Missile missile;
	

	// variables used for choices
	int warheadChoice = 0;

	std::cout << "Choose a warhead Mr. President\n\n";
	std::cout << "1. Explosive 2. Nuclear\n";
	std::cin >> warheadChoice;

	std::cout << "\n\n\nEnter your targets coordinates sir\n";
	std::cout << "x: ";
	std::cin >> missile.coordinates.x;
	std::cout << "\ny: ";
	std::cin >> missile.coordinates.y;

	
	

	return 0;
}