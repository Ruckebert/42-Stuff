/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:51:22 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/05 11:19:15 by aruckenb         ###   ########.fr       */
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
	Weapon(std::string weapon);
	~Weapon();

	void setType(std::string input);
	std::string getType(void);
} ;

#endif