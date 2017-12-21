/*
* BlackWitch.cpp
*
* Version information v1.0
* Authors: Oisin Cassidy
* Date: 20/12/2017
* Description: Implementation for BlackWitch class
*/

#include "BlackWitch.h"

BlackWitch::BlackWitch() {
}

BlackWitch::BlackWitch(std::string characterName, float health, float weightLimit, int food, CharacterState state, int magicProficiency, int darkPower)
	: GameCharacter(characterName, health, weightLimit, food, state), magicProficiency_{ magicProficiency }, darkPower_{ darkPower } {
}

void BlackWitch::SetMagicProficiency(int magicProficiency) {
	magicProficiency_ = magicProficiency;
}

int BlackWitch::GetMagicProficiency() const {
	return magicProficiency_;
}

void BlackWitch::SetDarkPower(int darkPower) {
	darkPower_ = darkPower;
}

int BlackWitch::GetDarkPower() const {
	return darkPower_;
}

bool BlackWitch::Attack(GameCharacter &character) {
	SetState(Idle); //setting character state to idle

	bool hitdetect = false;
	double weaponHealthDeterioration; //Weapon health deterioration 
	float attackChance; //attack chance
	float newHealth = 0;

	weaponHealthDeterioration = WeaponDeteriorationChance();
	attackChance = AttackChance();

	if (this->GetEquippedWeapon() == -1 || this->GetHealth() <= 20 || character.GetState() == Dead) {
		hitdetect = false;
	}
	else {
		if (GetDarkPower() >= 100) {
			if (this->GetWeapon(this->GetEquippedWeapon()).getWeaponHitStrength() < character.GetArmour(character.GetEquippedArmour()).getDefence()) {
				if (attackChance > 0 && attackChance <= 20) {
					hitdetect = true; //successful attack

					switch (character.GetState()) { //determining damage output
					case Defending:
						newHealth = character.GetHealth() * 0.7f;
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
						newHealth = character.GetHealth() * 0.6f;
						character.SetHealth(newHealth);
						break;
					case Running:
						newHealth = character.GetHealth() * 0.6f;
						character.SetHealth(newHealth);
						break;
					case Idle:
						newHealth = character.GetHealth() * 0.6f;
						character.SetHealth(newHealth);
						break;
					}
					double newArmourHealth = character.GetArmour(character.GetEquippedArmour()).getArmourHealth() * 0.7;
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

					switch(character.GetState()) { //determining damage output
					case Defending:
						newHealth = character.GetHealth() * 0.7f;
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
						newHealth = character.GetHealth() * 0.6f;
						character.SetHealth(newHealth);
						break;
					case Running:
						newHealth = character.GetHealth() * 0.6f;
						character.SetHealth(newHealth);
						break;
					case Idle:
						newHealth = character.GetHealth() * 0.6f;
						character.SetHealth(newHealth);
						break;
					}
					double newArmourHealth = character.GetArmour(character.GetEquippedArmour()).getArmourHealth() * 0.7;
					character.GetArmour(character.GetEquippedArmour()).setArmourHealth((int)newArmourHealth);


					//removal of Armor if its health is less than or equal to 0		
					if (character.GetArmour(character.GetEquippedArmour()).getArmourHealth() <= 0) {
						character.DropItem(character.GetArmour(character.GetEquippedArmour()));
						character.SetEquippedArmour(-1);
					}
					if (attackChance > 60 && attackChance <= 100) hitdetect = false; {
						this->GetWeapon(this->GetEquippedWeapon()).setWeaponHealth(this->GetWeapon(this->GetEquippedWeapon()).getWeaponHealth() / 100 * weaponHealthDeterioration);
						if (this->GetWeapon(this->GetEquippedWeapon()).getWeaponHealth() <= 0) {
							this->DropItem(this->GetWeapon(this->GetEquippedWeapon()));
							this->SetEquippedWeapon(-1);
						}
					}
					
				}
			}

			else if (character.GetEquippedArmour() == -1) {

				if (attackChance > 0 && attackChance <= 80) {
					hitdetect = true; //successful attack
					switch (character.GetState()) { //determining damage output
					case Defending:
						newHealth = character.GetHealth() * 0.7f;
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
						newHealth = character.GetHealth() * 0.6f;
						character.SetHealth(newHealth);
						break;
					case Running:
						newHealth = character.GetHealth() * 0.6f;
						character.SetHealth(newHealth);
						break;
					case Idle:
						newHealth = character.GetHealth() * 0.6f;
						character.SetHealth(newHealth);
						break;
					}
				}
			}

			else if (attackChance > 60 && attackChance <= 100) hitdetect = false;//unsuccessful attack
			{
				this->GetWeapon(this->GetEquippedWeapon()).setWeaponHealth(this->GetWeapon(this->GetEquippedWeapon()).getWeaponHealth() / 100 * weaponHealthDeterioration);
				if (this->GetWeapon(this->GetEquippedWeapon()).getWeaponHealth() <= 0) {
					this->DropItem(this->GetWeapon(this->GetEquippedWeapon()));
					this->SetEquippedWeapon(-1);
				}
			}
		}
		else if (GetDarkPower() < 100)
		{
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
					if (attackChance > 60 && attackChance <= 100) hitdetect = false;  {
						this->GetWeapon(this->GetEquippedWeapon()).setWeaponHealth(this->GetWeapon(this->GetEquippedWeapon()).getWeaponHealth() / 100 * weaponHealthDeterioration);
						if (this->GetWeapon(this->GetEquippedWeapon()).getWeaponHealth() <= 0) {
							this->DropItem(this->GetWeapon(this->GetEquippedWeapon()));
							this->SetEquippedWeapon(-1);
						}
					}
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

			else if (attackChance > 60 && attackChance <= 100) hitdetect = false; //unsuccessful attack
			{
				this->GetWeapon(this->GetEquippedWeapon()).setWeaponHealth(this->GetWeapon(this->GetEquippedWeapon()).getWeaponHealth() / 100 * weaponHealthDeterioration);
				if (this->GetWeapon(this->GetEquippedWeapon()).getWeaponHealth() <= 0) {
					this->DropItem(this->GetWeapon(this->GetEquippedWeapon()));
					this->SetEquippedWeapon(-1);
				}
			}
		}
		return hitdetect;
	}
}

void BlackWitch::Bewitch(GameCharacter &character) {

	std::random_device rd; //generator 1
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(1, 100);

	//Chance to set to sleeping
	double hit = 10 + (5 * GetMagicProficiency());
	double chance = dis(gen);

	if (hit >= chance) {
		character.SetState(Sleeping);
	}
}

void BlackWitch::Sleep() {
	//increase health by 15%
	float bwhealth = this->GetHealth() * 1.15f;
	if (bwhealth >= 100.f) {
		bwhealth = 100.f;
	}
	else {
		this->SetHealth(bwhealth);
	}
}