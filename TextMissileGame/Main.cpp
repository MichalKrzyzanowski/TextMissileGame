/// <summary>
/// Author: Michal K.
/// Login: C00240696
/// Date: 29/09/19
/// </summary>

#include <iostream>
#include <random>
#include <ctime>
#include <string>


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

	Coordinates coordinates;


	bool armed = false;

	void arm() { (armed ? armed = false : armed = true); };

	void init()
	{
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
	}

};


/// <summary>
/// main game funtion
/// </summary>
/// <returns></returns>
int main()
{
	srand(static_cast<unsigned>(time(nullptr)));

	Enemy enemy;
	enemy.coordinates.x = rand() % 9 + 1;
	enemy.coordinates.y = rand() % 9 + 1;

	Target friendly;
	friendly.coordinates.x = rand() % 9 + 1;
	friendly.coordinates.y = rand() % 9 + 1;

	Missile missile;
	
	int boundaries = 10;
	int nukeRadius = 4;

	bool nukeHit = false;

	// variables used for choices
	int warheadChoice = 0;
	int launchCode = 0;
	int missileArmChoice = 0;

	std::cout << "Choose a warhead Mr. General\n\n";
	std::cout << "1. Explosive(single target) 2. Nuclear(DO NOT USE)\n";
	std::cin >> warheadChoice;
	std::cout << std::string(100, '\n');
	
	

	std::cout << "\n\n\nEnter your targets coordinates sir (Boundaries x:10 y:10)\n";
	std::cout << "x: ";
	std::cin >> missile.coordinates.x;
	std::cout << "\ny: ";
	std::cin >> missile.coordinates.y;
	std::cout << std::string(100, '\n');

	std::cout << "\n\nEnter the launch code ";

	if (warheadChoice == EXPLOSIVE)
	{
		std::cout << "Explosive: 12234\n";
	}

	if (warheadChoice == NUCLEAR)
	{
		std::cout << "Nuclear: 1030747632487654\n";
	}

	std::cin >> launchCode;
	std::cout << std::string(100, '\n');

	if (warheadChoice == EXPLOSIVE && launchCode == 12234)
	{
		std::cout << "\n\nLaunch code entered for Explosive payload\n\n";
	}
	
	if (warheadChoice == NUCLEAR && launchCode == 1030747632487654)
	{
		std::cout << "\n\nLaunch code entered for Nuclear payload\n\n";
	}

	std::cout << "Missile ready, remember your actions will have consequences. Arm Missile?";
	std::cout << "\n1. yes 2. no\n\n";
	std::cin >> missileArmChoice;
	std::cout << std::string(100, '\n');

	if (missileArmChoice == 1)
	{
		missile.arm();
		std::cout << std::string(100, '\n');
	}

	while (missile.armed)
	{
		if (missile.coordinates.x >= boundaries || missile.coordinates.y >= boundaries)
		{
			std::cout << "The warhead has hit nothing!\n";
			std::cout << "Mission Failed! we'll get him next time\n\n\n\n";
			break;
		}

		if (warheadChoice == EXPLOSIVE)
		{
			if (missile.coordinates.x == enemy.coordinates.x && missile.coordinates.y == enemy.coordinates.y)
			{
				std::cout << "The missile has neutralised an enemy!\n";
				std::cout << "Mission complete!\n\n\n\n";
				break;
			}

			if (missile.coordinates.x == friendly.coordinates.x && missile.coordinates.y == friendly.coordinates.y)
			{
				std::cout << "The missile has wiped out a friendly!\n";
				std::cout << "you're no longer wanted on this operation!\n\n\n\n";
				break;
			}
		}

		if (warheadChoice == NUCLEAR)
		{
			if ((missile.coordinates.x >= enemy.coordinates.x - nukeRadius &&
				missile.coordinates.x <= enemy.coordinates.x + nukeRadius) &&
				(missile.coordinates.y >= enemy.coordinates.y - nukeRadius &&
					missile.coordinates.y <= enemy.coordinates.y + nukeRadius))
			{
				std::cout << "The nuke has neutralised an enemy!\n";
				std::cout << "Well Done!\n\n\n\n";
				nukeHit = true;
			}

			if ((missile.coordinates.x >= friendly.coordinates.x - nukeRadius &&
				missile.coordinates.x <= friendly.coordinates.x + nukeRadius) &&
				(missile.coordinates.y >= friendly.coordinates.y - nukeRadius &&
					missile.coordinates.y <= friendly.coordinates.y + nukeRadius))
			{
				std::cout << "The nuke has wiped out a friendly!\n";
				std::cout << "with great power comes great responsibility!\n\n\n\n";
				nukeHit = true;
			}

			if (nukeHit)
			{
				break;
			}
		}

		missile.collisionUpdate(missile);

	}

	return 0;
}


