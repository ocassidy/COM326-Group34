/*
* GameCharacter.h
*
* Version information v0.1
* Authors: <Insert group member names and IDs> of student(s) who write each class
* Date: 24/11/2017
* Description: header file for GameCharacter class
* Copyright notice
*/
#include "CharacterState.h"
#include <string>
#include <vector>

#pragma once
class GameCharacter {

private:
	std::string characterName_;
	float health_;
	float weightLimit_;
	int weapon_;
	int armour_;
	std::vector<Weapon> weapons_;
	std::vector<Armour> armour_;
	int food_;
	CharacterState state_;

public:
	//Default Constructor
	GameCharacter();

	//Custom Constructor
	GameCharacter(std::string characterName, float health, float weightLimit, 
		int weapon, int armour, std::vector<Weapon> weapons, std::vector<Armour> armour, int food, CharacterState state);

	~GameCharacter();

	std::string SetCharacterName(std::string name);

	std::string GetCharacterName() const;

	void SetHealth(float health);

	float GetHealth() const;

	void SetWeightLimit(float weight);

	float GetWeightLimit() const;

	void SetWeapon(int weapon);

	int GetWeapon() const;

	void SetArmour(int armour);

	int GetArmour() const;

	void SetWeapons(std::vector<Weapon> weapons);

	std::vector<Weapon> GetWeapons() const;

	void SetArmours(std::vector<Armour> armours);

	std::vector<Armour> GetArmour() const;

	void SetFood(int food);

	int GetFood() const;

	CharacterState SetState(CharacterState state);

	CharacterState GetState();

	virtual bool Attack(GameCharacter &character);

	void Defend(int armour);

	void Walk();

	void Run();

	virtual void Sleep();

	Weapon GetWeapon(int index);

	Armour GetArmour(int index);

	virtual bool PickUpWeapon(Weapon &weapon);

	virtual bool PickUpArmour(Armour &Armour);

	void DropItem(Armour &Armour);

	void DropItem(Weapon &weapon);

	bool EquipWeapon(int weapon);

	void AddFood(int amount);

	virtual void Eat();

};