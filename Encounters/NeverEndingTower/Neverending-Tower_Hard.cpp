#include "Neverending-Tower_Hard.h"

using namespace std;

// Implementation on Floors
bool Neverending_Tower_Hard::First_Floor(Character * Character)
{
	Read_Note("Encounters/NeverEndingTower/First_Floor.txt");
	system("pause");
	bool pass = false;
	bool one = false;
	srand(time(NULL));
	while (1)
	{
		int probability = rand() % 100;

		cout << "What do you want to do ?" << endl;
		if (!one)
		{
			cout << "1. Go to bar drink something" << endl;
		}
		cout << "2. Go buy food and eat it" << endl;
		cout << "3. Eavesdrop people conversation" << endl;
		cout << "4. Buy pass to next floor for 15g " << endl;
		cout << "5. Go to next floor" << endl;
		int choose;
		cin >> choose;
		switch (choose)
		{
		case 1:
			if (!one)
			{
				cout << "When you go drinking, one man, who is sitting near bar provoke you to fight. Pull out your weapon !" << endl;
				system("pause");
				if (Character->GetHP() < 1)
				{
					cout << "Your HP points is less than 1 HP." << endl;
					cout << "YOU DIED" << endl;
					return false;
				}
				cout << "That wasn't a good day for him... When you rummage his body, you are finding a pass to next floor !" << endl;
				system("pause");
				pass = true;
				one = true;
			}
			break;
		case 2:
			cout << "Ok, let's go eat something !" << endl;

			if (probability > 50)
			{
				cout << "After a meal you are feel very good - ready to upcoming challenges ! (your Toughness is increasing by 1 !)" << endl;
				Character->SetToughness(Character->GetToughness() + 1);
				Character->SetHP(Character->GetHP() + 6);
			}
			else
			{
				cout << "After a meal you are feel very bad (that was rotten meat) - it isn't a good start of journey. (your Toughness is decreasing by 1 !)" << endl;
				Character->SetToughness(Character->GetToughness() - 1);
				Character->SetHP(Character->GetHP() - 6);
			}
			if (Character->GetHP() < 1)
			{
				cout << "Your HP points is less than 1 HP." << endl;
				cout << "YOU DIED" << endl;
				return false;
			}
			break;
		case 3:
			//Read_Note("People_talking.txt");
			break;
		case 4:
			cout << "You are going to bar and asking for pass. Bartender told you, that you must pay 15g for pass." << endl;
			cout << "Do you want to buy pass ?" << endl;
			cout << "1.Yes (you lost 15g)" << endl;
			cout << "2.No" << endl;
			cin >> choose;
			if (choose == 1)
			{
				Character->SetGold(Character->GetGold() - 15);
				pass = true;
			}
			break;
		case 5:
			if (pass)
			{
				cout << "You are showing your pass and walking to next floor" << endl;
				system("pause");
				return true;
			}
			else
			{
				cout << "One man, whos staying next to door is asking for your pass. you haven't got it, so you can't go to next floor" << endl;
			}
			break;
		}
	}
}
bool Neverending_Tower_Hard::Second_Floor(Character * Character)
{
	srand(time(NULL));
	int points;
	int choose;
	vector<int> Good_way;
	int iteration = 0;
	for (int i = 0; i < 6; i++)
	{
		Good_way.push_back(rand() % 3 + 1);
	}
	cout << "On Second floor you are seeing a labirynth. You must choose which direction you choose." << endl;
	system("pause");
	while (iteration < 6)
	{
		int probability = rand() % 100;
		cout << "Which direction you choose ?" << endl;
		cout << "1. go left" << endl;
		cout << "2. go straight" << endl;
		cout << "3. go right" << endl;
		cin >> choose;
		if (choose == Good_way[iteration])
		{
			cout << "You are choosing good way !" << endl;
			system("pause");
			++iteration;
		}
		else if (probability >= 70)
		{
			points = probability / 6;
			cout << "You are falling into a trap and losting " << points << " Health Points !" << endl;
			system("pause");
			Character->SetHP(Character->GetHP() - points);
			if (Character->GetHP() < 1)
			{
				cout << "Your HP points is less than 1 HP." << endl;
				cout << "YOU DIED" << endl;
				return false;
			}
		}
		else if (probability < 70)
		{
			points = probability / 6;
			cout << "You are finding a chest with a HP Potion, which give you " << points << " Health Points !" << endl;
			system("pause");
			if (Character->GetHP() + points <= Character->GetToughness() * 6)
				Character->SetHP(Character->GetHP() + points);
			else
				Character->SetHP(6 * Character->GetToughness());
		}
	}
	cout << "You are finding a door to the next floor ! " << endl;
	system("pause");
	return true;
}
bool Neverending_Tower_Hard::Third_Floor(Character * Character)
{
	srand(time(NULL));
	
	int choose;
	int translation;
	vector<char> Solution;
	string your_solution;
	string Good_solution;
	translation = (rand() % 30) + 84;
	Solution.push_back(translation);
	for (int i = 1; i < 11; i++)
	{
		Solution.push_back(rand() % 62 + 48);
		Good_solution.push_back(Solution[i]);
	}
	vector<char> Cipher;
	Cipher.push_back(translation);
	for (int i = 1; i < 11; i++)
	{
		Cipher.push_back(Solution[i]+(100 - translation));
	}
	int probability = rand() % 100;
	cout << "On Third floor you are seeing a big, sleeping Cerberus laying near door to next floor." << endl;
	cout << "After that you are realized that next to you is a door with a strange cipher to solve !" << endl;
	system("pause");
	while (1)
	{
		cout << "What do you do ?" << endl;
		cout << "1. Try to sneak around the Cerberus and go to next floor" << endl;
		cout << "2. Try to solve the cipher" << endl;
		cin >> choose;
		if (choose == 1)
		{
			if (Character->GetAgility() > 19)
			{
				cout << "You slowly walking next to Cerberus and..." << endl;
				Sleep(1000);
				cout << "You successfully reach the door ! " << endl;
				system("pause");
				return true;
			}
			else
			{
				cout << "You slowly walking next to Cerberus and..." << endl;
				Sleep(1000);
				if (probability > Character->GetAgility() * 2)
				{
					cout << "You wake up Cerberus ! Let's Fight !" << endl;
					if (Character->GetHP() < 1)
					{
						cout << "Your HP points is less than 1 HP." << endl;
						cout << "YOU DIED" << endl;
						return false;
					}
					cout << "You killed the Cerberus and you can go to the next floor !" << endl;
					return true;
				}
				else
				{
					cout << "When you are sneaking around Cerberus, he is waking up ! You are running to the door, and you come into before Cerberus had attacked you ! You can go to the next floor." << endl;
					return true;
				}
			}
		}
		else if (choose == 2)
		{
			cout << "On the door you are seeing an inscription: " << endl << endl;
			for (int i = 0; i < 11; i++)
			{
				cout << Cipher[i];
			}
			cout << endl << endl;
			cout << "under it there was a hint: \"First letter must be substract by 100\"" << endl << endl;
			if (Character->GetWisdom() > 19)
				cout << "It's look like Ceasar Cipher !" << endl;

			cout << "Your idea of solution: ";
			cin >> your_solution;
			if (your_solution == Good_solution)
			{
				cout << "You are solved Cipher ! Now you can go to the next floor" << endl;
				return true;
			}
			else
			{
				cout << "You write it on the door, and suddenly door hurts you by the thunder ! (You are losing 10 hp). Mhm... I'm Sure that's not a solution for it" << endl;
				Character->SetHP(Character->GetHP() - 10);
				if (Character->GetHP() < 1)
				{
					cout << "Your HP points is less than 1 HP." << endl;
					cout << "YOU DIED" << endl;
					return false;
				}
			}
		}
	}
}
bool Neverending_Tower_Hard::Fourth_Floor(Character * Character)
{
	
		int choose;
		int choose2;
		bool done = false;
		cout << "When you opening the door, strange voice say to you \"Hello !\" " << endl;
		cout << "A humanoid creature tell you, that he keep a shop on this floor" << endl;
		cout << "\" I haven't got any clients since 11 years - what a pleasant suprise to see you ! \"" << endl;
		system("pause");
	while (1)
	{
		cout << "What do you do ?" << endl << endl;
		cout << "1. Buy something from Shopkeeper" << endl;
		cout << "2. Go To the next floor" << endl;
		if (Character->GetCharisma() > 19 && !done)
		{
			cout << "3. Ask him why he have a shop in a tower" << endl;
		}
		cin >> choose;
		// Buy Something
		if (choose == 1)
		{
			cout << "What do you want to buy from strange shopkeeper ?" << endl << endl;
			cout << "1. HP Potion (+10 HP) - 15g" << endl;
			cout << "2. Medallion of Courage (+1 to Strength and Charisma) - 20g" << endl;
			cout << "3. Bracelet of Power (+1 to Toughness and Strength) - 25g" << endl;
			cout << "4. Diary of lonely Goblin (+2 to Wisdom) - 20g " << endl;
			cout << "5. Stick with a unknown inscription(+2 to Intelligence) - 30g" << endl;
			cout << "6. Don't buy anything" << endl;
			cin >> choose2;
			switch (choose2)
			{
			case 1:
				if (Character->GetGold() < 15)
					cout << "You haven't got coins to buy this !" << endl;
				else
				{
					Character->SetGold(Character->GetGold() - 15);
					Character->SetHP(Character->GetHP() + 10);
					if (Character->GetHP() > 6 * Character->GetToughness())
						Character->SetHP(6 * Character->GetToughness());
				}
				cout << "You Buy an item !" << endl;
				system("pause");
				break;
			case 2:
				if (Character->GetGold() < 20)
					cout << "You haven't got coins to buy this !" << endl;
				else
				{
					Character->SetGold(Character->GetGold() - 20);
					Character->SetStrength(Character->GetStrength() + 1);
					Character->SetCharisma(Character->GetCharisma() + 1);
					cout << "You Buy an item !" << endl;
				}
				system("pause");
				break;
			case 3:
				if (Character->GetGold() < 25)
					cout << "You haven't got coins to buy this !" << endl;
				else
				{
					Character->SetGold(Character->GetGold() - 25);
					Character->SetStrength(Character->GetStrength() + 1);
					Character->SetCharisma(Character->GetToughness() + 1);
					Character->SetHP(Character->GetHP() + 6);
					cout << "You Buy an item !" << endl;
				}
				system("pause");
				break;
			case 4:
				if (Character->GetGold() < 20)
					cout << "You haven't got coins to buy this !" << endl;
				else
				{
					Character->SetGold(Character->GetGold() - 20);
					Character->SetWisdom(Character->GetWisdom() + 2);
					cout << "You Buy an item !" << endl;
				}
				system("pause");
				break;
			case 5:
				if (Character->GetGold() < 30)
					cout << "You haven't got coins to buy this !" << endl;
				else
				{
					Character->SetGold(Character->GetGold() - 30);
					Character->SetIntelligence(Character->GetIntelligence() + 2);
					Character->SetMana(Character->GetMana() + 6);
					cout << "You Buy an item !" << endl;
				}
				system("pause");
				break;
			}
		}
		else if (choose == 2)
		{
			return true;
		}
		else if (choose == 3 && Character->GetCharisma() > 19 && !done)
		{
			cout << "\"Huh ? I'm glad to hear someone care about me ! 100 years ago i was as brave as you ! \"" << endl;
			cout << "\"But on this floor i was scared about going higher. I stay here because i am safe here. \"" << endl;
			system("pause");
			cout << "\"I had a lots of artefacts from different journeys. I musn't eat and drink, so i only need a safety place to live\"" << endl;
			cout << "\"Mhm... You looks like me 100 years ago ! I give you an advice - don't stay here, go higher ! But wait,i'll give you something ! " << endl;
			cout << "Stranger give you an papirus. When you take it, it suddenly dissapeared - you feel more durable ! (Your Toughness is increasing by 2 !)" << endl;
			system("pause");
			Character->SetToughness(Character->GetToughness() + 2);
			Character->SetHP(Character->GetHP() + 12);
			done = true;
		}
	}
}
bool Neverending_Tower_Hard::Fifth_Floor(Character * Character)
{
	cout << "Room on the next floor looks like a snail - narrow and very long, going around the center of tower" << endl;
	cout << "Suddenly, you hear someone behind you. A giant rock is rolling around you ! RUN !" << endl;
	cout << "Enter 'a' to run on a left side of room, 'd' to run on a right side of room, or 'w' to jump over a barrier" << endl;
	system("pause");
	for (int i = 0; i < 10; i++)
	{
		typedef std::chrono::high_resolution_clock Clock;
		typedef std::chrono::milliseconds milliseconds;
		Clock::time_point t0 = Clock::now();
		Clock::time_point t1 = Clock::now();
		milliseconds diff = std::chrono::duration_cast<milliseconds>(t1 - t0);
		char direct;
		int mistakes = 0;
		int probability = rand() % 100;
		if (probability < 33)
		{
			cout << "barrier on a left side !" << endl;
			t0 = Clock::now();
			cin >> direct;
			t1 = Clock::now();
			diff = std::chrono::duration_cast<milliseconds>(t1 - t0);
			if (direct != 'd' || diff.count() > Character->GetAgility() * 80)
			{
				cout << "You hit in a barrier ! (you lost 10 hp)" << endl;
				system("pause");
				Character->SetHP(Character->GetHP() - 10);
				if (Character->GetHP() < 1)
				{
					cout << "Your HP points is less than 1 HP." << endl;
					cout << "YOU DIED" << endl;
					return false;
				}
				++mistakes;
			}
		}
		else if (probability >= 33 && probability < 66)
		{
			cout << "barrier on a right side !" << endl;
			t0 = Clock::now();
			cin >> direct;
			t1 = Clock::now();
			diff = std::chrono::duration_cast<milliseconds>(t1 - t0);
			if (direct != 'a' || diff.count() > Character->GetAgility() * 80)
			{
				cout << "You hit in a barrier ! (you lost 10 hp)" << endl;
				system("pause");
				Character->SetHP(Character->GetHP() - 10);
				if (Character->GetHP() < 1)
				{
					cout << "Your HP points is less than 1 HP." << endl;
					cout << "YOU DIED" << endl;
					return false;
				}
				++mistakes;
			}
		}
		else if (probability >= 66)
		{
			cout << "barrier on a floor !" << endl;
			t0 = Clock::now();
			cin >> direct;
			t1 = Clock::now();
			diff = std::chrono::duration_cast<milliseconds>(t1 - t0);
			if (direct != 'w' || diff.count() > Character->GetAgility() * 80)
			{
				cout << "You hit in a barrier ! (you lost 10 hp)" << endl;
				system("pause");
				Character->SetHP(Character->GetHP() - 10);
				if (Character->GetHP() < 1)
				{
					cout << "Your HP points is less than 1 HP." << endl;
					cout << "YOU DIED" << endl;
					return false;
				}
				++mistakes;
			}
		}
		if (mistakes == 3)
		{
			cout << "Giant Rock catch you up and crush you !" << endl;
			cout << "YOU DIED" << endl;
		}
	}
	cout << "When you are running you see a door straight to you. You are quickly open it and run upstairs." << endl;
	return true;
}
bool Neverending_Tower_Hard::Sixth_Floor(Character * Character)
{
	cout << "When you are moving to the door, you hear a sob." << endl;
	cout << "After open the door, you see a little girl, who is weighed down by the fragments of wall" << endl;
	cout << "\" Could you help me ? Please, i can't get out ! \"" << endl;
	if (Character->GetStrength() > 19)
	{
		cout << "You have enough strength, so you help her winkle out" << endl;
		system("pause");
		Read_Note("Encounters/NeverEndingTower/Seventh_Floor.txt");
		system("pause");
		Character->SetWisdom(Character->GetWisdom() + 1);
		Character->SetStrength(Character->GetStrength() + 1);
	}
	else
	{
		cout << "You haven't got enough strength to help her, so with great sadness you leaving the room." << endl;
		system("pause");
	}
	
	return true;
}
bool Neverending_Tower_Hard::Seventh_Floor(Character * Character)
{
	cout << "When you are reaching last step of stairs, you are seeing a big treasure chest in the middle of floor" << endl;
	system("pause");
	if (Character->GetIntelligence() > 19)
	{
		cout << "You suspect that it's a trap, so firstly you are trying to hit treasure Chest by a weapon " << endl;
		system("pause");
		cout << "Suddenly treasure chest is changing in a big monster with a chest as his head, and long, thin legs and arms. Monster attack you !" << endl;
		system("pause");
	}
	else
	{
		cout << "You are trying to open the treasure chest, then suddenly it bite you (you lost 10 HP before Fight), and changing in a big monster with a chest as his head, and long, thin legs and arms. Monster attack you !" << endl;
		system("pause");
		Character->SetHP(Character->GetHP() - 10);
		if (Character->GetHP() < 1)
		{
			cout << "Your HP points is less than 1 HP." << endl;
			cout << "YOU DIED" << endl;
			return false;
		}
	}
	if (Character->GetHP() < 1)
	{
		cout << "Your HP points is less than 1 HP." << endl;
		cout << "YOU DIED" << endl;
		return false;
	}
	cout << "You are defeating a Treasure Chest monster ! In his body (in treasure chest) you are finding 200g and medallion ! (in increase Strength, Ability and Intelligence by 2 !) !";
	system("pause");
	Character->SetStrength(Character->GetStrength() + 2);
	Character->SetAgility(Character->GetAgility() + 2);
	Character->SetIntelligence(Character->GetIntelligence() + 2);
	Character->SetGold(Character->GetGold() + 200);
	cout << "After that you realized that is a portal in the end of a room. You decide go to it (because you haven't got any other choice)" << endl;
	system("pause");
	cout << "You are teleport in a forest, near Neverending Tower" << endl;
	cout << "sick and tired after it, you sit on your horse and ride to the City" << endl;
	system("pause");
	return true;
}

void Neverending_Tower_Hard::Read_Note(string Name_Of_File)
{
	fstream Part_of_Encounter;
	Part_of_Encounter.open(Name_Of_File, std::ios::in);
	if (Part_of_Encounter.good() == false)
	{
		cout << "Error - " << Name_Of_File << " not included !" << endl;
	}
	string current_line;
	while (getline(Part_of_Encounter, current_line))
	{
		cout << current_line << endl;
	}
}
bool Neverending_Tower_Hard::Proceed(Character * Character)
{
	Read_Note("Encounters/NeverEndingTower/Beginning.txt");
	bool success = true;
	success = First_Floor(Character);
	if (!success)
	{
		exit(0);
	}
	success = Second_Floor(Character);
	if (!success)
	{
		exit(0);
	}
	success = Third_Floor(Character);
	if (!success)
	{
		exit(0);
	}
	success = Fourth_Floor(Character);
	if (!success)
	{
		exit(0);
	}
	success = Fifth_Floor(Character);
	if (!success)
	{
		exit(0);
	}
	success = Sixth_Floor(Character);
	if (!success)
	{
		exit(0);
	}
	success = Seventh_Floor(Character);
	if (!success)
	{
		exit(0);
	}
	return true;
}
