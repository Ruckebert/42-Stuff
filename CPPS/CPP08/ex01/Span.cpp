/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:35:46 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/30 09:04:35 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	size = 0;
}

Span::Span(unsigned int N): size(N)
{
}

Span::~Span()
{
}

void Span::addNumber(int value)
{
	if (array.size() >= size)
	{
		std::cout << "Container is full!. Cannot insert number:" << value << std::endl;
		return ;//This should throw an exception
	}
	else
		array.push_front(value);
}

int Span::shortestSpan()
{
	unsigned long i = 0;
	unsigned long smallest_position = 0;
	int smallest1 = array[i];
	int	smallest2 = 0;

	while (i < array.size())
	{
		if (array[i] < smallest1)
		{
			smallest1 = array[i];
			smallest_position = i;
		}
		i++;
	}
	i = 0;
	if (i != smallest_position)
		smallest2 = array[i];
	else
	 	smallest2 = array[i + 1];
	while (i < array.size())
	{
		if (array[i] < smallest2 && i != smallest_position)
			smallest2 = array[i];
		i++;
	}
	return (smallest2 - smallest1);
}

int Span::longestSpan()
{
	unsigned long i = 0;
	unsigned long smallest_position = 0;
	int smallest = array[i];
	int	largest = 0;

	while (i < array.size())
	{
		if (array[i] < smallest)
		{
			smallest = array[i];
			smallest_position = i;
		}
		i++;
	}
	i = 0;
	if (i != smallest_position)
		largest = array[i];
	else
	 	largest = array[i + 1];
	i = 0;
	while (i < array.size())
	{
		if (array[i] > largest)
			largest = array[i];
		i++;
	}
	return (largest - smallest);
}

template <typename T>
void Span::addMulti(T array)
{
	int i = 0;
	while (array[i])
	{
		addNumber(array[i]);
		i++;
	}
}