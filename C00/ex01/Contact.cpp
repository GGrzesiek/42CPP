#include "Contact.hpp"

void Contact::set(std::string firstName, std::string lastName, std::string nickname,
	std::string phoneNumber, std::string darkestSecret) {
	_firstName = firstName;
	_lastName = lastName;
	_nickname = nickname;
	_phoneNumber = phoneNumber;
	_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const {
	return _firstName;
}

std::string Contact::getLastName() const {
	return _lastName;
}

std::string Contact::getNickname() const {
	return _nickname;
}

std::string Contact::getPhoneNumber() const {
	return _phoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return _darkestSecret;
}
