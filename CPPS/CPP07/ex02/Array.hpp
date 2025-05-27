/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:21:53 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/26 12:07:35 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>
#include <iostream>

template <typename T>
class Array
{
	private:
	unsigned int arraySize;
	T *array1;
	
	public:
	Array(): arraySize(0), array1(NULL)
	{	
	};
	
	Array(unsigned int n): arraySize(n)
	{
		
		array1 = new T[arraySize];
	};
	
	Array(const Array& type1)
	{
		*this = type1;
	}

	Array &operator=(const Array& type1)
	{
		std::cout << "Copy assignment called\n";
		if (this != &type1)
		{
			*this = type1;
		}
		return (*this);
	};

	class InvalidScope:public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("Index Value is outside of scope!");
		}

	};
	
	T &operator[](unsigned int num)
	{
		try 
		{
			if (num >= arraySize)
				throw InvalidScope();
			return (array1[num]);
		}
		catch (const InvalidScope& e)
		{
			std::cout << e.what() << std::endl;
		}
	};

	const T &operator[](unsigned int num) const
	{
		try 
		{
			if (num >= (unsigned int)arraySize)
				throw InvalidScope();
			return (array1[num]);
		}
		catch (const InvalidScope& e)
		{
			std::cout << e.what() << std::endl;
		}
	};
	
	~Array()
	{
		delete[] array1;
		std::cout << "A Destructor" << std::endl;
	};


	unsigned int size(void) const
	{
		return (arraySize);
	};
};

#endif