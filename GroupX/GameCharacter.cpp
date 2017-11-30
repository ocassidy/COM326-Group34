/*
* GameCharacter.cpp
*
* Version information v0.1
* Authors: <Diarmuid Bryson - B00709477 & Ciaran Moore - 
* Date: 24/11/2017
* Description: Implementation for GameCharacter class
* Copyright notice
*/
#include <string>
#include <iostream>
#include "GameCharacter.h"


GameCharacter::GameCharacter(){
}

GameCharacter::GameCharacter(std::string characterName, float health, float weightLimit,
	int weapon, int armour, std::vector<Weapon> weapons, std::vector<Armour> armour, int food, CharacterState state)
	: characterName_{ characterName }, health_{ health }, weightLimit_{ weightLimit }, weapon_{ weapon }, armour_{ armour }
	, weapons_{ weapons }, armour_{ armour }, food_{ food }, state_{ state }) {}//need to finish this 


GameCharacter::~GameCharacter(){
}

std::string GameCharacter::SetCharacterName(std::string name) {
	characterName_ = name;
}

std::string GameCharacter::GetCharacterName() const {
	return characterName_;
}

void GameCharacter::SetHealth(float health) {
	health_ = health;
}

float GameCharacter::GetHealth() const {
	return health_;
}

void GameCharacter::SetWeightLimit(float weight) {
	weightLimit_ = weight;
}

float GameCharacter::GetWeightLimit() const {
	return weightLimit_;
}

void GameCharacter::SetWeapon(int weapon) {
	weapon_ = weapon;
}

int GameCharacter::GetWeapon() const {
	return weapon_;
}

//void GameCharacter::SetArmour(int armour) {
//	armour_ = armour;
//}
//
//int GameCharacter::GetArmour() const {
//
//}

void GameCharacter::SetFood(int food) {
	food_ = food;
}

int GameCharacter::GetFood() const {
	return food_;
}

CharacterState GameCharacter::SetState(CharacterState state) {
	state_ = state;
}

CharacterState GameCharacter::GetState() {
	return state_;
}

bool GameCharacter::Attack(GameCharacter &character) {

}

void GameCharacter::Defend(int armour) {

}

void GameCharacter::Walk() {
	
}

void GameCharacter::Run() {
	
}

void GameCharacter::Sleep() {

}

Weapon GameCharacter::GetWeapon(int index) {
	return 
}

Armour GameCharacter::GetArmour(int index) {

}

bool GameCharacter::PickUpWeapon(Weapon &weapon) {

}

bool GameCharacter::PickUpArmour(Armour &Armour) {

}

void GameCharacter::DropItem(Armour &Armour) {

}

void GameCharacter::DropItem(Weapon &weapon) {

}

bool GameCharacter::EquipWeapon(int weapon) {

}

void GameCharacter::AddFood(int amount) {
	food_ = food_ + amount;
}

void GameCharacter::Eat() {
	food_ = (food_ * 0.8);
}
