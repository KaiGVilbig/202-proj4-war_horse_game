#include "Warhorse.h"

Warhorse::Warhorse()
{

}

Warhorse::Warhorse(string name, Size size, int health, int speed):Horse(name, size, health, speed)
{
	
}

bool Warhorse::train()
{
	bool success = false;

	//50% chance of successful training (0 or 1)
	int chance = rand() % 2 + 0;
	if (chance == 0)
	{
		success = increaseTraining();
	}
	return success;
}

bool Warhorse::battle(Horse* enemy)
{
	int damage, counter = 0;
	bool result = false;

	//keep attacking while both horses are alive
	while ((getHealth() > 0) & (enemy->getHealth() > 0))
	{
		if (counter % getSpeed() == 0)
		{
			damage = attack(enemy->getName(), getHealth());
			enemy->setHealth(enemy->getHealth() - damage);

			//after friendly horse attacks the enemy horse may die. In that case 
			//the code should not execute the enemy attacking therefor I put a break 
			//that will leave the while loop
			if (enemy->getHealth() <= 0)
			{
				result = true;
				break;
			}
		}

		counter++;

		if (counter % enemy->getSpeed() == 0)
		{
			damage = enemy->attack(getName(), enemy->getHealth());
			setHealth(getHealth() - damage);
		}

		counter++;
	}

	return result;
}