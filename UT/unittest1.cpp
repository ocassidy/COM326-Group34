#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT
{		

	TEST_CLASS(CharacterManagement)
	{
	public:

		TEST_METHOD(TestBrawlerConstructor)
		{
			//Arrange the data
			std::string expectedName{ "Jim" };
			Brawler brawler{ "Jim", 100.f, 120.f, -1, -1, {}, {},20, Idle, 20, 16 };

			//Act
			std::string characterName = brawler.GetCharacterName();

			//Assert
			Assert::AreEqual(expectedName, characterName);
		}
		TEST_METHOD(TestClericConstructor)
		{
			//Arrange the data
			std::string expectedName{ "Micky" };
			Cleric cleric{ "Micky", 100.f, 120.f, -1, -1,{},{},20, Idle, 16 };

			//Act
			std::string characterName = cleric.GetCharacterName();

			//Assert
			Assert::AreEqual(expectedName, characterName);
		}
		TEST_METHOD(TestBlackWitchConstructor)
		{
			//Arrange the data
			std::string expectedName{ "Marcus" };
			BlackWitch blackwitch{ "Marcus", 100.f, 120.f, -1, -1,{},{},20, Idle, 20, 16 };

			//Act
			std::string characterName = blackwitch.GetCharacterName();

			//Assert
			Assert::AreEqual(expectedName, characterName);
		}
		TEST_METHOD(TestOrcConstructor)
		{
			//Arrange the data
			std::string expectedName{ "Noah" };
			Orc orc{ "Noah", 100.f, 120.f, -1, -1,{},{},20, Idle, 20, 16 };

			//Act
			std::string characterName = orc.GetCharacterName();

			//Assert
			Assert::AreEqual(expectedName, characterName);
		}

		TEST_METHOD(TestEatConsumesFood)
		{
			//Tests that food gets consumed by eat function
			//Arrange the data
			int expectedFood{ 16 }, actualFood;
			Brawler brawler{"Jim", 100.f, 120.f, -1, -1,{},{},20, Idle, 20, 16 };

			//Act
			brawler.Eat();
			actualFood = brawler.GetFood();

			//Assert
			Assert::AreEqual(expectedFood, actualFood);
		}

		TEST_METHOD(AddFood)
		{
			int expectedFood{ 25 }, actualFood;
			Brawler brawler{ "Jim", 100.f, 120.f, -1, -1,{},{},20, Idle, 20, 16 };

			brawler.AddFood(5);
			actualFood = brawler.GetFood();

			Assert::AreEqual(expectedFood, actualFood);

		}

		TEST_METHOD(TestEatIncreasesHealth)
		{

			//	Consumes 20% of the available food. Each unit (1) of food consumed will add 0.25 units of health to the character.
			//Tests that health increases correctly by eat function 
			//Arrange the data
			float expectedHealth{ 51.0f }, actualHealth; //(health should not exceed 100)
			Brawler brawler{ "Jim", 50.f, 120.f, -1, -1,{},{},20, Idle, 20, 16 };

			//Act
			brawler.Eat();
			actualHealth = brawler.GetHealth();

			//Assert
			Assert::AreEqual(expectedHealth, actualHealth);
		}

		TEST_METHOD(TestHealthCapped)
		{
			//Tests that health does not exceed 100 by eat function 
			//Arrange the data
			float expectedHealth{ 100.0f }, actualHealth; //(health should not exceed 100)
			Brawler brawler{ "Jim", 100.f, 120.f, -1, -1,{},{},20, Idle, 20, 16 };

			//Act
			brawler.Eat();
			actualHealth = brawler.GetHealth();

			//Assert
			Assert::AreEqual(expectedHealth, actualHealth);
		}
	};
}


