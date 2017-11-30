#pragma once

#include "GameCharacter.h"
#include <string>

#pragma once
class Cleric : public GameCharacter {

private:
	int pietyLevel_;

public:
	//Default Constructor
	Cleric();

	//Custom Constructor
	Cleric(std::string characterName, float health, float weightLimit,
		int weapon, int armour, std::vector<Weapon> weapons, std::vector<Armour> armour, int food, CharacterState state, int pietyLevel);

	void PrayFor(GameCharacter &charcter);

};
