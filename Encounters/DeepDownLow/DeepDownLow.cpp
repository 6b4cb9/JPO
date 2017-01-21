#pragma once

#include "DeepDownLow.h"
#include <time.h>
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

DeepDownLow::DeepDownLow()
{
}
DeepDownLow::~DeepDownLow()
{
}


bool Challengefunction1(Character* h)
{
	cout << "When u were walking down the path going thru the Ghastly Heath u suddenly fall down into a deep hole" << endl;
	cout << "To escape just press adequate buttons really quickly" << endl;
	Sleep(2000);
	cout << "Get ready?" << endl;
	Sleep(1500);
	cout << "GO!" << endl;
	time_t t1, t2;
	int tim = 8000;
	char odp;
	int good=0;
	int roz;
	char rr;
	int ra;

	string tab = "qwertyuiopasdfghjklzxcvbnm1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
	
	srand((unsigned int)time(NULL));
	for (int j=1; good!=10; j++)
	{
	
		ra = 0;
		
		ra = (rand() % (tab.length()));
		
		rr = tab[ra];
		cout << "PRESS " << rr  << endl;
		
		time(&t1);
		odp = _getch();
		time(&t2);
		roz = (int)difftime(t2, t1);

		if (odp == rr && roz < 2)
		{
			good++;
			cout << "Good job. You passed " << good << "/10!" << endl;
			
		}
		else if (odp == rr && roz > 2)
		{
			cout << "TO SLOW! LETS START FROM THE BEGINING 0/0" << endl;
			good = 0;
		}
		else if (odp != rr)
		{
			cout << "BAD ANSWER! LETS START FROM THE BEGINING 0/0" << endl;
			good = 0;
		}
		Sleep(100);
		
	}
	cout << "Well done! You manage to get out of this hole. You earned +3 toughness" << endl;
	h->SetToughness(h->GetToughness() + 3);
	Sleep(5000);
	return false;
	
	//wpadles w dol quicktime event im wiecej masz agility tym wiecej czasu na reakcje
}



bool DeepDownLow::Proceed(Character* hh)
{

	return Challengefunction1(hh);
	
	

}
		


