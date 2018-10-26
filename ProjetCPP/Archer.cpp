#include "Archer.h"
#include "World.h"

Archer::Archer() {
	this->initProp();
}

Archer::Archer(int hitPoints) {
	this->initProp();
	this->hitPoints = hitPoints;
}

Archer::Archer(Weapon* weapon) {
	this->initProp();
	this->weapon = weapon;
}

Archer::Archer(int hitPoints, Weapon* weapon) {
	this->hitPoints = hitPoints;
	this->weapon = weapon;
}

Archer::~Archer() {
	// TODO Auto-generated destructor stub
}

void Archer::initProp() {
	this->name = "Archer";

	ifstream archerSource("data/archer.csv");

	if (archerSource.peek() == std::ifstream::traits_type::eof()) {
		ofstream archerFile("data/archer.csv", ios::out | ios::trunc);
		if(archerFile) {
			archerFile << "16;";
			archerFile.close();
		}
		else
			cerr << "Error while opening the file \"archer.csv\"" << endl;
	}

	archerSource.close();
	archerSource.open("data/archer.csv");

	string line;

	while(!archerSource.eof()) {
		getline(archerSource, line);

		unsigned int startPosition = 0;
		unsigned int endPosition = 0;

		do {
			endPosition = line.find(";", startPosition);
			string value = line.substr(startPosition, endPosition - startPosition);
			this->hitPoints = stoi(value);
			startPosition = endPosition + 1;
		}
		while((startPosition !=0) && (line.length() != startPosition));
	}
}

string Archer::getName() {
	return this->name;
}

bool Archer::isDead() {
	return this->hitPoints==0;
}

void Archer::useWeapon(Character& character) {
	character.hitPoints = character.hitPoints - this->weapon->damageAmmount;
}

void Archer::changeWeapon(Weapon* weapon) {
	this->weapon = weapon;
}

void Archer::dealDamage(Character& character, int damageAmmount) {
	character.hitPoints = character.hitPoints - damageAmmount;
}

string Archer::exportDatas() {
	stringstream xml;
	xml << "<Archer><hitPoints>" << this->hitPoints << "</hitPoints>" << "</Archer>";
	return xml.str();
}

void Archer::pressA(World* world) {
	cout << "- " << this->getName() << " : I see yaaa~" << endl;
	cout << "You shoot a fire arrow thanks to the help of the mage." << endl;
	this_thread::sleep_for(chrono::milliseconds(1500));
	
	Character* ennemy = world->charactersList.at(3);
	Weapon* spell = world->weaponsList.at(1);

	// Weapon addition :
	this->dealDamage(*ennemy, *spell + *(this->weapon));
	cout << "Ennemy's HP are now " << ennemy->hitPoints << "\n" << endl;
}

void Archer::pressE(World* world) {
	Character* ennemy = world->charactersList.at(3);

	cout << "*bow bending*" << endl;
	this_thread::sleep_for(chrono::milliseconds(1500));
	cout << "*whistling*" << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));
	world->currentCharacter->useWeapon(*ennemy);
	cout << "Ennemy's HP are now " << ennemy->hitPoints << "\n" << endl;
}