//============================================================================
// Name        : ProjetCpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

#include "Archer.h"
#include "Bow.h"
#include "Character.h"
#include "Mage.h"
#include "Priestess.h"
#include "Spell.h"
#include "Staff.h"

#include "Weapon.h"
#include "conio.h"
#include <thread>
#include <chrono>

#if __cplusplus < 201703L // If the version of C++ is less than 17
	// It was still in the experimental:: namespace
namespace fs = std::experimental::filesystem;
#else
namespace fs = std::filesystem;
#endif

using namespace std;

int main() {
	fs::create_directory("./data");

	vector<Weapon*> weaponsList;
	vector<Character*> charactersList;

	// Weapon creation
	Weapon* bow = new Bow();
	Weapon* spell = new Spell();
	Weapon* staff = new Staff();

	weaponsList.push_back(bow);
	weaponsList.push_back(spell);
	weaponsList.push_back(staff);

	// Character creation
	Character* archer = new Archer(*bow);
	Character* mage = new Mage(*spell);
	Character* priestess = new Priestess(*staff);

	charactersList.push_back(archer);
	charactersList.push_back(mage);
	charactersList.push_back(priestess);

	// Game Loop
	cout << "To quit the game, press on ESC key. \n" << endl;
	cout << "Welcome to the battleground !" << endl;

	int turn = 0;
	int key;
	bool gameIsRunning = true;
	int currentTime = 0;
	int characterNumber = 0;

	Character* currentCharacter = charactersList.at(characterNumber);
	cout << "You currently are playing Archer (" << currentCharacter->hitPoints << "HP)" << endl;

	while (gameIsRunning) {
		this_thread::sleep_for(chrono::milliseconds(1000 / 120)); // 120 fps
		
		if (currentTime != turn/120)
		{
			// cout << "Current time :" << turn / 120 << endl;
			currentTime = turn / 120;
		}
		
		if (_kbhit()) {
			key = _getch();
			//cout << "key pressed : " << key << " " << turn << endl;

			switch (key) {
			// case "ESCAPE"
			case 27:
				gameIsRunning = false;
				break;
			// case "SPACE"
			case 32:
				cout << "Swaping the caracter..." << endl;
				characterNumber += 1;
				currentCharacter = charactersList.at(characterNumber % 3);
				cout << "New character : " << currentCharacter->getName() << endl;
				break;
			case 'T':
				cout << "Current time :" << currentTime << endl;
				break;
			}
		}
		while (_kbhit())
			_getch();
		//cout << "turn " << turn << endl;
		turn++;
	}

	// Data export
	ofstream worldFile;
	worldFile.open("data/world.xml");
		worldFile << "<World>" << endl;
			worldFile << "<Character>" << endl;
				for(Character* character : charactersList) {
					worldFile << character->exportDatas() << endl;
				}
			worldFile << "</Character>" << endl;
			worldFile << "<Spell>" << endl;
				for(Weapon* weapon : weaponsList) {
					worldFile << weapon->exportDatas() << endl;
				}
			worldFile << "</Spell>" << endl;
		worldFile << "</World>";
	worldFile.close();

	//deletion
	delete archer;
	delete mage;
	delete priestess;
	delete bow;
	delete spell;
	delete staff;

	return 0;
}