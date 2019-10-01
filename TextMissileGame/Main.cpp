/// <summary>
/// Author: Michal K.
/// Login: C00240696
/// Date: 29/09/19
/// </summary>

#include <iostream>
#include <random>
#include <ctime>
#include <string>

// warhead types
enum WarHead { EXPLOSIVE = 1, NUCLEAR };

/// <summary>
/// struct of coordinates
/// </summary>
typedef struct Position
{
	int x;
	int y;

	void print()
	{
		std::cout << x << y << "\n";
	}

}Coordinates;

/// <summary>
/// enemy struct
/// </summary>
typedef struct Enemy
{
	Coordinates coordinates;

}Target;


/// <summary>
/// struct of missile and all of its values
/// </summary>
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

	// move missile
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
	srand(static_cast<unsigned>(time(nullptr)));

	// enemy coords
	Enemy enemy;
	enemy.coordinates.x = rand() % 9 + 1;
	enemy.coordinates.y = rand() % 9 + 1;

	// friendly coords
	Target friendly;
	friendly.coordinates.x = rand() % 9 + 1;
	friendly.coordinates.y = rand() % 9 + 1;

	Missile missile;
	
	missile.init();

	int boundaries = 10;
	int nukeRadius = 4;

	bool nukeHit = false;

	// variables used for choices
	int warheadChoice = 0;
	int launchCode = 0;
	int missileArmChoice = 0;

	// warhead choice
	while (true)
	{
		std::cout << std::string(100, '\n');
		std::cout << "Choose a warhead Mr. General\n\n";
		std::cout << "1. Explosive(single target) 2. Nuclear(DO NOT USE)\n";
		std::cin >> warheadChoice;
		std::cout << std::string(100, '\n');

		if (warheadChoice == EXPLOSIVE || warheadChoice == NUCLEAR)
		{
			break;
		}
	}
	
	// target coords entry
	while (true)
	{
		std::cout << "\n\n\nEnter your targets coordinates sir (Boundaries x:10 y:10)\n";
		std::cout << "x: ";
		std::cin >> missile.coordinates.x;
		std::cout << "\ny: ";
		std::cin >> missile.coordinates.y;
		std::cout << std::string(100, '\n');

		if ((missile.coordinates.x <= boundaries && missile.coordinates.x >= 1) &&
			(missile.coordinates.y <= boundaries && missile.coordinates.y >= 1))
		{
			break;
		}
	}

	// launch code entry
	while (true)
	{
		std::cout << "\n\nEnter the launch code ";

		if (warheadChoice == EXPLOSIVE)
		{
			std::cout << "Explosive: 12234\n";
		}

		if (warheadChoice == NUCLEAR)
		{
			std::cout << "Nuclear: 1030754\n";
		}

		std::cin >> launchCode;
		std::cout << std::string(100, '\n');

		// if explosive warhead has been chosen and right code entered
		if (warheadChoice == EXPLOSIVE && launchCode == 12234)
		{
			std::cout << "\n\nLaunch code entered for Explosive payload\n\n";
			break;
		}

		// if nuclear warhead has been chosen and right code entered
		if (warheadChoice == NUCLEAR && launchCode == 1030754)
		{
			std::cout << "\n\nLaunch code entered for Nuclear payload\n\n";
			break;
		}
	}

	// ariming missile
	while (true)
	{
		std::cout << "Missile ready, remember your actions will have consequences. Arm Missile?";
		std::cout << "\n1. yes 2. no\n\n";
		std::cin >> missileArmChoice;
		std::cout << std::string(100, '\n');

		if (missileArmChoice == 1)
		{
			missile.arm();
			std::cout << std::string(100, '\n');
			break;
		}

		else
		{
			std::cout << std::string(100, '\n');
			std::cout << "Opereration has Been Cancelled!\n\n\n";
			break;
		}
	}

	// collision loop
	while (missile.armed)
	{
		if (missile.coordinates.x >= boundaries || missile.coordinates.y >= boundaries)
		{
			std::cout << "The warhead has hit nothing!\n";
			std::cout << "Mission Failed! we'll get him next time\n\n\n\n";
			break;
		}

		// if explosive warhead has been chosen
		if (warheadChoice == EXPLOSIVE)
		{
			// checking collision
			if (missile.coordinates.x == enemy.coordinates.x && missile.coordinates.y == enemy.coordinates.y)
			{
				std::cout << "The missile has neutralised an enemy!\n";
				std::cout << "Mission complete!\n\n\n\n";
				break;
			}

			// checking collision
			if (missile.coordinates.x == friendly.coordinates.x && missile.coordinates.y == friendly.coordinates.y)
			{
				std::cout << "The missile has wiped out a friendly!\n";
				std::cout << "you're no longer wanted on this operation!\n\n\n\n";
				break;
			}
		}

		// if nuclear warhead has been chosen
		if (warheadChoice == NUCLEAR)
		{
			// checking collision in a radius of 4
			if ((missile.coordinates.x >= enemy.coordinates.x - nukeRadius &&
				missile.coordinates.x <= enemy.coordinates.x + nukeRadius) &&
				(missile.coordinates.y >= enemy.coordinates.y - nukeRadius &&
					missile.coordinates.y <= enemy.coordinates.y + nukeRadius))
			{
				std::cout << "The nuke has neutralised an enemy!\n";
				std::cout << "Well Done!\n\n\n\n";
				nukeHit = true;
			}

			// checking collision in a radius of 4
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

		missile.update();

	}

	return 0;
}


