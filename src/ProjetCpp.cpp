//============================================================================
// Name        : ProjetCpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

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

	archer->exportDatas();
	delete archer;

	mage->exportDatas();
	delete mage;

	priestess->exportDatas();
	delete priestess;

	bow->exportDatas();
	delete bow;

	spell->exportDatas();
	delete spell;

	staff->exportDatas();
	delete staff;

	return 0;
}
