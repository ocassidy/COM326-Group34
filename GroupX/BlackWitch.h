/*
* BlackWitch.h
*
* Version information v0.1
* Authors: Oisin Cassidy
* Date: 30/11/2017
* Description: header file for BlackWitch class
* Copyright notice
*/

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

	void SetMagicProficiency(std::string magicProficiency);
	std::string GetMagicProficiency() const;

	virtual bool Attack(GameCharacter &charcter) override;

	void Bewitch(GameCharacter &charcter);

};