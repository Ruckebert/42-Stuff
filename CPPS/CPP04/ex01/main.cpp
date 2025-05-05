/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:59:19 by aruckenb          #+#    #+#             */
/*   Updated: 2025/04/01 11:09:50 by aruckenb         ###   ########.fr       */
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
	j->ShowIdea(1);
	j->AddIdea("Hello Meow\n");
	j->ShowIdea(1);

	//Copy Cat
	std::cout << "\nCopy Brain Type Test\n";
	Cat *k = j;

	k->ShowIdea(1);
	
	//Animal Array Test
	std::cout << "\nAnimal Array Test\n";
	Animal *animals[4] = {new Dog(), new Cat(), new Dog(), new Cat()};

	std::cout << "\nSound of Animal 1\n";
	animals[1]->makeSound();

	std::cout << "\nDeleting Array\n";
	int i = 0;
	while (i < 4)
	{
		delete animals[i];
		i++;
	}
	
	std::cout << "\nCleaning Up Tests\n";
	delete j; 
	return 0;
}