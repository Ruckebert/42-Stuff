/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:06:20 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/05 11:28:00 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon &type): name(str), weaponType(&type)
{}

HumanA::~HumanA() 
{}

void HumanA::attack()
{
	std::cout << name << " is Attacking with " << weaponType->getType() << std::endl;
}