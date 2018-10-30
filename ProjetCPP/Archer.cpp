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
			this->baseHitPoints = stoi(value);
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

int Archer::numberMissingHP() {
	return this->baseHitPoints - this->hitPoints;
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
	
	Character* ennemy = world->ennemy;
	Weapon* spell = world->weaponsList.at(1);

	// Weapon addition :
	this->dealDamage(*ennemy, *spell + *(this->weapon));
	cout << "Ennemy's HP are now " << ennemy->hitPoints << "\n" << endl;
}

void Archer::pressE(World* world) {
	Character* ennemy = world->ennemy;

	cout << "*bow bending*" << endl;
	this_thread::sleep_for(chrono::milliseconds(1500));
	cout << "*whistling*" << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));
	world->currentCharacter->useWeapon(*ennemy);
	cout << "Ennemy's HP are now " << ennemy->hitPoints << "\n" << endl;
}

string Archer::getPath() {
	return "archer.png";
}

void Archer::usePotion() {
	if (numberMissingHP() == 0) {
		cout << "You can't use a potion when hitpoints are at maximum" << endl;
		return;
	}
	if (this->numberMissingHP() <= (int)(this->baseHitPoints / 4)) {
		cout << "The potion made you regain " << this->numberMissingHP() << "HPs" << endl;
		this->hitPoints = this->baseHitPoints;
	}
	else {
		cout << "The potion made you regain " << (int)(this->baseHitPoints / 4) << "HPs" << endl;
		this->hitPoints += (int)(this->baseHitPoints / 4);
	}
}

void Archer::getHealed(int healAmmount) {
	if (numberMissingHP() == 0) {
		return;
	}
	if (this->numberMissingHP() <= healAmmount) {
		cout << this->name << " has been healed of " << this->numberMissingHP() << "HPs." << endl;
		this->hitPoints = this->baseHitPoints;
	}
	else {
		cout << this->name << " has been healed of " << healAmmount << "HPs" << endl;
		this->hitPoints += healAmmount;
	}
}