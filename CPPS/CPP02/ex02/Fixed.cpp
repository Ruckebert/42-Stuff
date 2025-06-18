/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:14:38 by aruckenb          #+#    #+#             */
/*   Updated: 2025/04/08 10:41:25 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() 
{
	//std::cout << "Default Constructor called\n";
	FixNumPoint = 0;
}

Fixed::~Fixed() 
{
	//std::cout << "Destructor called\n";	
}

Fixed::Fixed(int const type)
{
	//std::cout << "Int Constructor called\n";
	FixNumPoint = type << FractBits;
}

Fixed::Fixed(float const type)
{
	//std::cout << "Float Constructor called\n";
	FixNumPoint = roundf(type * (1 << FractBits));
	
}
	
int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits Number Function called\n";	
	return (FixNumPoint);
}

void Fixed::setRawBits(int const raw)
{
	FixNumPoint = raw;
}

Fixed::Fixed(const Fixed &type) 
{
	//std::cout << "Copy constructor called\n";
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

//Min and Max
Fixed& Fixed::min(Fixed& FixNum1, Fixed& FixNum2)
{
	if (FixNum1 < FixNum2)
		return (FixNum1);
	else 
		return (FixNum2);
}

const Fixed& Fixed::min(const Fixed& FixNum1, const Fixed& FixNum2)
{
	if (FixNum1 < FixNum2)
		return (FixNum1);
	else 
		return (FixNum2);
}

Fixed& Fixed::max(Fixed& FixNum1, Fixed& FixNum2)
{
	if (FixNum1 > FixNum2)
		return (FixNum1);
	else 
		return (FixNum2);
	
}

const Fixed& Fixed::max(const Fixed& FixNum1, const Fixed& FixNum2)
{
	if (FixNum1 > FixNum2)
		return (FixNum1);
	else 
		return (FixNum2);
}

//Copy Assignment
Fixed &Fixed::operator=(const Fixed& type)
{
	std::cout << "Copy assignment called\n";
	if (this != &type)
	{
		FixNumPoint = type.getRawBits();
	}
	return (*this);
}

//Comparison Operators
bool Fixed::operator>(const Fixed& type) const
{
	return (this->getRawBits() > type.getRawBits());
}

bool Fixed::operator>=(const Fixed& type)
{
	return (this->getRawBits() >= type.getRawBits());
}

bool Fixed::operator<(const Fixed& type) const
{
	return (this->getRawBits() < type.getRawBits());
}

bool Fixed::operator<=(const Fixed& type)
{
	return (this->getRawBits() <= type.getRawBits());
}

bool Fixed::operator==(const Fixed& type)
{
	return (this->getRawBits() == type.getRawBits());
}

bool Fixed::operator!=(const Fixed& type)
{
	return (this->getRawBits() != type.getRawBits());
}

//Arthemitic Operators 
Fixed Fixed::operator+(const Fixed& type) const
{
	return Fixed(this->toFloat() + type.toFloat());
}

Fixed Fixed::operator*(const Fixed& type) const
{
	return Fixed(static_cast<float>(this->toFloat() * type.toFloat()));
}

Fixed Fixed::operator-(const Fixed& type) const
{
	return Fixed(this->toFloat() - type.toFloat());
}

Fixed Fixed::operator/(const Fixed& type) const
{
	if (type.getRawBits() == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return (Fixed());
	}
	return Fixed((this->toFloat() / type.toFloat()));
}

//Increment and Decrement Operations 

Fixed& Fixed::operator++()
{
	this->FixNumPoint += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->FixNumPoint += 1;
	return (temp);
}

Fixed& Fixed::operator--()
{
	this->FixNumPoint -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->FixNumPoint -= 1;
	return (temp);
}

//Float Print
std::ostream& operator<<(std::ostream& os, const Fixed& type)
{
	os << type.toFloat();
	return (os);
}