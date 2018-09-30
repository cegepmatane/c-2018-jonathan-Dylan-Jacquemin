/*
 * Archer.cpp
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#include "Archer.h"

namespace std {

Archer::Archer() {
	this->hitPoints = 16;
}

Archer::Archer(int hitPoints) {
	this->hitPoints = hitPoints;
}

Archer::Archer(Weapon& weapon) {
	this->hitPoints = 16;
	this->weapon = weapon;
}

Archer::~Archer() {
	// TODO Auto-generated destructor stub
}

bool Archer::isDead() {
	return this->hitPoints==0;
}

void Archer::useWeapon(Character& character) {
	character.hitPoints = character.hitPoints - this->weapon.damageAmmount;
}

void Archer::exportDatas() {
	ofstream file("data/archer.csv", ios::out | ios::trunc);
	if(file) {
		string className = "Archer";

		file << className << ";" << this->hitPoints << ";" << endl;
		file.close();
		cout << "Archer datas succesfully exported" << endl;
	}
	else
		cerr << "Error while oppening the file \"archer.csv\"" << endl;
}

} /* namespace std */
