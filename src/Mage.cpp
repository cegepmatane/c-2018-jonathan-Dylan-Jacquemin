/*
 * Mage.cpp
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#include "Mage.h"

namespace std {

Mage::Mage() {
	this->hitPoints = 12;
}

Mage::Mage(Weapon& weapon) {
	this->hitPoints = 12;
	this->weapon = weapon;
}

Mage::~Mage() {
	// TODO Auto-generated destructor stub
}

bool Mage::isDead() {
	return this->hitPoints==0;
}

void Mage::useWeapon(Character& character) {
	character.hitPoints = character.hitPoints - this->weapon.damageAmmount;
}

void Mage::exportDatas() {
	ofstream file("data/mage.csv", ios::out | ios::trunc);
	if(file) {
		string className = "Mage";

		file << className << ";" << this->hitPoints << ";" << endl;
		file.close();
		cout << "Mage datas succesfully exported" << endl;
	}
	else
		cerr << "Error while oppening the file \"mage.csv\"" << endl;
}

} /* namespace std */
