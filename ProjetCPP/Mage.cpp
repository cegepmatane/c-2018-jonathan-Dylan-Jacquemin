#include "Mage.h"
#include "World.h"

Mage::Mage() {
	this->initProp();
}

Mage::Mage(int hitPoints) {
	this->initProp();
	this->hitPoints = hitPoints;
}

Mage::Mage(Weapon* weapon) {
	this->initProp();
	this->weapon = weapon;
}

Mage::Mage(int hitPoints, Weapon* weapon) {
	this->hitPoints = hitPoints;
	this->weapon = weapon;
}

Mage::~Mage() {
	// TODO Auto-generated destructor stub
}

void Mage::initProp() {
	this->name = "Mage";

	ifstream mageSource("data/mage.csv");

	if (mageSource.peek() == std::ifstream::traits_type::eof()) {
		ofstream mageFile("data/mage.csv", ios::out | ios::trunc);
		if(mageFile) {
			mageFile << "12;";
			mageFile.close();
		}
		else
			cerr << "Error while opening the file \"mage.csv\"" << endl;
	}

	mageSource.close();
	mageSource.open("data/mage.csv");

	string line;

	while(!mageSource.eof()) {
		getline(mageSource, line);

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

string Mage::getName() {
	return this->name;
}

bool Mage::isDead() {
	return this->hitPoints==0;
}

int Mage::numberMissingHP() {
	return this->baseHitPoints - this->hitPoints;
}

void Mage::useWeapon(Character& character) {
	character.hitPoints = character.hitPoints - this->weapon->damageAmmount;
}

void Mage::changeWeapon(Weapon* weapon) {
	this->weapon = weapon;
}

void Mage::dealDamage(Character& character, int damageAmmount) {
	character.hitPoints = character.hitPoints - damageAmmount;
}

string Mage::exportDatas() {
	stringstream xml;
	xml << "<Mage><hitPoints>" << this->hitPoints << "</hitPoints>" << "</Mage>";
	return xml.str();
}

void Mage::pressA(World* world) {
	cout << "- " << this->getName() << " : See if you can handle this !" << endl;
	cout << "You are casting a HUGE fireball !" << endl;
	this_thread::sleep_for(chrono::milliseconds(1500));

	Character* ennemy = world->charactersList.at(3);

	// Weapon addition :
	this->dealDamage(*ennemy, *(this->weapon) + *(this->weapon));
	cout << "Ennemy's HP are now " << ennemy->hitPoints << "\n" << endl;
}

void Mage::pressE(World* world) {
	Character* ennemy = world->charactersList.at(3);

	cout << "*fire*" << endl;
	this_thread::sleep_for(chrono::milliseconds(1500));
	cout << "*blast*" << endl;
	world->currentCharacter->useWeapon(*ennemy);
	cout << "Ennemy's HP are now " << ennemy->hitPoints << "\n" << endl;
}

string Mage::getPath() {
	return "mage.png";
}

void Mage::usePotion() {
	if (this->numberMissingHP() >= (this->baseHitPoints / 4)) {
		cout << "The potion made you regain " << this->numberMissingHP() << "HPs" << endl;
		this->hitPoints = this->baseHitPoints;
	}
	else {
		cout << "The potion made you regain " << this->baseHitPoints / 4 << "HPs" << endl;
		this->hitPoints += this->baseHitPoints / 4;
	}
}

void Mage::getHealed(int healAmmount) {
	if (this->numberMissingHP() >= healAmmount) {
		cout << this->name << " has been healed of " << this->numberMissingHP() << "HPs." << endl;
		this->hitPoints = this->baseHitPoints;
	}
	else {
		cout << this->name << " has been healed of " << healAmmount << "HPs" << endl;
		this->hitPoints += healAmmount;
	}
}