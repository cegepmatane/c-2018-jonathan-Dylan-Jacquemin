/*
 * Bow.cpp
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#include "Bow.h"

namespace std {

Bow::Bow() {
	this->initProp();
}

Bow::Bow(int damageAmmount) {
	this->initProp();
}

Bow::~Bow() {

}

void Bow::initProp() {
	ifstream bowSource;
	bowSource.open("data/bow.csv");

	string line;

	while(!bowSource.eof()) {
		getline(bowSource, line);

		unsigned int startPosition = 0;
		unsigned int endPosition = 0;

		do {
			endPosition = line.find(";", startPosition);
			string value = line.substr(startPosition, endPosition - startPosition);
			this->damageAmmount = stoi(value);
			startPosition = endPosition + 1;
		}
		while((startPosition !=0) && (line.length() != startPosition));
	}
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
