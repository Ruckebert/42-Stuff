/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:22:12 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/20 11:04:24 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

A::A()
{
	std::cout << "A Constructor" << std::endl;
}

A::~A()
{
	std::cout << "A Destructor" << std::endl;
}

A::A(const A &type1): Base(type1)
{
}

A &A::operator=(const A& type1)
{
	std::cout << "Copy assignment called\n";
	if (this != &type1)
	{
		*this = type1;
	}
	return (*this);
}