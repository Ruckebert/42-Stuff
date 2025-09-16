/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:21:51 by aruckenb          #+#    #+#             */
/*   Updated: 2025/09/11 12:21:41 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"
#include <cctype>
#include <ctime>
#include <vector>
#include <deque>


int main(int argc, char **argv)
{
	std::deque<std::deque<int> > type2;
	std::vector<std::vector<int> > type1; //Maybe have a vector of vectors
	std::vector<int> left;
	std::deque<int> left2;
	double duration2 = 0;
	double duration = 0;

	try
	{
		if (argc == 1)
			throw (false);
		checker(argc, argv);
	}
	catch(bool error)
	{
		std::cerr << "Error:Invalid Input" << std::endl;
		return (1);
	}
	
	//Elements before
	std::cout << "Before: ";
	if (argc > 100)
	{
		for (unsigned long i = 1; (int)i < 100; i++) 
		{
			unsigned long j = 0;
			while (argv[i][j])
			{
				std::cout << argv[i][j];
				j++;
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	else
	{
		for (unsigned long i = 1; (int)i < argc; i++) 
		{
			unsigned long j = 0;
			while (argv[i][j])
			{
				std::cout << argv[i][j];
				j++;
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}

	
	//Core Loops
	if (argc != 2)
	{
		core(argc, argv, left, type1, duration);
		core(argc, argv, left2, type2, duration2);

		//Printing the elements after (elements are from the first container)
		std::cout << "After: ";
		if (argc > 100)
		{
			for (unsigned long i = 0; i < 100; i++) 
			{
				unsigned long j = 0;
				while (j < type1[i].size())
				{
					std::cout << type1[i][j] << " ";
					j++;
				}
			}
			std::cout << std::endl;
		}
		else
		{
			for (unsigned long i = 0; i < type1.size(); i++) 
			{
				unsigned long j = 0;
				while (j < type1[i].size())
				{
					std::cout << type1[i][j] << " ";
					j++;
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;

		//Printing the time
		std::cout << "Sorting time for Vector " <<  type1.size() << " elements: " << duration << " seconds" << std::endl;
		std::cout << "Sorting time for Deque " <<  type2.size() << " elements: " << duration2 << " seconds" << std::endl;
	}
	else 
	{
		std::cout << "After: ";
		for (unsigned long i = 1; (int)i < argc; i++) 
		{
			unsigned long j = 0;
			while (argv[i][j])
			{
				std::cout << argv[i][j];
				j++;
			}
			std::cout << " ";
		}
		std::cout << std::endl;
		std::cout << "Sorting time for Vector 1 element: " << duration << " seconds" << std::endl;
		std::cout << "Sorting time for Deque 1 element: " << duration2 << " seconds" << std::endl;
	}
}