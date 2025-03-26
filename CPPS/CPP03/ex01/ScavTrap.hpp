/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:37:34 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/26 11:04:10 by aruckenb         ###   ########.fr       */
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
	~ScavTrap();

	//New Skill
	void guardGate();
};


#endif