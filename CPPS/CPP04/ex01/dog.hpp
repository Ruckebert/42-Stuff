/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:55:18 by aruckenb          #+#    #+#             */
/*   Updated: 2025/04/03 13:09:17 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "animal.hpp"
#include "Brain.hpp"

class Dog:public Animal
{
	private:
	Brain *DogBrain;

	public:
	Dog();
	Dog(const Dog& type);
	Dog &operator=(const Dog& type);
	~Dog();
	
	void ShowIdea(int i) const;
	void makeSound(void) const;
	void AddIdea(std::string idea) const;
	void ShowAllIdea(void) const;
};

#endif