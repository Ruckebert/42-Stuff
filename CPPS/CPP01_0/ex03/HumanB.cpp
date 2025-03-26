/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:06:20 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/19 11:12:35 by aruckenb         ###   ########.fr       */
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
	std::cout << name << " is Attacking with " << weaponType->getType() << std::endl;
}

//Weapon Setter
void HumanB::setWeapon(Weapon& type) {weaponType = &type;}