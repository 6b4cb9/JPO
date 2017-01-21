#include "EQ.h"

EQ::EQ() {}
EQ::~EQ() {}
void EQ::SetCapacity(int strength, int toughness) {
	Refresh();
	this->capacity = 3 * strength + 2 * toughness;
}
bool EQ::Add(Item* item) {
	Refresh();
	if (item->GetWeight() <= (capacity - SumWeights())) {
		content.push_back(item);
		return true;
	}
	else return false;
}
void EQ::Remove(int ind) {
	Refresh();
	if (content.size() > ind) {
		content.erase(content.begin() + ind);
	}
}
void EQ::View() {
	Refresh();
	cout << "Equipment includes: ";
	for (int i = 0; i < content.size(); i++) {
		cout << content[i]->GetName() << ", ";
	}
	cout << endl;
}
void EQ::VievWithDescriptions() {
	Refresh();
	cout << "Equipment includes: " << endl;
	for (int i = 0; i < content.size(); i++) {
		cout << content[i]->GetName() << " -> " << content[i]->GetDescription() << endl;
	}
}
void EQ::Use(int ind, Character* character) {
	Refresh();
	if (content.size() > ind) {
		content[ind]->Action(character);
	}
}
double EQ::SumWeights() {
	Refresh();
	double sum = 0;
	for (int i = 0; i < content.size(); i++) {
		sum += content[i]->GetWeight();
	}
	return sum;
}
void EQ::Refresh() {
	for (int i = 0; i < content.size(); i++) {
		if (content[i]->IsUsed() == true) {
			Remove(i);
		}
	}
}
Item* EQ::Get(int ind) {
	Refresh();
	Item* temp;
	if (content.size() > ind)
	{
		temp = content[ind];
	}
	else
	{
		temp = content[content.size() - 1];
	}
	return temp;
}
int EQ::GetQuantity() {
	Refresh();
	return content.size();
}
double EQ::GetCapacity(void) {
	Refresh();
	return capacity;
}