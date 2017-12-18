#include "Orc.h"

Orc::Orc() {
}

Orc::Orc(std::string characterName, float health, float weightLimit, int equippedWeapon, int equippedArmour, std::vector<Weapon> weapons, std::vector<Armour> armour, int food, CharacterState state, int ferociousness, int strength) : GameCharacter(characterName, health, weightLimit,
	equippedWeapon, equippedArmour, weapons, armour, food, state), ferociousness_{ ferociousness }, strength_{ strength } {
}

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

bool Orc::Attack(GameCharacter &character) {
	SetState(Idle); //setting character state to idle

	int y; //Weapon health deterioration 
	int x; //attack chance
	float newHealth = 0;

	std::random_device rd; //generator 1
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(0, 100);

	std::random_device rd2; //generator 2
	std::mt19937 gen2(rd2());
	std::uniform_real_distribution<float> dis2(10, 20);

	x = dis(gen);
	y = dis2(gen2);

	if (GetEquippedWeapon() == -1 || GetHealth() <= 20 || GetState() == Dead) {
		return false;
	}

	if (Weapon().getWeaponHitStrength() < Armour().getDefence()) {
		if (x > 0 && x <= 20) { //successful attack

			switch (GetState()) { //determining damage output
			case Defending:
				newHealth = character.GetHealth() * 0.9;
				character.SetHealth(newHealth);
				break;
			case Sleeping:
				character.SetHealth(0);
				break;
			case Dead:
				//no effect
				break;
			case Walking:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			case Running:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			case Idle:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			}
			float newArmourHealth = character.GetArmour().at(character.GetEquippedArmour()).getArmourHealth() * 0.9;
			character.GetArmour().at(character.GetEquippedArmour()).setArmourHealth(newArmourHealth);

			for (std::vector<int>::size_type i = 0; i != GetWeapons().size(); i++) //removal of Armor if its health is less than or equal to 0
			{
				if (Armour().getArmourHealth() <= 0) {
					GetArmour().erase(GetArmour().begin() + i);
				}
			}
		}
		return true;
	}

	if (x > 20 && x <= 100) { //unsuccessful attack + no damage
		double WepHealth = Weapon().getWeaponHealth();
		double removal = WepHealth / 100 * y;
		double newHealth = WepHealth - removal;
		float newHP = newHealth; //rounding the double value down to int so it can be passed through without error
		Weapon().setWeaponHealth(newHP);


		for (std::vector<int>::size_type i = 0; i != GetWeapons().size(); i++) //removal of weapon if its health is less than or equal to 0
		{
			if (Weapon().getWeaponHealth() <= 0) {
				GetWeapons().erase(GetWeapons().begin() + i);
			}
		}
		return true;
	}

	if (Weapon().getWeaponHitStrength() >= Armour().getDefence())
	{
		if (x > 0 && x <= 60) { //successful attack

			switch (GetState()) { //determining damage output
			case Defending:
				newHealth = character.GetHealth() * 0.9;
				character.SetHealth(newHealth);
				break;
			case Sleeping:
				character.SetHealth(0);
				break;
			case Dead:
				//no effect
			case Walking:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			case Running:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			case Idle:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			}
			float newArmourHealth = character.GetArmour().at(character.GetEquippedArmour()).getArmourHealth() * 0.9;
			character.GetArmour().at(character.GetEquippedArmour()).setArmourHealth(newArmourHealth);

			for (std::vector<int>::size_type i = 0; i != character.GetWeapons().size(); i++) //removal of weapon if its health is less than or equal to 0
			{
				if (Weapon().getWeaponHealth() <= 0) {
					character.GetWeapons().erase(character.GetWeapons().begin() + i);
				}
			}
			return true;
		}
	}

	if (x > 60 && x <= 100) { //unsuccessful attack + no damage
		double WepHealth = Weapon().getWeaponHealth();
		double removal = WepHealth / 100 * y;
		double newHealth = WepHealth - removal;
		float newHP = newHealth; //rounding the double value down to int so it can be passed through without error
		Weapon().setWeaponHealth(newHP);

		for (std::vector<int>::size_type i = 0; i != GetWeapons().size(); i++) //removal of weapon if its health is less than or equal to 0
		{
			if (Weapon().getWeaponHealth() <= 0) {
				GetWeapons().erase(GetWeapons().begin() + i);
			}
		}
		return true;
	}

	if (character.GetEquippedArmour() == -1) {

		if (x > 0 && x <= 80) { //successful attack
			switch (GetState()) { //determining damage output
			case Defending:
				newHealth = character.GetHealth() * 0.9;
				character.SetHealth(newHealth);
				break;
			case Sleeping:
				character.SetHealth(0);
				break;
			case Dead:
				//no effect
			case Walking:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			case Running:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			case Idle:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			}
		}
		return true;
	}

	if (x > 20 && x <= 100) { //unsuccessful attack + no damage
		double WepHealth = Weapon().getWeaponHealth();
		double removal = WepHealth / 100 * y;
		double newHealth = WepHealth - removal;
		float newHP = newHealth; //rounding the double value down to int so it can be passed through without error
		Weapon().setWeaponHealth(newHP);


		for (std::vector<int>::size_type i = 0; i != Orc::GetWeapons().size(); i++) //removal of weapon if its health is less than or equal to 0
		{
			if (Weapon().getWeaponHealth() <= 0) {
				Orc::GetWeapons().erase(Orc::GetWeapons().begin() + i);
			}
		}
		return true;
	}

	if (Weapon().getWeaponHitStrength() >= Armour().getDefence())
	{
		if (x > 0 && x <= 60) { //successful attack

			switch (Orc::GetState()) { //determining damage output
			case Defending:
				newHealth = character.GetHealth() * 0.9;
				character.SetHealth(newHealth);
				break;
			case Sleeping:
				character.SetHealth(0);
				break;
			case Dead:
				//no effect
			case Walking:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			case Running:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			case Idle:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			}
			float newArmourHealth = character.GetArmour().at(character.GetEquippedArmour()).getArmourHealth() * 0.9;
			character.GetArmour().at(character.GetEquippedArmour()).setArmourHealth(newArmourHealth);

			for (std::vector<int>::size_type i = 0; i != character.GetWeapons().size(); i++) //removal of weapon if its health is less than or equal to 0
			{
				if (Weapon().getWeaponHealth() <= 0) {
					character.GetWeapons().erase(character.GetWeapons().begin() + i);
				}
			}
			return true;
		}
	}

	if (x > 60 && x <= 100) { //unsuccessful attack + no damage
		double WepHealth = Weapon().getWeaponHealth();
		double removal = WepHealth / 100 * y;
		double newHealth = WepHealth - removal;
		float newHP = newHealth; //rounding the double value down to int so it can be passed through without error
		Weapon().setWeaponHealth(newHP);

		for (std::vector<int>::size_type i = 0; i != Orc::GetWeapons().size(); i++) //removal of weapon if its health is less than or equal to 0
		{
			if (Weapon().getWeaponHealth() <= 0) {
				Orc::GetWeapons().erase(Orc::GetWeapons().begin() + i);
			}
		}
		return true;
	}

	if (character.GetEquippedArmour() == -1) {

		if (x > 0 && x <= 80) { //successful attack
			switch (Orc::GetState()) { //determining damage output
			case Defending:
				newHealth = character.GetHealth() * 0.9;
				character.SetHealth(newHealth);
				break;
			case Sleeping:
				character.SetHealth(0);
				break;
			case Dead:
				//no effect
			case Walking:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			case Running:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			case Idle:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			}
		}
		return true;
	}

	if (x > 80 && x <= 100) { //unsuccessful attack + no damage
		double WepHealth = Weapon().getWeaponHealth();
		double removal = WepHealth / 100 * y;
		double newHealth = WepHealth - removal;
		float newHP = newHealth; //rounding the double value down to int so it can be passed through without error
		Weapon().setWeaponHealth(newHP);

		for (std::vector<int>::size_type i = 0; i != Orc::GetWeapons().size(); i++) //removal of weapon if its health is less than or equal to 0
		{
			if (Weapon().getWeaponHealth() <= 0) {
				Orc::GetWeapons().erase(Orc::GetWeapons().begin() + i);
			}
		}
		return true;
	}
}

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