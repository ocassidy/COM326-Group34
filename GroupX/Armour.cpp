/*
* Weapon.cpp
*
* Version information v1.0
* Authors: Oisin Cassidy, Diarmuid Bryson, Chantelle Green
* Date: 20/12/2017
* Description: Implementation for Weapon class
*/

#include "Armour.h"

Armour::Armour() {
}

Armour::Armour(std::string itemName, int itemValue, float weight, int armourHealth, int defence, ArmourType ArmourType)
	:Item(itemName, itemValue, weight), armourHealth_{ armourHealth }, defence_{ defence }, ArmourType_{ ArmourType } {
}

//setters
void Armour::setDefence(int defence) {
	defence_ = defence;
}
void Armour::setArmourHealth(int armourhealth) {
	armourHealth_ = armourhealth;
}

//getters
int Armour::getDefence() const {
	return defence_;
}

int Armour::getArmourHealth() const {
	return armourHealth_;
}

void Armour::SetArmourType(ArmourType ArmourType) {
	ArmourType_ = ArmourType;
}

ArmourType Armour::GetArmourType() const {
	return ArmourType_;
}
