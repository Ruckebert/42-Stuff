/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:59:19 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/15 13:33:39 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Serializer encoder;
	Data type;
	unsigned long decoded;

	type.num = 1;
	std::cout << "Default Address: "<< &type << std::endl;
	std::cout << "Default Num: "<< type.num << std::endl;
	decoded = encoder.serialize(&type);
	std::cout << "encoded Address: "<< decoded << std::endl;
	type = *encoder.deserialize(decoded);
	std::cout << "Decoded Address: "<< &type << std::endl;
	std::cout << "Decoded Num: "<< type.num << std::endl;
}