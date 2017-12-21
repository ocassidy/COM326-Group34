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

//default constructor
GameCharacter::GameCharacter() {
}

//custom constructor
GameCharacter::GameCharacter(std::string characterName, float health, float weightLimit, int food, CharacterState state) :
	characterName_{ characterName }, health_{ health }, weightLimit_{ weightLimit }, food_{ food }, state_{ state } {
}

//default destructor
GameCharacter::~GameCharacter() {
}

//getters + setters
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

//changes character state to walking
void GameCharacter::Walk() {

	SetState(Walking);
}

//changes character state to running
void GameCharacter::Run() {

	SetState(Running);
}

//sets character state to sleeping
void GameCharacter::Sleep() {

	SetState(Sleeping);
}

Weapon GameCharacter::GetWeapon(int index) {
	return weapons_.at(index); //needs reviewed
}

Armour GameCharacter::GetArmour(int index) {
	return armour_.at(index);
}

//method which calculate if an item being added will exceed weight limit, called in other function
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

//adds a weapon to vector if under weight limit
bool GameCharacter::PickUpWeapon(Weapon &weapon) {

	if (weapon.getWeight() + CalculateTotalWeight(armour_, weapons_) <= this->weightLimit_) {
		weapons_.push_back(weapon);
		return true;
	}
	else {
		return false;
	}
}

//adds armour to vector if under weight limit
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

//equips a weapon from the vector to allow character to attack
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

//sets state to defend and allows character to defend against incoming attacks
void GameCharacter::Defend(int armour) { 

	if (this->GetState() == Dead) {

	}
	else {
		this->SetState(Defending); //setting character state to defending

		if (armour < armour_.size() && armour >= 0) {
			this->equippedArmour_ = armour;
		}
		else {
			this->equippedArmour_ = -1;
		}
	}
}

//adds food for the character
void GameCharacter::AddFood(int amount) {
	food_ = food_ + amount;
}

//consumes food and updates health accordingly
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

//calculates the chance of weapon health being reduced
double GameCharacter::WeaponDeteriorationChance() {
	std::random_device rd; //generator 1
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(0, 100);

	double chance = dis(gen);

	return chance;
}

//calculates the chance of an attack
double GameCharacter::AttackChance() {
	std::random_device rd; //generator 2
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dis(10, 20);

	double chance = dis(gen);

	return chance;
}