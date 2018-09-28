/*
 * Character.h
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

namespace std {

class Character {
public:
	Character();
	virtual ~Character();
	// attributes
	int hitPoints;
	// methods
	virtual bool isDead();
	virtual void useWeapon(Character&);
};

} /* namespace std */

#endif /* CHARACTER_H_ */
