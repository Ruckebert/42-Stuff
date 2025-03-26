/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:37:31 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/26 11:24:06 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default")
{
	std::cout << "ScavTrap Constructor" << std::endl;
	this->SetClassname("ScavTrap");
	this->SetAttackDamage(20);
	this->SetHp(100);
	this->SetEnergy(50);
}

ScavTrap::ScavTrap(std::string name1): ClapTrap(name1)
{
	std::cout << "ScavTrap Constructor" << std::endl;
	this->SetClassname("ScavTrap");
	this->SetAttackDamage(20);
	this->SetHp(100);
	this->SetEnergy(50);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << this->classNameGetter() << " " << this->NameGetter() << " entering Guard Mode" << std::endl;
}