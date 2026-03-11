/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:22:58 by trupham           #+#    #+#             */
/*   Updated: 2026/03/06 10:03:28 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include "main.hpp"

class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_num;
	std::string secret;

public:
	Contact();
	~Contact();
	Contact(
		std::string first_name,
		std::string last_name,
		std::string nick_name,
		std::string phone_num,
		std::string secret
	);

	std::string formatStr(std::string str);
	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string getPhone();
	std::string getSecret();
};

std::ostream& operator<<(std::ostream& os, Contact& c);

#endif // !CONTACT_H
