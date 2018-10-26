#include "Character.h"
#include "World.h"

Character::Character() {}

Character::Character(int hitPoints) {}

Character::Character(Weapon* weapon) {}

Character::Character(int, Weapon*){}

Character::~Character() {}

void Character::initProp() {}

void Character::useWeapon(Character& character) {}

void Character::changeWeapon(Weapon* weapon) {}

void Character::dealDamage(Character& character, int damageAmmount) {}

string Character::exportDatas() {return "";}

void Character::pressA(World* world) {}

void Character::pressE(World* world) {}
