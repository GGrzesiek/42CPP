#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
	PhoneBook phonebook;
	std::string command;

	while (1) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break;
		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else if (command == "EXIT")
			break;
	}
	return 0;
}
