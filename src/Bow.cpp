/*
 * Bow.cpp
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#include "Bow.h"

namespace std {

Bow::Bow() {
	this->damageAmmount = 3;
}

Bow::~Bow() {

}

void Bow::giveWeaponSpecifications() {
	cout << "A mystic bow. Deals " << this->damageAmmount << " damage." << endl;
}

void Bow::exportDatas() {
	ofstream file("data/bow.csv", ios::out | ios::trunc);
	if(file) {
		string className = "Bow";

		file << className << ";" << this->damageAmmount << ";" << endl;
		file.close();
		cout << "Bow datas succesfully exported" << endl;
	}
	else
		cerr << "Error while oppening the file \"bow.csv\"" << endl;
}

} /* namespace std */
