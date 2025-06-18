/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:51:00 by aruckenb          #+#    #+#             */
/*   Updated: 2025/04/09 11:05:33 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name")
{
	std::cout << "DiamondTrap Constructor" << std::endl;
	_name = "Default";
	this->SetClassname("DiamondTrap");
	this->SetAttackDamage(30);
	this->SetHp(100);
	this->SetEnergy(50);
}

DiamondTrap::DiamondTrap(std::string name1): ClapTrap(name1 + "_clap_name")
{
	std::cout << "DiamondTrap Constructor" << std::endl;
	_name = name1;
	this->SetClassname("DiamondTrap");
	this->SetAttackDamage(30);
	this->SetHp(100);
	this->SetEnergy(50);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &type) : ClapTrap(type)
{
	std::cout << "Copy constructor called\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& type)
{
	std::cout << "Copy assignment called\n";
	if (this != &type)
	{
		ClapTrap::operator=(type);
	}
	return (*this);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "My Name is " << _name << ", " << "My ClapTrap Name is " << this->NameGetter() << std::endl;
}