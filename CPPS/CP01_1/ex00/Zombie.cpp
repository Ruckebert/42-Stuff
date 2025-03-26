/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:18:59 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/19 11:10:50 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name): name(name) {}

Zombie::~Zombie() 
{
	std::cout << ZombieNameGet() << " Deconstructing" << std::endl;
	
}

void Zombie::ZombieNameSet(std::string &input) 
{
	name = input;
}

std::string Zombie::ZombieNameGet(void) 
{
	return (name);
}

void	Zombie::announce(void)
{
	std::cout << ZombieNameGet() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

