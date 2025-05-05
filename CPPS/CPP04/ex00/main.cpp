/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:59:19 by aruckenb          #+#    #+#             */
/*   Updated: 2025/04/30 09:08:00 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\nAnimal Type Test\n";
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << "\nNoise Test\n";
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	
	std::cout << "\nOther Test\n";
	const WrongAnimal* Wrongi = new WrongCat();
	std::cout << "\nWrong Type and Noise Test\n";
	std::cout << Wrongi->getType() << " " << std::endl;
	Wrongi->makeSound(); //will output the cat sound!
	
	std::cout << "\nCLeaning Up Tests\n";
	delete meta;
	delete j; 
	delete i;
	delete Wrongi;
	return 0;
}