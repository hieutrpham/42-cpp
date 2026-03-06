/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:43:51 by trupham           #+#    #+#             */
/*   Updated: 2026/03/06 14:13:32 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie *z = newZombie("heap zombie");
	z->announce();
	randomChump("random");
	std::cout << "here at main\n";
	delete z;
	return 0;
}
