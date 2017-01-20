#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stdio.h>
#include "Tavern.h"

using namespace std;
/////////////////////////////////////////////////////////
/*
	Event FARM has difficulty level 2, it suits to road
	Event TAVERN has difficulty level 3, it suits to village, city or maybe countryside
	Both of them have priority level 3
*/
/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

bool Tavern::Proceed(Character * Adventurer)
{
	cout << "You're entering to tavern. Locals don't look friendly... ";
	cout << "In their eyes you can see fire and will of murder. ";
	cout << "After moment of doubt, you go inside.";

	if (Adventurer->GetCharisma() >= 14)
	{
		cout << "Looking bravely in locals eyes, ";
		cout << "you entered tavern and sit at the bar." << endl;
		cout << "What you want to do: " << endl;
		cout << "1. Just sit and listen, what people say" << endl;
		cout << "2. Buy a beer for you and that lonely, old man, ";
		cout << "who's sitting in the corner" << endl;
		cout << "HINT: Who doesn't drink... doesn't end very well..." << endl;
		
		cin >> choice1;

		while (choice1 != '1' || choice1 != '2')
		{
			switch (choice1)
			{
			case '1':
			{
						cout << "Without beer, you look suspicious. Locals doesn't like it. ";
						cout << "Under the skin you feel, something bad is going to happen... ";
						cout << "And it really does. The biggest guy in tavern stands up, and ";
						cout << "slowly comes to you." << endl;
						cout << "'You've entered our place, you don't drink our beer. ";
						cout << "It's rude, and we don't like rude people. ";
						cout << "You'll tell me, who you are, what do you want, ";
						cout << "Or something really, really bad will happen to you.'" << endl;
						cout << "He isn't joking... You have to decide very fast!" << endl;
						cout << endl;
						cout << "1. Tell him everything he wants to know" << endl;
						cout << "2. Refuse his offer (it means very tough fight)" << endl;

						cin >> choice2;
						system("cls");

						if (choice2 == '1')
						{
							cout << "'You've chosen wisely. ";
							cout << "So, who you are, what do you want here ? '" << endl;
							cout << endl;
							cout << "'My name is Lee. I am a knight in our Kingdom Army. ";
							cout << "My master has died, and now I'm looking for some ";
							cout << "wise man, who would like to teach me.'" << endl;
							cout << endl;
							cout << "'I see. I can't help you, but my father can. ";
							cout << "Come with me. I'll lead you to him.'" << endl;
							cout << endl;
							cout << "You have no choice. You're going with that giant. ";
							cout << "You're not sure, if it's a trap... ";

							system("cls");

							cout << "After a while, you reach inconspicuous house. ";
							cout << "Inside, next to fireplace sits old but ";
							cout << "good-looking man." << endl;
							cout << endl;
							cout << "'Father, this men, knight in our Kingdom Army, ";
							cout << "is looking for wise man, who would like to become ";
							cout << "his master and teache him. I've brought him to you, ";
							cout << "because, I'm sure that you know such person.'" << endl;
							cout << endl;
							cout << "'It's true, I know such guy, but I don't know if ";
							cout << "he would like to teach anybody. Besides, I can tell ";
							cout << "where he lives.'" << endl;
							getchar();
							cout << endl;
							cout << "'His place is begind the haunted cementery. ";
							cout << "To get to his house, you will have to go through it. ";
							cout << "For 20 year none succeeded. You can guess, why. ";
							cout << "I wish you luck, son. You will need it.'" << endl;
							cout << endl;
							cout << "You leave giant and his father's home and go to your ";
							cout << "future master.";

							getchar();
							getchar();

							system("cls");

							cout << "An old man, was right. Cementery doesn't look very ";
							cout << "encouraginly... " << endl;
							cout << "'It can't be so hard... I'm going!'" << endl;
							cout << endl;
							cout << "WILD GHOST APPEARS!!!" << endl;
							cout << endl;
							cout << "All you can to do is try to run through ";
							cout << "cementery to house. You have one chance!" << endl;

							getchar();
							getchar();
							system("cls");

							if (Adventurer->GetAgility() >= 14)
							{
								cout << "YOU DID IT!!! You've reached house! In front of ";
								cout << "house stands very old, bald and white-beard man." << endl;
								cout << endl;
								cout << "'I knew, that you'll come. I will teach you, but ";
								cout << "on one condition. You have to answer to my question.'" << endl;
								cout << endl;
								cout << "'So let it be said, so let it be done. Ask your ";
								cout << "question, old man.'" << endl;
								cout << endl;
								cout << "'It's dark. You have 10 gray and 10 blue socks you ";
								cout << "want to put into pairs. All socks are exactly the ";
								cout << "same except their colour. How many socks would you ";
								cout << "need to take with you to ensure you had at least a pair?" << endl;
								cout << "16" << endl;
								cout << "3" << endl;
								cout << "8" << endl;
								cout << "7" << endl;

								cin >> answer1;

								if (answer1 == '3')
								{
									cout << "'Yes, this is right answer. I will tell you ";
									cout << "everything I know.";

									getchar();

									Adventurer->SetWisdom(Adventurer->GetWisdom() + 2);

									cout << "You've get 2 points wisdom." << endl;

									getchar();

									cout << "'My master, thank you very much! ";
									cout << "I would like stay longer, but now I have to ";
									cout << "go ahead. Bye! " << endl;

									getchar();
									getchar();
									return true;
								}
								else
								{
									cout << "'It's wrong answer. I won't teach you. ";
									cout << "Go away and never come back!" << endl;

									getchar();
									getchar();
									return false;
								}
							}
							else
							{
								cout << "It did't worked. Ghost catches and kills you!" << endl;
								cout << "GAME OVER!!!" << endl;

								getchar();
								getchar();
								return false;
							}
						}
						else
						{
							if (Adventurer->GetStrength() >= 18 && Adventurer->GetToughness() >= 18)
							{
								cout << "It was tough opponent, but you've beaten him. ";
								cout << "You survived, but you have to leave tavern. ";
								cout << "Locals are too frightend to tell you anything.";

								getchar();
								getchar();
								return true;
							}
							else
							{
								Adventurer->SetHP(Adventurer->GetHP() - 30);

								cout << "You've lost 30 points HP after fight." << endl;

								if (Adventurer->GetHP() <= 0)
								{
									cout << "You had not enough HP to survive!" << endl;
									cout << "Giant killed you!" << endl;
									cout << endl;
									cout << "GAME OVER!!!" << endl;

									getchar();
									getchar();
									return false;
								}
								else
								{
									cout << "He was to strong for you. ";
									cout << "He kicked you out of tavern. You better go away.";

									getchar();
									getchar();
									return true;
								}
							}
						}
						break;
			}
			case '2':
			{
						system("cls");

						Adventurer->SetGold(Adventurer->GetGold() - 4);

						cout << "You've lost 4x gold for buying beers." << endl;

						cout << "You gives beer an old man and asks: " << endl;
						cout << endl;
						cout << "'Cheers! I'm looking for a someone very wise. ";
						cout << "Someone, who would like to teache me. Do you ";
						cout << "know a place where I can find ";
						cout << "such person?'" << endl;
						cout << endl;
						cout << "'Bring me best drink in this tavern, and I ";
						cout << "will tell you all I know.'" << endl;
						cout << endl;
						cout << "'Okay, old man. Just wait.'" << endl;
						cout << "'Hey, bartender! Best drink for my friend!'" << endl;
						cout << endl;

						Adventurer->SetGold(Adventurer->GetGold() - 7);

						cout << "You've lost 7x gold for buying drink." << endl;
						cout << endl;

						getchar();
						getchar();

						cout << "'Here you are, my friend. Now tell me ";
						cout << "place and person.'" << endl;
						cout << endl;
						cout << "'Great. You're looking for Innos monastery. ";
						cout << "And his name is Paladin Marcos. He can show you ";
						cout << "how to be stronger.'" << endl;
						cout << endl;
						cout << "Thank you very much, old man. So, I will go there. ";
						cout << "Bye!'" << endl;

						getchar();
						getchar();

						system("cls");

						cout << "After long journey, you finaly have reached your ";
						cout << "destination. You don't want to lose time, so ";
						cout << "immediately you're going to Paladin Marcos." << endl;
						cout << endl;
						cout << "'Honorable Paladin Marcos, some old man in tavern ";
						cout << "told me, that you are great warrior and even better ";
						cout << "teacher. As you can see, I'm also knight and maybe, ";
						cout << "in future, paladin, as you. Would you like to help ";
						cout << "me with that? I would be very grateful.'" << endl;
						cout << endl;
						cout << "'Hm... I can do that. But under two conditions. ";
						cout << "First of all, you have to be at least average strong. ";
						cout << "It means, that you have to be able to lift my sword. ";
						cout << "Second, you will have to answer to my question.'" << endl;
						cout << endl;
						cout << "'If it is your will, so let it be. Give me sword.'" << endl;
						cout << endl;

						getchar();
						getchar();

						system("cls");

						if (Adventurer->GetStrength() >= 14)
						{
							cout << "'Yes, you are really strong. Now it is time ";
							cout << "for question. When I was 4 years old, my sister ";
							cout << "was half of my age. How old is she, when I'm 50?'" << endl;
							cout << "2" << endl;
							cout << "48" << endl;
							cout << "25" << endl;
							cout << "52" << endl;

							cin >> answer2;

							cout << endl;
							cout << endl;

							if (answer2 == 48)
							{
								cout << "'Your answer is correct. I will teach you.'" << endl;

								Adventurer->SetStrength(Adventurer->GetStrength() + 3);

								cout << "You've get 2 points strength." << endl;
								cout << endl;

								cout << "'Thank you, master. Now I have to go ahead. Bye!'" << endl;

								getchar();
								getchar();
								return true;
							}
							else
							{
								cout << "'It's wrong answer. I won't teach you. ";
								cout << "Go away and never come back!" << endl;

								getchar();
								getchar();
								return false;
							}
						}
						else
						{
							cout << "'You are too weak. I won't teach you. ";
							cout << "Go away and never come back!" << endl;

							getchar();
							getchar();
							return false;
						}
						break;
			}
			default:
			{
					   cout << "Choose available decision!!!";
					   system("cls");

					   cout << "What you want to do: " << endl;
					   cout << "1. Just sit and listen, what people say" << endl;
					   cout << "2. Buy a beer for you and that lonely, old man, ";
					   cout << "who's sitting in the corner" << endl;

					   cin >> choice1;
					   break;
			}
			}
		}
	}
	else if (Adventurer->GetStrength() >= 18 && Adventurer->GetToughness() >= 18)
	{
		cout << "You were not enough confident. It seems that locals ";
		cout << "don't like it. The biggest guy in tavern stands up, and ";
		cout << "slowly comes to you." << endl;
		cout << endl;
		cout << "'It is our place. You have nothing to do here! It was ";
		cout << "wrong decision to come here. Stand up and fight!'" << endl;
		cout << endl;
		
		getchar();
		getchar();
		system("cls");

		cout << "Your high level of strength and toughness let you ";
		cout << "win in this fight. After everything you sit at the bar, ";
		cout << "order a beer and start talking with bartender." << endl;
		cout << endl;
		cout << "'Hey, man. I know, you hear many things here. Would ";
		cout << "you like to tell me something interesting?'" << endl;
		cout << endl;
		cout << "'You've beaten our strongest man, but it doesn't mean ";
		cout << "that I will tell you anything for free. You have to pay. ";
		cout << "It will cost 35 gold. You pay, I talk. Otherwise, go away.'" << endl;

		getchar();
		getchar();
		system("cls");

		if (Adventurer->GetGold() >= 35)
		{
			Adventurer->SetGold(Adventurer->GetGold() - 35);

			cout << "You've lost 35x gold for buying informations." << endl;
			cout << endl;
			
			cout << "'Okay. Now, I can tell you, what I know.";
			if (Adventurer->GetIntelligence() >= 18)
			{
				Adventurer->SetWisdom(Adventurer->GetWisdom() + 4);

				cout << "There aren't droids you looking for" << endl;

				cout << "You've got 4 wisdom." << endl;
				cout << endl;

				cout << "'Thank you, man. Now I have to go. Bye!" << endl;
				getchar();
				getchar();
				return true;
			}
			else if (Adventurer->GetIntelligence() >= 14)
			{
				Adventurer->SetWisdom(Adventurer->GetWisdom() + 3);

				cout << "Look, I'm your father" << endl;

				cout << "You've got 3 wisdom." << endl;
				cout << endl;

				cout << "'Thank you, man. Now I have to go. Bye!" << endl;
				getchar();
				getchar();
				return true;
			}
			else if (Adventurer->GetIntelligence() >= 11)
			{
				Adventurer->SetWisdom(Adventurer->GetWisdom() + 2);

				cout << "Who has died, then is dead" << endl;

				cout << "You've got 2 wisdom." << endl;
				cout << endl;

				cout << "'Thank you, man. Now I have to go. Bye!" << endl;
				getchar();
				getchar();
				return true;
			}
			else
			{
				
				Adventurer->SetWisdom(Adventurer->GetWisdom() + 1);

				cout << "a^2 - b^2 = (a+b)(a-b)" << endl;
				cout << endl;

				cout << "You've got 1 wisdom." << endl;
				cout << endl;
				cout << "'Thank you, man. Now I have to go. Bye!" << endl;
				getchar();
				getchar();
				return true;
			}
		}
		else
		{
			cout << "'You don't have enough money. Go away.'" << endl;
			cout << endl;
			cout << "Lack of money is strong in this one. You have ";
			cout << "to find other source of informations.";

			getchar();
			getchar();
			return false;
		}

	}
	else
	{
		cout << endl;
		cout << endl;
		cout << "You were not enough confident and charismatic, ";
		cout << "moreover not enough strong. ";
		cout << "Locals very easily beated you and kicked out of tavern. ";
		cout << "You have to find other place to rest.";
		
		getchar();
		getchar();
		return true;
	}
}