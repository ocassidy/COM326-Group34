/*
* GameCharacter.h
*
* Version information v0.1
* Authors: <Insert group member names and IDs> of student(s) who write each class
* Date: 24/11/2017
* Description: header file for GameCharacter class
* Copyright notice
*/

#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <random>
#include <ctime>
#include "Weapon.h"
#include "Item.h"
#include "Armour.h"

enum CharacterState { Idle, Running, Sleeping, Walking, Defending, Dead }; //character states

class GameCharacter {

private:
	std::string characterName_;
	float health_;
	float weightLimit_;
	int equippedWeapon_ = -1;
	int equippedArmour_ = -1;
	std::vector<Weapon> weapons_;
	std::vector<Armour> armour_;
	int food_;
	CharacterState state_;

public:
	//Default Constructor
	GameCharacter();

	//Custom Constructor: possible correction on including equipped armor / weapon
	GameCharacter(std::string characterName, float health, float weightLimit,
		int equippedweapon, int equippedarmour, std::vector<Weapon> weapons, std::vector<Armour> armour, int food, CharacterState state);

	//deconstructor
	~GameCharacter();

	//get and set character name
	void SetCharacterName(std::string name);
	std::string GetCharacterName() const;

	//get and set health
	void SetHealth(float health);
	float GetHealth() const;

	//get and set weight limit
	void SetWeightLimit(float weight);
	float GetWeightLimit() const;

	//equipped wep + armor
	void SetEquippedWeapon(int equippedweapon);
	int GetEquippedWeapon() const;
	void SetEquippedArmour(int equippedarmour);
	int GetEquippedArmour() const;

	//weapon and armor vectors
	std::vector<Weapon> GetWeapons() const;
	std::vector<Armour> GetArmour() const;

	//get and set food
	void SetFood(int food);
	int GetFood() const;

	//get and set character state
	void SetState(CharacterState state);
	CharacterState GetState();

	//attack logic
	virtual bool Attack(GameCharacter &character)=0;

	//character states
	void Defend(int armour);
	void Walk();
	void Run();
	virtual void Sleep();

	//Index of specific weapon and armor
	Weapon GetWeapon(int index);
	Armour GetArmour(int index);

	//pick up weapon and armor logic
	virtual bool PickUpWeapon(Weapon &weapon);
	virtual bool PickUpArmour(Armour &Armour);

	//drop iteam and armor logic
	void DropItem(Armour &Armour);
	void DropItem(Weapon &weapon);

	//changes weapon currently equipped
	bool EquipWeapon(int weapon);

	//add food
	void AddFood(int amount);

	//eats food + adds health
	virtual void Eat();

};