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
	std::string getFirstName() {
		return first_name;
	}

	void setContact(
		std::string _first_name,
		std::string _last_name,
		std::string _nick_name,
		std::string _phone_num
	) {
		this->first_name = _first_name;
		this->last_name = _last_name;
		this->nick_name = _nick_name;
		this->phone_num = _phone_num;
	}
};

class PhoneBook {
private:
	Contact contacts[CONTACT_CAP];
	int contact_count = 0;

public:
	std::string getContactFirstName(int index) {
		return contacts[index].getFirstName();
	}

	void addContact(
		std::string first_name,
		std::string last_name,
		std::string nick_name,
		std::string phone_num
	) {
		Contact new_contact;
		new_contact.setContact(first_name, last_name, nick_name, phone_num);
		if (contact_count < CONTACT_CAP) {
			contacts[contact_count++] = new_contact;
		}
	}
};

int main() {
	std::string buffer;
	PhoneBook p = {};

	p.addContact("hieu", "pham", "hp", "834791387");
	std::cout << p.getContactFirstName(0);

	// while (true) {
	// 	std::cout << "enter name: ";
	// 	std::getline(std::cin, buffer);
	// 	if (buffer == "EXIT")
	// 		exit(0);
	// 	else if (buffer == "ADD")
	// 		p.addContact();
	// 	else if (buffer.empty())
	// 		exit(0);
	// 	else
	// 		continue;
	// 	std::cout << buffer;
	// }
	return 0;
}
