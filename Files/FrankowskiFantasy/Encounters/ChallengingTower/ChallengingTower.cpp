#pragma once
#include"stdafx.h"
#include "ChallengingTower.h"


ChallengingTower::ChallengingTower()
{
}


ChallengingTower::~ChallengingTower()
{
}

void ChallengingTower::firstfloor(Character * a)
{
	cout << "\nAfter a few seconds, ring begins to talk:\n\n";
	Sleep(4000);
	cout << "           - That's the 'Challenging Tower' where my owner lives.\n\n";
	Sleep(4000);
	cout << "           - Take me to him, to the top floor, and u will get rewarded.\n\n";
	Sleep(4000);
	cout << "           - Although, it will not be as easy as you might think...\n\n";
	Sleep(4000);
	cout << "\n           - As you can see, entrance to the next floor is closed..., Hahaaaa !\n\n";
	Sleep(4000);
	cout << "           - On each of three floors, I shall preapre a challenge for ya...\n\n";
	Sleep(4000);
	cout << "           - I must check if u are worthy to see my master...\n\n";
	Sleep(4000);
	cout << "           - Here is the first, quite simple one to start your journey...\n\n\n";
	Sleep(4000);
	cout << "Three man are standing in the dark room with no lights, they can see nothing...\n\n";
	Sleep(3500);
	cout << "There is a table with five hats, from which 3 are black and 2 are white...\n\n";
	Sleep(3500);
	cout << "Each man grabs one hat, puts it on his head and goes back to the line...\n\n";
	Sleep(3500);
	cout << "Lights ON !!!\n\n\n\n";
	Sleep(3500);
	cout << "The first man obviously can not see any other man...\n\n";
	Sleep(3500);
	cout << "The second man can see only first man and his hat...\n\n";
	Sleep(3500);
	cout << "The third man can see first and second guy with their hats...\n\n";
	Sleep(3500);
	cout << "Now, the first man asks the third man:\n\n";
	Sleep(3500);
	cout << "           - What is the colour of your hat ???\n";
	Sleep(3500);
	cout << "           - I don't know...\n\n";
	Sleep(3500);
	cout << "So now, the first guy asks the second man:\n\n";
	Sleep(3500);
	cout << "           - What is the colour of your hat ???\n";
	Sleep(3500);
	cout << "           - I don't know...\n\n";
	Sleep(3500);
	cout << "The question for YOU is..., what is the colour of the first man hat ???\n\n";
	Sleep(1000);
	cout << "Clock is ticking ...[black/white]...???\n\n";

	string answer;
	cin >> answer;
	if (answer == "black")
	{
		cout << "\nAlright, you answer is actually correct...\n\n";
		Sleep(3500);
		cout << "Follow me..., FOLLOW ME !!!  Hahaaaa......\n\n";
		Sleep(3500);
		cout << "Lets see how you handle the second floor challenge..\n\n";
		Sleep(3500);
		cout << "Inteligence + 1 !!!\n\n";
		a->SetIntelligence(a->GetIntelligence() + 1);
	}
	else
	{
		cout << "\nYour answer is incorrect, Hahaaa !\n\n";
		Sleep(4000);
		cout << "You are not worthy to see my master, but...\n";
		Sleep(4000);
		cout << "I'm having too much fun to quit now, I'll take you to the next floor...\n";
		Sleep(4000);
		cout << "But there has to be some consequences, because you are DUMB !\n\n";
		Sleep(4000);
		cout << "Inteligence - 1 !!!\n\n";
		a->SetIntelligence(a->GetIntelligence() - 1);
	}
}

void ChallengingTower::secondfloor(Character * a)
{
	cout << "Welcome to the second floor of a 'Challenging Tower' !\n\n";
	Sleep(4000);
	cout << "This time your task will not be that easy, so focus and listen carefully...\n\n";
	Sleep(4000);
	cout << "There is a 'Train of Death' going every day right beneath this tower...\n\n";
	Sleep(6000);
	cout << "At each stop, number of creatures inside the train changes...\n\n";
	Sleep(6000);
	cout << "Train left today really early with only 6 nightmares on board..., and then...\n\n\n";
	Sleep(8000);
	cout << "At first stop, 3 nightmares left, while 6 little devils stepped in....\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	Sleep(8000);
	cout << "Next stop, 2 coakroaches stepped in, along with 3 orcs...\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	Sleep(8000);
	cout << "Next stop, 1 little devil left, 1 nightmare did the same...\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	Sleep(8000);
	cout << "Next stop, 2 orcs left, 1 little devil came back...\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	Sleep(8000);
	cout << "And at the final stop of this puzzle...\n\n";
	Sleep(8000);
	cout << "ALL coakroaches left along, with ALL orcs !";
	Sleep(8000);
	cout << " \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "The question for YOU is...\n\n";
	Sleep(4000);
	cout << "How many creatures were in the train after its first stop ???\n\n";
	string answer;
	cin >> answer;
	if (answer == "9")
	{
		cout << "\n\ngoood..., GOOOD ! Hahaaaa !!!\n\n";
		Sleep(4000);
		cout << "Looks like i may have finally found the right traveller...\n";
		Sleep(4000);
		cout << "The One that can return me to my master...\n";
		Sleep(4000);
		cout << "But, you have one more challenge to pass before you can meet HIM !\n\n";
		Sleep(4000);
		cout << "Wisdom + 2 !!!\n\n";
		a->SetWisdom(a->GetWisdom() + 2);
	}
	else
	{
		cout << "\n\nHahaaaaa !!!.....\n\n";
		Sleep(4000);
		cout << "WRONG !\n\n";
		Sleep(4000);
		cout << "Prepare for bigger consequences after failing this one...\n";
		Sleep(4000);
		cout << "I really should not bring you here but..., whatever...\n";
		Sleep(4000);
		cout << "Lets go to the final challenge !\n\n";
		Sleep(4000);
		cout << "Wisdom - 2 !!!\n\n";
		a->SetWisdom(a->GetWisdom() - 2);
	}
}

