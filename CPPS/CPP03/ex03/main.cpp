/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:27:44 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/26 11:39:18 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	int i = 0;
	FragTrap michael("Michael");

	michael.attack("David");
	michael.takeDamage(9);
	while (i < 5)
	{
		michael.beRepaired(1);
		i++;
	}
	michael.attack("David");
	michael.takeDamage(10);
	michael.highFivesGuys();
}