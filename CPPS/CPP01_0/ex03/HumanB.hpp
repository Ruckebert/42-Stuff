/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:53:30 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/05 11:26:45 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
	std::string name;
	Weapon *weaponType;
	
	public:
	HumanB(std::string str);
	~HumanB();

	void setWeapon(Weapon &type);
	void attack();
} ;

#endif