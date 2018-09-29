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
	Weapon* staff = new Staff();
	Weapon* spell = new Spell();
	Weapon* bow = new Bow();

	Character* priestess = new Priestess(*staff);
	Character* archer = new Archer(*bow);

	priestess->useWeapon(*archer);
	cout << archer->hitPoints << endl;

	Character* mage = new Mage(*spell);

	mage->useWeapon(*archer);
	mage->useWeapon(*archer);

	cout << archer->hitPoints << endl;

	delete priestess;
	delete archer;
	delete mage;

	return 0;
}
