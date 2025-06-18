/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:32:38 by aruckenb          #+#    #+#             */
/*   Updated: 2025/04/09 11:00:03 by aruckenb         ###   ########.fr       */
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

ClapTrap::ClapTrap(const ClapTrap &type) 
{
	std::cout << "Copy constructor called\n";
	name = type.name;
	hp = type.hp;
	eng = type.eng;
	atkDmg = type.atkDmg;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& type)
{
	std::cout << "Copy assignment called\n";
	if (this != &type)
	{
		name = type.name;
		hp = type.hp;
		eng = type.eng;
		atkDmg = type.atkDmg;
	}
	return (*this);
}

//Setters and Getters
void ClapTrap::SetAttackDamage(int type)
{
	atkDmg = type;
}

int ClapTrap::GetAttackDamage(void)
{
	return (atkDmg);
}

void ClapTrap::SetHp(unsigned int type)
{
	hp = type;
}

unsigned int ClapTrap::GetHp(void)
{
	return (hp);
}

void ClapTrap::SetEnergy(int type)
{
	eng = type;
}

int ClapTrap::GetEng(void)
{
	return (eng);
}

void ClapTrap::Namesetter(std::string type)
{
	name = type;
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
		std::cout << "ClapTrap " << name <<	" is dead\n";
		return ;
	}
	if (eng != 0)
	{
		std::cout << "ClapTrap " << name <<	" Repairs itsself for " << amount << "Hp" << std::endl;
		if (amount >= 2147483646)
		{
			hp = 2147483647;
			std::cout << "ClapTrap " << name <<	" Hitpoints is maxed out." << std::endl;
		}
		else
			hp += amount;
		--eng;
	}
	else
		std::cout << "ClapTrap " << name <<	" has no energy left to repair\n";
}