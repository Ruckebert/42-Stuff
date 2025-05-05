/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:55:10 by aruckenb          #+#    #+#             */
/*   Updated: 2025/04/03 13:15:20 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "animal.hpp"
#include "Brain.hpp"

class Cat:public Animal
{
	private:
	Brain *CatBrain;

	public:
	Cat();
	Cat(const Cat& type);
	Cat &operator=(const Cat& type);
	~Cat();
	
	void makeSound(void) const ;
	void AddIdea(std::string idea) const;
	void ShowIdea(int i) const;
	void ShowAllIdea(void) const;
};

#endif