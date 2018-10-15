//============================================================================
// Name        : ProjetCpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>

#include "Archer.h"
#include "Bow.h"
#include "Character.h"
#include "Mage.h"
#include "Priestess.h"
#include "Spell.h"
#include "Staff.h"
#include "Weapon.h"

using namespace std;

int main() {
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

	// Program
	priestess->useWeapon(*archer);
	cout << "Archer current HP : " << archer->hitPoints << endl;
	mage->useWeapon(*archer);
	mage->useWeapon(*archer);
	cout << "Archer current HP : " << archer->hitPoints << endl;

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
