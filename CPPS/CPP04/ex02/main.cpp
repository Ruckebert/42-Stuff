/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:59:19 by aruckenb          #+#    #+#             */
/*   Updated: 2025/04/03 13:16:20 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"

int main()
{
	//Cat Brain Test
	Cat* j = new Cat();

	std::cout << "\nBrain Type Test\n";
	j->makeSound();
	
	//Animal Array Test
	
	std::cout << "\nCleaning Up Tests\n";
	delete j; 
	return 0;
}