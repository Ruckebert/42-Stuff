/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:37:31 by aruckenb          #+#    #+#             */
/*   Updated: 2025/04/09 10:59:26 by aruckenb         ###   ########.fr       */
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

ScavTrap::ScavTrap(const ScavTrap &type) : ClapTrap(type)
{
	std::cout << "Copy constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap& type)
{
	std::cout << "Copy assignment called\n";
	if (this != &type)
	{
		ClapTrap::operator=(type);
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (this->GetHp() == 0)
	{
		std::cout << "ScavTrap " << this->NameGetter() << " is dead\n";
		return ;
	}
	if (this->GetEng() != 0)
	{
		std::cout << "ScavTrap " << this->NameGetter() << " scratches " << target << ", causing " << this->GetAttackDamage() << " points of damage!" << std::endl;
		this->SetEnergy(this->GetEng() - 1);
	}
	else 
		std::cout << "ScavTrap " << this->NameGetter() <<	" has no energy left to attack\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << this->classNameGetter() << " " << this->NameGetter() << " entering Guard Mode" << std::endl;
}