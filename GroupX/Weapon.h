#pragma once
#include <string>
#include "Item.h"
class Weapon : public Item
{
private:
	int weaponHitStrength_;
	int weaponHealth_;

public:
	Weapon();
	Weapon(std::string itemName, int itemValue, float weight, int hitStrength, int health);

	//setters
	void setWeaponHitStrength(int weaponHitStrength);
	void setWeaponHealth(int weaponHealth);

	//getters
	int getWeaponHitStrength() const;
	int getWeaponHealth()const;
};
