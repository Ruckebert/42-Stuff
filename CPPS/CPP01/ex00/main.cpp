/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:18:16 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/03 14:45:10 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *NewBeing;
	std::string NewName;
	int i;

	//Omg its Youre Zombie
	std::cout << "Please Enter the New Zombie: ";
	std::cin >> NewName;
	if (std::cin.eof())
	{
		std::cout << "Error Exiting!" << std::endl;
		return (1);
	}
	std::cout << std::endl ; 
	NewBeing = newZombie(NewName);
	NewBeing->announce();
	
	//Chump Boy
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

	//Lets Play A Quick game
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

	//What will you do!
	if (i == 1) //All Zombies must die
	{
		std::cout << "You found the Zombie " << NewBeing->ZombieNameGet() << " Well Done!" << std::endl;
		std::cout << "BANG!!!! You killed them" << std::endl ;
		std::cout << "Exiting Program! Thanks for Playing" << std::endl ;
		delete NewBeing;
		return (0);
	}
	else if (i == 2) //wow You choose to look for them lets rename them
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
	else //Welp Looks like you didnt want to play lets exit
	{
		std::cout << "Invalid Number! Exiting Program" << std::endl;
		delete NewBeing;
		return (1);
	}
}