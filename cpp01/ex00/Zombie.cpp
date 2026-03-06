/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:55:51 by trupham           #+#    #+#             */
/*   Updated: 2026/03/06 14:12:37 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::~Zombie () {
	std::cout << this->name + " got destroyed!" << std::endl;
}

Zombie::Zombie(std::string name) {
	this->name = name;
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name) {
	return new Zombie(name);
}

void randomChump(std::string name) {
	Zombie z = Zombie(name);
	z.announce();
}
