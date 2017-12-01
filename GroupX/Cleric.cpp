#include "Cleric.h"

Cleric::Cleric(){
}

Cleric::Cleric(std::string characterName, float health, float weightLimit, int equippedWeapon, int equippedaArmour, std::vector<Weapon> weapons, std::vector<Armour> armour, int food, CharacterState state, int pietyLevel) : GameCharacter(characterName, health, weightLimit,
	weapon, armour, weapons, armour, food, state), pietyLevel_{ pietyLevel } {
}

void Cleric::PrayFor(GameCharacter & charcter){
}
