/*
* Cleric.h
*
* Version information v0.1
* Authors: Oisin Cassidy
* Date: 30/11/2017
* Description: header file for Cleric class
* Copyright notice
*/
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
		int equippedWeapon, int equippedArmour, std::vector<Weapon> weapons, std::vector<Armour> armour, int food, CharacterState state, int pietyLevel);

	void PrayFor(GameCharacter &charcter);

};
