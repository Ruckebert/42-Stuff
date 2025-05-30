/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:34:42 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/29 12:28:02 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef SPAN_HPP
#define SPAN_HPP

#include <deque>

class Span
{
	private:
	//container to store the int
	std::deque<int> array;
	unsigned int size;

	public:
	Span();	
	Span(unsigned int N);
	~Span();


	void addNumber(int value);
	int shortestSpan(); //gets the 2 smallest values and subtracts them and returns them
	int longestSpan(); //Gets the smallest and biggest value and subtract them together
	
	template <typename T>
	void addMulti(T array);
};

#endif