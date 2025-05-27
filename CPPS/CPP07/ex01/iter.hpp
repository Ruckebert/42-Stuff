/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:25:44 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/21 13:41:12 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef>
#include <string>
#include <iostream>

template <typename A, typename F>
void iter(A* address, unsigned int length, F function)
{
	if (address == NULL)
		return ;
	unsigned int size = sizeof(address) / 2;
	if (length != size)
		return ;
	unsigned int i = 0;
	while (i < length)
	{	
		function(address[i]);
		i++;
	}
}



#endif