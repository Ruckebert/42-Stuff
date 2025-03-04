/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:51:22 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/04 15:04:07 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>
#include <new>

class Weapon
{
	private:
	std::string type;

	public:
	Weapon(std::string weapon) {type = weapon;}
	~Weapon() {}

	// Setter&Getter
	void setType(std::string input) {type = input;}
	std::string getType(void) {return (type);}
} ;

#endif