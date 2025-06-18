/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:23:03 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/20 11:04:36 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

C::C()
{
	std::cout << "C Constructor" << std::endl;
}

C::~C()
{
	std::cout << "C Destructor" << std::endl;
}

C::C(const C &type1): Base(type1)
{
}

C &C::operator=(const C& type1)
{
	std::cout << "Copy assignment called\n";
	if (this != &type1)
	{
		*this = type1;
	}
	return (*this);
}