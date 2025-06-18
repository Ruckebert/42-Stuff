/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:59:19 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/12 10:55:00 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"

int main()
{
	//Cat Brain Test
	Cat* j = new Cat();
	//Animal *K = new Animal(); //Test To show that animal is a abstract class
	Animal *K = new Dog();


	std::cout << "\nBrain Type Test\n";
	j->makeSound();
	K->makeSound();
	
	//Animal Array Test
	std::cout << "\nCleaning Up Tests\n";
	delete j; 
	delete K;
	return 0;
}