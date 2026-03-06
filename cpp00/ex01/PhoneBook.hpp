/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:20:55 by trupham           #+#    #+#             */
/*   Updated: 2026/03/06 10:04:01 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "main.hpp"
#include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[CONTACT_CAP];
	int contact_count = 0;
	int oldest_contact = 0;

public:
	PhoneBook();
	~PhoneBook();

	Contact& getContact(int index);
	int getContactCount();
	bool addContact();
	bool searchContact();
};
std::ostream& operator<<(std::ostream& os, PhoneBook& p);

#endif // !PHONEBOOK_H
