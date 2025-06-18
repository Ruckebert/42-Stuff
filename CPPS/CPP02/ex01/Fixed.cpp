/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:14:38 by aruckenb          #+#    #+#             */
/*   Updated: 2025/04/08 10:33:29 by aruckenb         ###   ########.fr       */
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

Fixed::Fixed(int const type)
{
	std::cout << "Int Constructor called\n";
	FixNumPoint = type << FractBits;
}

Fixed::Fixed(float const type)
{
	std::cout << "Float Constructor called\n";
	FixNumPoint = roundf(type * (1 << FractBits));
	
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

float Fixed::toFloat(void) const
{
	double const floatype = static_cast<float>(FixNumPoint)/ (1 << FractBits);
	return (floatype);	
}

int Fixed::toInt(void) const
{
	return (FixNumPoint >> FractBits);
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

std::ostream& operator<<(std::ostream& os, const Fixed& type)
{
	os << type.toFloat();
	return (os);
}
