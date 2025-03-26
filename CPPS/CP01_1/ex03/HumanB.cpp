/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:06:20 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/20 13:52:14 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string str): name(str)
{
	weaponType = NULL;
}
HumanB::~HumanB() 
{}

void HumanB::attack()
{
	if (this->weaponType == NULL)
	{
		std::cout << name << " is with no weapons " << std::endl;
	}
	else
		std::cout << name << " is Attacking with " << weaponType->getType() << std::endl;
}

//Weapon Setter
void HumanB::setWeapon(Weapon& type) {weaponType = &type;}