void ChallengingTower::thirdfloor(Character * a)
{
	cout << "Here we are, at the final floor of the tower ! Hahaaaa !!!\n\n";
	Sleep(4000);
	cout << "This is where my master Aivras lives...\n\n";
	Sleep(4000);
	cout << "It its time for your final test, better pass this one...\n\n";
	Sleep(4000);
	cout << "Listen carefully to the puzzle...\n\n";
	Sleep(6000);
	cout << "There is a Queen of Destruction, Sandra, that has four childern...\n\n";
	Sleep(4000);
	cout << "Actually my master is one of them, but never mind...\n\n";
	Sleep(4000);
	cout << "There was a time she really liked to play with the elements...\n\n";
	Sleep(4000);
	cout << "She got devoted so much, that she decided to name her upcoming childen...\n\n";
	Sleep(4000);
	cout << "                     ... to name them like elements.\n\n";
	Sleep(4000);
	cout << "                So the first child is called 'Earth'...\n";
	Sleep(4000);
	cout << "                Second one..., 'Air'...\n";
	Sleep(4000);
	cout << "                Third one is 'Fire' ...\n\n";
	Sleep(4000);
	cout << "The question for YOU is...\n\n";
	Sleep(4000);
	cout << "What is the name of the final child ...??? (upper case letters matters)\n\n";
	string answer;
	cin >> answer;
	if (answer == "Aivras")
	{
		cout << "\nYes..., YESSSSS !! Hahaaaa !!!\n\n";
		Sleep(4000);
		cout << "You are ready..., you are finally worthy to meet HIM !!!\n\n";
		Sleep(4000);
		cout << "FOLLOW ME..., Follow me to the statue !!!\n\n";
		Sleep(4000);
		cout << "Inteligence + 2 !!!\n\n";
		a->SetIntelligence(a->GetIntelligence() + 2);
	}
	else
	{
		cout << "\nNo..., NO, NOOOOO !!!\n\n";
		Sleep(4000);
		cout << "I can't ..., I CAN'T take you to meet HIM !!!\n\n";
		Sleep(4000);
		cout << "You are NOT WORTHY !!! GET LOST !!!\n\n";
		Sleep(4000);
		cout << "No wait.., there is no way back anyway.., ARGHHHHH !!!\n\n";
		Sleep(4000);
		cout << "Guess i have to take you..., take you to the statue...\n\n";
		Sleep(4000);
		cout << "...follow me ... ;-[ ... \n\n";
		Sleep(4000);
		cout << "Inteligence - 2 !!!\n\n";
		a->SetIntelligence(a->GetIntelligence() - 2);
	}
}

void ChallengingTower::meeting(Character * a)
{
	cout << "Here we are, in the Throne hall, where the great statue stands...\n\n";
	Sleep(4000);
	cout << "          ...stands back from when i got lost :-/ !\n\n";
	Sleep(4000);
	cout << "You see, without me my master cannot control his power...\n\n";
	Sleep(4000);
	cout << "So he is waiting for me in this form to remain alive...\n\n";
	Sleep(4000);
	cout << "Waiting for me to return ..., but maybe i don't want to return ...\n\n";
	Sleep(4000);
	cout << "Maybe..., you can take me from now ! And we could travel TOGETHER ?!\n\n";
	Sleep(4000);
	cout << "My master will reward you with gold, but i can reward you too ...\n\n";
	Sleep(4000);
	cout << "You must make a choice ! Its all up to you now ...\n\n";
	Sleep(4000);
	cout << "Type 'ring' to keep the ring, or 'return' to return it.\n\n";
	Sleep(4000);
	string choice;
	cin >> choice;
	if (choice == "ring")
	{
		cout << "\n\n\nWisdom + 2 !!!\n\n";
		a->SetWisdom(a->GetWisdom() + 2);
		cout << "The moment you decide to keep the ring, everything goes into dark fog again...\n\n";
		Sleep(4000);
		cout << "After few seconds, you are back in the exact spot when u first saw the ring...\n\n";
		Sleep(4000);
		cout << "Time to continue the journey...\n\n";
		Sleep(4000);
	}
	else
	{
		Sleep(4000);
		cout << "\n\n\nGold + 500 !!!\n\n";
		a->SetGold(a->GetGold() + 500);
		cout << "The moment you decide to return the ring, everything goes into dark fog again...\n\n";
		Sleep(4000);
		cout << "After few seconds, you are back in the exact spot when u first saw the ring...\n\n";
		Sleep(4000);
		cout << "Time to continue the journey...\n\n";
		Sleep(4000);
	}
}

void ChallengingTower::wait()
{
	cout << "                                     @";
	Sleep(1000);
	cout << "@";
	Sleep(1000);
	cout << "@\n\n\n";
	Sleep(1000);
}
