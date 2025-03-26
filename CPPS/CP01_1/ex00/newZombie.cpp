/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:19:03 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/03 14:44:46 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie (std::string name)
{
	Zombie *New;
	
	New = new Zombie(name);
	New->ZombieNameSet(name);

	return (New);
}