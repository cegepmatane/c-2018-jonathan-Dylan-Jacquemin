//============================================================================
// Name        : ProjetCpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

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
	Weapon* bow = new Bow();
	Weapon* spell = new Spell();
	Weapon* staff = new Staff();

	Character* archer = new Archer(35, *bow);
	Character* mage = new Mage(*spell);
	Character* priestess = new Priestess(*staff);

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
				worldFile << archer->exportDatas() << endl;
				worldFile << mage->exportDatas() << endl;
				worldFile << priestess->exportDatas() << endl;
			worldFile << "</Character>" << endl;
			worldFile << "<Spell>" << endl;
				worldFile << bow->exportDatas() << endl;
				worldFile << spell->exportDatas() << endl;
				worldFile << staff->exportDatas() << endl;
			worldFile << "</Spell>" << endl;
		worldFile << "</World>" << endl;
	worldFile.close();

	delete archer;
	delete mage;
	delete priestess;

	delete bow;
	delete spell;
	delete staff;

	return 0;
}
