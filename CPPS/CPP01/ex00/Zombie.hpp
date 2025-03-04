/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:18:25 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/04 12:27:08 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <new>

class Zombie
{
	private:
	std::string name;

	public:
	Zombie(std::string name): name(name) {}
	~Zombie() {}

	// Setter&Getter
	void ZombieNameSet(std::string &input) {name = input;}
	std::string ZombieNameGet(void) {return (name);}
	
	void announce(void);


} ;


Zombie* newZombie (std::string name);
void randomChump(std::string name);

#endif