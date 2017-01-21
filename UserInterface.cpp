#include "UserInterface.h"

UserInterface* UserInterface::instance = 0;

void UserInterface::clearScreen() {
	system("cls");
}

UserInterface* UserInterface::getInstance() {
	if (instance == 0)
		instance = new UserInterface();
	return instance;
}

UserInterface::UserInterface()
{
}


UserInterface::~UserInterface()
{
}

int UserInterface::getAns(int num) {
	std::string tmp;
	int ans = 0;
	std::string infos[] = { "Yyyy... Are You sure? Try again!" , "plsdfsudfusdfu... What?" , "I can't understand you. Please repeat." };
	std::getline(std::cin, tmp);
	if (tmp[0] >= '0' && tmp[0] <= '9')
		ans = std::stoi(tmp);
	else
		ans = 0;
	while (ans<1 || ans>num) {
		write(infos[rand() % 3]);
		std::getline(std::cin, tmp);
		if (tmp[0] >= '0' && tmp[0] <= '9')
			ans = std::stoi(tmp);
		else
			ans = 0;
	}
	return ans;
}

void UserInterface::write(std::string text) {
	std::cout << text << std::endl;
}

int UserInterface::choice(std::vector <std::string> text, std::string invit) {
	std::string posibilitys[] = { "What do you choose?", "What is your decision?" , "What shall you do?", "It's time to decide what to do." };
	if (invit != " ")
		write(invit);
	write(posibilitys[rand() % 4]);
	for (unsigned int i = 0; i < text.size(); i++)
		write(std::to_string(i + 1) + ")\t" + text[i]);
	return getAns(text.size());
}

void UserInterface::wait() {
	system("PAUSE");
}