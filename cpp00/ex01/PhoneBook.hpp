/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:20:55 by trupham           #+#    #+#             */
/*   Updated: 2026/03/05 16:36:09 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include "Contact.hpp"
#define CONTACT_CAP 8

class PhoneBook {
private:
	Contact contacts[CONTACT_CAP];
	int contact_count;

public:
	PhoneBook() : contact_count(0) {}
	~PhoneBook() {}

	Contact& getContact(int index);
	int getContactCount();
	bool addContact();
	bool searchContact();
};
std::ostream& operator<<(std::ostream& os, PhoneBook& p);
