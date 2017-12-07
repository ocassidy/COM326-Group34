/*
* GameCharacter.cpp
*
* Version information v0.1
* Authors: <Diarmuid Bryson - B00709477 & Ciaran Moore - B00688223
* Date: 07/12/2017
* Description: Implementation for GameCharacter class
* Copyright notice
*/
#include <string>
#include <iostream>
#include <random>
#include <ctime>
#include "GameCharacter.h"
#include "Item.h"
#include "Weapon.h"
#include "Armour.h"
#include "BlackWitch.h"
#include "Brawler.h"
#include "Cleric.h"
#include "Orc.h"



GameCharacter::GameCharacter() {
}

GameCharacter::GameCharacter(std::string characterName, float health, float weightLimit,
	int equippedWeapon, int equippedArmour, std::vector<Weapon> weapons, std::vector<Armour> armour, int food, CharacterState state) :
	characterName_{ characterName }, health_{ health }, weightLimit_{ weightLimit }, equippedWeapon_{ equippedWeapon }, equippedArmour_{ equippedArmour }
	, weapons_{ weapons }, armour_{ armour }, food_{ food }, state_{ state } {
}


GameCharacter::~GameCharacter() {
}

std::string GameCharacter::SetCharacterName(std::string name) {
	characterName_ = name;
}

std::string GameCharacter::GetCharacterName() const {
	return characterName_;
}

void GameCharacter::SetHealth(float health) {
	health_ = health;
}

float GameCharacter::GetHealth() const {
	return health_;
}

void GameCharacter::SetWeightLimit(float weight) {
	weightLimit_ = weight;
}

float GameCharacter::GetWeightLimit() const {
	return weightLimit_;
}


void GameCharacter::SetEquippedWeapon(int eqweapon) {
	equippedWeapon_ = eqweapon;
}

int GameCharacter::GetEquippedWeapon() const {
	return equippedWeapon_;
}

void GameCharacter::SetEquippedArmour(int eqarmour) {
	equippedArmour_ = eqarmour;
}

int GameCharacter::GetEquippedArmour() const {
	return equippedArmour_;
}

void GameCharacter::SetFood(int food) {
	food_ = food;
}

int GameCharacter::GetFood() const {
	return food_;
}

CharacterState GameCharacter::SetState(CharacterState state) {
	state_ = state;
}

CharacterState GameCharacter::GetState() {
	return state_;
}


