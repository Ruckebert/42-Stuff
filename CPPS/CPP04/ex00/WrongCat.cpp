/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:55:07 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/31 13:32:40 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat Constructor" << std::endl;
	this->setType("WrongCat");
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &type1) 
{
	std::cout << "Copy constructor called\n";
	this->setType(type1.getType());
}

WrongCat &WrongCat::operator=(const WrongCat& type1)
{
	std::cout << "Copy assignment called\n";
	if (this != &type1)
	{
		this->setType(type1.getType());
	}
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "Wrong Meow Wrong Meow" << std::endl;
}