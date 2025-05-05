/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:55:07 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/31 13:19:53 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Constructor" << std::endl;
	this->setType("Cat");
}

Cat::~Cat()
{
	std::cout << "Cat Destructor" << std::endl;
}

Cat::Cat(const Cat &type1) 
{
	std::cout << "Copy constructor called\n";
	this->setType(type1.getType());
}

Cat &Cat::operator=(const Cat& type1)
{
	std::cout << "Copy assignment called\n";
	if (this != &type1)
	{
		this->setType(type1.getType());
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}