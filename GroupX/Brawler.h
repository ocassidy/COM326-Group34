#pragma once

#include "GameCharacter.h"
#include <string>

#pragma once
class Brawler : public GameCharacter {

private:
	std::string punchDamage_;
	int strength_;

public:
	//Default Constructor
	Brawler();

	//Custom Constructor
	Brawler(std::string characterName, float health, float weightLimit,
		int weapon, int armour, std::vector<Weapon> weapons, std::vector<Armour> armour, int food, CharacterState state, std::string punchDamage, int strength);

	virtual bool Attack(GameCharacter &charcter) override;

	void Brawl(GameCharacter &charcter);

};