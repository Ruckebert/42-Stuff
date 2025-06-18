/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:37:34 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/27 13:02:56 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
 
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:

	public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& type);
	ScavTrap &operator=(const ScavTrap& type);
	~ScavTrap();
	
	void attack(const std::string& target);

	//New Skill
	void guardGate();
};


#endif