// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{

	////Arrange the data		
	//float baseHealth;
	//float newHealth;
	//Cleric cleric{ "Zen", 50.f, 120.f, -1, -1,{},{}, 20, Idle, 16 };
	//Brawler brawler{ "Jim", 100.f, 120.f, -1, -1,{},{}, 20, Idle, 20, 16 };
	//Weapon sword{ "Sword", 30, 115.0f, 50, 60 };
	//Weapon axe{ "Axe", 40, 56.0f, 70, 60 };
	//Armour shield{ "Shield", 25, 30.0f, 60, 70, ArmourType::Cardboard };
	//Armour shiled2{ "Shield2", 30, 120, 50, 60, ArmourType::Leather };

	//cleric.PickUpWeapon(sword);
	//cleric.PickUpWeapon(axe);
	//cleric.PickUpArmour(shield);
	//cleric.PickUpArmour(shiled2);
	//cleric.DropItem(shiled2);
	//cleric.EquipWeapon(1);
	////Act

	//cleric.Attack(brawler);

	//cleric.AddFood(10);
	//cleric.Sleep();
	//cleric.AddFood(0);
	//cleric.SetState(Running);

	/*baseHealth = cleric.GetHealth();
	brawler.Attack(cleric);
	cleric.Defend(0);
	newHealth = cleric.GetHealth();*/

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

	Brawler brawler{ "Jim", 100.f, 120.f, -1, -1,{},{}, 20, Idle, 20, 16 };
	Weapon spear{ "Spear", 15, 25.f, 100, 6 };
	Armour glove{ "Leather glove", 3, 25.0f, 1, 100, ArmourType::Leather };
	Armour chainMail{ "Chain Mail", 45, 85.f, 200, 100, ArmourType::Steel };


	//Act
	brawler.PickUpWeapon(spear);
	brawler.PickUpArmour(glove);
	brawler.PickUpArmour(chainMail);

    return 0;
}