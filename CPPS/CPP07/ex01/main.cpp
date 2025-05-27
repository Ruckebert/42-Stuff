/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:49:16 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/21 13:43:11 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

void	printstr(std::string &dogs)
{
	std::cout << dogs << std::endl;
}

void	printint(int &nums)
{
	std::cout << nums << std::endl;
}

int main()
{
	std::string dogs[4] = {"dog1", "dog2", "dog3", "dog4"};
	int	num[4] = {1,2,3,4};
	std::string *cat = NULL;
	
	iter(dogs, 4, printstr); //Nomarl Test
	iter(dogs, 5, printstr); //Over length
	iter(dogs, 2, printstr); //Less ;ength
	iter(cat, 5, printstr); //Invalid Array
	iter(num, 4, printint); //Int Array
}