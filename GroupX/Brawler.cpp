#include "Brawler.h"

Brawler::Brawler() {
}

Brawler::Brawler(std::string characterName, float health, float weightLimit, int equippedWeapon, int equippedArmour, std::vector<Weapon> weapons, std::vector<Armour> armour, int food, CharacterState state, std::string punchDamage, int strength) : GameCharacter(characterName, health, weightLimit,
	equippedWeapon, equippedArmour, weapons, armour, food, state), punchDamage_{ punchDamage }, strength_{ strength } {
}

void Brawler::SetPunchDamage(std::string punchDamage) {
	punchDamage_ = punchDamage;
}

std::string Brawler::GetPunchDamage() const {
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

	int y; //Weapon health deterioration 
	int x; //attack chance
	int newHealth = 0;

	std::random_device rd; //generator 1
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dis(0, 100);

	std::random_device rd2; //generator 2
	std::mt19937 gen2(rd2());
	std::uniform_real_distribution<double> dis2(10, 20);

	x = dis(gen);
	y = dis2(gen2);

	if (Brawler::GetEquippedWeapon() == -1) {
		Brawl(character);
		return true;
	}
	if (Brawler::GetHealth() <= 20 || Brawler::GetState() == Dead) {
		return false;
	}

	if (Weapon().getWeaponHitStrength() < Armour().getDefence()) {
		if (x > 0 && x <= 20) { //successful attack

			switch (character.GetState()) { //determining damage output
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
			int newArmourHealth = character.GetArmour().at(character.GetEquippedArmour()).getArmourHealth() * 0.9;
			character.GetArmour().at(character.GetEquippedArmour()).setArmourHealth(newArmourHealth);

			for (std::vector<int>::size_type i = 0; i != Brawler::GetWeapons().size(); i++) //removal of Armor if its health is less than or equal to 0
			{
				if (Armour().getArmourHealth() <= 0) {
					Brawler::GetArmour().erase(Brawler::GetArmour().begin() + i);
				}
			}
		}
		return true;
	}

	if (x > 20 && x <= 100) { //unsuccessful attack + no damage
		double WepHealth = Weapon().getWeaponHealth();
		double removal = WepHealth / 100 * y;
		double newHealth = WepHealth - removal;
		int newHP = newHealth; //rounding the double value down to int so it can be passed through without error
		Weapon().setWeaponHealth(newHP);


		for (std::vector<int>::size_type i = 0; i != Brawler::GetWeapons().size(); i++) //removal of weapon if its health is less than or equal to 0
		{
			if (Weapon().getWeaponHealth() <= 0) {
				Brawler::GetWeapons().erase(Brawler::GetWeapons().begin() + i);
			}
		}
		return true;
	}

	if (Weapon().getWeaponHitStrength() >= Armour().getDefence())
	{
		if (x > 0 && x <= 60) { //successful attack

			switch (character.GetState()) { //determining damage output
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
			int newArmourHealth = character.GetArmour().at(character.GetEquippedArmour()).getArmourHealth() * 0.9;
			character.GetArmour().at(character.GetEquippedArmour()).setArmourHealth(newArmourHealth);

			for (std::vector<int>::size_type i = 0; i != Brawler::GetWeapons().size(); i++) //removal of weapon if its health is less than or equal to 0
			{
				if (Weapon().getWeaponHealth() <= 0) {
					Brawler::GetWeapons().erase(Brawler::GetWeapons().begin() + i);
				}
			}
			return true;
		}
	}

	if (x > 60 && x <= 100) { //unsuccessful attack + no damage
		double WepHealth = Weapon().getWeaponHealth();
		double removal = WepHealth / 100 * y;
		double newHealth = WepHealth - removal;
		int newHP = newHealth; //rounding the double value down to int so it can be passed through without error
		Weapon().setWeaponHealth(newHP);

		for (std::vector<int>::size_type i = 0; i != Brawler::GetWeapons().size(); i++) //removal of weapon if its health is less than or equal to 0
		{
			if (Weapon().getWeaponHealth() <= 0) {
				Brawler::GetWeapons().erase(Brawler::GetWeapons().begin() + i);
			}
		}
		return true;
	}

	if (character.GetEquippedArmour() == -1) {

		if (x > 0 && x <= 80) { //successful attack
			switch (character.GetState()) { //determining damage output
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
		int newHP = newHealth; //rounding the double value down to int so it can be passed through without error
		Weapon().setWeaponHealth(newHP);

		for (std::vector<int>::size_type i = 0; i != Brawler::GetWeapons().size(); i++) //removal of weapon if its health is less than or equal to 0
		{
			if (Weapon().getWeaponHealth() <= 0) {
				Brawler::GetWeapons().erase(Brawler::GetWeapons().begin() + i);
			}
		}
		return true;
	}
}

void Brawler::Brawl(GameCharacter &character) {
}
