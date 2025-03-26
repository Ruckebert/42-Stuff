/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:32:38 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/25 14:57:55 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap()
{
	name = "Default";
	hp = 10;
	eng = 10;
	atkDmg = 0;
}

ClapTrap::ClapTrap(std::string name1)
{
	name = name1;
	hp = 10;
	eng = 10;
	atkDmg = 0;
}

ClapTrap::~ClapTrap()
{

	
}


void ClapTrap::attack(const std::string& target)
{
	if (hp == 0)
	{
		std::cout << "ClapTrap " << name <<	" is dead\n";
		return ;
	}
	if (eng != 0)
	{
		std::cout << "ClapTrap " << name <<	" attacks " << target << ", causing " << atkDmg << " points of damage!" << std::endl;
		--eng;
	}
	else 
		std::cout << "ClapTrap " << name <<	" has no energy left to attack\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hp == 0)
	{
		std::cout << "ClapTrap " << name <<	" is dead\n";
		return ;
	}
	std::cout << "ClapTrap " << name <<	" has taken " << amount << " damage." << std::endl;

	if (amount > hp)
		hp = 0;
	else
		hp -= amount;

	if (hp == 0)
		std::cout << "ClapTrap " << name <<	" has died\n";
	else
		std::cout << "ClapTrap " << name <<	" has " << hp << " amount left\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hp == 0)
	{
		std::cout << "ClapTrap " << name <<	" is dead\n";
		return ;
	}
	if (eng != 0)
	{
		std::cout << "ClapTrap " << name <<	" Repairs itsself for " << amount << "Hp" << std::endl;
		--eng;
	}
	else
		std::cout << "ClapTrap " << name <<	" has no energy left to repair\n";
}