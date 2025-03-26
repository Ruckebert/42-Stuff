/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:28:52 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/04 14:12:45 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *NewBeing;
	std::string NewName;
	int i = 0;
	int N = 0;

	//Omg its Youre Zombie
	std::cout << "Please Enter the New Zombie species: ";
	std::cin >> NewName;
	if (std::cin.eof())
	{
		std::cout << "Error Exiting!" << std::endl;
		return (1);
	}
	std::cout << std::endl ;

	//Numbers
	std::cout << "Please Enter the Numbers of Zombies you can see: ";
	std::cin >> N;
	if (std::cin.eof())
	{
		std::cout << "Error Exiting!" << std::endl;
		return (1);
	}
	std::cout << std::endl ;
	
	NewBeing = zombieHorde(N, NewName);
	while (i < N)
	{
		NewBeing[i].announce();
		std::cout << "Zombie Number: " << i << std::endl;
		i++;
	}
	delete[] NewBeing;
	return (0);
}