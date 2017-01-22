#include"stdafx.h"
#include "MagicalDoors.h"


MagicalDoors::MagicalDoors()
{
}


MagicalDoors::~MagicalDoors()
{
}
void Artefacts(Character* h)
{

	cout << "There is a stack full of magical artefacts" << endl;
	cout << "To pick up a great you must press the . button perfectly when the screen turns black. The closer you are to the result the better artefact you will get " << endl;
	time_t pocz, kon;
	char cc;
	cout << "Get ready!" << endl;
	Sleep(6000);
	system("cls");
	time(&pocz);
	int e = 0;
	while (e == 0)
	{
		if (_kbhit())
		{
			cc = _getch();
			time(&kon);
			double roznica = difftime(kon, pocz);
			if (roznica < 2)
			{
				cout << "Concratulation! You did it perfectly. You picked up powerfull item." << endl;
				e = 1;
				int as = rand() % 3 + 1;
				int bs = rand() % 2 + 1;
				int cs = rand() % 4 + 1;
				h->SetIntelligence(as);
				h->SetAgility(bs);
				h->SetCharisma(cs);
				cout << "ITEM: Edge Of Infinity" << endl;
				cout << "STATISTICS: " << endl;
				cout << "+ " << as << " to intelligence" << endl;
				cout << "+ " << bs << " to agility" << endl;
				cout << "+ " << cs << " to charisma" << endl;
			}
			else if (roznica > 2 || roznica < 3)
			{
				cout << "Well done! You got magic item, which boosts your statistics" << endl;
				int ds = rand() % 3 + 1;
				h->SetToughness(ds);
				cout << "ITEM: Shield Of Victory" << endl;
				cout << "STATISTICS: " << endl;
				cout << "+ " << ds << " to toughness" << endl;
				e = 1;
			}
			else
			{
				cout << "You failed to push the button on time. No item collected" << endl;
				e = 1;
			}

		}
		Sleep(3000);


	}

}
void GoldenGold(Character* h)
{

	int i = 0;
	char c;
	int timer = 1000 * h->GetToughness();
	cout << "To colect gold press  .  rapidly, but hurry up, the room is going to colapse soon" << endl;
	Sleep(3000);
	while (timer > 0)
	{
		if (timer % 1000 == 0 || timer == 10)
		{
			system("cls");
			cout << "You have to only " << timer / 1000 << " seconds. Hurry up!";
		}

		if (_kbhit())
		{
			c = _getch();
			if (c == '.')
			{
				i++;
			}
		}
		Sleep(10);
		timer -= 10;
	}
	system("cls");
	cout << "That's it. You managed to colect only " << i << " gold before the room colapsed" << endl;
	h->SetGold(h->GetGold() + i);
	Sleep(4000);
}
void Behindethedoors(Character* h)
{
	cout << "wow" << endl;
	cout << "Well done boy!. You manage to open the doors! You entered to the magic room" << endl;
	cout << "You see a lot of gold, artefacts and little turtle turned upside down. What do you want to do first? " << endl;
	cout << "1. Get gold" << endl << "2. Search the stack with magical artefacts" << endl << "3. Help the little turtle." << endl;
	int w2;
	cin >> w2;
	if (w2 == 1)
	{
		GoldenGold(h);
	}
	else if (w2 == 2)
	{
		Artefacts(h);
	}
	else if (w2 == 3)
	{
		if (h->GetWisdom() > 5)
		{
			cout << "My mind whispering me: it's a trap! don't do that!" << endl;
			cout << " 1. Search the stack full of magical artefacts " << endl << " 2. Get the gold" << endl;
			int w3;
			cin >> w3;
			if (w3 == 1)
			{
				Artefacts(h);
			}
			else if (w3 == 2)
			{
				GoldenGold(h);
			}
			else cout << "You did nothing. You were standing and watching when suddenly you died" << endl;
			getchar();
		}
		else
		{
			cout << "That little turtle was a clever thief. He robbed you and run away." << endl;
		}
		if (h->GetAgility() > 6)
		{
			cout << "You started chasing turtle. Your agility was high enough to catch the thief and got back your gold. Unfortunatelly you ran away from magic comnate" << endl;
		}
		else
		{
			cout << "You started chasing turtle. Your agility was too low to catch turtle. You lost all your gold and escaped the magic comnate" << endl;
			h->SetGold(0);
		}
	}

	else
	{
		cout << "You did nothing. You were standing and watching when suddenly you died";
		Sleep(1000);
	}
	Sleep(10000);
}
bool Challengefunction2(Character* h)
{
	int ii;
	string ans;
	string pass = "POTATOES";
	string X = "XXXXXXXX";
	srand((unsigned int)time(NULL));
	cout << "There was something hide in a bush. You approached a bit to this place and you found magical doors in the middle of the bush. Unfortunatelly the doors are locked " << endl;
	Sleep(5000);
	cout << " WAIT! There is a sign: " << endl;
	cout << "'Write down the secret password to open the doors. If u are wise enough u won't have problems to solve this riddle' " << endl;
	cout << "1. Try solve the riddle" << endl << "2.Run away" << endl;
	int w1;
	cin >> w1;

	if (w1 == 1)
	{
		for (ii = 1; ii <= h->GetWisdom(); ii++)
		{
			int ind = rand() % pass.length();
			X[ind] = pass[ind];
		}
		cout << "You are wise man. You can spot some letter of the answer on the dirty doors" << endl << endl;
		cout << X << endl;
		cout << "Tell the answer" << endl << endl;
		cin >> ans;

		if (pass == ans)
		{
			Behindethedoors(h);
			return true;
		}
		else
		{
			cout << "You stupid prick. Go get some wisdom. You wasn't even close to solve it" << endl;
			Sleep(5000);
			return false;
		}

	}
	else if (w1 == 2)
	{
		cout << " You run away from old magical doors, you fool" << endl;
		return false;
	}
	else
	{
		cout << "Please try again";
		Challengefunction2(h);
	}
}
bool MagicalDoors::Proceed(Character * h)
{
	return Challengefunction2(h);
}