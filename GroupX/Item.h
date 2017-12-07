#pragma once

#include <string>


class Item {

private:
	std::string itemName_;
	int itemValue_;
	float weight_;

public:
	//Default Constructor
	Item();

	//Custom Constructor
	Item(std::string itemName, int itemValue, float weight);

	//get + set itemname
	void setItemName(std::string itemName);
	std::string getItemName();

	//get + set itemValue
	void setItemValue(int itemValue);
	int getItemValue();

	//get + set weight
	void setWeight(float weight);
	float getWeight();


};