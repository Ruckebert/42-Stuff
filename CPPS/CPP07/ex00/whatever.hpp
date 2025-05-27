/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:17:16 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/20 12:24:48 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename A>
void swap(A &type1, A &type2)
{
	A type0 = type1;
	type1 = type2;
	type2 = type0;
}

template <typename A>
A min(A type1, A type2)
{
	if (type1 < type2)
		return (type1);
	else if (type2 < type1)
		return (type2);
	else
	 	return (type2);
}

template <typename A>
A max(A type1, A type2)
{
	if (type1 > type2)
		return (type1);
	else if (type2 > type1)
		return (type2);
	else
	 	return (type2);
	return (type2);
}

#endif 