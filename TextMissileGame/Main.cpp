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

	bool armed = false;

	void arm() { (armed ? armed = false : armed = true); };

	void init()
	{
		payload = EXPLOSIVE;
		coordinates.x = 0;
		coordinates.y = 0;
	}

	void update()
	{
		coordinates.x += 1;
		coordinates.y += 2;
	}

	void collisionUpdate(Missile& t_missile)
	{
		t_missile.update();
		std::cout << t_missile.coordinates.x << " " << t_missile.coordinates.y << "\n";
	}

};


/// <summary>
/// main game funtion
/// </summary>
/// <returns></returns>
int main()
{
	Enemy enemy;
	enemy.coordinates.x = 4;
	enemy.coordinates.y = 5;

	Missile missile;
	
	int boundaries = 10;

	// variables used for choices
	int warheadChoice = 0;
	int launchCode = 0;
	int missileArmChoice = 0;

	std::cout << "Choose a warhead Mr. President\n\n";
	std::cout << "1. Explosive 2. Nuclear\n";
	std::cin >> warheadChoice;

	std::cout << "\n\n\nEnter your targets coordinates sir (Boundaries x:10 y:10)\n";
	std::cout << "x: ";
	std::cin >> missile.coordinates.x;
	std::cout << "\ny: ";
	std::cin >> missile.coordinates.y;

	std::cout << "\n\nEnter the launch code ";

	if (warheadChoice == EXPLOSIVE)
	{
		std::cout << "Explosive: 12234";
	}

	if (warheadChoice == NUCLEAR)
	{
		std::cout << "Nuclear: 103074";
	}

	std::cin >> launchCode;

	if (warheadChoice == EXPLOSIVE && launchCode == 12234)
	{
		std::cout << "\n\n Launch code entered for Explosive payload";
	}
	
	if (warheadChoice == NUCLEAR && launchCode == 103074)
	{
		std::cout << "\n\n Launch code entered for Nuclear payload";
	}

	std::cout << "Missile ready, remember your actions will have consequences. Arm Missile?";
	std::cout << "\n1. yes 2. no\n\n";
	std::cin >> missileArmChoice;

	if (missileArmChoice == 1)
	{
		missile.arm();
	}

	while (missile.armed)
	{
		missile.collisionUpdate(missile);

		if (missile.coordinates.x >= boundaries || missile.coordinates.y >= boundaries)
		{
			missile.arm();
		}
	}

	return 0;
}


