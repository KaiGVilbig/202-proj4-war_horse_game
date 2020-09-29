#include "Untrained.h"
#include "Warhorse.h"
#include "War.h"

Untrained::Untrained()
{
	string name;

	cout << "\nWhat would you like to name the horse?\n";
	cin >> name;

	int sizeVal = rand() % 3 + 0;
	int health, speed;
	
	switch (sizeVal)
	{
	case 0:
		health = rand() % LT_MAX_HEALTH + LT_MIN_HEALTH;
		speed = rand() % LT_MAX_SPEED + LT_MIN_SPEED;
		break;
	case 1:
		health = rand() % MD_MAX_HEALTH + MD_MIN_HEALTH;
		speed = rand() % MD_MAX_SPEED + MD_MIN_SPEED;
		break;
	case 2:
		health = rand() % HV_MAX_HEALTH + HV_MIN_HEALTH;

		speed = rand() % HV_MAX_SPEED + HV_MIN_SPEED;
		break;
	}

	setName(name);
	setHealth(health);
	setSpeed(speed);
}

Untrained::Untrained(string name, Size size, int health, int speed):Horse(name, size, health, speed)
{

}

Horse* Untrained::specialize()
{
	Horse *newHorse;

	//speciallize
	if (getSize() == SMALL)
	{
		newHorse = new Light(getName(), getSize(), getHealth(), getSpeed());
	}
	else if (getSize() == MEDIUM)
	{
		newHorse = new Medium(getName(), getSize(), getHealth(), getSpeed());
	}
	else
	{
		newHorse = new Heavy(getName(), getSize(), getHealth(), getSpeed());
	}
	return newHorse;
}

bool Untrained::train()
{
	//can't train a non-speciallized horse
	return false;
}

string Untrained::toString()
{
	return "Unknown";
}

int Untrained::attack(string name, int health)
{
	cout << "You can not attack with an untrained horse\n";
	return 0;
}