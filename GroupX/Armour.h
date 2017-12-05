#pragma once
#include <string>
#include "Item.h"

enum class ArmourType {Cardboard, Leather, Wood, Iron, Steel};
class Armour : public Item
{
private:
	int defence_;
	int armourHealth_;
	ArmourType ArmourType_;

public:
	Armour();
	Armour(std::string itemName, int itemValue, float weight, std::string armourName, int value, int armourHealth, int defence, ArmourType ArmourType);

	//setters
	void setDefence(int defence);
	void setArmourHealth(int armourhealth);

	//getters
	int getDefence()const;
	int getarmourHealth()const;
};
