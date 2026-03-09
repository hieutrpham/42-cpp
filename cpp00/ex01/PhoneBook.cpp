/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:33:11 by trupham           #+#    #+#             */
/*   Updated: 2026/03/05 16:34:52 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "main.hpp"
#include <stdexcept>

PhoneBook::PhoneBook() : contact_count(0) {}
PhoneBook::~PhoneBook() {}

Contact& PhoneBook::getContact(int index) {
	if (contact_count != 0 && index < CONTACT_CAP)
		return this->contacts[index];
	else
		return this->contacts[CONTACT_CAP - 1];
}

int PhoneBook::getContactCount() {
	return this->contact_count;
}

bool PhoneBook::addContact() {
	std::string first_name;
	std::cout << "First Name: ";
	std::getline(std::cin, first_name);
	if (first_name.empty())
		return false;

	std::string last_name;
	std::cout << "Last Name: ";
	std::getline(std::cin, last_name);
	if (last_name.empty())
		return false;

	std::string nick_name;
	std::cout << "Nick Name: ";
	std::getline(std::cin, nick_name);
	if (nick_name.empty())
		return false;

	std::string phone_num;
	std::cout << "Phone: ";
	std::getline(std::cin, phone_num);
	if (phone_num.empty())
		return false;

	std::string secret;
	std::cout << "Secret: ";
	std::getline(std::cin, secret);
	if (secret.empty())
		return false;

	if (first_name.empty() || last_name.empty() || nick_name.empty() || phone_num.empty() || secret.empty())
		return false;

	Contact new_contact(first_name, last_name, nick_name, phone_num, secret);

	if (this->contact_count < CONTACT_CAP) {
		contacts[this->contact_count++] = new_contact;
	} else if (this->contact_count >= CONTACT_CAP) {
		contacts[this->oldest_contact % (CONTACT_CAP)] = new_contact;
		this->oldest_contact++;
	}
	std::cout << "Contact added!\n";
	return true;
}

bool PhoneBook::searchContact() {
	for (int i = 0; i < this->contact_count; i++) {
		std::cout << std::setw(FIELD_WIDTH) << i << "|" << this->contacts[i] << std::endl;
	}

	std::string input_index;
	std::cout << "Enter index: ";
	std::getline(std::cin, input_index);
	if (input_index.empty())
		return false;
	int index;
	try {
		index = std::stoi(input_index);
	} catch (std::invalid_argument& e) {
		return false;
	} catch (std::out_of_range& e) {
		return false;
	}

	if (index < 0 || index >= CONTACT_CAP)
		return false;
	if (contact_count != 0 && !this->contacts[index].getFirstName().empty()) {
		std::cout << "First Name:   " << this->contacts[index].getFirstName() << "\n";
		std::cout << "Last Name:    " << this->contacts[index].getLastName() << "\n";
		std::cout << "Nick Name:    " << this->contacts[index].getNickName() << "\n";
		std::cout << "Phone number: " << this->contacts[index].getPhone() << "\n";
		std::cout << "Secret:       " << this->contacts[index].getSecret() << "\n";
	}
	else
	std::cout << "No available contact\n";
	return true;
}

std::ostream& operator<<(std::ostream& os, PhoneBook& p) {
	for (int i = 0; i < p.getContactCount(); i++) {
		os << p.getContact(i) << "\n";
	}
	return os;
}

