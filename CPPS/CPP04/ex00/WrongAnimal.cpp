/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:54:14 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/31 13:41:13 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Constructor" << std::endl;
	type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &type1) 
{
	std::cout << "Copy constructor called\n";
	type = type1.getType();
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& type1)
{
	std::cout << "Copy assignment called\n";
	if (this != &type1)
	{
		type = type1.getType();
	}
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal Noises" << std::endl;
}

void WrongAnimal::setType(std::string ani)
{
	type = ani;
}

std::string WrongAnimal::getType(void) const
{
	return (type);
}