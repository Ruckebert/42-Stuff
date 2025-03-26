/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:14:35 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/18 10:56:34 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
	int	FixNumPoint;
	static const int FractBits = 8;

	public:
	Fixed();
	~Fixed();
	Fixed (const Fixed& type);
	Fixed &operator=(const Fixed& type);

	int getRawBits(void) const;
	void setRawBits(int const raw);
} ;

#endif