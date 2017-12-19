// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main() {

	float baseHealth;
	float newHealth;
	Cleric cleric{ "Zen", 100.f, 120.f, -1, -1,{},{}, 20, Idle, 16 };
	Brawler brawler{ "Jim", 100.f, 120.f, -1, -1,{},{}, 20, Idle, 20, 16 };
	Weapon spear{ "Spear", 15, 25.f, 200, 6 };
	//Armour chainMail{ "Chain Mail", 45, 85.f, 200, 100, ArmourType::Steel };

	//Act
	brawler.PickUpWeapon(spear);
	//cleric.PickUpArmour(chainMail);
	baseHealth = cleric.GetHealth();
	brawler.Attack(cleric);

	cleric.Defend(0);
	newHealth = cleric.GetHealth();

    return 0;
}