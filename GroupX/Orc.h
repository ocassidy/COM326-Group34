#pragma once

#include "GameCharacter.h"
#include <string>

#pragma once
class Orc : public GameCharacter {

private:
	int ferociousness_;
	int strength_;

public:
	//Default Constructor
	Orc();

	//Custom Constructor
	Orc(std::string characterName, float health, float weightLimit,
		int weapon, int armour, std::vector<Weapon> weapons, std::vector<Armour> armour, int food, CharacterState state, int ferociousness, int strength);

	virtual bool Attack(GameCharacter &charcter) override;

	void Scream(GameCharacter &charcter);

};
