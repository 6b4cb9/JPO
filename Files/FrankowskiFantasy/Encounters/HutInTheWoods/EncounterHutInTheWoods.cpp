#include "stdafx.h"

#include <chrono>
#include <thread>

#include "EncounterHutInTheWoods.h"


EncounterHutInTheWoods::EncounterHutInTheWoods()
{
}


EncounterHutInTheWoods::~EncounterHutInTheWoods()
{
}

bool EncounterHutInTheWoods::run()
{
	print_msg("Travelling through a forest, you stumble upon a decrepit hut.\n");
	print_msg("Wooden totems scattered around are carved with chilling depictions of faces\n"
		"contorted in emotion that feels familiar, but escapes words.\n");
	print_msg("There's an animal carcass on the ground. It's been rotting for days.\n");

	// Choice #1
	if (choice_1() == RCODE_EXIT) {
		wait_for_input(); return true;
	}

	print_msg("You notice the stagnant air grows colder as you move.\n");
	print_msg("Your steps echo against the unusual silence shrouding this place.\n");

	// Agility check
	if (ch->getAgility() > 12)
		print_msg("You instinctively attempt to walk quietly.\n"
			"Silence returns while you gently move near the carcass.\n");
	else
		print_msg("You instinctively attempt to walk quietly,\n"
			"only to show your lack of agility, stumbling and almost falling upon the carcass.\n");

	print_msg("You stand by the body, inhaling it's stench.\n");
	print_msg("You realize the animal is unlike any species you've ever seen.\n");

	// Choice #2
	if (choice_2() == RCODE_EXIT) {
		wait_for_input(); return true;
	}

	print_msg("The air is now so cold it burns your skin, despite having seemingly no effect on surrounding vegetation.\n");

	// Toughness check
	if (ch->getToughness() > 12) {
		print_msg("Without winter clothing to protect you only your extraordinary endurance allows you to move unhampered.\n");
	}
	else {
		print_msg("Without winter clothing, and as feeble as you are, the cold takes it's toll.\n");
		if (ch->getHP() < 10) {
			print_msg("You collapse, unable to move further. You will freeze and die here.\n");
			wait_for_input();
			exit(0);
		}
		else {
			print_msg("You take 10 damage.\n");
			ch->setHP(ch->getHP() - 10);
		}
	}

	print_msg("You stand in front of the hut. The cold is unbearable.\n");
	print_msg("Up close it reveals no details.\n");
	print_msg("Somehow the hut escapes any attempt at description.\n");
	print_msg("Trying to focus on anything but the plain wooden doors makes your head spin.\n");
	print_msg("The doors are closed.\n");

	// Choice #3
	if (choice_3() == RCODE_EXIT) {
		wait_for_input(); return true;
	}

	print_msg("The interior is warm and welcoming.\n");
	print_msg("A scent reminding you of your childhood home is in the air.Your nervousness dissipates.\n");
	print_msg("The small, turquoise pillar of stone stands in the centre. It's surface looks unbelievably smooth.\n");
	print_msg("You wish for nothing in this world but to touch it.\n");

	print_msg("---------------------------------------------------------\n");

	print_msg("You find yourself on the edge of the forest, unharmed.\n");

	wait_for_input();
	return true;
}

int EncounterHutInTheWoods::choice_1()
{
	print_msg("\nIt will be dusking soon. Do you...\n", true);
	print_choice(1, "Approach the hut?\n");
	print_choice(2, "Turn back?\n");
	int i = get_choice(2);
	switch (i) {
	case 1:
		print_msg("You decide to approach the hut. Gods have mercy on you.\n");
		return RCODE_CONTINUE;
	case 2:
		print_msg("You turn around and walk away, trying to erase the memory of this place.\n");
		return RCODE_EXIT;
	default:
		return RCODE_EXIT;
	}
}

int EncounterHutInTheWoods::choice_2()
{
	print_msg("It will be dusking soon. Do you...\n", true);
	print_choice(1, "Continue approaching the hut?\n");
	print_choice(2, "Turn back?\n");
	int i = get_choice(2);
	switch (i) {
	case 1:
		print_msg("You decide to push on.\n");
		return RCODE_CONTINUE;
	case 2:
		print_msg("You turn around and walk away, trying to erase the memory of this place.\n");
		return RCODE_EXIT;
	default:
		return RCODE_EXIT;
	}
}

int EncounterHutInTheWoods::choice_3()
{
	print_choice(1, "Force your way through.\n");
	print_choice(2, "Turn back.\n");
	int i = get_choice(2);
	switch (i) {
	case 1:
		print_msg("You push the doors with all your strength.\n");
		if (ch->getStrength() > 12) {
			print_msg("They open with little resistance, sending you flying into the hut.\n");
		}
		else {
			print_msg("Your feeble attempt to force the door is an unexpected success, as they pose little resistance. You enter the hut.\n");
		}
		return RCODE_CONTINUE;
	case 2:
		print_msg("To your terror, as you turn away from the doors you chear barely distinguishable whisper.\n");
		print_msg("You understand no words, but feel a powerful urge to stay...\n");
		if (ch->getCharisma() > 12) {
			print_msg("... but your strong mind and charisma allows you to resist it. You turn your back on the hut and make a hasty retreat, trying to erase the memory of this place.\n");
			return RCODE_EXIT;
		}
		else {
			print_msg("... which proves irresisible. You push the doors and enter the hut.\n");
			return RCODE_CONTINUE;
		}
	default:
		return RCODE_CONTINUE;
	}
}



void EncounterHutInTheWoods::wait_for_input()
{
	print_choice(1, "Continue.\n");
	get_choice(1);
}

void EncounterHutInTheWoods::print_msg(std::string s, bool skipSleep)
{
	//if (!skipSleep) std::this_thread::sleep_for(std::chrono::milliseconds(MSG_DELAY_MS));
	std::cout << s;
	if (!skipSleep) {
		std::cin.get();
	}
}

void EncounterHutInTheWoods::print_choice(int num, std::string msg)
{
	print_msg("\t" + std::to_string(num) + ". " + msg, true);
}

int EncounterHutInTheWoods::get_choice(int maxChoiceNum)
{
	using namespace std;
	int i;
	string line;
	cout << endl << "Decision #: ";
	do {
		getline(cin, line);
		i = (int)(line[0]) - 48;
	} while (i > maxChoiceNum || i < 1);
	cout << i << endl;
	return i;
}


