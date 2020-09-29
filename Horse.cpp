#include "Horse.h"

Horse::Horse()
{
	Size size;
	int randSize = rand() % 3 + 0;
	size = Size(randSize);

	m_name = "";
	m_size = size;
	//m_health = health;
	//m_speed = speed;
	m_training = Training(0);
}

Horse::Horse(string name, Size size, int health, int speed)
{
	m_name = name;
	m_size = size;
	m_health = health;
	m_speed = speed;
	m_training = Training(0);
}

string Horse::getName()
{
	return m_name;
}

Size Horse::getSize()
{
	return m_size;
}

int Horse::getHealth()
{
	return m_health;
}

int Horse::getSpeed()
{
	return m_speed;
}

Training Horse::getTraining()
{
	return m_training;
}

void Horse::setHealth(int health)
{
	m_health = health;
}

void Horse::setName(string name)
{
	m_name = name;
}

void Horse::setSize(Size size)
{
	m_size = size;
}

void Horse::setSpeed(int speed)
{
	m_speed = speed;
}

void Horse::setTraining(Training training)
{
	m_training = training;
}

bool Horse::increaseTraining()
{
	if (m_training == Size(MAX_TRAINING))
	{
		return false;
	}
	else
	{
		//increase the training level by 1
		switch (m_training) {
		case 0:
			setTraining(SADDLE);
			break;
		case 1:
			setTraining(GREEN);
			break;
		case 2:
			setTraining(INTERMEDIATE);
			break;
		case 3:
			setTraining(EXPERT);
			break;
		case 4:
			setTraining(MASTER);
			break;
		}
		return true;
	}
}

Horse* Horse::specialize()
{
	return NULL;
}

bool Horse::battle(Horse*)
{
	return true;
}

ostream& operator<<(ostream& horseData, Horse& horse)
{
	horseData << "\t" << left << setw(16) << horse.getName() << "\t" << horse.toString() << "\t";
	horseData << horse.getHealth() << "\t" << horse.getSpeed() << "\t";
	horseData << horse.trainingString(horse.getTraining()) << endl;

	return horseData;
}

bool Horse::randomPercentBased(int pass)
{
	int random = rand() % 100 + 1;

	if (pass < random)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string Horse::trainingString(Training training)
{
	switch (training)
	{
	case 0:
		return "Untrained";
		break;
	case 1:
		return "Saddle";
		break;
	case 2:
		return "Green";
		break;
	case 3:
		return "Intermediate";
		break;
	case 4:
		return "Expert";
		break;
	case 5:
		return "Master";
		break;
	}
	return "";
}