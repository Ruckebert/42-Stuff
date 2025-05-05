/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:55:05 by aruckenb          #+#    #+#             */
/*   Updated: 2025/04/30 09:29:32 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
	std::string type;

	public:
	Animal();
	Animal(const Animal& type);
	Animal &operator=(const Animal& type);
	virtual ~Animal();
	
	//Setters and Getter
	void setType(std::string ani);
	std::string getType(void) const; 
	
	virtual void makeSound(void) const = 0;
};

#endif