/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:27:44 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/25 14:59:46 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	int i = 0;
	ClapTrap michael("Michael");

	michael.attack("David");
	michael.takeDamage(9);
	while (i < 10)
	{
		michael.beRepaired(1);
		i++;
	}
	michael.attack("David");
	michael.takeDamage(10);
}