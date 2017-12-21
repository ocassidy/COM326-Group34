/*
* Brawler.cpp
*
* Version information v1.0
* Authors: Oisin Cassidy, Ciaran Moore
* Date: 20/12/2017
* Description: Implementation for Brawler class
*/

#include "Brawler.h"

Brawler::Brawler() {
}

Brawler::Brawler(std::string characterName, float health, float weightLimit, int food, CharacterState state, int punchDamage, int strength)
	: GameCharacter(characterName, health, weightLimit, food, state), punchDamage_{ punchDamage }, strength_{ strength } {
}

void Brawler::SetPunchDamage(int punchDamage) {
	punchDamage_ = punchDamage;
}

int Brawler::GetPunchDamage() const {
	return punchDamage_;
}

void Brawler::SetStrength(int strength) {
	strength_ = strength;
}

int Brawler::GetStrength() const {
	return strength_;
}

bool Brawler::Attack(GameCharacter &character) {
	SetState(Idle); //setting character state to idle

	bool hitdetect = false;
	double weaponHealthDeterioration; //Weapon health deterioration 
	float attackChance; //attack chance
	float newHealth = 0;

	weaponHealthDeterioration = WeaponDeteriorationChance();
	attackChance = AttackChance();

	if (this->GetHealth() <= 20 || character.GetState() == Dead) {
		hitdetect = false;
	}
	else if (this->GetEquippedWeapon() == -1) {
		Brawl(character);
		hitdetect = false;
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
				if (attackChance > 60 && attackChance <= 100)  {
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

bool Brawler::Brawl(GameCharacter &character) {
	SetState(Idle); //setting character state to idle

	bool hitdetect = false;
	float attackChance; //attack chance
	float newHealth = 0;

	attackChance = AttackChance();

	if (this->GetHealth() <= 20 || character.GetState() == Dead) {
		hitdetect = false;
	}
	else {
		if (this->GetPunchDamage() < character.GetArmour(character.GetEquippedArmour()).getDefence()) {
			if (attackChance > 0 && attackChance <= 20) {
				hitdetect = true; //successful attack

				switch (character.GetState()) { //determining damage output
				case Defending:
					newHealth = character.GetHealth() * 0.95f;
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
					newHealth = character.GetHealth() * 0.9f;
					character.SetHealth(newHealth);
					break;
				case Running:
					newHealth = character.GetHealth() * 0.9f;
					character.SetHealth(newHealth);
					break;
				case Idle:
					newHealth = character.GetHealth() * 0.9f;
					character.SetHealth(newHealth);
					break;
				}
				double newArmourHealth = character.GetArmour(character.GetEquippedArmour()).getArmourHealth() * 0.95;
				character.GetArmour(character.GetEquippedArmour()).setArmourHealth((int)newArmourHealth);


				//removal of Armor if its health is less than or equal to 0		
				if (character.GetArmour(character.GetEquippedArmour()).getArmourHealth() <= 0) {
					character.DropItem(character.GetArmour(character.GetEquippedArmour()));
					character.SetEquippedArmour(-1);
				}
				if (attackChance > 20 && attackChance <= 100)   //unsuccessful attack
				{
					hitdetect = false;
				}
			}
		}

		else if (this->GetPunchDamage() >= character.GetArmour(character.GetEquippedArmour()).getDefence())
		{
			if (attackChance > 0 && attackChance <= 60) {
				hitdetect = true; //successful attack

				switch (character.GetState()) { //determining damage output
				case Defending:
					newHealth = character.GetHealth() * 0.95f;
					character.SetHealth(newHealth);
					break;
				case Sleeping:
					character.SetHealth(0.0f);
					character.SetState(Dead);
					break;
				case Dead:
					//no effect
				case Walking:
					newHealth = character.GetHealth() * 0.9f;
					character.SetHealth(newHealth);
					break;
				case Running:
					newHealth = character.GetHealth() * 0.9f;
					character.SetHealth(newHealth);
					break;
				case Idle:
					newHealth = character.GetHealth() * 0.9f;
					character.SetHealth(newHealth);
					break;
				}
				double newArmourHealth = character.GetArmour(character.GetEquippedArmour()).getArmourHealth() * 0.95;
				character.GetArmour(character.GetEquippedArmour()).setArmourHealth((int)newArmourHealth);


				//removal of Armor if its health is less than or equal to 0		
				if (character.GetArmour(character.GetEquippedArmour()).getArmourHealth() <= 0) {
					character.DropItem(character.GetArmour(character.GetEquippedArmour()));
					character.SetEquippedArmour(-1);
				}
				if (attackChance > 60 && attackChance <= 100); //unsuccessful attack
				{
					hitdetect = false;
				}
			}
		}

		else if (character.GetEquippedArmour() == -1) {

			if (attackChance > 0 && attackChance <= 80) {
				hitdetect = true;//successful attack
				switch (character.GetState()) { //determining damage output
				case Defending:
					newHealth = character.GetHealth() * 0.95f;
					character.SetHealth(newHealth);
					break;
				case Sleeping:
					character.SetHealth(0.0f);
					character.SetState(Dead);
					break;
				case Dead:
					//no effect
				case Walking:
					newHealth = character.GetHealth() * 0.9f;
					character.SetHealth(newHealth);
					break;
				case Running:
					newHealth = character.GetHealth() * 0.9f;
					character.SetHealth(newHealth);
					break;
				case Idle:
					newHealth = character.GetHealth() * 0.9f;
					character.SetHealth(newHealth);
					break;
				}
			}
		}

		else if (attackChance > 60 && attackChance <= 100) //unsuccessful attack
		{
			hitdetect = false;
		}
	}
	return hitdetect;
}

void Brawler::Sleep() {
	//brawler 20% health increase
	float bhealth = this->GetHealth() * 1.2f;
	if (bhealth >= 100.f) {
		bhealth = 100.f;
	}
	else {
		this->SetHealth(bhealth);
	}
}