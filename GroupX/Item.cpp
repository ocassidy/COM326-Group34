/*
* Item.cpp
*
* Version information v1.0
* Authors: Ciaran Moore, Chantelle Green
* Date: 07/12/2017
* Description: Implementation for Item class
*/

#include "Item.h"

//default constructor
Item::Item () {
}

//custom constructor
Item::Item(std::string itemName, int itemValue, float weight) : itemName_{ itemName }, itemValue_{ itemValue }, weight_{ weight } {
}

//setters 
void Item::setItemName(std::string itemName) {
	itemName_ = itemName;
}

void Item::setItemValue(int itemValue) {
	itemValue_ = itemValue;
}

void Item::setWeight(float Weight) {
	weight_ = Weight;
}

//getters
std::string Item::getItemName() {
	return itemName_;
}

int Item::getItemValue() {
	return itemValue_;
}

float Item::getWeight() {
	return weight_;
}