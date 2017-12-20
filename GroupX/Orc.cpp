#include "Orc.h"

Orc::Orc() {
}

Orc::Orc(std::string characterName, float health, float weightLimit, int food, CharacterState state, int ferociousness, int strength) 
	: GameCharacter(characterName, health, weightLimit, food, state), ferociousness_{ ferociousness }, strength_{ strength } {
}

void Orc::SetFeroiousness(int ferociousness) {
	ferociousness_ = ferociousness;
}

int Orc::GetFeroiousness() const {
	return ferociousness_;
}

void Orc::SetStrength(int strength) {
	strength_ = strength;
}

int Orc::GetStrength() const {
	return strength_;
}

bool Orc::Attack(GameCharacter &character) {
	return true;
}

void Orc::Scream(GameCharacter &character) {
	
	std::random_device rd; //generator 1
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(1, 100);

	//Chance to set to running
	double hit = 20 + (5 * GetFeroiousness());
	int chance = dis(gen); 

	if (hit >= chance) {
		character.SetState(Running);
	}
	else {
		std::cout << "Failed to apply Scream" << std::endl;
	}
}

void Orc::Sleep() {
	//Orc 15% health increase
	float ohealth = this->GetHealth() * 1.15;
	if (ohealth >= 100.f) {
		ohealth = 100.f;
	}
	else {
		this->SetHealth(ohealth);
	}
}