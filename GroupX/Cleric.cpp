#include "Cleric.h"

Cleric::Cleric() {
}

Cleric::Cleric(std::string characterName, float health, float weightLimit,  int food, CharacterState state, int pietyLevel) 
	: GameCharacter(characterName, health, weightLimit, food, state), pietyLevel_{ pietyLevel } {
}

void Cleric::SetPietyLevel(int pietyLevel) {
	pietyLevel_ = pietyLevel;
}

int Cleric::GetPietyLevel() const {
	return pietyLevel_;
}

bool Cleric::Attack(GameCharacter &character) {
	return true;
}

void Cleric::PrayFor(GameCharacter &character) {
	
	std::random_device rd; //generator 1
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(50, 100);

	//Chance to set to running
	double hit = 50 + (5 * GetPietyLevel());
	int chance = dis(gen);

	if (hit >= chance) {
		character.SetHealth((5 * GetPietyLevel()));
	}
	else {
		std::cout << "Failed to apply Scream" << std::endl;
	}
}

void Cleric::Sleep() {
	//cleric 20% health increase
	float chealth = this->GetHealth() * 1.2;
	if (chealth >= 100.f) {
		chealth = 100.f;
	}
	else {
		this->SetHealth(chealth);
	}
}
