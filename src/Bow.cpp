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

Bow::Bow(int damageAmmount) {
	this->damageAmmount = damageAmmount;
}

Bow::~Bow() {

}

void Bow::giveWeaponSpecifications() {
	cout << "A mystic bow. Deals " << this->damageAmmount << " damage." << endl;
}

string Bow::exportDatas() {
	stringstream xml;
	xml << "<Bow><damageAmmount>" << this->damageAmmount << "</damageAmmount>" << "</Bow>";
	return xml.str();
}

} /* namespace std */
