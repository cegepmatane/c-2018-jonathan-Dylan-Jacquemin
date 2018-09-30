/*
 * Spell.cpp
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#include "Spell.h"

namespace std {

Spell::Spell() {
	this->damageAmmount = 4;
}

Spell::~Spell() {

}

void Spell::giveWeaponSpecifications() {
	cout << "A powerful magic fireball ! Inflicts " << this->damageAmmount << " damage." << endl;
}

void Spell::exportDatas() {
	ofstream file("data/spell.csv", ios::out | ios::trunc);
	if(file) {
		string className = "Spell";

		file << className << ";" << this->damageAmmount << ";" << endl;
		file.close();
		cout << "Spell datas succesfully exported" << endl;
	}
	else
		cerr << "Error while oppening the file \"spell.csv\"" << endl;
}

} /* namespace std */
