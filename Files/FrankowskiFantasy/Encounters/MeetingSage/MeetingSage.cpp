/// Autor: KAMIL £ECZYCKI GR. 3 11:15
/// MOJE WYDARZENIA:

///		-TO UWIÊZIENIE - pasuje mi to do LOCHÓW (sterowanie w labiryncie W,S,A,D)
///		-stopien trudnosci: 2


///		-ROZMOWA Z MÊDRCEM W JEGO CHACIE - pasuje mi to do LASU
//		-stopien trudnosci: 1

#include"stdafx.h"
#include <iostream>
#include <cstdlib>
#include "windows.h"
#include <time.h>
#include <vector>
#include "MeetingSage.h"
#include "Load_from_file1.h"


using namespace std;


/////*************************************************
////**********************************************
///***********************************************


bool MeetingSage::Proceed(Character * Character)
{
	Text text1;
	text1.load("beginning2.txt");
	
	char choice = '0';
	cin >> choice;
	while(1)
	{
		
		if (choice == '1')
		{
			cout << "Good decision. You gain: \n+2 WISDOM\n+3 INTELLIGENCE\n+5 HP  " << endl;
			Character->SetWisdom((Character->GetWisdom()) + 2);
			Character->SetIntelligence((Character->GetIntelligence()) + 3);
			Character->SetHP((Character->GetHP()) + 5);
			text1.show_stats(Character);
			text1.press_any();
			break;


	}
	else if (choice == '2')
	{
			cout << "Not good decision. You lose: -1 WISDOM\n -1 INTELLIGENCE" << endl;
			Character->SetWisdom((Character->GetWisdom()) - 1);
			text1.show_stats(Character);
			text1.press_any();
			break;
	
	}
	
	else
	{
		cout << "Wrong choice. Again! Choice: ";
		cin >> choice;
	}

	}

	///************************************************************
	
	system("cls");
	text1.load("advices.txt");
	char choice2 = '0';

	while (1)
	{
	cin >> choice2;
	if (choice2 == '1')
	{
		cout << "Good decision. That woman is eternally grateful to you. You gain: +5 WISDOM" << endl;
		Character->SetWisdom((Character->GetWisdom()) + 5);
		text1.show_stats(Character);
		text1.press_any();
		break;
	}
	else if (choice2 == '2')
	{
		cout << "Wrr. What have you done?. You lose: -6 WISDOM" << endl;
		Character->SetWisdom((Character->GetWisdom()) - 6);
		text1.show_stats(Character);
		text1.press_any();
		break;
	}

	else if (choice2 == '3')
	{
		cout << "Not good decision. You lose: -3 WISDOM" << endl;
		Character->SetWisdom((Character->GetWisdom()) - 3);
		text1.show_stats(Character);
		text1.press_any();
		break;
	}
	else
	{
	cout << "Wrong choice. Again! Choice: ";
	cin >> choice;
	}
	}
	system("cls");
	text1.load("sage.txt");
	text1.show_stats(Character);
	vector<int> numbers;

	vector <int> my_numbers;
	text1.press_any();
	srand((unsigned int)time(NULL));
	for (int i = 0; i<5; ++i)
	{
		system("cls");
		int num;
		num = rand() % 10;
		numbers.push_back(num);
		cout << endl << num << endl;
		if ((Character->GetWisdom()) > 18)
		{
			Sleep(2 * 1000);
		}
		else if ((Character->GetWisdom()) > 13 && (Character->GetWisdom()) < 18)
		{
			Sleep(1200);
		}
		else
		{
			Sleep(800);
		}

		
	}

	system("cls");
	cout << "Insert numbers in properly sequence" << endl;
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		int el;

		cout << "Number " << i << ":\t";
		cin >> el;
		my_numbers.push_back(el);
	}

	cout << endl << "SAGE'S NUMBERS SEQUENCE" << endl;
	for (size_t i = 0; i < numbers.size(); i++)
		cout << numbers[i] << endl;


	cout << "YOUR NUMBERS SEQUENCE" << endl;
	for (size_t i = 0; i < my_numbers.size(); i++)
		cout << my_numbers[i] << endl;

	int correct = 0;
	int wrong = 0;
	for (unsigned int z = 0; z < numbers.size(); z++)
	{
		if (my_numbers[z] == numbers[z])
		{
			correct += 1;
		}
		else
		{
			wrong += 1;
		}

	}
	cout << "Correct: " << correct << "\t" << "Wrong: " << wrong << endl;
	
	Character->SetWisdom((Character->GetWisdom()) + correct);
	Character->SetIntelligence((Character->GetIntelligence()) + correct);

	Character->SetWisdom((Character->GetWisdom()) - wrong);
	Character->SetIntelligence((Character->GetIntelligence()) - wrong);
	cout << endl;
	text1.show_stats(Character);
	text1.press_any();

	system("cls");
	text1.load("second_quest.txt");
	string answer;
	cin >> answer;
	if (answer == "Regina")
	{
		cout << "Good answer. Real sense of INTELLIGENCY & WISDOM is known for you.\n This is magic book with spell for you.";
		Sleep(2000);
		cout << endl<<"END OF SECOND ENCOUNTER" << endl;
		return true;
		system("PAUSE");
	}
	else
	{
		cout << "You don't know real sense of INTELLIGENCY & WISDOM\n Go away!" << endl;
		Character->SetWisdom((Character->GetWisdom()) - 15);
		Character->SetIntelligence((Character->GetIntelligence()) - 8);
		text1.show_stats(Character);
		Sleep(2000);
		cout <<endl<< "END OF SECOND ENCOUNTER" << endl;
		return true;
		system("PAUSE");
	}

	
	

}
	
