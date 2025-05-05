/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:55:07 by aruckenb          #+#    #+#             */
/*   Updated: 2025/04/01 10:57:18 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Constructor" << std::endl;
	this->setType("Cat");
	CatBrain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat Destructor" << std::endl;
	delete CatBrain;
}

Cat::Cat(const Cat &type1) 
{
	std::cout << "Copy constructor called\n";
	this->setType(type1.getType());
	CatBrain = type1.CatBrain;
}

Cat &Cat::operator=(const Cat& type1)
{
	std::cout << "Copy assignment called\n";
	if (this != &type1)
	{
		this->setType(type1.getType());
		CatBrain = type1.CatBrain;
	}
	return (*this);
}

void Cat::ShowIdea(int i) const
{
	std::cout << CatBrain->GetIdea(i);
}

void Cat::ShowAllIdea(void) const
{
	int i = 0;
	while (i < 100)
	{
		std::cout << CatBrain->GetIdea(i);
		i++;
	}
}

void Cat::AddIdea(std::string idea) const
{
	CatBrain->IdeasAdder(idea);
}

void Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}