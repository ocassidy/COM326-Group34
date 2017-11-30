#include "BlackWitch.h"

BlackWitch::BlackWitch(){
}

BlackWitch::BlackWitch(std::string characterName, float health, float weightLimit, int equippedWeapon, int equippedArmour, std::vector<Weapon> weapons, std::vector<Armour> armour, int food, CharacterState state, std::string magicProficiency, int darkPower) : GameCharacter(characterName,  health, weightLimit,
	weapon, armour, weapons, armour, food, state), magicProficiency_{ magicProficiency }, darkPower_{ darkPower }  {

}



bool BlackWitch::Attack(GameCharacter & charcter){
	return false;
}

void BlackWitch::Bewitch(GameCharacter & charcter){
}