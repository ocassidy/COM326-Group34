// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{

	//Arrange the data		
	float baseHealth;
	float newHealth;
	Cleric cleric{ "Zen", 100.f, 120.f, -1, -1,{},{}, 20, Idle, 16 };
	Brawler brawler{ "Jim", 100.f, 120.f, -1, -1,{},{}, 20, Idle, 20, 16 };

	//Act
	baseHealth = cleric.GetHealth();
	brawler.Attack(cleric);
	cleric.Defend(0);
	newHealth = cleric.GetHealth();

	//Brawler brawler{ "Jim", 100.f, 100.f, -1, -1,{},{},20, Idle, 20, 16 };
	//Armour shield{ "Shield", 40, 80, 100, 100, ArmourType::Leather };
	//Armour hat{ "Tinfoil Hat", 2, 21, 21, 100, ArmourType::Cardboard };

	////Act
	//brawler.PickUpArmour(shield);
	//brawler.PickUpArmour(hat);

	//int totalWeight = shield.getWeight() + hat.getWeight();

	//if (totalWeight > brawler.GetWeightLimit()) {
	//	std::cout << "Too heavy bro" << std::endl;
	//}
	//else {
	//	std::cout << "Picked that shit up" << std::endl;
	//}



    return 0;
}