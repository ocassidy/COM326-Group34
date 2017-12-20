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
#include "Weapon.h"
#include "Item.h"
#include "Armour.h"
#include <string>
#include <iostream>
#include <random>
#include <vector>

class Brawler : public GameCharacter {

private:
	int punchDamage_;
	int strength_;

public:
	//Default Constructor
	Brawler();

	//Custom Constructor
	Brawler(std::string characterName, float health, float weightLimit, int food, CharacterState state, int punchDamage, int strength);

	void SetPunchDamage(int punchDamage);
	int GetPunchDamage() const;

	void SetStrength(int strength);
	int GetStrength() const;

	virtual bool Attack(GameCharacter &charcter) override;

	bool Brawl(GameCharacter &charcter);

	virtual void Sleep();

};