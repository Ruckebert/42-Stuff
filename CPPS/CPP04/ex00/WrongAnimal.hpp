/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:55:05 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/31 13:36:57 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	private:
	std::string type;

	public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& type);
	WrongAnimal &operator=(const WrongAnimal& type);
	~WrongAnimal();
	
	//Setters and Getter
	void setType(std::string ani);
	std::string getType(void) const; 
	
	void makeSound(void) const;
};

#endif