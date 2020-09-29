#include "Light.h"

Light::Light()
{

}

Light::Light(string name, Size size, int health, int speed):Warhorse(name, size, health, speed)
{

}

int Light::attack(string name, int health)
{
	int damage = health / 6 + getTraining();
	cout << "The light warhorse " << getName() << " hits " << name << endl;
	return damage;
}

string Light::toString()
{
	return "Light";
}