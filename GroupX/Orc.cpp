#include "Orc.h"

Orc::Orc(){
}

Orc::Orc(std::string characterName, float health, float weightLimit, int equippedWeapon, int equippedArmour, std::vector<Weapon> weapons, std::vector<Armour> armour, int food, CharacterState state, int ferociousness, int strength) : GameCharacter(characterName, health, weightLimit,
	weapon, armour, weapons, armour, food, state), ferociousness_{ ferociousness }, strength_{ strength } {
}

bool Orc::Attack(GameCharacter & charcter){
	return false;
}

void Orc::Scream(GameCharacter & charcter){
}
