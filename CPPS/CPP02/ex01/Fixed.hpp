/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:14:35 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/20 10:38:23 by aruckenb         ###   ########.fr       */
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

	//Setters and Getters 
	int getRawBits(void) const;
	void setRawBits(int const raw);

	//New Functions
	float toFloat(void) const;
	int toInt(void) const;

} ;

std::ostream& operator<<(std::ostream& os, const Fixed& type);

#endif