/*
* Orc.h
*
* Version information v0.1
* Authors: Oisin Cassidy
* Date: 24/11/2017
* Description: header file for Orc class
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

class Orc : public GameCharacter {

private:
	int ferociousness_;
	int strength_;

public:
	//Default Constructor
	Orc();

	//Custom Constructor
	Orc(std::string characterName, float health, float weightLimit, int food, CharacterState state, int ferociousness, int strength);

	void SetFeroiousness(int ferociousness);
	int GetFeroiousness() const;

	void SetStrength(int strength);
	int GetStrength() const;

	virtual bool Attack(GameCharacter &character) override;

	void Scream(GameCharacter &character);

	virtual void Sleep();

};