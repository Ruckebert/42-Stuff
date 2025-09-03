/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:21:51 by aruckenb          #+#    #+#             */
/*   Updated: 2025/09/02 09:31:41 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	std::deque<std::deque<int> > type2;
	std::vector<std::vector<int> > type1; //Maybe have a vector of vectors
	std::vector<int> left;
	std::deque<int> leftd;
	int com = 0; //Counter for comparisons 


	if (argc == 1)
		return (1);
	
	int i = 1;
	while (i < argc) //simple creating the first pairs, and putting them into their containers
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
				std::vector<int> pair;
				pair.push_back(atoi(argv[i - 1]));
				pair.push_back(atoi(argv[i]));
				type1.push_back(pair);

				//Deque
				/*std::deque<int> dpair;
				dpair.push_back(atoi(argv[i - 1]));
				dpair.push_back(atoi(argv[i]));
				type2.push_back(dpair);*/
				com++;
			}
			else if (atoi(argv[i]) <= atoi(argv[i - 1]))
			{
				//Vector
				std::vector<int> pair;
				pair.push_back(atoi(argv[i]));
				pair.push_back(atoi(argv[i - 1]));
				type1.push_back(pair);

				//Deque
				/*std::deque<int> dpair;
				dpair.push_back(atoi(argv[i - 1]));
				dpair.push_back(atoi(argv[i]));
				type2.push_back(dpair);*/
				com++;
			}
		}
		if ((argc-1) % 2 == 1 && i == (argc - 1))
		{
			if (atoi(argv[i]) < 0)
				return (1); //Negative Number Error
			left.push_back(atoi(argv[i]));
			//leftd.push_back(atoi(argv[i]));
		}
		i++;
	} //get the size of the 2d vector and reduce it by /2 add the odd ones into a seperate vector, idk if this is a single vector or 2d one

	std::cout << "Vector Before:";
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
	//int comD = com;

	//Sorting them into greater pairs
	int num = 1;
	//int num2 = 1;
	std::cout << "Function" << std::endl;
	function(type1, left, num, com);
	//functionD(type2, leftd, num2, comD);
	std::cout << "Function Finish" << std::endl;

	
	//Jacobsthal Numbers!
	std::cout << "Jacob" << std::endl;
	jacobsten(num, type1, left, com);
	//jacobstenD(num2, type2, leftd, comD);
	std::cout << "Jacob Finish" << std::endl;
	
	std::cout << "Comparsions Vector:" << com << std::endl;
	std::cout << "Vector:";
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
	/*std::cout << "Comparsions Deque:" << comD << std::endl;
	std::cout << "Deque: " << std::endl;
	for (unsigned long i = 0; i < type2.size(); i++) 
	{
		unsigned long j = 0;
		while (j < type2[i].size())
		{
			std::cout << type2[i][j] << " ";
			j++;
		}
	}
	std::cout << std::endl;*/
	
	//printer 1
	/*for (unsigned long i = 0; i < type2.size(); i++) 
	{
		unsigned long j = 0;
  		while (j < type2[i].size())
		{
			std::cout << type1[i][j] << " ";
			j++;
		}
		std::cout << std::endl;
	}
	if (leftd.empty() == 0)
	{
		std::cout << leftd[0] << std::endl;
	}
	std::cout << std::endl;*/
		//Printer 2
	/*for (unsigned long i = 0; i < type1.size(); i++) 
	{
		unsigned long j = 0;
  		while (j < type1[i].size())
		{
			std::cout << type1[i][j] << " ";
			j++;
		}
		std::cout << std::endl;
	}
	if (left.empty() == 0)
	{
		size_t i = 0;
		while (i < left.size())
		{
			std::cout << left[i] << " ";
			i++;
		}
		std::cout << std::endl;
	}
	//std::cout << num << std::endl;
	std::cout << std::endl;*/
	//Printers 3
	/*std::cout << "Main" << std::endl;
	for (unsigned long i = 0; i < type1.size(); i++) 
	{
		std::cout << "Group:" << i << " ";
		unsigned long j = 0;
  		while (j < type1[i].size())
		{
			std::cout << type1[i][j] << " ";
			j++;
		}
		std::cout << std::endl;
	}*/
	/*
	std::cout << std::endl;
	std::cout << "Pend" << std::endl;
	for (unsigned long i = 0; i < pend.size(); i++) 
	{
		std::cout << "Group:" << i << " ";
		unsigned long j = 0;
  		while (j < pend[i].size())
		{
			std::cout << pend[i][j] << " ";
			j++;
		}
		std::cout << std::endl;
	}
	i = 0;
	while ((size_t)i < left.size())
	{
		std::cout << left[i] << " ";
		i++;
	}*/

	//Make a while loop to transfer all elements from type1 and left into a new first vector
	//Then short them depending on the number of times we looped 
	
}