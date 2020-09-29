#include "Medium.h"

Medium::Medium()
{

}

Medium::Medium(string name, Size size, int health, int speed):Warhorse(name, size, health, speed)
{

}

int Medium::attack(string name, int health)
{
	int damage = health / 6 + getTraining();
	cout << "The medium warhorse " << getName() << " hits " << name << endl;
	return damage;
}

string Medium::toString()
{
	return "Medium";
}