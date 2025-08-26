/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:21:51 by aruckenb          #+#    #+#             */
/*   Updated: 2025/08/26 15:59:10 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <cmath>

//The two types of containers im gonna use
#include <ostream>
#include <vector>
#include <deque> // worry about the deque later


int function(std::vector<std::vector<int> > &type1, std::vector<int> &left, int &count)
{
	if (type1.size() == 1)
		return (0);
	size_t i = 0;
	std::vector<std::vector<int> > type2;
	while (i+1 < type1.size()) //simple creating the first pairs
	{
		if (type1[i].back() > type1[i+1].back())
		{
			std::vector<int> pair1;
			unsigned long j = 0;
			while (j < type1[i + 1].size())
			{
				pair1.push_back(type1[i+1][j]);
				j++;
			}
			j = 0;
			while (j < type1[i].size())
			{
				pair1.push_back(type1[i][j]);
				j++;
			}
			type2.push_back(pair1);
		}
		else
		{
			std::vector<int> pair1;
			unsigned long j = 0;
			while (j < type1[i].size())
			{
				pair1.push_back(type1[i][j]);
				j++;
			}
			j = 0;
			while (j < type1[i + 1].size())
			{
				pair1.push_back(type1[i+1][j]);
				j++;
			}
			
			type2.push_back(pair1);
		}
		i += 2;
	}
	if (type1.size() % 2 == 1) //leftovers
	{
		std::vector<int> pair1;
		unsigned long j = 0;
		while (j < type1[i].size())
		{
			pair1.push_back(type1[i][j]);
			j++;
		}
		j = 0;
		while (j < left.size())
		{
			pair1.push_back(left[j]);
			j++;
		}
		left = pair1;
	}

	type1 = type2;
	count++;
	function(type1, left, count);
	return (0);
}

int jacobsten(int num, std::vector<std::vector<int> > &type1, std::vector<int> &left)
{
	std::vector<int> temp;
	std::vector<std::vector<int> > main;
	std::vector<std::vector<int> > pend;
	std::vector<int> nonpar;
	
	size_t k = 0;
	while(k < type1.size())
	{
		size_t j = 0;
		while (j < type1[k].size())
		{
			temp.push_back(type1[k][j]);
			j++;
		}
		k++;
	}
	k = 0;
	while (k < left.size())
	{
		temp.push_back(left[k]);
		k++;
	}
	type1.clear();


	size_t count = 1;
	std::vector<int> pair;
	k = 0;
	while (k < temp.size())
	{
		pair.push_back(temp[k]);
		if (pair.size() == (size_t)num)
		{
			if (count % 2 == 1 && count != 1)
				pend.push_back(pair);
			else if (count % 2 == 0 || count == 1)
				main.push_back(pair);
			pair.clear();
			count++;
		}
		
		k++;
	}
	if (temp.size() % num != 0)
	{
		size_t start = temp.size() - (temp.size() % num);
		while (start < temp.size())
		{
			nonpar.push_back(temp[start]);
			start++;
		}
	}
	
	k = 2;
	int n = 2;
	int jacob = (std::pow(2, (n+1)) + std::pow((-1), n)) / 3;
	while (!pend.empty()) //Adding something in the case there is only one element left in the vector 
	{
		std::vector<std::vector<int> > type1;
		size_t i = 0;
		while (i < main.size())
		{	//Think of a way to add the jacobs number 
			if (pend.size() == 1 && (jacob - k) < 0)
			{
				if (main[main.size() - i].back() > pend[pend.size()].back())
				{
					size_t j = 0;
					while (j != i) 
					{
						type1.push_back(main[j]);
						j++;
					}
					type1.push_back(pend[jacob-k]);
					while (i < main.size())
					{
						type1.push_back(main[i]);
						i++;
					}
					main = type1;
					break ;
				}
			}
			else if (main[i].back() > pend[jacob-k].back())
			{
				size_t j = 0;
				while (j != i) 
				{
					type1.push_back(main[j]);
					j++;
				}
				type1.push_back(pend[jacob-k]);
				while (i < main.size())
				{
					type1.push_back(main[i]);
					i++;
				}
				pend.erase(pend.begin() + (jacob-k));
				main = type1;
				break ;
			}
			i++;
		}
		if ((jacob - k) == 0 && pend.empty() != 0) //This part needs fixing
		{
			n++;
			jacob = (std::pow(2, (n+1)) + std::pow((-1), n)) / 3;
			k = 2;
			std::cout << "Jacobs Number:" << jacob << std::endl;
		}
		else if ((size_t)jacob <= k)
			break ;
		k++;
	}
	
	left = nonpar;
	type1 = main;
	if (num == 1)
		return (0);
	else
	 	jacobsten(num/2, type1, left);
	return (0);
}

int main(int argc, char **argv)
{
	std::vector<std::vector<int> > type1; //Maybe have a vector of vectors
	std::vector<int> left;


	if (argc == 1)
		return (1);
	
	int i = 1;
	while (i < argc) //simple creating the first pairs
	{
		if (i % 2 == 0)
		{
			if (atoi(argv[i]) < 0 || atoi(argv[i - 1]) < 0)
			{
				return (1); //Negative Number Error
			}
			//here you sort them into pairs the left being the smallest, the right being the biggest
			if (atoi(argv[i]) > atoi(argv[i - 1]))
			{
				std::vector<int> pair;
				pair.push_back(atoi(argv[i - 1]));
				pair.push_back(atoi(argv[i]));
				type1.push_back(pair);
			}
			else if (atoi(argv[i]) < atoi(argv[i - 1]))
			{
				std::vector<int> pair;
				pair.push_back(atoi(argv[i]));
				pair.push_back(atoi(argv[i - 1]));
				type1.push_back(pair);
			}
		}
		if ((argc-1) % 2 == 1 && i == (argc - 1))
		{
			if (atoi(argv[i]) < 0)
				return (1); //Negative Number Error
			left.push_back(atoi(argv[i]));
		}
		i++;
	} //get the size of the 2d vector and reduce it by /2 add the odd ones into a seperate vector, idk if this is a single vector or 2d one

	
	//second sequence is creating pairs of 4 and puting the odd ones other then the first one into the pend
	//second sequence the pairs are made using the level of recursion reached
	//Create a non recursion one

	/*printer 1
	for (unsigned long i = 0; i < type1.size(); i++) 
	{
  		std::cout << type1[i][0] << type1[i][1] << "\n";
	}
	if (left.empty() == 0)
	{
		std::cout << left[0] << std::endl;
	}
	std::cout << std::endl;
	*/
	int num = 1;
	function(type1, left, num);

	
	//Printer 2
	for (unsigned long i = 0; i < type1.size(); i++) 
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
	std::cout << num << std::endl;
	std::cout << std::endl;
	
	//Jacobsthal Numbers!
	//Everything below this should be in a function and its own loop
	
	jacobsten(num, type1, left);

	//Printers
	std::cout << "Main" << std::endl;
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
	}
	std::cout << std::endl;
	/*std::cout << "Pend" << std::endl;
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
	}*/
	i = 0;
	while ((size_t)i < left.size())
	{
		std::cout << left[i] << " ";
		i++;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	//Make a while loop to transfer all elements from type1 and left into a new first vector
	//Then short them depending on the number of times we looped 
	
}