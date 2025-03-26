/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:26:45 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/26 11:43:05 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default")
{
	std::cout << "FragTrap Constructor" << std::endl;
	this->SetClassname("FragTrap");
	this->SetAttackDamage(30);
	this->SetHp(100);
	this->SetEnergy(100);
}

FragTrap::FragTrap(std::string name1): ClapTrap(name1)
{
	std::cout << "FragTrap Constructor" << std::endl;
	this->SetClassname("FragTrap");
	this->SetAttackDamage(30);
	this->SetHp(100);
	this->SetEnergy(100);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::string decision;
	std::cout << "High Five!" << std::endl;
	std::cout << "Please enter either Yes or No: ";
	std::getline(std::cin, decision);
	if (std::cin.eof())
	{
		std::cerr << "\nError Input!!" << std::endl;
		return ;
	}
	std::cout << std::endl;
	if ((decision.compare("yes") == 0) || (decision.compare("Yes") == 0))
		std::cout << "Yippeeeee!! Thanks for the High Five!" << std::endl;
	else if ((decision.compare("no") == 0) || (decision.compare("No") == 0))
		std::cout << "Awwweeee Okay....." << std::endl;
	else
		std::cout << "Huh What are you doing??" << std::endl;
}