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

};