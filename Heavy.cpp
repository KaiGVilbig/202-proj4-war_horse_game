#include "Heavy.h"

Heavy::Heavy()
{

}

Heavy::Heavy(string name, Size size, int health, int speed) :Warhorse(name, size, health, speed)
{

}

int Heavy::attack(string name, int health)
{
	int damage = health / 6 + getTraining();
	int damageMult;
	damageMult = kick();
	cout << "The heavy warhorse " << getName() << " hits " << name << endl;
	cout << "The heavy warhorse spins and kicks the enemy\n";
	return damage + damageMult;
}

string Heavy::toString()
{
	return "Heavy";
}

int Heavy::kick()
{
	int addDamage = rand() % 3 + 1;
	return addDamage;
}