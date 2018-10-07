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

string Staff::exportDatas() {
	stringstream xml;
	xml << "<Staff><damageAmmount>" << this->damageAmmount << "</damageAmmount>" << "</Staff>";
	return xml.str();
}

} /* namespace std */
