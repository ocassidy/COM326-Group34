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
#include "Weapon.h"
#include "Item.h"
#include "Armour.h"
#include <string>
#include <iostream>
#include <random>
#include <vector>

class BlackWitch : public GameCharacter {

private:
	int magicProficiency_;
	int darkPower_;

public:
	//Default Constructor
	BlackWitch();

	//Custom Constructor
	BlackWitch(std::string characterName, float health, float weightLimit,
		int equippedWeapon, int equippedArmour, std::vector<Weapon> weapons, std::vector<Armour> armour, int food, CharacterState state, int magicProficiency, int darkPower);

	void SetMagicProficiency(int magicProficiency);
	int GetMagicProficiency() const;

	void SetDarkPower(int darkPower);
	int GetDarkPower() const;

	virtual bool Attack(GameCharacter &character) override;

	void Bewitch(GameCharacter &character);

};