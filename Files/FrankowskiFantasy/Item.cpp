#include"stdafx.h"
#include "Item.h"


Item::Item() : used(false), weared(false) {}


Item::~Item()
{
}


void Item::SetPrice(int a)
{
	price = a;
}
int Item::GetPrice()
{
	return price;
}
void Item::SetWeight(double a)
{
	weight = a;
}
double Item::GetWeight()
{
	return weight;
}
void Item::SetName(string a)
{
	name = a;
}
string Item::GetName()
{
	return name;
}
void Item::SetDescription(string a)
{
	description = a;
}
string Item::GetDescription()
{
	string text = description;
	text += "\n\tprice = " + to_string(price);
	text += "\n\tweight = " + to_string(weight);
	return text;
}
bool Item::IsUsed()
{
	return used;
}
bool Item::IsWeared()
{
	return weared;
}