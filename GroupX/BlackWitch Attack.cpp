//bool BlackWitch::Attack(GameCharacter &character) {
//	this->SetState(Idle); //setting character state to idle
//
//	double y; //Weapon health deterioration
//	float x; //attack chance
//	float newHealth = 0.0f;
//
//	std::random_device rd; //generator 1
//	std::mt19937 gen(rd());
//	std::uniform_real_distribution<float> dis(0, 100);
//
//	std::random_device rd2; //generator 2
//	std::mt19937 gen2(rd2());
//	std::uniform_real_distribution<double> dis2(10, 20);
//
//	x = dis(gen);
//	y = dis2(gen2);
//
//	if (GetEquippedWeapon() == -1 || GetHealth() <= 20 || character.GetState() == Dead) {
//		return false;
//	}
//	if (GetDarkPower() == 100) {
//		if (this->GetWeapons().at(this->GetEquippedWeapon()).getWeaponHitStrength() < character.GetArmour().at(character.GetEquippedArmour()).getDefence()) {
//			if (x > 0 && x <= 20) { //successful attack
//
//				switch (character.GetState()) { //determining damage output
//				case Defending:
//					newHealth = character.GetHealth() * 0.72f;
//					character.SetHealth(newHealth);
//					break;
//				case Sleeping:
//					character.SetHealth(0.0f);
//					break;
//				case Dead:
//					//no effect
//					break;
//				case Walking:
//					newHealth = character.GetHealth() * 0.64f;
//					character.SetHealth(newHealth);
//					break;
//				case Running:
//					newHealth = character.GetHealth() * 0.64f;
//					character.SetHealth(newHealth);
//					break;
//				case Idle:
//					newHealth = character.GetHealth() * 0.64f;
//					character.SetHealth(newHealth);
//					break;
//				}
//				double newArmourHealth = character.GetArmour().at(character.GetEquippedArmour()).getArmourHealth() * 0.9;
//				character.GetArmour().at(character.GetEquippedArmour()).setArmourHealth((int)newArmourHealth);
//
//				for (std::vector<int>::size_type i = 0; i != GetWeapons().size(); i++) //removal of Armor if its health is less than or equal to 0
//				{
//					if (Armour().getArmourHealth() <= 0) {
//						GetArmour().erase(GetArmour().begin() + i);
//						return true;
//					}
//				}
//			}
//			return true;
//		}
//
//		if (x > 20 && x <= 100) { //unsuccessful attack + no damage
//			double WepHealth = Weapon().getWeaponHealth();
//			double removal = WepHealth / 100 * y;
//			double newHealth = WepHealth - removal;
//			double newHP = newHealth; //rounding the double value down to int so it can be passed through without error
//			Weapon().setWeaponHealth((int)newHP);
//
//
//			for (std::vector<int>::size_type i = 0; i != GetWeapons().size(); i++) //removal of weapon if its health is less than or equal to 0
//			{
//				if (Weapon().getWeaponHealth() <= 0) {
//					GetWeapons().erase(GetWeapons().begin() + i);
//					return true;
//				}
//			}
//			return true;
//		}
//
//		if (this->GetWeapons().at(this->GetEquippedWeapon()).getWeaponHitStrength() < character.GetArmour().at(character.GetEquippedArmour()).getDefence())
//		{
//			if (x > 0 && x <= 60) { //successful attack
//
//				switch (character.GetState()) { //determining damage output
//				case Defending:
//					newHealth = character.GetHealth() * 0.72f;
//					character.SetHealth(newHealth);
//					break;
//				case Sleeping:
//					character.SetHealth(0.0f);
//					break;
//				case Dead:
//					//no effect
//					break;
//				case Walking:
//					newHealth = character.GetHealth() * 0.64f;
//					character.SetHealth(newHealth);
//					break;
//				case Running:
//					newHealth = character.GetHealth() * 0.64f;
//					character.SetHealth(newHealth);
//					break;
//				case Idle:
//					newHealth = character.GetHealth() * 0.64f;
//					character.SetHealth(newHealth);
//					break;
//				}
//				double newArmourHealth = character.GetArmour().at(character.GetEquippedArmour()).getArmourHealth() * 0.9;
//				character.GetArmour().at(character.GetEquippedArmour()).setArmourHealth((int)newArmourHealth);
//
//				for (std::vector<int>::size_type i = 0; i != character.GetWeapons().size(); i++) //removal of weapon if its health is less than or equal to 0
//				{
//					if (Weapon().getWeaponHealth() <= 0) {
//						character.GetWeapons().erase(character.GetWeapons().begin() + i);
//						return true;
//					}
//				}
//				return true;
//			}
//		}
//
//		if (x > 60 && x <= 100) { //unsuccessful attack + no damage
//			double WepHealth = Weapon().getWeaponHealth();
//			double removal = WepHealth / 100 * y;
//			double newHealth = WepHealth - removal;
//			double newHP = newHealth; //rounding the double value down to int so it can be passed through without error
//			Weapon().setWeaponHealth((int)newHP);
//
//			for (std::vector<int>::size_type i = 0; i != GetWeapons().size(); i++) //removal of weapon if its health is less than or equal to 0
//			{
//				if (Weapon().getWeaponHealth() <= 0) {
//					GetWeapons().erase(GetWeapons().begin() + i);
//					return true;
//				}
//			}
//			return true;
//		}
//
//		if (character.GetEquippedArmour() == -1) {
//
//			if (x > 0 && x <= 80) { //successful attack
//				switch (character.GetState()) { //determining damage output
//				case Defending:
//					newHealth = character.GetHealth() * 0.72f;
//					character.SetHealth(newHealth);
//					break;
//				case Sleeping:
//					character.SetHealth(0.0f);
//					break;
//				case Dead:
//					//no effect
//					break;
//				case Walking:
//					newHealth = character.GetHealth() * 0.64f;
//					character.SetHealth(newHealth);
//					break;
//				case Running:
//					newHealth = character.GetHealth() * 0.64f;
//					character.SetHealth(newHealth);
//					break;
//				case Idle:
//					newHealth = character.GetHealth() * 0.64f;
//					character.SetHealth(newHealth);
//					break;
//				}
//			}
//			return true;
//		}
//
//		if (x > 80 && x <= 100) { //unsuccessful attack + no damage
//			double WepHealth = Weapon().getWeaponHealth();
//			double removal = WepHealth / 100 * y;
//			double newHealth = WepHealth - removal;
//			double newHP = newHealth; //rounding the double value down to int so it can be passed through without error
//			Weapon().setWeaponHealth((int)newHP);
//
//			for (std::vector<int>::size_type i = 0; i != GetWeapons().size(); i++) //removal of weapon if its health is less than or equal to 0
//			{
//				if (Weapon().getWeaponHealth() <= 0) {
//					GetWeapons().erase(GetWeapons().begin() + i);
//					return true;
//				}
//			}
//			return true;
//		}
//	}
//	//End of darkPower check attack
//
//	if (this->GetWeapons().at(this->GetEquippedWeapon()).getWeaponHitStrength() < character.GetArmour().at(character.GetEquippedArmour()).getDefence()) {
//		if (x > 0 && x <= 20) { //successful attack
//
//			switch (character.GetState()) { //determining damage output
//			case Defending:
//				newHealth = character.GetHealth() * 0.72f;
//				character.SetHealth(newHealth);
//				break;
//			case Sleeping:
//				character.SetHealth(0.0f);
//				break;
//			case Dead:
//				//no effect
//				break;
//			case Walking:
//				newHealth = character.GetHealth() * 0.64f;
//				character.SetHealth(newHealth);
//				break;
//			case Running:
//				newHealth = character.GetHealth() * 0.64f;
//				character.SetHealth(newHealth);
//				break;
//			case Idle:
//				newHealth = character.GetHealth() * 0.64f;
//				character.SetHealth(newHealth);
//				break;
//			}
//			double newArmourHealth = character.GetArmour().at(character.GetEquippedArmour()).getArmourHealth() * 0.9;
//			character.GetArmour().at(character.GetEquippedArmour()).setArmourHealth((int)newArmourHealth);
//
//			for (std::vector<int>::size_type i = 0; i != GetWeapons().size(); i++) //removal of Armor if its health is less than or equal to 0
//			{
//				if (Armour().getArmourHealth() <= 0) {
//					GetArmour().erase(GetArmour().begin() + i);
//					return true;
//				}
//			}
//		}
//		return true;
//	}
//
//	if (x > 20 && x <= 100) { //unsuccessful attack + no damage
//		double WepHealth = Weapon().getWeaponHealth();
//		double removal = WepHealth / 100 * y;
//		double newHealth = WepHealth - removal;
//		double newHP = newHealth; //rounding the double value down to int so it can be passed through without error
//		Weapon().setWeaponHealth((int)newHP);
//
//
//		for (std::vector<int>::size_type i = 0; i != GetWeapons().size(); i++) //removal of weapon if its health is less than or equal to 0
//		{
//			if (Weapon().getWeaponHealth() <= 0) {
//				GetWeapons().erase(GetWeapons().begin() + i);
//				return true;
//			}
//		}
//		return true;
//	}
//
//	if (this->GetWeapons().at(this->GetEquippedWeapon()).getWeaponHitStrength() < character.GetArmour().at(character.GetEquippedArmour()).getDefence())
//	{
//		if (x > 0 && x <= 60) { //successful attack
//
//			switch (character.GetState()) { //determining damage output
//			case Defending:
//				newHealth = character.GetHealth() * 0.72f;
//				character.SetHealth(newHealth);
//				break;
//			case Sleeping:
//				character.SetHealth(0.0f);
//				break;
//			case Dead:
//				//no effect
//				break;
//			case Walking:
//				newHealth = character.GetHealth() * 0.64f;
//				character.SetHealth(newHealth);
//				break;
//			case Running:
//				newHealth = character.GetHealth() * 0.64f;
//				character.SetHealth(newHealth);
//				break;
//			case Idle:
//				newHealth = character.GetHealth() * 0.64f;
//				character.SetHealth(newHealth);
//				break;
//			}
//			double newArmourHealth = character.GetArmour().at(character.GetEquippedArmour()).getArmourHealth() * 0.9;
//			character.GetArmour().at(character.GetEquippedArmour()).setArmourHealth((int)newArmourHealth);
//
//			for (std::vector<int>::size_type i = 0; i != character.GetWeapons().size(); i++) //removal of weapon if its health is less than or equal to 0
//			{
//				if (Weapon().getWeaponHealth() <= 0) {
//					character.GetWeapons().erase(character.GetWeapons().begin() + i);
//					return true;
//				}
//			}
//			return true;
//		}
//	}
//
//	if (x > 60 && x <= 100) { //unsuccessful attack + no damage
//		double WepHealth = Weapon().getWeaponHealth();
//		double removal = WepHealth / 100 * y;
//		double newHealth = WepHealth - removal;
//		double newHP = newHealth; //rounding the double value down to int so it can be passed through without error
//		Weapon().setWeaponHealth((int)newHP);
//
//		for (std::vector<int>::size_type i = 0; i != GetWeapons().size(); i++) //removal of weapon if its health is less than or equal to 0
//		{
//			if (Weapon().getWeaponHealth() <= 0) {
//				GetWeapons().erase(GetWeapons().begin() + i);
//			}
//		}
//		return true;
//	}
//
//	if (character.GetEquippedArmour() == -1) {
//
//		if (x > 0 && x <= 80) { //successful attack
//			switch (character.GetState()) { //determining damage output
//			case Defending:
//				newHealth = character.GetHealth() * 0.72f;
//				character.SetHealth(newHealth);
//				break;
//			case Sleeping:
//				character.SetHealth(0.0f);
//				break;
//			case Dead:
//				//no effect
//				break;
//			case Walking:
//				newHealth = character.GetHealth() * 0.64f;
//				character.SetHealth(newHealth);
//				break;
//			case Running:
//				newHealth = character.GetHealth() * 0.64f;
//				character.SetHealth(newHealth);
//				break;
//			case Idle:
//				newHealth = character.GetHealth() * 0.64f;
//				character.SetHealth(newHealth);
//				break;
//			}
//		}
//		return true;
//	}
//
//	if (x > 80 && x <= 100) { //unsuccessful attack + no damage
//		double WepHealth = Weapon().getWeaponHealth();
//		double removal = WepHealth / 100 * y;
//		double newHealth = WepHealth - removal;
//		double newHP = newHealth; //rounding the double value down to int so it can be passed through without error
//		Weapon().setWeaponHealth((int)newHP);
//
//		for (std::vector<int>::size_type i = 0; i != GetWeapons().size(); i++) //removal of weapon if its health is less than or equal to 0
//		{
//			if (Weapon().getWeaponHealth() <= 0) {
//				GetWeapons().erase(GetWeapons().begin() + i);
//				return true;
//			}
//		}
//		return true;
//	}
//}