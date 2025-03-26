/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:14:35 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/25 10:22:42 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
	int	FixNumPoint;
	static const int FractBits = 8;

	public:
	//Constructors 
	Fixed();
	Fixed(int const type);
	Fixed(float const type);

	//Copy constructor
	Fixed (const Fixed& type);

	//Destructor
	~Fixed();
	
	//Copy Assignment
	Fixed &operator=(const Fixed& type);
	bool operator>(const Fixed& type) const ;
	bool operator>=(const Fixed& type);
	bool operator<(const Fixed& type) const ;
	bool operator<=(const Fixed& type);
	bool operator==(const Fixed& type);
	bool operator!=(const Fixed& type);

	Fixed operator+(const Fixed& type) const ;
	Fixed operator-(const Fixed& type) const ;
	Fixed operator*(const Fixed& type) const ;
	Fixed operator/(const Fixed& type) const ;

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	//Setters and Getters 
	int getRawBits(void) const;
	void setRawBits(int const raw);

	//Conversions 
	float toFloat(void) const;
	int toInt(void) const;

	//New Functions
	static Fixed &min(Fixed &FixNum1, Fixed &FixNum2);
	static const Fixed &min(const Fixed& FixNum1, const Fixed& FixNum2);

	static Fixed &max(Fixed& FixNum1, Fixed& FixNum2);
	static const  Fixed &max(const Fixed& FixNum1, const Fixed& FixNum2);	
};

std::ostream& operator<<(std::ostream& os, const Fixed& type);

#endif