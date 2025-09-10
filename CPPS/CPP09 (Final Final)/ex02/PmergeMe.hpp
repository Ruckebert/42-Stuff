/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:53:54 by aruckenb          #+#    #+#             */
/*   Updated: 2025/09/10 10:08:37 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <cmath>


int jacobsthal(int n);
bool checker(int argc, char **argv);

template<typename D2, typename D1>
int startsort(int argc, char **argv, D2 &type1, D1 &left, int com)
{
	int i = 1;
	while (i < argc)
	{
		if (i % 2 == 0)
		{
			//here you sort them into pairs the left being the smallest, the right being the biggest
			if (atoi(argv[i]) >= atoi(argv[i - 1]))
			{
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

template <typename D2, typename D1>
int function(D2 &type1, D1 &left, int &count, int &com)
{
	if (type1.size() == 1)
		return (0);
	size_t i = 0;
	D2 type2;
	while (i+1 < type1.size()) //simple creating the first pairs
	{
		if (type1[i].back() >= type1[i+1].back())
		{
			D1 pair1;
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
			D1 pair1;
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
		com++;
		i += 2;
	}
	if (type1.size() % 2 == 1) //leftovers
	{
		D1 pair1;
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
	function(type1, left, count, com);
	return (0);
}

template <typename D2, typename D1>
int jacobsten(int num, D2 &type1, D1 &left, int &com)
{
	D1 temp;
	D1 index;
	D1 indexmain;
	D2 main;
	D2 pend;
	D1 nonpar;
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
	int ind = 2;
	int indmain = 0;
	D1 pair;
	k = 0;
	while (k < temp.size())
	{
		pair.push_back(temp[k]);
		if (pair.size() == (size_t)num)
		{
			if (count % 2 == 1 && count != 1)
			{
				pend.push_back(pair);
				index.push_back(ind);
				ind++;
			}
			else if (count % 2 == 0 || count == 1)
			{
				main.push_back(pair);
				indexmain.push_back(indmain);
				indmain++;
			}
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
	
	
	int n = 2;
	int last = 1;
	int jacob = jacobsthal(n);
	int lastjaco = jacob;

	while (!pend.empty())
	{
		if (pend.size() == 1)
			break ;
		size_t i = 0;
		while (i < pend.size())
		{
			if (pend.size() == 1)
				break ;
			if (index[i] == jacob)
			{
				size_t k = 0;
				while (k < indexmain.size())
				{
					if (index[i] == indexmain[k])
						break ;
					k++;
				}
				
				size_t left_bound = 0;
				size_t right_bound = k;
				size_t j = 0;

				while (left_bound < right_bound) 
				{
					size_t mid = left_bound + (right_bound - left_bound) / 2;
					com++;
					if (main[mid].back() < pend[i].back()) 
						left_bound = mid + 1;
					else 
						right_bound = mid;
				}
				j = left_bound;

				main.insert(main.begin() + j, pend[i]);
				indexmain.insert(indexmain.begin() + j, index[i]);
				
				pend.erase(pend.begin() + i);
				index.erase(index.begin() + i);
				jacob--;
				if (jacob == last)
				{
					n++;
					last = lastjaco;
					jacob = jacobsthal(n);
					lastjaco = jacob;
					size_t k = 0;
					while (k < index.size())
					{
						if (jacob == index[k])
							break ;
						k++;
					}
					if (k == index.size() && pend.size() != 1)
					{
						jacob = index.back();
					}
				}
				break;
			}
			else
				i++;
		}
	}
	if (pend.size() == 1)
	{
		size_t k = 0;
		while (k < indexmain.size())
		{
			if (index[0] == indexmain[k])
				break ;
			k++;
		}
		size_t left = 0;
		size_t right = k;
		
		while (left < right)
		{
			size_t mid = left + (right - left) / 2;
			com++;
			if (main[mid].back() < pend[0].back())
				left = mid + 1;
			else
				right = mid;
		}
		main.insert(main.begin() + left, pend[0]);
		pend.erase(pend.begin());
	}
	
	left = nonpar;
	type1 = main;
	if (num == 1)
		return (0);
	else 
	{
		jacobsten(num/2, type1, left, com);
	}
	return (0);
}

template<typename D1, typename D2>
int core(int argc, char **argv, D1 left, D2 &type1, double &duration)
{
	int com = 0;
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
	duration = double(end - start) / CLOCKS_PER_SEC; //calculate the duration
	//std::cout << "Vector End" << std::endl;
	//std::cout << "Total amount of comparisons: " << com << std::endl;
	return (0);
}

#endif