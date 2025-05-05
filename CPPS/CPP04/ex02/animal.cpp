/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:54:14 by aruckenb          #+#    #+#             */
/*   Updated: 2025/04/30 10:04:10 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Constructor" << std::endl;
	type = "Animal";
}

Animal::~Animal()
{
	std::cout << "Animal Destructor" << std::endl;
}

Animal::Animal(const Animal &type1) 
{
	std::cout << "Copy constructor called\n";
	type = type1.getType();
}

Animal &Animal::operator=(const Animal& type1)
{
	std::cout << "Copy assignment called\n";
	if (this != &type1)
	{
		type = type1.getType();
	}
	return (*this);
}

void Animal::setType(std::string ani)
{
	type = ani;
}

std::string Animal::getType(void) const
{
	return (type);
}