#include "MorbusEpidemic.h"

MorbusEpidemic::MorbusEpidemic()
{
}
MorbusEpidemic::~MorbusEpidemic()
{
}

bool MorbusEpidemic::Proceed(Character* Adventurer)
{
	srand(time(0));
	EpidemicDescription();
	ChanceDescription();
	string choice = "0";
	do { choice = SaveAChoice(); } 
	while (choice != "1" && choice != "2");
	
	if (choice == "1") { BuyingMedicine(Adventurer);}
	else if (choice == "2") { Waiting(Adventurer); }
	
	return true;
}

void MorbusEpidemic::EpidemicDescription()
{
	system("cls");
	cout << "--------------------------------------------------------------------" << endl;
	cout << "    There is a dangerous epidemic in your town! " << endl;
	cout << "  Previously unknown disease decimates inhabitants," << endl;
	cout << "  independently from age, sex and material status." << endl;
	cout << "  People called it a MORBUS." << endl << endl ;
	cout << "  Unfortunatelly, you are also ill..." << endl;
	cout << "--------------------------------------------------------------------" << endl;
}

void MorbusEpidemic::ChanceDescription()
{
	cout << "    But.. Maybe, there is a chance! " << endl;
	cout << "  Thanks to your old contacts, you can get a mistic medicine." << endl;
	cout << "  It's not a cheap thing, and nobady knows, whether it is effective." << endl;
	cout << "  You can buy this medicine. Its cost is 10 pieces of gold. " << endl;
	cout << "  Or... you can try to wait and see what is going to happen." << endl << endl;
	cout << "  What is your choice?" << endl;
	cout << "  1.Buying a precarious medicine." << endl;
	cout << "  2.Waiting." << endl;
	cout << "--------------------------------------------------------------------" << endl << endl;
}

void MorbusEpidemic::BuyingDescription()
{
	system("cls");
	cout << "--------------------------------------------------------------------" << endl;
	cout << "    You have decided - buying this precarious medicine. " << endl;
	cout << "  10 pieces of gold have been received by strange Druid." << endl;
	cout << "  He looks suspicious... maybe it wasn't a good idea." << endl;
	cout << "  You should wait... " << endl;
	cout << "--------------------------------------------------------------------" << endl;
}

void MorbusEpidemic::DiseaseDescription()
{
	cout << "   Everything looks terrible. You can't move." << endl;
	cout << "  If you have enough mana, you can try to use it.. "<<endl;
	cout << "  maybe something will go better." << endl;
	cout << "  Strange Driud said that you needed a 5 mana points." << endl;
	cout << "  It's the last chance." << endl;
	cout << "  Try!" << endl << endl ;
	cout << "  1.Yes, I want to use mana" << endl;
	cout << "  2.No, I don't want to use mana" << endl;
	cout << "--------------------------------------------------------------------" << endl;
}

void MorbusEpidemic::DruidHelpDescription()
{
	cout << "  You are getting better.. but you still feel a terrible pain. " << endl << endl;
	cout << "  Do you see this Druid.. he can use his spells to help you. " << endl;
	cout << "  You don't have a choice. He decided to be your hero." << endl << endl;
	cout << "  Ooo, it's a magic. You feel totally better" << endl;
	cout << "  Do you want to thank him? " << endl;
	cout << "  1.Yes." << endl;
	cout << "  2.No" << endl;
}

void MorbusEpidemic::WaitingDescription()
{
	cout << "  It's hard time to you.. The pain is incredible." << endl;
	cout << "  Maybe, you can use somthing to prepere your own medicine" << endl;
	cout << "  You should ask Druid, how to create usefull antidote." << endl << endl;
	cout << "  Do you want to ask Druid?" << endl;
	cout << "  1.Yes" << endl;
	cout << "  2.No" << endl;

}


string MorbusEpidemic::SaveAChoice()
{
	string choice;
	cin >> choice;
	return choice;
}

void MorbusEpidemic::Death()
{
	cout << "  Unfortunatelly, you are died!" << endl;
	_getch();
	exit(0);
}


