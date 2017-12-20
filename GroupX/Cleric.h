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
#include "Weapon.h"
#include "Item.h"
#include "Armour.h"
#include <string>
#include <iostream>
#include <random>
#include <vector>

class Cleric : public GameCharacter {

private:
	int pietyLevel_;

public:
	//Default Constructor
	Cleric();

	//Custom Constructor
	Cleric(std::string characterName, float health, float weightLimit,
		 int food, CharacterState state, int pietyLevel);

	void SetPietyLevel(int pietyLevel);
	int GetPietyLevel() const;

	virtual bool Attack(GameCharacter &character) override;

	void PrayFor(GameCharacter &character);

	virtual void Sleep();
};
