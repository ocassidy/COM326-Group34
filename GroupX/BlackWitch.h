#pragma once

#include "GameCharacter.h"
#include <string>

#pragma once
class BlackWitch : public GameCharacter {

private:
	std::string magicProficiency_;
	int darkPower_;

public:
	//Default Constructor
	BlackWitch();

	//Custom Constructor
	BlackWitch(std::string characterName, float health, float weightLimit,
		int equippedWeapon, int equippedArmour, std::vector<Weapon> weapons, std::vector<Armour> armour, int food, CharacterState state, std::string magicProficiency, int darkPower);

	virtual bool Attack(GameCharacter &charcter) override;

	void Bewitch(GameCharacter &charcter);

};