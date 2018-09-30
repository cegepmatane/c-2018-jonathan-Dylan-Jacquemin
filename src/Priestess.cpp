/*
 * Priestess.cpp
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#include "Priestess.h"

namespace std {

Priestess::Priestess() {
	this->hitPoints = 20;
}

Priestess::Priestess(int hitPoints) {
	this->hitPoints = hitPoints;
}

Priestess::Priestess(Weapon& weapon) {
	this->hitPoints = 20;
	this->weapon = weapon;
}

Priestess::~Priestess() {
	// TODO Auto-generated destructor stub
}

bool Priestess::isDead() {
	return this->hitPoints==0;
}

void Priestess::useWeapon(Character& character) {
	character.hitPoints = character.hitPoints - this->weapon.damageAmmount;
}

void Priestess::exportDatas() {
	ofstream file("data/priestess.csv", ios::out | ios::trunc);
	if(file) {
		string className = "Priestess";

		file << className << ";" << this->hitPoints << ";" << endl;
		file.close();
		cout << "Priestess datas succesfully exported" << endl;
	}
	else
		cerr << "Error while oppening the file \"priestess.csv\"" << endl;
}

} /* namespace std */
