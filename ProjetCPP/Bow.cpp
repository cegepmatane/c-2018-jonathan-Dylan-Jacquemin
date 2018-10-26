#include "Bow.h"

Bow::Bow() {
	this->initProp();
}

Bow::Bow(int damageAmmount) {
	this->initProp();
}

Bow::~Bow() {

}

void Bow::initProp() {
	ifstream bowSource("data/bow.csv");

	if (bowSource.peek() == std::ifstream::traits_type::eof()) {
		ofstream bowFile("data/bow.csv", ios::out | ios::trunc);
		if(bowFile) {
			bowFile << "3;";
			bowFile.close();
		}
		else
			cerr << "Error while opening the file \"bow.csv\"" << endl;
	}

	bowSource.close();
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

int Bow::operator+(Weapon & other)
{
	int damageCombined;
	damageCombined = this->damageAmmount + other.damageAmmount;
	return damageCombined;
}
