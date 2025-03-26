/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:42:29 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/04 12:46:12 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *Horde = new Zombie[N];
	int i = 0;
	while (i < N)
	{
		Horde[i] = Zombie(name);
		i++;
	}
	return (Horde);
}