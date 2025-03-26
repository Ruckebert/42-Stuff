/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:18:25 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/19 10:58:32 by aruckenb         ###   ########.fr       */
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
	Zombie();
	Zombie(std::string name);
	~Zombie();

	// Setter&Getter
	void ZombieNameSet(std::string &input);
	std::string ZombieNameGet(void);
	
	void announce(void);

} ;


Zombie* newZombie (std::string name);
Zombie *zombieHorde(int N, std::string name);

#endif