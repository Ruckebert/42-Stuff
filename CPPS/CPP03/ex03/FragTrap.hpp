/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:27:02 by aruckenb          #+#    #+#             */
/*   Updated: 2025/04/09 11:04:56 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
 
#include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap
{
	private:

	public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& type);
	FragTrap &operator=(const FragTrap& type);
	~FragTrap();

	void highFivesGuys(void);
};

#endif