/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:51:03 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/26 13:06:56 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
 
#include "ClapTrap.hpp"

class DiamondTrap: public ClapTrap, public FragTrao, public ScavTrap
{
	private:

	public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();

	void highFivesGuys(void);
};

#endif