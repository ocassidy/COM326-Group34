// Main.cpp : Used for testing/debugging, is a blank Console App
//Diarmuid bryson - B00709477
//tests do not need to run, only used as a mean of testing functions along side unit tests - this is why all is commented out

#include "stdafx.h"

int main() {

	//Cleric cleric{ "Zen", 0.f, 120.f, 20, Dead, 16 };
	//BlackWitch blackwitch{ "Jim", 100.f, 120.f, 20, Idle, 20, 100 };
	//Weapon spear{ "Spear", 15, 25.f, 200, 6 };
	//Armour glove{ "Leather glove", 3, 25.0f, 1, 0, ArmourType::Leather };

	//blackwitch.PickUpWeapon(spear);
	//blackwitch.EquipWeapon(0);
	//cleric.PickUpArmour(glove);
	//cleric.Defend(0);
	//blackwitch.Attack(cleric);

	//Cleric cleric1{ "John", 30.0f, 70.0f, 50, Idle, 50 };
	//Brawler brawler1{ "Jim", 40.0f, 80.0f, 30, Idle, 70, 60 };
	//Orc orc1{ "Kyle", 45.0f, 65.0f, 25, Idle, 50, 30 };
	//BlackWitch bw1{ "Sean", 60.0f, 40.0f, 60, Idle, 70, 50 };

	//following tests are being used along side the unit tests to ensure methods are working. these will involve stepping through the debugger
	//to verify that values are actually changing

	//test to ensure all characters health is increaded by the sleep function
	//cleric1.Sleep();
	//brawler1.Sleep();
	//orc1.Sleep();
	//bw1.Sleep();

	//tests to ensure food is being added
	//cleric1.AddFood(20);
	//brawler1.AddFood(20);
	//bw1.AddFood(20);
	//orc1.AddFood(20);

	////tests to ensure eating food actually increase health
	//cleric1.Eat();
	//orc1.Eat();
	//bw1.Eat();
	//brawler1.Eat();

	//tests to ensure set state is changing for each character
	//cleric1.SetState(Running);
	//orc1.SetState(Defending);
	//bw1.SetState(Walking);
	//brawler1.SetState(Sleeping);

	//tests to ensure characters can add pickup weapons
	//Weapon Axe{ "Axe", 30, 25.0f, 30, 45 };
	//Weapon Sword{ "Sword", 40, 24.0f, 30, 45 };
	//Weapon Spear{ "Spear", 40, 35.0f, 45, 40 };

	//cleric1.PickUpWeapon(Axe);
	//cleric1.PickUpWeapon(Sword);
	//cleric1.PickUpWeapon(Spear);//shouldn't pick up as over weight limit
	//cleric1.EquipWeapon(0);
	//cleric1.EquipWeapon(1);

	//tests to ensure character can pickup armour
	//Armour Shield{ "Shield", 30, 30.0f, 80, 75, ArmourType::Iron };
	//Armour Vest{ "Vest", 30, 25.0f, 50, 50, ArmourType::Steel };
	//Armour Hat{ "Hat", 20, 25.0f, 40, 50, ArmourType::Leather };

	//cleric1.PickUpArmour(Shield);
	//cleric1.PickUpArmour(Vest);
	//cleric1.PickUpArmour(Hat);//shouldn't pick up as over weight limit

	//test to ensure character can not go over weight limit using both weapon and armour
	//cleric1.PickUpWeapon(Axe);
	//cleric1.PickUpArmour(Shield);
	//cleric1.PickUpWeapon(Spear);//shouldn't pickup as over weight limit

	//declare new characters for attack methods
	//////Cleric cleric{ "Zen", 100.f, 120.f, 20, Idle, 16 };
	//////Brawler brawler{ "Jim", 100.f, 120.f, 20, Idle, 20, 16 };
	//////Orc orc{ "John", 100.0f, 120.0f, 30, Idle, 40, 45 };
	//////BlackWitch bw1{ "James", 100.0f, 120.0f, 45, Idle, 40, 50 };
	//////Weapon spear{ "Spear", 15, 25.f, 200, 6 };
	//////Armour glove{ "Leather glove", 3, 25.0f, 1, 0, ArmourType::Leather };

	//test brawler attack functions to ensure the health of the character being attacked reduces
	//brawler attacks cleric
	//brawler.PickUpWeapon(spear);
	//brawler.EquipWeapon(0);
	//cleric.PickUpArmour(glove);
	//cleric.Defend(0);
	//brawler.Attack(cleric);

	//brawler attacks black witch
	//brawler.PickUpWeapon(spear);
	//brawler.EquipWeapon(0);
	//bw1.PickUpArmour(glove);
	//bw1.Defend(0);
	//brawler.Attack(bw1);

	//brawler attacks orc
	//brawler.PickUpWeapon(spear);
	//brawler.EquipWeapon(0);
	//orc.PickUpArmour(glove);
	//orc.Defend(0);
	//brawler.Attack(orc);

	//brawler brawls cleric
	//brawler.Brawl(cleric);
	//cleric.GetHealth();
	
	//test cleric attack functions to ensure target characters health is reduced
	//cleric attacks brawler
	//cleric.PickUpWeapon(spear);
	//cleric.EquipWeapon(0);
	//brawler.PickUpArmour(glove);
	//brawler.Defend(0);
	//cleric.Attack(brawler);

	//cleric attacks orc
	//cleric.PickUpWeapon(spear);
	//cleric.EquipWeapon(0);
	//orc.PickUpArmour(glove);
	//orc.Defend(0);
	//cleric.Attack(orc);

	//cleric attacks blackwitch
	//cleric.PickUpWeapon(spear);
	//cleric.EquipWeapon(0);
	//bw1.PickUpArmour(glove);
	//bw1.Defend(0);
	//cleric.Attack(bw1);

	//cleric prays for brawler
	//cleric.PrayFor(brawler);
	//brawler.GetHealth();

	////cleric prays for orc
	//cleric.PrayFor(orc);
	//orc.GetHealth();

	//cleric prays for blackwitch
	//cleric.PrayFor(bw1);
	//bw1.GetHealth();

	//test blackwitch attack functions to ensure opponent health is reduced
	//blackwitch attacks brawler
	//bw1.PickUpWeapon(spear);
	//bw1.EquipWeapon(0);
	//brawler.PickUpArmour(glove);
	//brawler.Defend(0);
	//bw1.Attack(brawler);

	//blackwitch attacks orc
	//bw1.PickUpWeapon(spear);
	//bw1.EquipWeapon(0);
	//orc.PickUpArmour(glove);
	//orc.Defend(0);
	//bw1.Attack(orc);

	//blackwitch attacks cleric
	//bw1.PickUpWeapon(spear);
	//bw1.EquipWeapon(0);
	//cleric.PickUpArmour(glove);
	//cleric.Defend(0);
	//bw1.Attack(cleric);

	//blackwitch bewitch orc
	//bw1.Bewitch(orc);
	//orc.GetState();

	//blackwitch bewitch brawler
	//bw1.Bewitch(brawler);
	//brawler.GetState();

	//blackwitch bewitch cleric
	//bw1.Bewitch(cleric);
	//cleric.GetState();

	//test orc attack functions to ensure opposite characters health is being reduced
	//orc attacks brawler
	//orc.PickUpWeapon(spear);
	//orc.EquipWeapon(0);
	//brawler.PickUpArmour(glove);
	//brawler.Defend(0);
	//orc.Attack(brawler);

	//orc attacks black witch
	//orc.PickUpWeapon(spear);
	//orc.EquipWeapon(0);
	//bw1.PickUpArmour(glove);
	//bw1.Defend(0);
	//orc.Attack(bw1);

	//orc attacks cleric
	//orc.PickUpWeapon(spear);
	//orc.EquipWeapon(0);
	//cleric.PickUpArmour(glove);
	//cleric.Defend(0);
	//orc.Attack(cleric);

	//orc screams at brawler
	//orc.Scream(brawler);
	//brawler.GetState();

	//orc screams at blackwitch
	//orc.Scream(bw1);
	//bw1.GetState();

	//orc screams at cleric
	//orc.Scream(cleric);
	//cleric.GetState();

    return 0;
}