bool GameCharacter::Attack(GameCharacter &character) {  //attack logic here

	int y; //Weapon health deterioration 
	int x; //attack chance

	std::random_device rd; //generator 1
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0, 100);


	std::random_device rd2; //generator 2
	std::mt19937 gen2(rd2());
	std::uniform_real_distribution<> dis2(10, 20);

	x = dis(gen);
	y = dis2(gen2);


	if (equippedWeapon_ == -1 || health_ <= 20 || character.GetState() == Dead) {
		return false;

	}

	Brawler().Attack;

	if (Weapon().getWeaponHitStrength < Armour().getDefence) {
		if (x > 0 && x <= 20) { //successful attack

			switch (state_) { //determining damage output
			case Defending:
				int newHealth = character.GetHealth() * 0.9;
				character.SetHealth(newHealth);
				break;
			case Sleeping:
				character.SetHealth(0);
				break;
			case Dead:
				//no effect
				break;
			case Walking:
				int newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			case Running:
				int newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			case Idle:
				int newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			}
			int newArmourHealth = character.armour_.at(character.equippedArmour_).getArmourHealth() * 0.9;
			character.armour_.at(character.equippedArmour_).setArmourHealth(newArmourHealth);

			for (std::vector<int>::size_type i = 0; i != weapons_.size(); i++) //removal of Armor if its health is less than or equal to 0
			{
				if (Armour().getArmourHealth() <= 0) {
					armour_.erase(armour_.begin() + i);
					return;
				}
			}
		}
		return true;
	}



	if (x > 20 && x <= 100) { //unsuccessful attack + no damage
		double WepHealth = Weapon().getWeaponHealth;
		double removal = WepHealth / 100 * y;
		double newHealth = WepHealth - removal;
		int newHP = newHealth; //rounding the double value down to int so it can be passed through without error
		Weapon().setWeaponHealth(newHP);


		for (std::vector<int>::size_type i = 0; i != weapons_.size(); i++) //removal of weapon if its health is less than or equal to 0
		{
			if (Weapon().getWeaponHealth() <= 0) {
				weapons_.erase(weapons_.begin() + i);
				return;
			}
		}

		return true;
	}


	if (Weapon().getWeaponHitStrength >= Armour().getDefence)
	{
		if (x > 0 && x <= 60) { //successful attack

			switch (state_) { //determining damage output
			case Defending:
				int newHealth = character.GetHealth() * 0.9;
				character.SetHealth(newHealth);
				break;
			case Sleeping:
				character.SetHealth(0);
				break;
			case Dead:
				//no effect
			case Walking:
				int newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			case Running:
				int newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			case Idle:
				int newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			}
			int newArmourHealth = character.armour_.at(character.equippedArmour_).getArmourHealth() * 0.9;
			character.armour_.at(character.equippedArmour_).setArmourHealth(newArmourHealth);

			for (std::vector<int>::size_type i = 0; i != weapons_.size(); i++) //removal of Armor if its health is less than or equal to 0
			{
				if (Armour().getArmourHealth() <= 0) {
					armour_.erase(armour_.begin() + i);
					return;
				}
			}
			return true;
		}

	}

		if (x > 60 && x <= 100) { //unsuccessful attack + no damage
			double WepHealth = Weapon().getWeaponHealth;
			double removal = WepHealth / 100 * y;
			double newHealth = WepHealth - removal;
			int newHP = newHealth; //rounding the double value down to int so it can be passed through without error
			Weapon().setWeaponHealth(newHP);

			for (std::vector<int>::size_type i = 0; i != weapons_.size(); i++) //removal of weapon if its health is less than or equal to 0
			{
				if (Weapon().getWeaponHealth() <= 0) {
					weapons_.erase(weapons_.begin() + i);
					return;
				}
			}
			return true;
		}


		if (character.equippedArmour_ == -1) {

			if (x > 0 && x <= 80) { //successful attack
				switch (state_) { //determining damage output
				case Defending:
					int newHealth = character.GetHealth() * 0.9;
					character.SetHealth(newHealth);
					break;
				case Sleeping:
					character.SetHealth(0);
					break;
				case Dead:
					//no effect
				case Walking:
					int newHealth = character.GetHealth() * 0.8;
					character.SetHealth(newHealth);
					break;
				case Running:
					int newHealth = character.GetHealth() * 0.8;
					character.SetHealth(newHealth);
					break;
				case Idle:
					int newHealth = character.GetHealth() * 0.8;
					character.SetHealth(newHealth);
					break;
				}
			}
			return true;
		}


		if (x > 80 && x <= 100) { //unsuccessful attack + no damage
			double WepHealth = Weapon().getWeaponHealth;
			double removal = WepHealth / 100 * y;
			double newHealth = WepHealth - removal;
			int newHP = newHealth; //rounding the double value down to int so it can be passed through without error
			Weapon().setWeaponHealth(newHP);



			for (std::vector<int>::size_type i = 0; i != weapons_.size(); i++) //removal of weapon if its health is less than or equal to 0
			{
				if (Weapon().getWeaponHealth() <= 0) {
					weapons_.erase(weapons_.begin() + i);
					return;
				}
			}

			return true;

		}

	}



void GameCharacter::Defend(int armour) {

}

void GameCharacter::Walk() {

}

void GameCharacter::Run() {

}

void GameCharacter::Sleep() {

}

Weapon GameCharacter::GetWeapon(int index) {
	return;
}

Armour GameCharacter::GetArmour(int index) {

}

bool GameCharacter::PickUpWeapon(Weapon &weapon) {

}

bool GameCharacter::PickUpArmour(Armour &Armour) {

}

void GameCharacter::DropItem(Armour &Armour) {

}

void GameCharacter::DropItem(Weapon &weapon) {

}

bool GameCharacter::EquipWeapon(int weapon) {

}

void GameCharacter::AddFood(int amount) {
	food_ = food_ + amount;
}

void GameCharacter::Eat() {
	food_ = (food_ * 0.8);
}
