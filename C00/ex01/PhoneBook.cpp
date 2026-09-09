#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

static std::string askField(std::string label) {
	std::string value;

	while (value.empty()) {
		std::cout << label << ": ";
		if (!std::getline(std::cin, value))
			return "";
	}
	return value;
}

static void printColumn(std::string text) {
	if (text.length() > 10)
		std::cout << text.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << text;
	std::cout << "|";
}

PhoneBook::PhoneBook() : _index(0), _count(0) {
}

void PhoneBook::add() {
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	firstName = askField("First name");
	if (firstName.empty())
		return;
	lastName = askField("Last name");
	if (lastName.empty())
		return;
	nickname = askField("Nickname");
	if (nickname.empty())
		return;
	phoneNumber = askField("Phone number");
	if (phoneNumber.empty())
		return;
	darkestSecret = askField("Darkest secret");
	if (darkestSecret.empty())
		return;
	_contacts[_index].set(firstName, lastName, nickname, phoneNumber, darkestSecret);
	_index = (_index + 1) % 8;
	if (_count < 8)
		_count++;
}

void PhoneBook::search() const {
	std::string input;
	int i;

	if (_count == 0) {
		std::cout << "Phonebook is empty." << std::endl;
		return;
	}
	printColumn("index");
	printColumn("first name");
	printColumn("last name");
	printColumn("nickname");
	std::cout << std::endl;
	i = 0;
	while (i < _count) {
		std::cout << std::setw(10) << i + 1 << "|";
		printColumn(_contacts[i].getFirstName());
		printColumn(_contacts[i].getLastName());
		printColumn(_contacts[i].getNickname());
		std::cout << std::endl;
		i++;
	}
	std::cout << "Index: ";
	if (!std::getline(std::cin, input))
		return;
	if (input.length() != 1 || input[0] < '1' || input[0] - '0' > _count) {
		std::cout << "Wrong index." << std::endl;
		return;
	}
	i = input[0] - '1';
	std::cout << "First name: " << _contacts[i].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[i].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[i].getNickname() << std::endl;
	std::cout << "Phone number: " << _contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[i].getDarkestSecret() << std::endl;
}
