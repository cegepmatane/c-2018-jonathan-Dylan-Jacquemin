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
	cout << "|====| Welcome to the battleground ! |====|" << endl;

	int frames = 0;
	int key;
	bool gameIsRunning = true;
	int currentPlayingTime = 0;
	int playingCharacterNumber = 0;
	int waitCount = 0;
	int gameTurn = 0;
	bool isPlayingAction = false;

	Character* currentCharacter = charactersList.at(playingCharacterNumber);
	cout << "You currently are playing archer (" << currentCharacter->hitPoints << "HP)" << endl;

	while (gameIsRunning) {
		this_thread::sleep_for(chrono::milliseconds(1000 / 120)); // 120 fps

		if (waitCount != 0) {
			if (_kbhit()) {
				key = _getch();
				cout << "key pressed : " << key << " " << frames << endl;

				switch (key) {
				// case "ESCAPE"
				case 27:
					gameIsRunning = false;
					break;

				// case "SPACE"
				case 32:
					cout << "Swaping the caracter..." << endl;
					playingCharacterNumber += 1;
					currentCharacter = charactersList.at(playingCharacterNumber % 3);
					cout << "You are now playing as : " << currentCharacter->getName() << "(" << currentCharacter->hitPoints << "HP)" << endl;
					
					waitCount = 0;
					break;

				case 't':
					cout << "Current time :" << currentPlayingTime << endl;
					break;

				// case 'ENTER'
				case 13:
					cout << "|==| Interaction Menu |==|" << endl;
					cout << "HP : " << currentCharacter->hitPoints << " | DMG : " << currentCharacter->weapon.damageAmmount << endl;
					cout << "Press :" << endl;
					cout << "	- 'a' to unleash your ultimate" << endl;
					cout << "	- 'e' to do a simple attack" << endl;
					cout << "	- 'p' to use a potion" << endl;
					isPlayingAction = true;
					break;

				}

				// In case the player has chosen to interact (with 'ENTER') in the current turn
				if (isPlayingAction) {
					switch (key) {
					// 'a' ('A' : 65)
					case 65:
					case 97:
						if ((currentCharacter->getName())._Equal("Archer")) {
							cout << "" << endl;
						}
						else if ((currentCharacter->getName())._Equal("Mage")) {

						}
						else if ((currentCharacter->getName())._Equal("Priestess")) {

						}
						waitCount = 0;
						break;

					// 'e' ('E' = 69)
					case 69:
					case 101:
						break;

					// 'p' ('P' = 80)
					case 80:
					case 112:
						currentCharacter->hitPoints = currentCharacter->hitPoints + 5;
						cout << "You used a potion. You now have " << currentCharacter->hitPoints << "HP" << endl;
						waitCount = 0;
						break;

					}
				}
			}
			while (_kbhit())
				_getch();
			//cout << "frames " << frames << endl;
			frames++;
		}
		else {
			// START A NEW TURN
			gameTurn++;
			waitCount = 15;
			cout << "Turn " << gameTurn << ". You now have 15sec to play your turn." << endl;
		}

		if (currentPlayingTime != frames / 120) {
			currentPlayingTime = frames / 120;
			waitCount--;
		}

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