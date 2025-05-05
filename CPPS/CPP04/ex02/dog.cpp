/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:55:15 by aruckenb          #+#    #+#             */
/*   Updated: 2025/04/03 14:21:42 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Constructor" << std::endl;
	this->setType("Dog");
	DogBrain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog Destructor" << std::endl;
	delete DogBrain;
}

Dog::Dog(const Dog &type1) 
{
	std::cout << "Copy constructor called\n";
	this->setType(type1.getType());
	DogBrain = type1.DogBrain;
}

Dog &Dog::operator=(const Dog& type1)
{
	std::cout << "Copy assignment called\n";
	if (this != &type1)
	{
		this->setType(type1.getType());
		DogBrain = type1.DogBrain;
	}
	return (*this);
}

void Dog::ShowIdea(int i) const
{
	std::cout << DogBrain->GetIdea(i);
}

void Dog::makeSound(void) const
{
	std::cout << "Woof Woof" << std::endl;
}