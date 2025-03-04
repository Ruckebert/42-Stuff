/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:53:30 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/04 15:05:27 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
	std::string name;
	Weapon weaponType;
	
	public:
	HumanB(std::string str) {name = str;}
	~HumanB() {}

	void setWeapon(std::string weapon) {weaponType.setType(weapon);}
} ;

#endif