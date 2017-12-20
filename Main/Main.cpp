// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main() {

	Cleric cleric{ "Zen", 100.f, 120.f, 20, Idle, 16 };
	Brawler brawler{ "Jim", 100.f, 120.f, 20, Idle, 20, 16 };
	Weapon spear{ "Spear", 15, 25.f, 200, 6 };

	brawler.PickUpWeapon(spear);
	brawler.SetEquippedWeapon(0);
	brawler.Attack(cleric);

    return 0;
}