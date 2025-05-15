/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:56:59 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/15 13:31:09 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <iostream>
#include <string>

class Serializer
{
	private:
	
	public:
	Serializer();
	Serializer(const Serializer& type);
	Serializer &operator=(const Serializer& type);
	~Serializer();

	static unsigned long serialize(Data *ptr);
	static Data *deserialize(unsigned long raw);
	
};


#endif