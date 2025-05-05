/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:55:10 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/31 13:38:54 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "animal.hpp"

class Cat:public Animal
{
	private:

	public:
	Cat();
	Cat(const Cat& type);
	Cat &operator=(const Cat& type);
	~Cat();
	
	void makeSound(void) const;
};

#endif