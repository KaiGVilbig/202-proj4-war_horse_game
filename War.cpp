#include "War.h"

War::War()
{

}

//destructor
War::~War()
{
	for (unsigned int i = 0; i < m_enemyStable.size(); i++)
	{
		delete m_enemyStable[i];
	}
	for (unsigned int i = 0; i < m_myStable.size(); i++)
	{
		delete m_myStable[i];
	}
}

void War::loadHorses(char* file)
{
	fstream inputStream;
	inputStream.open(file);

	if (inputStream.is_open())
	{
		string name, carriegeReturn;
		int sizeValue, health, speed;

		//makes sure that the line we are reading in isnt the last line with nothing in it
		while (!inputStream.eof())
		{
			inputStream >> name >> sizeValue >> health >> speed;
			getline(inputStream, carriegeReturn);

			Horse *newHorse = NULL;
			Size size;

			switch (sizeValue)
			{
			//if the size is 0, it is a small horse and will be light
			case 0:
				size = SMALL;
				newHorse = new Light(name, size, health, speed);
				break;
			//if the size is 1, it is a medium horse and will be medium
			case 1:
				size = MEDIUM;
				newHorse = new Medium(name, size, health, speed);
				break;
			//if the size is 2, it is a large horse and will be heavy
			case 2:
				size = LARGE;
				newHorse = new Heavy(name, size, health, speed);
				break;
			}
			//add horse to the enemy stable
			if (!inputStream.eof())
			{
				m_enemyStable.push_back(newHorse);
			}
			else
			{
				delete newHorse;
			}
		}
		inputStream.close();
	}
	else
	{
		cout << "no such file\n";
	}
}

void War::mainMenu()
{
	int choice = 0;
	cout << "What would you like to do?\n";

	//keeps looping through until 6 is inputted or enemy stable size is 0
	//becauuse that would mean the player has defeated every enemy
	while ((choice != 6) & (m_enemyStable.size() > 0))
	{
		cout << "1. Display Friendly Stable\n";
		cout << "2. Display Enemy Stable\n";
		cout << "3. Acquire Horse\n";
		cout << "4. Train Horse\n";
		cout << "5. Battle\n";
		cout << "6. Quit\n";

		cin >> choice;

		switch (choice)
		{
		case 1:
			displayMyHorses();
			break;
		case 2:
			displayEnemyHorses();
			break;
		case 3:
			acquireHorse();
			break;
		case 4:
			trainHorse();
			break;
		case 5:
			startBattle();
			break;
		case !6:
			//input validation
			cout << "\nPlease chose a valid choice (1 - 6)\n\n";
			break;
		}
	}
}

void War::acquireHorse()
{
	Horse *newHorse = new Untrained();

	cout << "\nYou have acquired a new horse\n";
	m_myStable.push_back(newHorse);
	cout << endl;
}

void War::trainHorse()
{	
	int choice;
	displayMyHorses();
	choice = chooseHorse();
	Horse *newHorse;
	bool train; 

	if (choice != -1)
	{
		train = m_myStable[choice]->train();

		//if train == false, the horse is untrained and this function will call
		//the speciallize function. if it is true, it attempts to train the horse
		//in the train function and depending what it returns, it will display the 
		//correct message
		if ((train == false) & (m_myStable[choice]->toString() == "Unknown"))
		{
			newHorse = m_myStable[choice]->specialize();
			delete m_myStable[choice];
			m_myStable[choice] = newHorse;
			cout << endl << m_myStable[choice]->getName() << " has been speciallized\n\n";
		}
		else
		{
			if (train == false)
			{
				cout << "\nTraining failed\n\n";
			}
			else
			{
				cout << endl << m_myStable[choice]->getName() << " has been trained\n\n";
			}
		}
	}
}

void War::startBattle()
{
	int choice;
	bool playerWin = false;

	cout << "Which horse would you like to battle with?\n";
	displayMyHorses();
	choice = chooseHorse();
	cout << endl;
	if ((m_myStable.size() > 0) & (m_enemyStable.size() > 0))
	{
		if (m_myStable[choice]->getTraining() == 0)
		{
			cout << "You are not ready for battle\n\n";
		}
		else
		{
			playerWin = m_myStable[choice]->battle(m_enemyStable[0]);
			if (playerWin)
			{
				Horse *delHorse = *m_enemyStable.begin();
				m_enemyStable.erase(m_enemyStable.begin());
				delete delHorse;

				//if you defeated every enemy horse you get a special message
				if (m_enemyStable.size() == 0)
				{
					cout << "\nCongrats! You have defeated every enemy and have successfully\n";
					cout << "ended the war bringing long lost peace back to this land!\n\n";
				}
				else
				{
					cout << "\nCongrats you won the battle!\n\n";
				}
			}
			else
			{
				Horse *delHorse = m_myStable[choice];
				m_myStable.erase(m_myStable.begin() + choice);
				delete delHorse;
				cout << "\nYour horse perished in the battle\n" << endl;
			}
		}
	}
	else
	{
		cout << "You can not go into battle without a horse\n\n";
	}
	
}

void War::displayMyHorses()
{
	cout << "\nMy Horses\n";
	cout << "Num\tHorse\t\t\tSize\tHealth\tSpeed\tTraining\n";
	for (unsigned int i = 0; i < m_myStable.size(); i++)
	{
		cout << i + 1 << *m_myStable[i];
	}
	cout << endl;
}

void War::displayEnemyHorses()
{
	cout << "\nEnemy Horses\n";
	cout << "Num\tHorse\t\t\tSize\tHealth\tSpeed\tTraining\n\n";
	for (unsigned int i = 0; i < m_enemyStable.size(); i++)
	{
		cout << i + 1 << *m_enemyStable[i];
	}
	cout << endl;
}

int War::chooseHorse()
{
	int choice = 0;
	int size = m_myStable.size();
	if (size != 0)
	{
		do
		{
			cout << "Which horse would you like to work with?\n";
			cin >> choice;
		} while(choice <= 0 || choice > size);
	}
	else
	{
		cout << "You don't have any horses in your stable\n";
	}
	return choice - 1;
}