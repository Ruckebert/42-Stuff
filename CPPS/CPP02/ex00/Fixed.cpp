/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:14:38 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/18 10:56:30 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() 
{
	std::cout << "Default Constructor called\n";
	FixNumPoint = 0;
}

Fixed::~Fixed() 
{
	std::cout << "Destructor called\n";	
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits Number Function called\n";	
	return (FixNumPoint);
}

void Fixed::setRawBits(int const raw)
{
	FixNumPoint = raw;
}

Fixed::Fixed(const Fixed &type) 
{
	std::cout << "Copy constructor called\n";
	FixNumPoint = type.getRawBits();
}

Fixed &Fixed::operator=(const Fixed& type)
{
	std::cout << "Copy assignment called\n";
	if (this != &type)
	{
		FixNumPoint = type.getRawBits();
	}
	return (*this);
}