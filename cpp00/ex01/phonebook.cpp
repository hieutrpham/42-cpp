/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:33:11 by trupham           #+#    #+#             */
/*   Updated: 2026/03/03 11:58:47 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#define CONTACT_CAP 2
#define FIELD_WIDTH 10

class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_num;
	std::string secret;

public:
	Contact() {}
	~Contact() {}
	Contact(
		std::string first_name,
		std::string last_name,
		std::string nick_name,
		std::string phone_num,
		std::string secret
	) : first_name(first_name), last_name(last_name), nick_name(nick_name), phone_num(phone_num), secret(secret){}

	std::string formatStr(std::string str) {
		std::string ret = str;
		if (str.length() > FIELD_WIDTH) {
			int i;
			for (i = 0; i < FIELD_WIDTH - 1; i++) {
				ret[i] = str[i];
			}
			ret[i] = '.';
		}
		ret.erase(FIELD_WIDTH);
		return ret;
	}

	std::string getFirstName() {
		return formatStr(this->first_name);
	}

	std::string getLastName() {
		return formatStr(this->last_name);
	}

	std::string getNickName() {
		return formatStr(this->nick_name);
	}

	std::string getPhone() {
		return formatStr(this->phone_num);
	}

	std::string getSecret() {
		return formatStr(this->secret);
	}
};

std::ostream& operator<<(std::ostream& os, Contact& c) {
	os << std::setw(FIELD_WIDTH)
		<< std::setw(FIELD_WIDTH) << c.getFirstName() << "|"
		<< std::setw(FIELD_WIDTH) << c.getLastName() << "|"
		<< std::setw(FIELD_WIDTH) << c.getNickName();
	return os;
}

class PhoneBook {
private:
	Contact contacts[CONTACT_CAP];
	int contact_count;

public:
	PhoneBook() : contact_count(0) {}
	~PhoneBook() {}

	Contact& getContact(int index) {
		if (index < CONTACT_CAP)
			return this->contacts[index];
		else
			return this->contacts[CONTACT_CAP - 1];
	}

	int getContactCount() {
		return this->contact_count;
	}

	bool addContact() {
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
			contacts[0] = new_contact;
		}
		std::cout << "Contact added!\n";
		return true;
	}

	bool searchContact() {
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
		}
		if (index < 0 || index >= CONTACT_CAP)
			return false;
		if (!this->contacts[index].getFirstName().empty())
			std::cout << this->contacts[index] << "\n";
		else
			std::cout << "No available contact\n";
		return true;
	}
};

std::ostream& operator<<(std::ostream& os, PhoneBook& p) {
	for (int i = 0; i < p.getContactCount(); i++) {
		os << p.getContact(i) << "\n";
	}
	return os;
}

std::string upperString(std::string str) {
	std::string ret = str;

	for (int i = 0; i < str.length(); i++) {
		ret[i] = (char)std::toupper(str[i]);
	}
	return ret;
}

int main() {
	std::string buffer;
	PhoneBook p;

	while (true) {
		if (std::cin.eof())
			exit(0);
		std::cout << "Please enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, buffer);
		if (upperString(buffer) == "EXIT")
			exit(0);
		else if (upperString(buffer) == "ADD")
		{
			if (!p.addContact()) {
				std::cout << "Failed to add contact\n";
				continue;
			}
			std::cout << p << std::endl;
		}
		else if (upperString(buffer) == "SEARCH") {
			if (!p.searchContact()) {
				std::cout << "Invalid contact\n";
				continue;
			}
		}
		else
			continue;
	}
	return 0;
}
