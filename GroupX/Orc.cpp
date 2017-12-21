/*
* Orc.cpp
*
* Version information v1.0
* Authors: Oisin Cassidy
* Date: 20/12/2017
* Description: Implementation for Orc class
*/

#include "Orc.h"

//default constructor
Orc::Orc() {
}

//custom constructor
Orc::Orc(std::string characterName, float health, float weightLimit, int food, CharacterState state, int ferociousness, int strength) 
	: GameCharacter(characterName, health, weightLimit, food, state), ferociousness_{ ferociousness }, strength_{ strength } {
}

//getters + setters
void Orc::SetFeroiousness(int ferociousness) {
	ferociousness_ = ferociousness;
}

int Orc::GetFeroiousness() const {
	return ferociousness_;
}

void Orc::SetStrength(int strength) {
	strength_ = strength;
}

int Orc::GetStrength() const {
	return strength_;
}

//orc specific attack function
bool Orc::Attack(GameCharacter &character) {
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

//orc specific scream function
void Orc::Scream(GameCharacter &character) {
	
	std::random_device rd; //generator 1
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(1, 100);

	//Chance to set to running
	double hit = 20 + (5 * GetFeroiousness());
	int chance = dis(gen); 

	if (hit >= chance) {
		character.SetState(Running);
	}
	else {
		std::cout << "Failed to apply Scream" << std::endl;
	}
}

void Orc::Sleep() {
	//Orc 15% health increase
	float ohealth = this->GetHealth() * 1.15;
	if (ohealth >= 100.f) {
		ohealth = 100.f;
	}
	else {
		this->SetHealth(ohealth);
	}
}