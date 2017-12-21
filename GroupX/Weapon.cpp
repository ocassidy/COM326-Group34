/*
* Weapon.cpp
*
* Version information v1.0
* Authors: Oisin Cassidy, Diarmuid Bryson, Chantelle Green
* Date: 20/12/2017
* Description: Implementationfor Weapon class
*/

#include "Weapon.h"

//default constructor
Weapon::Weapon() {}

//custom constructor
Weapon::Weapon(std::string itemName, int itemValue, float weight, int hitStrength, int health) 
	: Item(itemName, itemValue, weight), weaponHitStrength_{ hitStrength }, weaponHealth_{ health } {
}

//Getters and setters
void Weapon::setWeaponHitStrength(int weaponHitStrength) {
	weaponHitStrength_ = weaponHitStrength;
}

int Weapon::getWeaponHitStrength() const {
	return weaponHitStrength_;
}

void Weapon::setWeaponHealth(int weaponHealth) {
	weaponHitStrength_ = weaponHealth;
}

int Weapon::getWeaponHealth()const {
	return weaponHealth_;
}