/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:23:32 by aruckenb          #+#    #+#             */
/*   Updated: 2025/09/04 13:22:27 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ostream>

int function(std::vector<std::vector<int> > &type1, std::vector<int> &left, int &count, int &com)
{
	if (type1.size() == 1)
		return (0);
	size_t i = 0;
	std::vector<std::vector<int> > type2;
	while (i+1 < type1.size()) //simple creating the first pairs
	{
		if (type1[i].back() >= type1[i+1].back())
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
		std::cout << "piar compare" << std::endl;
		com++;
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
	function(type1, left, count, com);
	return (0);
}

int jacobsthal(int n) 
{
    int power_of_2 = 1 << (n + 1);
    int sign = (n % 2 == 0) ? 1 : -1;
    return (power_of_2 + sign) / 3;
}

int jacobsten(int num, std::vector<std::vector<int> > &type1, std::vector<int> &left, int &com)
{
	std::vector<int> temp;
	std::vector<int> index;
	std::vector<int> indexmain;
	std::vector<std::vector<int> > main;
	std::vector<std::vector<int> > pend;
	std::vector<int> nonpar;
	size_t k = 0;

	std::cout << num << std::endl; //Loop Num
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

	/*std::cout << "Temp: " ;
	for (unsigned long i = 0; i < temp.size(); i++) 
	{
		std::cout << temp[i] << " ";
	}
	std::cout << std::endl;*/

	size_t count = 1;
	int ind = 2;
	int indmain = 0;
	std::vector<int> pair;
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
	
	/*std::cout << "Indexes: " ;
	for (unsigned long i = 0; i < index.size(); i++) 
	{
		std::cout << index[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Pend: " ;
	for (unsigned long i = 0; i < pend.size(); i++) 
	{
		std::cout << pend[i].back() << " ";
	}
	std::cout << std::endl;
	std::cout << "Main Indexes: " ;
	for (unsigned long i = 0; i < indexmain.size(); i++) 
	{
		std::cout << indexmain[i] << " ";
	}
	std::cout << std::endl;*/
	
	
	int n = 2;
	int last = 1;
	int jacob = jacobsthal(n);
	int lastjaco = jacob;

	//The last bit needs to be worked on
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
				//std::cout << "jacob " << jacob << " Last " << last << " jacob last:" << lastjaco << std::endl;
				size_t k = 0;
				while (k < indexmain.size())
				{
					if (index[i] == indexmain[k])
						break ;
					k++;
				}
				
				// Binary search for insertion point
				size_t left_bound = 0;
				size_t right_bound = k;
				size_t j = 0;

				while (left_bound < right_bound) 
				{
					size_t mid = left_bound + (right_bound - left_bound) / 2;
					com++;  // Count the comparison
					std::cout << "main: "<< main[mid].back() << " pend: " << pend[i].back() << std::endl;
					if (main[mid].back() < pend[i].back()) 
						left_bound = mid + 1;
					else 
						right_bound = mid;
				}
				j = left_bound;  // This is the insertion point

				main.insert(main.begin() + j, pend[i]);
				indexmain.insert(indexmain.begin() + j, index[i]);
				
				pend.erase(pend.begin() + i);
				index.erase(index.begin() + i);
				jacob--;
				if (jacob == last)
				{
					//std::cout << "last and Jacob: " << last << " " << jacob << std::endl;
					n++;
					last = lastjaco;
					jacob = jacobsthal(n);
					//std::cout << "AFTER last and Jacob: " << last << " " << jacob << std::endl;
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
						//std::cout << "No valid index: " << index.back() << " Pend Size: " << pend.size() << " " << index.size()<< std::endl;
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
