/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:27:02 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/26 11:37:07 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
 
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	private:

	public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();

	void highFivesGuys(void);
};

#endif