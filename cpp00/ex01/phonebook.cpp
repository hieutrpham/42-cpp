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

#include <iostream>
#include <ostream>
#include <string>
#define CONTACT_CAP 8

class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_num;
	std::string secret;

public:
	Contact() {}
	Contact(
		std::string first_name,
		std::string last_name,
		std::string nick_name,
		std::string phone_num,
		std::string secret
	) : first_name(first_name), last_name(last_name), nick_name(nick_name), phone_num(phone_num), secret(secret){}

	std::string getFirstName() {
		return this->first_name;
	}

	std::string getLastName() {
		return this->last_name;
	}

	std::string getNickName() {
		return this->nick_name;
	}

	std::string getPhone() {
		return this->phone_num;
	}

	std::string getSecret() {
		return this->secret;
	}
};

std::ostream& operator<<(std::ostream& os, Contact c) {
	os << c.getFirstName() + " " + c.getLastName();
	return os;
}

class PhoneBook {
private:
	Contact contacts[CONTACT_CAP];
	int contact_count;

public:
	PhoneBook() : contact_count(0) {}

	Contact getContact(int index) {
		if (index < CONTACT_CAP)
			return this->contacts[index];
		else
			return this->contacts[CONTACT_CAP - 1];
	}

	int getContactCount() {
		return this->contact_count;
	}

	void addContact() {
		std::string first_name;
		std::cout << "First Name: ";
		std::getline(std::cin, first_name);
		std::string last_name;
		std::cout << "Last Name: ";
		std::getline(std::cin, last_name);
		std::string nick_name;
		std::cout << "Nick Name: ";
		std::getline(std::cin, nick_name);
		std::string phone_num;
		std::cout << "Phone: ";
		std::getline(std::cin, phone_num);
		std::string secret;
		std::cout << "Secret: ";
		std::getline(std::cin, secret);

		Contact new_contact(first_name, last_name, nick_name, phone_num, secret);
		if (this->contact_count < CONTACT_CAP) {
			contacts[this->contact_count] = new_contact;
			this->contact_count++;
		} else if (this->contact_count >= CONTACT_CAP) {
			contacts[CONTACT_CAP - 1] = new_contact;
		}
		std::cout << "Contact added!\n";
	}
};

std::ostream& operator<<(std::ostream& os, PhoneBook p) {
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

Contact searchContact () {
	Contact contact;
	return contact;
}

int main() {
	std::string buffer;
	PhoneBook p;

	while (true) {
		std::cout << "Please enter command (ADD, SEARCH, EXIT):";
		std::getline(std::cin, buffer);
		if (upperString(buffer) == "EXIT")
			exit(0);
		else if (upperString(buffer) == "ADD")
		{
			p.addContact();
		std::cout << p << std::endl;
		}
		else if (upperString(buffer) == "SEARCH")
			searchContact();
		else if (buffer.empty())
			exit(0);
		else
			continue;
	}
	return 0;
}
