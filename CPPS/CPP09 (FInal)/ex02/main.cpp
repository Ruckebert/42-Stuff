/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:21:51 by aruckenb          #+#    #+#             */
/*   Updated: 2025/09/04 13:03:30 by aruckenb         ###   ########.fr       */
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
			}
			else
			{
				std::vector<int> pair;
				pair.push_back(atoi(argv[i]));
				pair.push_back(atoi(argv[i - 1]));
				type1.push_back(pair);
			}
			std::cout << "piar compare" << std::endl;
			com++;
		}
		if ((argc-1) % 2 == 1 && i == (argc - 1))
		{
			if (atoi(argv[i]) < 0)
				return (1); //Negative Number Error
			left.push_back(atoi(argv[i]));
		}
		i++;
	} //get the size of the 2d vector and reduce it by /2 add the odd ones into a seperate vector, idk if this is a single vector or 2d one

	/*std::cout << "Vector Before:";
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
	std::cout << std::endl;*/

	//Sorting them into greater pairs
	int num = 1;
	//int num2 = 1;
	std::cout << "Function" << std::endl;
	function(type1, left, num, com);
	//functionD(type2, leftd, num2, comD);
	std::cout << "Function Finish" << std::endl;

	//Jacobsthal Numbers!
	std::cout << "Jacob" << std::endl;
	std::cout << "Num: " << num << std::endl;
	jacobsten(pow(2, num), type1, left, com);
	std::cout << "Jacob Finish" << std::endl;
	
	std::cout << "Comparsions Vector:" << com << std::endl;
	std::cout << "Vector:";
	std::cout << "Vector Size: " << type1.size() << std::endl;
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