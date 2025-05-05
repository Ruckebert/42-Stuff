/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:55:15 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/31 13:22:27 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Constructor" << std::endl;
	this->setType("Dog");
}

Dog::~Dog()
{
	std::cout << "Dog Destructor" << std::endl;
}

Dog::Dog(const Dog &type1) 
{
	std::cout << "Copy constructor called\n";
	this->setType(type1.getType());
}

Dog &Dog::operator=(const Dog& type1)
{
	std::cout << "Copy assignment called\n";
	if (this != &type1)
	{
		this->setType(type1.getType());
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Woof Woof" << std::endl;
}