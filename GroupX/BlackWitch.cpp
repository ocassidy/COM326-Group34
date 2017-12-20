#include "BlackWitch.h"

BlackWitch::BlackWitch() {
}

BlackWitch::BlackWitch(std::string characterName, float health, float weightLimit, int food, CharacterState state, int magicProficiency, int darkPower)
	: GameCharacter(characterName, health, weightLimit, food, state), magicProficiency_{ magicProficiency }, darkPower_{ darkPower } {
}

void BlackWitch::SetMagicProficiency(int magicProficiency) {
	magicProficiency_ = magicProficiency;
}

int BlackWitch::GetMagicProficiency() const {
	return magicProficiency_;
}

void BlackWitch::SetDarkPower(int darkPower) {
	darkPower_ = darkPower;
}

int BlackWitch::GetDarkPower() const {
	return darkPower_;
}

bool BlackWitch::Attack(GameCharacter &character) {
	return true;
}

void BlackWitch::Bewitch(GameCharacter &character) {

	std::random_device rd; //generator 1
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(1, 100);

	//Chance to set to sleeping
	double hit = 10 + (5 * GetMagicProficiency());
	double chance = dis(gen);

	if (hit >= chance) {
		character.SetState(Sleeping);
	}
}

void BlackWitch::Sleep() {
	//increase health by 15%
	float bwhealth = this->GetHealth() * 1.15f;
	if (bwhealth >= 100.f) {
		bwhealth = 100.f;
	}
	else {
		this->SetHealth(bwhealth);
	}
}