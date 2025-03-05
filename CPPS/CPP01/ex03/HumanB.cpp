/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:06:20 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/05 11:28:03 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string str): name(str), weaponType(nullptr)
{}
HumanB::~HumanB() 
{}

void HumanB::attack()
{
	std::cout << name << " is Attacking with " << weaponType->getType() << std::endl;
}

//Weapon Setter
void HumanB::setWeapon(Weapon& type) {weaponType = &type;}