/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:57:07 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/15 13:31:59 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "ScalarConverter Constructor" << std::endl;
}


Serializer::~Serializer()
{
	std::cout << "ScalarConverter Destructor" << std::endl;
}

Serializer::Serializer(const Serializer &type1) 
{
	std::cout << "Copy constructor called\n";
	*this = type1;
}

Serializer &Serializer::operator=(const Serializer& type1)
{
	std::cout << "Copy assignment called\n";
	if (this != &type1)
	{
		*this = type1;
	}
	return (*this);
}

unsigned long Serializer::serialize(Data *ptr)
{
	if (ptr == NULL)
		return (0);
	unsigned long i = reinterpret_cast<unsigned long>(ptr);
	return (i);
	
}

Data *Serializer::deserialize(unsigned long raw)
{
	Data *i = reinterpret_cast<Data*>(raw);
	return (i);
}
	