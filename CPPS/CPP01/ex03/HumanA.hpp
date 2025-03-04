/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:53:30 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/04 15:08:45 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
	std::string name;
	Weapon weaponType;

	public:
	HumanA(std::string str, Weapon type) {name = str; weaponType = type;}
	~HumanA() {}

	void setWeapon(std::string weapon) {weaponType.setType(weapon);}
} ;

#endif