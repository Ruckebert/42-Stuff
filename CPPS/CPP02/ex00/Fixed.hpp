/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:14:35 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/17 11:16:46 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
	int	FixNumPoint;
	static const int eight = 8;

	public:
	Harl();
	~Harl();

	int getRawBits(void);
	void setRawBits(int const raw);
} ;

#endif