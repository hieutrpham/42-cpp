/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:28:10 by trupham           #+#    #+#             */
/*   Updated: 2026/03/05 16:38:09 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

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
