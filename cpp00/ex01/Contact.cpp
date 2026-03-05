/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:22:34 by trupham           #+#    #+#             */
/*   Updated: 2026/03/05 16:37:07 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string Contact::formatStr(std::string str) {
	std::string ret = str;
	if (str.length() > FIELD_WIDTH) {
		int i;
		for (i = 0; i < FIELD_WIDTH - 1; i++) {
			ret[i] = str[i];
		}
		ret[i] = '.';
		ret.erase(FIELD_WIDTH);
	}
	return ret;
}

std::string Contact::getFirstName() {
	return this->first_name;
}

std::string Contact::getLastName() {
	return this->last_name;
}

std::string Contact::getNickName() {
	return this->nick_name;
}

std::string Contact::getPhone() {
	return this->phone_num;
}

std::string Contact::getSecret() {
	return this->secret;
}

std::ostream& operator<<(std::ostream& os, Contact& c) {
	os << std::setw(FIELD_WIDTH)
		<< std::setw(FIELD_WIDTH) << c.formatStr(c.getFirstName()) << "|"
		<< std::setw(FIELD_WIDTH) << c.formatStr(c.getLastName()) << "|"
		<< std::setw(FIELD_WIDTH) << c.formatStr(c.getNickName());
	return os;
}
