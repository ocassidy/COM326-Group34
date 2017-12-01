#include "Brawler.h"

Brawler::Brawler(){
}

Brawler::Brawler(std::string characterName, float health, float weightLimit, int equippedWeapon, int equippedArmour, std::vector<Weapon> weapons, std::vector<Armour> armour, int food, CharacterState state, std::string punchDamage, int strength) : GameCharacter(characterName, health, weightLimit,
	weapon, armour, weapons, armour, food, state), punchDamage_{ punchDamage }, strength_{ strength } {
}

bool Brawler::Attack(GameCharacter & charcter){
	return false;
}

void Brawler::Brawl(GameCharacter & charcter){
}
