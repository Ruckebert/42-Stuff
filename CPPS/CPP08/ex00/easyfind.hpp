/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:30:58 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/27 11:28:38 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &type, int num)
{
	typename T::iterator found = std::find(type.begin(), type.end(), num);
	if (found == type.end())
		throw std::runtime_error("Value Not Found!");
	return (found);
}

template <typename T, size_t N>
T easyfind(T (&array)[N], int num)
{
	int i = 0;
	while (array[i])
	{
		if (array[i] == num)
			return (array[i]);
		i++;
	}
	throw std::runtime_error("Value Not Found!");

}


#endif