namespace Conflict_UnitTests
{
	TEST_CLASS(Conflict)
	{
	public:
		TEST_METHOD(Defend1)
		{
			//Test that the character enters defending state
			//Arrange the data
			int expectedState{ 4 }, actualState;
			Brawler brawler{ "Jim", 100.f, 120.f, -1, -1,{},{},20, Idle, 20, 16 };

			//Act
			brawler.Defend(1); //invalid index! no armour in vector
			actualState = brawler.GetState();

			//Assert
			Assert::AreEqual(expectedState, actualState);
		}

		TEST_METHOD(Defend2)
		{
			//Test that the character selected armour remains -1 
			//Arrange the data
			int expectedIndex{ -1 }, actualIndex;
			Brawler brawler{ "Jim", 100.f, 120.f, -1, -1,{},{},20, Idle, 20, 16 };

			//Act
			brawler.Defend(0); //invalid index! no armour in vector
			actualIndex = brawler.GetEquippedArmour();

			//Assert
			Assert::AreEqual(expectedIndex, actualIndex);
		}
		TEST_METHOD(BrawlerAttack1)
		{
			//Arrange the data
			int expectedState{ 4 }, actualState;
			Brawler brawler{ "Jim", 100.f, 120.f, -1, -1,{},{},20, Idle, 20, 16 };

			//Act
			brawler.Defend(1); //invalid index! no armour in vector
			actualState = brawler.GetState();

			//Assert
			Assert::AreEqual(expectedState, actualState);
		}
		TEST_METHOD(BrawlerAttack2)
		{
			//Arrange the data		
			float baseHealth;
			float newHealth;
			Cleric cleric{ "Zen", 100.f, 120.f, -1, -1,{},{}, 20, Idle, 16 };
			Brawler brawler{ "Jim", 100.f, 120.f, -1, -1,{},{}, 20, Idle, 20, 16 };
			Weapon spear{ "Spear", 15, 25.f, 200, 6 };

			//Act
			brawler.PickUpWeapon(spear);
			baseHealth = cleric.GetHealth();
			brawler.Attack(cleric);
			cleric.Defend(0);
			newHealth = cleric.GetHealth();

			//Assert
			Assert::AreNotEqual(baseHealth, newHealth);
		}
		TEST_METHOD(BrawlerBrawl)
		{
			//Arrange the data		
			float baseHealth;
			float newHealth;
			Cleric cleric{ "Zen", 100.f, 120.f, -1, -1,{},{}, 20, Idle, 16 };
			Brawler brawler{ "Jim", 100.f, 120.f, -1, -1,{},{}, 20, Idle, 50, 16 };

			//Act
			baseHealth = cleric.GetHealth();
			brawler.Brawl(cleric);
			cleric.Defend(0);
			newHealth = cleric.GetHealth();

			//Assert
			Assert::AreNotEqual(baseHealth, newHealth);
		}
		TEST_METHOD(BrawlerBrawlPassFromAttack)
		{
			//Arrange the data		
			float baseHealth;
			float newHealth;
			Cleric cleric{ "Zen", 100.f, 120.f, -1, -1,{},{}, 20, Idle, 16 };
			Brawler brawler{ "Jim", 100.f, 120.f, -1, -1,{},{}, 20, Idle, 50, 16 };

			//Act
			baseHealth = cleric.GetHealth();
			brawler.Attack(cleric);
			cleric.Defend(0);
			newHealth = cleric.GetHealth();

			//Assert
			Assert::AreNotEqual(baseHealth, newHealth);
		}
		TEST_METHOD(BlackWitchBewitch)
		{
			//Arrange the data		
			int expectedState{ 2 };
			int actualState;
			Cleric cleric{ "Micky", 100.f, 120.f, -1, -1,{},{}, 20, Idle, 16 };
			BlackWitch blackwitch{ "Mark", 100.f, 120.f, -1, -1,{},{}, 20, Idle, 20, 100 };

			//Act
			blackwitch.Bewitch(cleric);
			actualState = cleric.GetState();

			//Assert
			Assert::AreEqual(expectedState, actualState);
		}
		TEST_METHOD(OrcScream)
		{
			//If tests fails Scream function failed to apply, if passed then function successful
			//Arrange the data		
			int expectedState{ 1 };
			int actualState;
			Cleric cleric{ "John", 100.f, 120.f, -1, -1,{},{}, 20, Idle, 16 };
			Orc orc{ "Jim", 100.f, 120.f, -1, -1,{},{}, 20, Idle, 14, 16 };

			//Act
			orc.Scream(cleric);
			actualState = cleric.GetState();

			//Assert
			Assert::AreEqual(expectedState, actualState);
			
		}

		TEST_METHOD(ClericPrayFor)
		{
			//Arrange the data		
			Cleric cleric{ "Sean", 100.f, 120.f, -1, -1,{},{}, 20, Idle, 12 };
			BlackWitch blackwitch{ "Oran", 50.f, 120.f, -1, -1,{},{}, 20, Idle, 20, 100 };

			int intialHealth = blackwitch.GetHealth();

			//Act
			cleric.PrayFor(blackwitch);
			int newHealth = blackwitch.GetHealth();

			//Assert
			Assert::AreNotEqual(intialHealth, newHealth);
		}
	};
}

