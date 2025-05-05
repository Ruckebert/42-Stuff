/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:55:18 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/31 13:38:30 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "animal.hpp"

class Dog:public Animal
{
	private:

	public:
	Dog();
	Dog(const Dog& type);
	Dog &operator=(const Dog& type);
	~Dog();
	
	void makeSound(void) const ;
};

#endif