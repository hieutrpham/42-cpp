/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:22:58 by trupham           #+#    #+#             */
/*   Updated: 2026/03/05 16:36:22 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
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

	std::string formatStr(std::string str);
	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string getPhone();
	std::string getSecret();
};

std::ostream& operator<<(std::ostream& os, Contact& c);