namespace Inventory_UnitTests {
	TEST_CLASS(InventoryManagement) {
	public:
		TEST_METHOD(TestAddItemWeight) {
			//Test that adding items above weight limit fails
			//Arrange the data
			bool addItemResult;
			//No point initialising vectors as character should start off with no items.
			Brawler brawler{"Jim", 100.f, 120.f, -1, -1, {}, {}, 20, Idle, 20, 16};
			Weapon spear{"Spear", 15, 25.f, 100, 6};
			Armour glove{"Leather glove", 3, 0.25f, 1, 100, ArmourType::Leather};
			Armour chainMail{"Chain Mail", 45, 85.f, 200, 100, ArmourType::Steel};

			//Act
			addItemResult = brawler.PickUpWeapon(spear);
			addItemResult = brawler.PickUpArmour(glove);
			addItemResult = brawler.PickUpArmour(chainMail);

			//Assert - add weapon should be false as the weight exceeds the limit
			Assert::IsFalse(addItemResult);
		}

		TEST_METHOD(TestAddWeaponWeight)
		{
			//Test that adding items above weight limit fails
			//Arrange the data
			bool addWeaponResult;
			//No point initialising vectors as character should start off with no items.
			Brawler brawler{ "Jim", 100.f, 120.f, -1, -1,{},{},20, Idle, 20, 16 };
			Weapon spear{"Spear", 15, 25.f, 100, 6 };
			Weapon bow{"Bow", 25, 25.f, 100, 6 };

			//Act
			addWeaponResult = brawler.PickUpWeapon(spear);
			addWeaponResult = brawler.PickUpWeapon(bow);

			//Assert - add weapon should be false as the weight exceeds
			Assert::IsFalse(addWeaponResult);
		}

		TEST_METHOD(TestAddArmourWeight)
		{
			//Test that adding items above weight limit fails
			//Arrange the data
			int initialWeight, newWeight;
			//No point initialising vectors as character should start off with no items.
			Brawler brawler{ "Jim", 100.f, 100.f, -1, -1,{},{},20, Idle, 20, 16 };
			Armour shield{ "Shield", 40, 80, 100, 100, ArmourType::Leather };
			Armour hat{ "Tinfoil Hat", 2, 21, 21, 100, ArmourType::Cardboard };

			//Act
			initialWeight = brawler.GetWeightLimit();
			brawler.PickUpArmour(shield);
			brawler.PickUpArmour(hat);

			newWeight = shield.getWeight() + hat.getWeight();

			//Assert - add weapon should be false as the weight exceeds
			Assert::IsTrue(brawler.GetWeightLimit() <= 100);
		}

		TEST_METHOD(TestAddWeapons)
		{
			//Arrange the data
			Brawler brawler{"Jim", 100.f, 120.f, -1, -1,{},{},20, Idle, 20, 16};
			Weapon spear{"Spear", 15, 25.f, 100, 6 };
			Weapon bow{"Bow", 25, 22.f, 100, 6};
			Weapon spear2{"Lance of Longinus", 100, 35.f, 200, 35};
			Weapon arrow{"Arrow", 15, 25.f, 100, 6 };

			brawler.PickUpWeapon(spear);
			brawler.PickUpWeapon(bow);
			brawler.PickUpWeapon(spear2);
			brawler.PickUpWeapon(arrow);
			brawler.PickUpWeapon(arrow);
			brawler.PickUpWeapon(arrow);
			brawler.PickUpWeapon(arrow);

			std::string expectedWeaponName{ "Lance of Longinus" };

			//Act
			Weapon tempWeapon = brawler.GetWeapon(2);
			std::string weaponName = tempWeapon.getItemName();

			//Assert
			Assert::AreEqual(expectedWeaponName, weaponName);
		}

		TEST_METHOD(TestDropWeapon)
		{
			//Test Drop weapon
			//Arrange the data
			std::string expectedWeaponName{ "Spear" };
			Brawler brawler{"Jim", 100.f, 120.f, -1, -1,{},{},20, Idle, 20, 16};
			Weapon spear1{"Spear", 15, 25.f, 100, 6 };
			Weapon bow{"Bow", 25, 22.f, 100, 6 };
			Weapon spear2{"Spear", 34, 54.f, 90, 16 };

			brawler.PickUpWeapon(spear1);
			brawler.PickUpWeapon(bow);
			brawler.PickUpWeapon(spear2);

			//Act

			brawler.DropItem(spear2); //Weapon spear2 should be removed not spear2 - same name different attributes!

			Weapon tempWeapon = brawler.GetWeapon(0);
			std::string actualWeaponName = tempWeapon.getItemName();

			//Assert
			Assert::AreEqual(expectedWeaponName, actualWeaponName);
		}

		TEST_METHOD(TestDropArmour)
		{
			//Test Drop weapon
			//Arrange the data
			std::string expectedArmourName{ "Cardboard suit of armour" };
			Brawler brawler{ "Jim", 100.f, 120.f, -1, -1,{},{},20, Idle, 20, 16 };
			Armour shield{ "Shield", 40, 40, 50, 100, ArmourType::Leather };
			Armour hat{ "Tinfoil Hat", 2, 0.5f, 1, 100, ArmourType::Cardboard };
			Armour glove1{ "Leather glove", 1, 0.23f, 1, 100, ArmourType::Leather };
			Armour suit{ "Cardboard suit of armour", 10, 2.0f, 15, 100, ArmourType::Cardboard };
			Armour glove2{ "Leather glove", 1, 0.2f, 1, 75, ArmourType::Leather };

			brawler.PickUpArmour(shield);
			brawler.PickUpArmour(hat);
			brawler.PickUpArmour(glove1);
			brawler.PickUpArmour(suit);
			brawler.PickUpArmour(glove2);

			//Act
			brawler.DropItem(glove1); //Weapon spear2 should be removed not spear2 - same name different attributes!

			Armour tempArmour = brawler.GetArmour(2);
			std::string actualArmourName = tempArmour.getItemName();

			//Assert
			Assert::AreEqual(expectedArmourName, actualArmourName);
		}

		TEST_METHOD(TestArmourConstructor)
		{
			std::string expectedName = "Shield";
			Armour armour1{ "Shield", 30, 40, 60, 50, ArmourType::Iron };

			std::string actualName = armour1.getItemName();

			Assert::AreEqual(expectedName, actualName);
		}

		TEST_METHOD(TestWeaponConstructor)
		{
			std::string expectedName = "Sword";
			Weapon sword1{ "Sword", 56, 30.0f, 60, 70 };

			std::string actualName = sword1.getItemName();

			Assert::AreEqual(expectedName, actualName);
		}
	};
}