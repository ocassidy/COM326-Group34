// Main.cpp : Used for testing/debugging, is a blank Console App

#include "stdafx.h"

int main() {
	int expectedState{ 5 }, actualState;
	Cleric cleric{ "Zen", 0.f, 120.f, 20, Dead, 16 };
	BlackWitch blackwitch{ "Jim", 100.f, 120.f, 20, Idle, 20, 100 };
	Weapon spear{ "Spear", 15, 25.f, 200, 6 };
	Armour glove{ "Leather glove", 3, 25.0f, 1, 0, ArmourType::Leather };

	//Act
	blackwitch.PickUpWeapon(spear);
	blackwitch.EquipWeapon(0);
	cleric.PickUpArmour(glove);
	cleric.Defend(0);
	blackwitch.Attack(cleric);

    return 0;
}