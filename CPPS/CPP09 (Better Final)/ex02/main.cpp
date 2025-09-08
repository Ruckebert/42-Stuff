/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:21:51 by aruckenb          #+#    #+#             */
/*   Updated: 2025/09/08 11:46:36 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"
#include <cctype>
#include <ctime>
#include <vector>
#include <deque>

template<typename D2, typename D1>
int startsort(int argc, char **argv, D2 &type1, D1 &left, int com)
{
	int i = 1;
	while (i < argc)
	{
		if (i % 2 == 0)
		{
			if (atoi(argv[i]) < 0 || atoi(argv[i - 1]) < 0)
			{
				return (1); //Negative Number Error
			}
			//here you sort them into pairs the left being the smallest, the right being the biggest
			if (atoi(argv[i]) >= atoi(argv[i - 1]))
			{
				//Vector
				D1 pair;
				pair.push_back(atoi(argv[i - 1]));
				pair.push_back(atoi(argv[i]));
				type1.push_back(pair);
			}
			else
			{
				D1 pair;
				pair.push_back(atoi(argv[i]));
				pair.push_back(atoi(argv[i - 1]));
				type1.push_back(pair);
			}
			com++;
		}
		if ((argc-1) % 2 == 1 && i == (argc - 1))
		{
			left.push_back(atoi(argv[i]));
		}
		i++;
	}
	return (0);
}
bool checker(int argc, char **argv)
{
	int i = 1;
	while (i < argc)
	{
		std::string str = argv[i];
		if (str.length() > 10)
            throw (false);
        if (str.length() == 10 && str > "2147483647")
           	throw (false);
		if (atoi(argv[i]) < 0)
			throw (false);
		size_t j = 0;
		while (argv[i][j])
		{
			if (!std::isdigit(argv[i][j]))
				throw (false);
			j++;
		}
		i++;
	}
	return (true);
}

int main(int argc, char **argv)
{
	std::deque<std::deque<int> > type2;
	std::vector<std::vector<int> > type1; //Maybe have a vector of vectors
	std::vector<int> left;
	std::deque<int> left2;
	int com = 0; //Counter for comparisons 
	int com2 = 0;

	if (argc == 1)
		return (1);
	try
	{
		checker(argc, argv);
	}
	catch(bool error)
	{
		std::cerr << "Error:Invalid Input" << std::endl;
		return (1);
	}

		
	//Elements before
	std::cout << "Before:";
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
	
	//Time and Sort for Vector
	clock_t start = clock(); // start the clock
	startsort(argc, argv, type1, left, com); //first pair sorting
	//std::cout << "Start End" << std::endl;
	int num = 1;
	function(type1, left, num, com); //begin to sort into greater pairs
	//std::cout << "Function End" << std::endl;
	jacobsten(pow(2, num), type1, left, com); //the actually sorting
	//std::cout << "Jacob End" << std::endl;
	clock_t end = clock(); //end the clock
	double duration = double(end - start) / CLOCKS_PER_SEC; //calculate the duration
	//std::cout << "Vector End" << std::endl;

	//Time and Sort for Deque
	clock_t start2 = clock();
	startsort(argc, argv, type2, left2, com2);
	//std::cout << "Start End" << std::endl;
	int num2 = 1;
	function(type2, left2, num2, com2);
	//std::cout << "Function End" << std::endl;
	jacobsten(pow(2, num2), type2, left2, com2);
	//std::cout << "Jacob End" << std::endl;
	clock_t end2 = clock();
	double duration2 = double(end2 - start2) / CLOCKS_PER_SEC;
	//std::cout << "Deque End" << std::endl;
	
	//Printing the elements
	std::cout << "After:";
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
    std::cout << "Sorting time for Vector " <<  type1.size() << " elements: " << duration << " seconds" << std::endl;
    std::cout << "Sorting time for Deque " <<  type2.size() << " elements: " << duration2 << " seconds" << std::endl;
}