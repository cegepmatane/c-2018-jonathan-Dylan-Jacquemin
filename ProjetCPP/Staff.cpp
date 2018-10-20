/*
 * Staff.cpp
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#include "Staff.h"

namespace std {

Staff::Staff() {
	this->initProp();
}

Staff::Staff(int damageAmmount) {
	this->initProp();
	this->damageAmmount = damageAmmount;
}

Staff::~Staff() {

}

void Staff::initProp() {
	ifstream staffSource("data/staff.csv");

	if (staffSource.peek() == std::ifstream::traits_type::eof()) {
		ofstream staffFile("data/staff.csv", ios::out | ios::trunc);
		if(staffFile) {
			staffFile << "-5;";
			staffFile.close();
		}
		else
			cerr << "Error while opening the file \"staff.csv\"" << endl;
	}

	staffSource.close();
	staffSource.open("data/staff.csv");

	string line;

	while(!staffSource.eof()) {
		getline(staffSource, line);

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

void Staff::giveWeaponSpecifications() {
	cout << "A golden staff. Heals " << this->damageAmmount << " hit points." << endl;
}

string Staff::exportDatas() {
	stringstream xml;
	xml << "<Staff><damageAmmount>" << this->damageAmmount << "</damageAmmount>" << "</Staff>";
	return xml.str();
}

int Staff::operator+(Weapon & other)
{
	int damageCombined;
	damageCombined = this->damageAmmount + other.damageAmmount;
	return damageCombined;
}

} /* namespace std */
