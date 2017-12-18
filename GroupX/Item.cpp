/*
* BlackWitch.h
*
* Version information v1.0
* Authors: Ciaran Moore
* Date: 07/12/2017
* Description: .cpp file for BlackWitch class
* Copyright notice
*/

#include "Item.h"
#include <string>

Item::Item () {
}

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