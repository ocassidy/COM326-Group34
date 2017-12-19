/*
* GameCharacter.cpp
*
* Version information v0.1
* Authors: <Diarmuid Bryson - B00709477, Ciaran Moore - B00688223, Oisin Cassidy B00714881
* Date: 07/12/2017
* Description: Implementation for GameCharacter class
* Copyright notice
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

GameCharacter::GameCharacter(std::string characterName, float health, float weightLimit,
	int equippedWeapon, int equippedArmour, std::vector<Weapon> weapons, std::vector<Armour> armour, int food, CharacterState state) :
	characterName_{ characterName }, health_{ health }, weightLimit_{ weightLimit }, equippedWeapon_{ equippedWeapon }, equippedArmour_{ equippedArmour }
	, weapons_{ weapons }, armour_{ armour }, food_{ food }, state_{ state } {
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

void GameCharacter::SetEquippedWeapon(int eqweapon) {
	equippedWeapon_ = eqweapon;
}

int GameCharacter::GetEquippedWeapon() const {
	return equippedWeapon_;
}

void GameCharacter::SetEquippedArmour(int eqarmour) {
	equippedArmour_ = eqarmour;
}

int GameCharacter::GetEquippedArmour() const {
	return equippedArmour_;
}

std::vector<Weapon> GameCharacter::GetWeapons() const
{
	return weapons_;
}

std::vector<Armour> GameCharacter::GetArmour() const
{
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

CharacterState GameCharacter::GetState() {
	return state_;
}

//all above is get / set

bool GameCharacter::Attack(GameCharacter &character) {  //attack logic here

	SetState(Idle); //setting character state to idle

	int chanceOfAttack; //attack chance
	int weaponDeteriation; //Weapon health deterioration 
	
	float newHealth = 0;

	std::random_device rd; //generator 1
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(0, 100);

	std::random_device rd2; //generator 2
	std::mt19937 gen2(rd2());
	std::uniform_real_distribution<float> dis2(10, 20);

	chanceOfAttack = dis(gen);
	weaponDeteriation = dis2(gen2);

	if (equippedWeapon_ == -1 || health_ <= 20 || character.GetState() == Dead) {
		return false;
	}

	if (Weapon().getWeaponHitStrength() < Armour().getDefence()) {
		if (chanceOfAttack > 0 && chanceOfAttack <= 20) { //successful attack

			switch (state_) { //determining damage output
			case Defending:
				newHealth = character.GetHealth() * 0.9;
				character.SetHealth(newHealth);
				break;
			case Sleeping:
				character.SetHealth(0);
				break;
			case Dead:
				//no effect
				break;
			case Walking:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			case Running:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			case Idle:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			}
			float newArmourHealth = character.armour_.at(character.equippedArmour_).getArmourHealth() * 0.9;
			character.armour_.at(character.equippedArmour_).setArmourHealth(newArmourHealth);

			for (std::vector<int>::size_type i = 0; i != weapons_.size(); i++) //removal of Armor if its health is less than or equal to 0
			{
				if (Armour().getArmourHealth() <= 0) {
					armour_.erase(armour_.begin() + i);
				}
			}
		}
		return true;
	}

	if (chanceOfAttack > 20 && chanceOfAttack <= 100) { //unsuccessful attack + no damage
		double WepHealth = Weapon().getWeaponHealth();
		double removal = WepHealth / 100 * weaponDeteriation;
		double newHealth = WepHealth - removal;
		float newHP = newHealth; //rounding the double value down to int so it can be passed through without error
		Weapon().setWeaponHealth(newHP);

		for (std::vector<int>::size_type i = 0; i != weapons_.size(); i++) //removal of weapon if its health is less than or equal to 0
		{
			if (Weapon().getWeaponHealth() <= 0) {
				weapons_.erase(weapons_.begin() + i);
			}
		}
		return true;
	}

	if (Weapon().getWeaponHitStrength() >= Armour().getDefence()) {
		if (chanceOfAttack > 0 && chanceOfAttack <= 60) { //successful attack

			switch (state_) { //determining damage output
			case Defending:
				newHealth = character.GetHealth() * 0.9;
				character.SetHealth(newHealth);
				break;
			case Sleeping:
				character.SetHealth(0);
				break;
			case Dead:
				//no effect
			case Walking:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			case Running:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			case Idle:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			}
			float newArmourHealth = character.armour_.at(character.equippedArmour_).getArmourHealth() * 0.9;
			character.armour_.at(character.equippedArmour_).setArmourHealth(newArmourHealth);

			for (std::vector<int>::size_type i = 0; i != weapons_.size(); i++) //removal of Armor if its health is less than or equal to 0
			{
				if (Armour().getArmourHealth() <= 0) {
					armour_.erase(armour_.begin() + i);
				}
			}
			return true;
		}
	}

	if (chanceOfAttack > 60 && chanceOfAttack <= 100) { //unsuccessful attack + no damage
		double WepHealth = Weapon().getWeaponHealth();
		double removal = WepHealth / 100 * weaponDeteriation;
		double newHealth = WepHealth - removal;
		float newHP = newHealth; //rounding the double value down to int so it can be passed through without error
		Weapon().setWeaponHealth(newHP);

		for (std::vector<int>::size_type i = 0; i != weapons_.size(); i++) //removal of weapon if its health is less than or equal to 0
		{
			if (Weapon().getWeaponHealth() <= 0) {
				weapons_.erase(weapons_.begin() + i);
			}
		}
		return false;
	}

	if (character.equippedArmour_ == -1) {
		if (chanceOfAttack > 0 && chanceOfAttack <= 80) { //successful attack
			switch (state_) { //determining damage output
			case Defending:
				newHealth = character.GetHealth() * 0.9;
				character.SetHealth(newHealth);
				break;
			case Sleeping:
				character.SetHealth(0);
				break;
			case Dead:
				//no effect
			case Walking:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			case Running:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			case Idle:
				newHealth = character.GetHealth() * 0.8;
				character.SetHealth(newHealth);
				break;
			}
		}
		return true;
	}

	if (chanceOfAttack > 80 && chanceOfAttack <= 100) { //unsuccessful attack + no damage
		double WepHealth = Weapon().getWeaponHealth();
		double removal = WepHealth / 100 * weaponDeteriation;
		double newHealth = WepHealth - removal;
		float newHP = newHealth; //rounding the double value down to int so it can be passed through without error
		Weapon().setWeaponHealth(newHP);

		for (std::vector<int>::size_type i = 0; i != weapons_.size(); i++) //removal of weapon if its health is less than or equal to 0
		{
			if (Weapon().getWeaponHealth() <= 0) {
				weapons_.erase(weapons_.begin() + i);
			}
		}
		return false;
	}
}

void GameCharacter::Defend(int armour) { //need to review this

	SetState(Defending); //setting character state to defending

	for (std::vector<int>::size_type i = 0; i != armour_.size(); i++){

		if (armour < armour_.size() && armour >= 0) {
			equippedArmour_ = armour;
		}
		else {
			equippedArmour_ = -1;
		}
	}
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

bool GameCharacter::PickUpWeapon(Weapon &weapon) {

	float totalweight{ 0.0f };
	float wepweight{ 0.0f };
	float armourweight{ 0.0f };

	for (std::vector<int>::size_type i = 0; i != weapons_.size(); i++) {

		wepweight = wepweight + weapons_[i].getWeight();
	}

	for (std::vector<int>::size_type i = 0; i != armour_.size(); i++) {

		armourweight = armourweight + armour_[i].getWeight();
	}

	totalweight = armourweight + wepweight;

	if (totalweight >= GetWeightLimit()) {
		return false;
	}
	else {
		weapons_.push_back(weapon);
		return true;
	}
}

bool GameCharacter::PickUpArmour(Armour &Armour) {

	float totalweight{ 0.0f };
	float wepweight{ 0.0f };
	float armourweight{ 0.0f };

	for (std::vector<int>::size_type i = 0; i != weapons_.size(); i++) {

		wepweight = wepweight + weapons_[i].getWeight();
	}

	for (std::vector<int>::size_type i = 0; i != armour_.size(); i++) {

		armourweight = armourweight + armour_[i].getWeight();
	}

	totalweight = wepweight + armourweight;

	if (totalweight >= GetWeightLimit()) {
		//DropItem(Armour);
		return false;
	}
	else {
		armour_.push_back(Armour);
		return true;	
	}
}

//method which drops the current armour item
void GameCharacter::DropItem(Armour &Armour) {

	for (std::vector<int>::size_type i = 0; i != armour_.size(); i++) {
		if (Armour.getItemName() == armour_[i].getItemName()) {
			if (Armour.getWeight() == armour_[i].getWeight()) {
				if (Armour.getItemValue() == armour_[i].getItemValue())	{
					armour_.erase(armour_.begin() + i);
					return;
				}
			}
		}
	}
	//	value weight name
}

//method which drops the current weapon item
void GameCharacter::DropItem(Weapon &weapon) {

	for (std::vector<int>::size_type i = 0; i != weapons_.size(); i++) {

		if (weapon.getItemName() == weapons_[i].getItemName()) {
			if (weapon.getWeight() == weapons_[i].getWeight()) {
				if (weapon.getItemValue() == weapons_[i].getItemValue()) {
					weapons_.erase(weapons_.begin() + i);
					return;
				}

			}
		}
	}
}

bool GameCharacter::EquipWeapon(int weapon) { //like defend / need to review with unit tests
	for (std::vector<int>::size_type i = 0; i != weapons_.size(); i++) {

		if (weapon < weapons_.size() && weapon > -1) {
			equippedWeapon_ = weapon;
			return true;
		}
		else {
			equippedWeapon_ = -1;
			return false;
		}
	}
}

void GameCharacter::AddFood(int amount) {
	food_ = food_ + amount;
}

void GameCharacter::Eat() {

	float foodate = food_ * 0.2;
	food_ = (food_ - foodate);
	float addhealth = foodate * 0.25;

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
