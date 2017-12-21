/*
* Armour.h
*
* Version information v0.1
* Authors: Oisin Cassidy, Diarmuid Bryson, Chantelle Green
* Date: 24/11/2017
* Description: header file for GameCharacter class
*/

#pragma once
#include <string>
#include "Item.h"

enum class ArmourType {Cardboard, Leather, Wood, Iron, Steel};

class Armour : public Item {
private:
	int defence_;
	int armourHealth_;
	ArmourType ArmourType_;

public:
	Armour();
	Armour(std::string itemName, int itemValue, float weight, int armourHealth, int defence, ArmourType ArmourType);

	//setters
	void setDefence(int defence);
	void setArmourHealth(int armourhealth);

	//getters
	int getDefence()const;
	int getArmourHealth()const;

	void SetArmourType(ArmourType ArmourType);
	ArmourType GetArmourType() const;
};
