/*
* Brawler.h
*
* Version information v0.1
* Authors: Oisin Cassidy
* Date: 30/11/2017
* Description: header file for Brawler class
* Copyright notice
*/
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
		int equippedWeapon, int equippedArmour, std::vector<Weapon> weapons, std::vector<Armour> armour, int food, CharacterState state, std::string punchDamage, int strength);

	void SetP

	virtual bool Attack(GameCharacter &charcter) override;

	void Brawl(GameCharacter &charcter);

};