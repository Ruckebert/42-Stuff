/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:32:38 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/26 11:23:45 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <typeinfo>

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Constructor" << std::endl;
	className = "ClapTrap";
	name = "Default";
	hp = 10;
	eng = 10;
	atkDmg = 0;
}

ClapTrap::ClapTrap(std::string name1)
{
	std::cout << "ClapTrap Constructor" << std::endl;
	className = "ClapTrap";
	name = name1;
	hp = 10;
	eng = 10;
	atkDmg = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor" << std::endl;	
}

//Setters and Getters
void ClapTrap::SetAttackDamage(int type)
{
	atkDmg = type;
}

void ClapTrap::SetHp(unsigned int type)
{
	hp = type;
}

void ClapTrap::SetEnergy(int type)
{
	eng = type;
}

std::string ClapTrap::NameGetter(void)
{
	return (name);
}

void ClapTrap::SetClassname(std::string type)
{
	className = type;
}

std::string ClapTrap::classNameGetter(void)
{
	return (className);
}


// Actions 

void ClapTrap::attack(const std::string& target)
{
	if (hp == 0)
	{
		std::cout << className << " " << name << " is dead\n";
		return ;
	}
	if (eng != 0)
	{
		std::cout << className << " " << name << " attacks " << target << ", causing " << atkDmg << " points of damage!" << std::endl;
		--eng;
	}
	else 
		std::cout << className << " " << name <<	" has no energy left to attack\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hp == 0)
	{
		std::cout << className << " " << name << " is dead\n";
		return ;
	}
	std::cout << className << " " << name << " has taken " << amount << " damage." << std::endl;

	if (amount > hp)
		hp = 0;
	else
		hp -= amount;

	if (hp == 0)
		std::cout << className << " " << name << " has died\n";
	else
		std::cout << className << " " << name << " has " << hp << " amount left\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hp == 0)
	{
		std::cout << className << " " << name << " is dead\n";
		return ;
	}
	if (eng != 0)
	{
		std::cout << className << " " << name << " Repairs itsself for " << amount << "Hp" << std::endl;
		--eng;
	}
	else
		std::cout << className << " " << name << " has no energy left to repair\n";
}