void MorbusEpidemic::BuyingMedicine(Character * Adventurer)
{
	BuyingDescription();
	int g = Adventurer->GetGold() - 10;				//10- cost of medicine
	Adventurer->SetGold(g);
	DiseaseDescription();							//do you want to use mana
	string a = "0";
	do { a = SaveAChoice(); } 
	while (a != "1" && a != "2");

	if (Adventurer->GetToughness() < 2) { Death(); }
	else if (Adventurer->GetToughness() > 15 && Adventurer->GetStrength()>15) { cout << "  You don't have to lose mana, you are so strong and tough" << endl; }
	//using mana
	if (a == "1")		
	{
		if (Adventurer->GetMana() > 5)   //you want to use mana, you have enough mana
		{
			
			int a = rand() % 10;

			if (a < 5)        //lucky men, you aren't ill, mana was helpfull
			{
				cout << "  You are lukcy! " << endl;
				cout << "  You have enough mana,so the medicine will help you" << endl;
				cout << "  Additionally, you will receive same extra points of toughness." << endl << endl;
				int random = rand() % 3 + 1;
				cout << "  What's a lucky day. You have received " << random << " points!" << endl;
				cout << "  This medicine has amazing power" << endl;
				cout << "  And... the major thing - you are not ill." << endl;
				Adventurer->SetMana(Adventurer->GetMana() - 5);
				Adventurer->SetToughness(Adventurer->GetToughness() + random);
			}
			else   // Druid help
			{
				DruidHelpDescription();
				string thank = "0";					//do you want to thank him?
				do { thank= SaveAChoice(); }
				while (thank != "1" && thank != "2");

				Adventurer->SetMana(Adventurer->GetMana() - 5);
				if (thank == "1") 
				{ 
					cout << "  Druid is very satysfied. you received 2 points of charisma" << endl; 
					Adventurer->SetCharisma(Adventurer->GetCharisma() + 2); 
				}
				else if(thank == "2") 
				{ 
					cout << "  Your behaviour was inapprioriate, you lost 2 point of charisma" << endl;
					Adventurer->SetCharisma(Adventurer->GetCharisma() - 2);
				}
				
			}
		}
		else { Death();}			//you want to use mana , you don't have enough mana
	}
	//not using mana
	else if (a == "2")   //do not using mana 
	{ 
		cout << "  You are waiting for a lack... You can't do anyting, just waiting..." << endl;
		Sleep(1000);
		int ran = rand() % 2+ 1;
		Adventurer->SetStrength(Adventurer->GetStrength() - ran);
		cout << "  You are lucky - still alive! Unfortunatellu, you lost some strength points" << endl;
		
	}
}

void MorbusEpidemic::Waiting(Character * Adventurer)
{
	if (Adventurer->GetToughness() < 2) { Death(); }
	else if (Adventurer->GetToughness() > 15 && Adventurer->GetStrength() > 15) { cout << "  You don't have to lose mana, you are so strong and tough" << endl; }
	else
	{
		WaitingDescription();
		string a = "0";
		do { a = SaveAChoice(); }			//Druid antidote
		while (a != "1" && a != "2");

		if (a == "1")						//you want a hint
		{
			system("cls");
			cout << " You receive a hint!" << endl;
			if (Adventurer->GetIntelligence() >= 12) {cout << "  And it was a good hint, because you created a antidote!" <<endl; }
			else if( Adventurer->GetIntelligence() <12)
			{
				int percentage = (rand() % 11);
				if (percentage >=6 ) { cout << "  And it was a good hint, because you created a antidote!" << endl; }
				else 
				{ 
					cout << "  And it was a good hint, because you created a antidote! Unfortunatelly, you lost some mana" << endl; 
					Adventurer->SetMana(Adventurer->GetMana() - 2);
				}
			}
		}
		else if (a == "2")					//without  a hint
		{
			
			if (Adventurer->GetIntelligence() >= 20) 
			{ 
				system("cls");
				cout << "  Congratulations, your skills allowed you to create antidote" << endl;
				cout << "  Now, you are not ill! " << endl;
				cout << "  Additionally, you get even stronger " << endl;
				Adventurer->SetToughness(Adventurer->GetToughness() + 1);
			}
			else
			{
				system("cls");
				cout << "  What a mess... It seems you don't know what to do. " << endl;
				cout << "  Omg! there was a BOOM! You have to use mana to fix it!" << endl;
				Adventurer->SetMana(Adventurer->GetMana() - 3);
				Sleep(1000);
				cout << "  You are lucky, in the end you created the antidote." << endl;
			}
		}
		
	}
}
