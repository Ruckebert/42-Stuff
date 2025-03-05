/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:06:49 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/05 13:28:22 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon): type(weapon) 
{}

Weapon::~Weapon() 
{}

void Weapon::setType(std::string input) 
{
	type = input;
}


std::string Weapon::getType(void) 
{
	return (type);
}