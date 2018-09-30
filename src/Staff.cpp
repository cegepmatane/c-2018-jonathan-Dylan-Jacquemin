/*
 * Staff.cpp
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#include "Staff.h"

namespace std {

Staff::Staff() {
	this->damageAmmount = -5;
}

Staff::Staff(int damageAmmount) {
	this->damageAmmount = damageAmmount;
}

Staff::~Staff() {

}

void Staff::giveWeaponSpecifications() {
	cout << "A golden staff. Heals " << this->damageAmmount << " hit points." << endl;
}

void Staff::exportDatas() {
	ofstream file("data/staff.csv", ios::out | ios::trunc);
	if(file) {
		string className = "Staff";

		file << className << ";" << this->damageAmmount << ";" << endl;
		file.close();
		cout << "Staff datas succesfully exported" << endl;
	}
	else
		cerr << "Error while oppening the file \"staff.csv\"" << endl;
}

} /* namespace std */
