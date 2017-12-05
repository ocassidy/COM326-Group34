#include "Weapon.h"
#include <string>

Weapon::Weapon() {}

Weapon::Weapon(std::string itemName, int itemValue, float weight, int hitStrength, int health) : Item(itemName, itemValue, weight), weaponHitStrength_{ hitStrength }, weaponHealth_{ health } {}

//setters
void Weapon::setWeaponHitStrength(int weaponHitStrength) {
	weaponHitStrength_ = weaponHitStrength;
}
void Weapon::setWeaponHealth(int weaponHealth) {
	weaponHitStrength_ = weaponHealth;
}

//getters
int Weapon::getWeaponHitStrength() const {
	return weaponHitStrength_;
}
int Weapon::getWeaponHealth()const {
	return weaponHealth_;
}
