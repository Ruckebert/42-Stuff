/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:55:10 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/31 13:40:28 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat:public WrongAnimal
{
	private:

	public:
	WrongCat();
	WrongCat(const WrongCat& type);
	WrongCat &operator=(const WrongCat& type);
	~WrongCat();
	
	void makeSound(void) const;
};

#endif