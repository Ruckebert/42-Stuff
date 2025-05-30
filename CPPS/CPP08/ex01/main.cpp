/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:34:13 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/30 09:55:44 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	int array[7] = {1,2,3,4,5,6,7};

	Span type(5);
	type.addNumber(1);
	type.addNumber(3);
	type.addNumber(4);
	type.addNumber(5);
	type.addNumber(6);
	type.addNumber(7);
	
	std::cout << type.shortestSpan() << std::endl;
	std::cout << type.longestSpan() << std::endl;
	
}