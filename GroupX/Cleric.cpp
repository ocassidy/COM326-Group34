/*
* Cleric.cpp
*
* Version information v1.0
* Authors: Oisin Cassidy
* Date: 20/12/2017
* Description: Implementation for Cleric class
*/

#include "Cleric.h"

Cleric::Cleric() {
}

Cleric::Cleric(std::string characterName, float health, float weightLimit,  int food, CharacterState state, int pietyLevel) 
	: GameCharacter(characterName, health, weightLimit, food, state), pietyLevel_{ pietyLevel } {
}

void Cleric::SetPietyLevel(int pietyLevel) {
	pietyLevel_ = pietyLevel;
}

int Cleric::GetPietyLevel() const {
	return pietyLevel_;
}

bool Cleric::Attack(GameCharacter &character) {
	SetState(Idle); //setting character state to idle

	bool hitdetect = false;
	double weaponHealthDeterioration; //Weapon health deterioration 
	float attackChance; //attack chance
	float newHealth = 0;

	weaponHealthDeterioration = WeaponDeteriorationChance();
	attackChance = AttackChance();

	if (this->GetEquippedWeapon() == -1 || this->GetHealth() <= 20 || character.GetState() == Dead) {
		hitdetect = false;
		return hitdetect;
	}
	else {
		if (this->GetWeapon(this->GetEquippedWeapon()).getWeaponHitStrength() < character.GetArmour(character.GetEquippedArmour()).getDefence()) {
			if (attackChance > 0 && attackChance <= 20) {
				hitdetect = true; //successful attack

				switch (character.GetState()) { //determining damage output
				case Defending:
					newHealth = character.GetHealth() * 0.9f;
					character.SetHealth(newHealth);
					break;
				case Sleeping:
					character.SetHealth(0.0f);
					character.SetState(Dead);
					break;
				case Dead:
					//no effect
					break;
				case Walking:
					newHealth = character.GetHealth() * 0.8f;
					character.SetHealth(newHealth);
					break;
				case Running:
					newHealth = character.GetHealth() * 0.8f;
					character.SetHealth(newHealth);
					break;
				case Idle:
					newHealth = character.GetHealth() * 0.8f;
					character.SetHealth(newHealth);
					break;
				}
				double newArmourHealth = character.GetArmour(character.GetEquippedArmour()).getArmourHealth() * 0.9;
				character.GetArmour(character.GetEquippedArmour()).setArmourHealth((int)newArmourHealth);


				//removal of Armor if its health is less than or equal to 0		
				if (character.GetArmour(character.GetEquippedArmour()).getArmourHealth() <= 0) {
					character.DropItem(character.GetArmour(character.GetEquippedArmour()));
					character.SetEquippedArmour(-1);
				}
				if (attackChance > 20 && attackChance <= 100)  hitdetect = false; //unsuccessful attack
				{
					this->GetWeapon(this->GetEquippedWeapon()).setWeaponHealth(this->GetWeapon(this->GetEquippedWeapon()).getWeaponHealth() / 100 * weaponHealthDeterioration);
					if (this->GetWeapon(this->GetEquippedWeapon()).getWeaponHealth() <= 0) {
						this->DropItem(this->GetWeapon(this->GetEquippedWeapon()));
						this->SetEquippedWeapon(-1);
					}
				}
			}
		}

		else if (this->GetWeapon(this->GetEquippedWeapon()).getWeaponHitStrength() >= character.GetArmour(character.GetEquippedArmour()).getDefence())
		{
			if (attackChance > 0 && attackChance <= 60) {
				hitdetect = true; //successful attack

				switch (character.GetState()) { //determining damage output
				case Defending:
					newHealth = character.GetHealth() * 0.9f;
					character.SetHealth(newHealth);
					break;
				case Sleeping:
					character.SetHealth(0.0f);
					character.SetState(Dead);
					break;
				case Dead:
					//no effect
				case Walking:
					newHealth = character.GetHealth() * 0.8f;
					character.SetHealth(newHealth);
					break;
				case Running:
					newHealth = character.GetHealth() * 0.8f;
					character.SetHealth(newHealth);
					break;
				case Idle:
					newHealth = character.GetHealth() * 0.8f;
					character.SetHealth(newHealth);
					break;
				}
				double newArmourHealth = character.GetArmour(character.GetEquippedArmour()).getArmourHealth() * 0.9;
				character.GetArmour(character.GetEquippedArmour()).setArmourHealth((int)newArmourHealth);


				//removal of Armor if its health is less than or equal to 0		
				if (character.GetArmour(character.GetEquippedArmour()).getArmourHealth() <= 0) {
					character.DropItem(character.GetArmour(character.GetEquippedArmour()));
					character.SetEquippedArmour(-1);
				}
				if (attackChance > 60 && attackChance <= 100) {
					this->GetWeapon(this->GetEquippedWeapon()).setWeaponHealth(this->GetWeapon(this->GetEquippedWeapon()).getWeaponHealth() / 100 * weaponHealthDeterioration);
					if (this->GetWeapon(this->GetEquippedWeapon()).getWeaponHealth() <= 0) {
						this->DropItem(this->GetWeapon(this->GetEquippedWeapon()));
						this->SetEquippedWeapon(-1);
					}
				}
				hitdetect = false;
			}
		}

		else if (character.GetEquippedArmour() == -1) {

			if (attackChance > 0 && attackChance <= 80) {
				hitdetect = true;//successful attack
				switch (character.GetState()) { //determining damage output
				case Defending:
					newHealth = character.GetHealth() * 0.9f;
					character.SetHealth(newHealth);
					break;
				case Sleeping:
					character.SetHealth(0.0f);
					character.SetState(Dead);
					break;
				case Dead:
					//no effect
				case Walking:
					newHealth = character.GetHealth() * 0.8f;
					character.SetHealth(newHealth);
					break;
				case Running:
					newHealth = character.GetHealth() * 0.8f;
					character.SetHealth(newHealth);
					break;
				case Idle:
					newHealth = character.GetHealth() * 0.8f;
					character.SetHealth(newHealth);
					break;
				}
			}
		}

		else if (attackChance > 60 && attackChance <= 100);//unsuccessful attack
		{
			this->GetWeapon(this->GetEquippedWeapon()).setWeaponHealth(this->GetWeapon(this->GetEquippedWeapon()).getWeaponHealth() / 100 * weaponHealthDeterioration);
			if (this->GetWeapon(this->GetEquippedWeapon()).getWeaponHealth() <= 0) {
				this->DropItem(this->GetWeapon(this->GetEquippedWeapon()));
				this->SetEquippedWeapon(-1);
			}
			hitdetect = false;
		}
	}
	return hitdetect;
}

void Cleric::PrayFor(GameCharacter &character) {
	
	std::random_device rd; //generator 1
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(50, 100);

	//Chance to set to running
	double hit = 50 + (5 * GetPietyLevel());
	int chance = dis(gen);

	if (hit >= chance) {
		character.SetHealth((5 * GetPietyLevel()));
	}
	else {
		std::cout << "Failed to apply Scream" << std::endl;
	}
}

void Cleric::Sleep() {
	//cleric 20% health increase
	float chealth = this->GetHealth() * 1.2;
	if (chealth >= 100.f) {
		chealth = 100.f;
	}
	else {
		this->SetHealth(chealth);
	}
}
