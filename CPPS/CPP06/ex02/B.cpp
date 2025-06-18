/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:44:35 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/20 11:04:32 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

B::B()
{
	std::cout << "B Constructor" << std::endl;
}

B::~B()
{
	std::cout << "B Destructor" << std::endl;
}

B::B(const B &type1): Base(type1)
{
}

B &B::operator=(const B& type1)
{
	std::cout << "Copy assignment called\n";
	if (this != &type1)
	{
		*this = type1;
	}
	return (*this);
}