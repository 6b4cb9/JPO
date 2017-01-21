#include "SafeEncounter.h"
//#include "stdafx.h"

void SafeEncounter::Rest(Character* character) {
	if (character->GetHP() < 6*character->GetToughness()) {
		character->SetHP(6 * character->GetToughness());
	}
	
	int Mana = max(character->GetWisdom(), character->GetIntelligence());
	
	if (character->GetMana() < 6 * Mana) {
		character->SetMana(6 * Mana);
	}

}

void SafeEncounter::Trade(Character* character) {
	char choice;
	int decision;
	do {
		cout << "Do you want to (1) buy, (2) sell or (3) go back?" << endl;
		cin >> choice;
		if (choice == '1') {
			shop.VievWithDescriptions();
			cout << "Which item do you want to buy? Tell me the number of item!" << endl;
			cin >> decision;
			int quantity = shop.GetQuantity();
			double FreeCapacity = character->myEQ.GetCapacity() - character->myEQ.SumWeights();
			if (decision < quantity) { //check if item exist
				Item* proposedItem = shop.GetItem(decision - 1);
				if ((proposedItem->GetPrice() <= character->GetGold()) && proposedItem->GetWeight() <= FreeCapacity) //check if the character have enough gold and capacity to buy
				{
					character->myEQ.Add(proposedItem);
					character->SetGold(character->GetGold() - proposedItem->GetPrice());
					shop.Remove(decision - 1);
				}
				else cout << "You don't have enough money or capacity to buy this item!!!" << endl;
			}
			else cout << "Such an item doesn't exist!" << endl;
		}
		else if (choice == '2') {
			character->myEQ.VievWithDescriptions();
			cout << "Which item do you want to sell? Tell me the number of item!" << endl;
			cin >> decision;
			int quantity = character->myEQ.GetQuantity();
			double FreeShopCapacity = shop.GetCapacity() - shop.SumWeights();
			if (!((character->myEQ.GetItem(decision - 1))->IsWeared())) {
				if (decision < quantity) {
					Item* proposedItem = character->myEQ.GetItem(decision - 1);
						if (proposedItem->GetWeight() <= FreeShopCapacity) //check if the character have enough gold and capacity to buy
					{
						shop.Add(proposedItem);
						character->myEQ.Remove(decision - 1);
					}
				else cout << "Shop doesn't have enough capacity to buy this item." << endl;
				}
			else cout << "Such an item doesn't exist!!!" << endl;
		}
			else cout << "You are wearing this item!" << endl;
		}
		else if (choice == '3') return;
		else cout << "Choose one from displayed options!!!" << endl;
	} while (choice != '1' && choice != '2' && choice != '3');
}
