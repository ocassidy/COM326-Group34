/*
* GameCharacter.cpp
*
* Version information v0.1
* Authors: Diarmuid Bryson - B00709477, Ciaran Moore - B00688223, Oisin Cassidy B00714881
* Date: 07/12/2017
* Description: Implementation for GameCharacter class
*/

#include "GameCharacter.h"
#include "Item.h"
#include "Weapon.h"
#include "Armour.h"
#include "BlackWitch.h"
#include "Brawler.h"
#include "Cleric.h"
#include "Orc.h"

GameCharacter::GameCharacter() {
}

GameCharacter::GameCharacter(std::string characterName, float health, float weightLimit, int food, CharacterState state) :
	characterName_{ characterName }, health_{ health }, weightLimit_{ weightLimit }, food_{ food }, state_{ state } {
}

GameCharacter::~GameCharacter() {
}

void GameCharacter::SetCharacterName(std::string name) {
	characterName_ = name;
}

std::string GameCharacter::GetCharacterName() const {
	return characterName_;
}

void GameCharacter::SetHealth(float health) {
	health_ = health;

	if (health_ < 1)
	{
		this->SetState(Dead);
	}
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

void GameCharacter::SetEquippedWeapon(int equippedWeapon) {
	equippedWeapon_ = equippedWeapon;
}

int GameCharacter::GetEquippedWeapon() const {
	return equippedWeapon_;
}

void GameCharacter::SetEquippedArmour(int equippedArmour) {
	equippedArmour_ = equippedArmour;
}

int GameCharacter::GetEquippedArmour() const {
	return equippedArmour_;
}

std::vector<Weapon> GameCharacter::GetWeapons() const {
	return weapons_;
}

std::vector<Armour> GameCharacter::GetArmour() const {
	return armour_;
}

void GameCharacter::SetFood(int food) {
	food_ = food;
}

int GameCharacter::GetFood() const {
	return food_;
}

void GameCharacter::SetState(CharacterState state) {
	state_ = state;
}

CharacterState GameCharacter::GetState() const {
	return state_;
}

bool GameCharacter::Attack(GameCharacter &character) {
	return true;
}

void GameCharacter::Walk() {

	SetState(Walking);
}

void GameCharacter::Run() {

	SetState(Running);
}

void GameCharacter::Sleep() {

	SetState(Sleeping);
}

Weapon GameCharacter::GetWeapon(int index) {
	return weapons_.at(index); //needs reviewed
}

Armour GameCharacter::GetArmour(int index) {
	return armour_.at(index);
}

float GameCharacter::CalculateTotalWeight(std::vector<Armour> armour, std::vector<Weapon>weapons) {
	float sumWeight = 0;

	for (int i = 0; i < armour_.size(); i++) {
		sumWeight = sumWeight + armour_[i].getWeight();
	}

	for (int i = 0; i < weapons_.size(); i++) {
		sumWeight = sumWeight + weapons_[i].getWeight();
	}
	return sumWeight;
}

bool GameCharacter::PickUpWeapon(Weapon &weapon) {

	if (weapon.getWeight() + CalculateTotalWeight(armour_, weapons_) <= this->weightLimit_) {
		weapons_.push_back(weapon);
		return true;
	}
	else {
		return false;
	}
}

bool GameCharacter::PickUpArmour(Armour &Armour) {

	if (Armour.getWeight() + CalculateTotalWeight(armour_, weapons_) <= this->weightLimit_) {
		armour_.push_back(Armour);
		return true;
	}
	else {
		return false;
	}
}

//method which drops the current armour item
void GameCharacter::DropItem(Armour &Item) {

	for (int i = 0; i != armour_.size(); i++) {
		if (Item.getItemName() == armour_[i].getItemName()) {
			if (Item.getWeight() == armour_[i].getWeight()) {
				if (Item.getItemValue() == armour_[i].getItemValue()) {
					armour_.erase(armour_.begin() + i);
					return;
				}
			}
		}
	}
}

//method which drops the current weapon item
void GameCharacter::DropItem(Weapon &Item) {

	for (int i = 0; i != weapons_.size(); i++) {
		if (Item.getItemName() == weapons_[i].getItemName()) {
			if (Item.getWeight() == weapons_[i].getWeight()) {
				if (Item.getItemValue() == weapons_[i].getItemValue()) {
					weapons_.erase(weapons_.begin() + i);
					return;
				}
			}
		}
	}
}

bool GameCharacter::EquipWeapon(int weapon) { 
	bool value = false;

	if (weapon < weapons_.size() && weapon >= 0) {
		this->equippedWeapon_ = weapon;
		value = true;
	}
	else {
		this->equippedWeapon_ = -1;
		value = false;
	}
	return value;
}

void GameCharacter::Defend(int armour) { 

	this->SetState(Defending); //setting character state to defending

	if (armour < armour_.size() && armour >= 0) {
		this->equippedArmour_ = armour;
	}
	else {
		this->equippedArmour_ = -1;
	}
}

void GameCharacter::AddFood(int amount) {
	food_ = food_ + amount;
}

void GameCharacter::Eat() {

	float foodate = food_ * 0.2f;
	float value = food_ - foodate;
	food_ = ((int)value);
	float addhealth = foodate * 0.25f;

	if (health_ >= 100.f)
	{
		return;
	}
	else
	{
		health_ = health_ + addhealth;
		if (health_ >= 100.f) {
			health_ = 100;
		}
		else {
			return;
		}
	}
}

double GameCharacter::WeaponDeteriorationChance() {
	std::random_device rd; //generator 1
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(0, 100);

	double chance = dis(gen);

	return chance;
}

double GameCharacter::AttackChance() {
	std::random_device rd; //generator 2
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dis(10, 20);

	double chance = dis(gen);

	return chance;
}