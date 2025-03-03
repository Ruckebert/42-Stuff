/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:18:16 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/03 14:43:50 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


//Dont forget to delete the randomChump and rework this main to show off zombiehorde


int main()
{
	Zombie *NewBeing;
	std::string NewName;
	int i;

	std::cout << "Please Enter the New Zombie: ";
	std::cin >> NewName;
	if (std::cin.eof())
	{
		std::cout << "Error Exiting!" << std::endl;
		return (1);
	}
	std::cout << std::endl ; 
	NewBeing = newZombie(NewName);
	
	std::cout << std::endl ; 
	std::cout << "Please Enter the Name of this random Chump: ";
	std::cin >> NewName;
	if (std::cin.eof())
	{
		std::cout << "Error Exiting!" << std::endl;
		delete NewBeing;
		return (1);
	}
	std::cout << std::endl ; 
	randomChump(NewName);

	
	std::cout << "Do you Wish to kill the Named Zombie or Search for it?" << std::endl;
	std::cout << "1: Kill" << std::endl;
	std::cout << "2: Search" << std::endl;
	std::cout << "Enter the Numbered Option: ";
	std::cin >> i;
	if (std::cin.eof())
	{
		std::cout << "Error Exiting!" << std::endl;
		delete NewBeing;
		return (1);
	}

	if (i == 1)
	{
		std::cout << "You found the Zombie " << NewBeing->ZombieNameGet() << " Well Done!" << std::endl;
		std::cout << "BANG!!!! You killed them" << std::endl ;
		std::cout << "Exiting Program! Thanks for Playing" << std::endl ;
		delete NewBeing;
		return (0);
	}
	else if (i == 2)
	{
		std::cout << "Omg You Found " << NewBeing->ZombieNameGet() << std::endl;
		std::cout << std::endl ; 
		std::cout << "What Should Their New Name be: ";
		std::cin >> NewName;
		delete NewBeing;
		NewBeing = newZombie(NewName);
		std::cout << "Exiting Program! Thanks for Playing" << std::endl ;
		delete NewBeing;
		return (0);
	}
	else
	{
		std::cout << "Invalid Number! Exiting Program" << std::endl;
		delete NewBeing;
		return (1);
	}
}