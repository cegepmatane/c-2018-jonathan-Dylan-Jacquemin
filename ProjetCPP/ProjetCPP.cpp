//============================================================================
// Name        : ProjetCpp.cpp
// Author      : DYLAN-MSI
// Version     :
// Copyright   : 
// Description : 
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

	Character* ennemy = new Mage(100, *spell);
	charactersList.push_back(ennemy);

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
	cout << "You currently are playing archer (" << currentCharacter->hitPoints << "HP) \n" << endl;

	while (gameIsRunning) {
		this_thread::sleep_for(chrono::milliseconds(1000 / 120)); // 120 fps

		if (waitCount != 0) {
			if (_kbhit()) {
				key = _getch();
				//cout << "key pressed : " << key << " frame n." << frames << endl;

				switch (key) {
				// case "ESCAPE", to quit the game
				case 27:
					gameIsRunning = false;
					break;

				// UP
				case 122:
					cout << "move up" << endl;
					waitCount = 0;
					break;
				// LEFT
				case 113:
					cout << "move left" << endl;
					waitCount = 0;
					break;
				// DOWN
				case 115:
					cout << "move down" << endl;
					waitCount = 0;
					break;
				// RIGHT
				case 100:
					cout << "move right" << endl;
					waitCount = 0;
					break;

				// case "SPACE"
				case 32:
					cout << "Swaping the caracter..." << endl;
					playingCharacterNumber += 1;
					currentCharacter = charactersList.at(playingCharacterNumber % 3);
					cout << "You are now playing as : " << currentCharacter->getName() << "(" << currentCharacter->hitPoints << "HP)\n" << endl;
					
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
					cout << " - 'a' to unleash your ultimate" << endl;
					cout << " - 'e' to do a simple attack" << endl;
					cout << " - 'p' to use a potion \n" << endl;
					isPlayingAction = true;
					break;

				}

				// In case the player has chosen to interact (with 'ENTER') in this turn
				if (isPlayingAction) {
					switch (key) {
					// 'A' then 'a'
					case 65:
					case 97:
						if ((currentCharacter->getName())._Equal("Archer")) {
							cout << "- " << currentCharacter->getName() << " : I see yaaa~" << endl;
							cout << "You shoot a fire arrow thanks to the help of the mage." << endl;
							this_thread::sleep_for(chrono::milliseconds(1500));
							// Weapon addition :
							currentCharacter->dealDamage(*ennemy, *bow + *spell);
							cout << "Ennemy's HP are now " << ennemy->hitPoints << "\n" << endl;
						}
						else if ((currentCharacter->getName())._Equal("Mage")) {
							cout << "- " << currentCharacter->getName() << " : See if you can handle this !" << endl;
							cout << "You are casting a HUGE fireball !" << endl;
							this_thread::sleep_for(chrono::milliseconds(1500));
							// Weapon addition :
							currentCharacter->dealDamage(*ennemy, *spell + *spell);
							cout << "Ennemy's HP are now " << ennemy->hitPoints << "\n" << endl;
						}
						else if ((currentCharacter->getName())._Equal("Priestess")) {
							cout << "- " << currentCharacter->getName() << " : I won't let you down, my friends !" << endl;
							for (Character* character : charactersList) {
								currentCharacter->useWeapon(*character);
							}
							// TODO : define a baseHP attribute in std::Character
							cout << "You healed all your team of " << 0-currentCharacter->weapon.damageAmmount << "HP\n" << endl;
						}
						isPlayingAction = false;
						waitCount = 0;
						break;

					// 'E' then 'e'
					case 69:
					case 101:
						if ((currentCharacter->getName())._Equal("Archer")) {
							cout << "*bow bending*" << endl;
							this_thread::sleep_for(chrono::milliseconds(1500));
							cout << "*whistling*" << endl;
							currentCharacter->useWeapon(*ennemy);
							cout << "Ennemy's HP are now " << ennemy->hitPoints << "\n" << endl;
						}
						else if ((currentCharacter->getName())._Equal("Mage")) {
							cout << "*fire*" << endl;
							this_thread::sleep_for(chrono::milliseconds(1500));
							cout << "*blast*" << endl;
							currentCharacter->useWeapon(*ennemy);
							cout << "Ennemy's HP are now " << ennemy->hitPoints << "\n" << endl;
						}
						else if ((currentCharacter->getName())._Equal("Priestess")) {
							cout << "- " << currentCharacter->getName() << " : Come here, I will heal you~" << endl;
							this_thread::sleep_for(chrono::milliseconds(1000));
							currentCharacter->useWeapon(*charactersList.at(gameTurn%2));
							// TODO : define a baseHP attribute in std::Character
							cout << "You healed an ally for " << 0 - currentCharacter->weapon.damageAmmount << "HP\n" << endl;
						}
						isPlayingAction = false;
						waitCount = 0;
						break;

					// 'P' then 'p'
					case 80:
					case 112:
						// TODO : define a baseHP attribute and a method to usePotion in std::Character
						currentCharacter->hitPoints = currentCharacter->hitPoints + 5;
						cout << "You used a potion. You now have " << currentCharacter->hitPoints << "HP" << endl;
						isPlayingAction = false;
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
			// NEW TURN
			gameTurn++;
			waitCount = 15;
			cout << "Turn " << gameTurn << ". You now have 15sec to play your turn.\n" << endl;
			// TODO make the ennemy attack
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

	cout << "Game finished, exported datas can be found on ./data/world.xml" << endl;

	return 0;
}