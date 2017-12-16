#include "Weapon.h"
#include <string>

Weapon::Weapon() {}

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