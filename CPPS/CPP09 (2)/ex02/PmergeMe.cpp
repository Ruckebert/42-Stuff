/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:23:32 by aruckenb          #+#    #+#             */
/*   Updated: 2025/09/01 15:30:56 by aruckenb         ###   ########.fr       */
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
			com++;
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
			com++;
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
	function(type1, left, count, com);
	return (0);
}
int functionD(std::deque<std::deque<int> > &type1, std::deque<int> &left, int &count, int &com)
{
	if (type1.size() == 1)
		return (0);
	size_t i = 0;
	std::deque<std::deque<int> > type2;
	while (i+1 < type1.size()) //simple creating the first pairs
	{
		if (type1[i].back() >= type1[i+1].back())
		{
			std::deque<int> pair1;
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
			com++;
		}
		else
		{
			std::deque<int> pair1;
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
			com++;
		}
		i += 2;
	}
	if (type1.size() % 2 == 1) //leftovers
	{
		std::deque<int> pair1;
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
	functionD(type1, left, count, com);
	return (0);
}

int jacobsten(int num, std::vector<std::vector<int> > &type1, std::vector<int> &left, int &com)
{
	std::vector<int> temp;
	std::vector<int> index;
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
	
	/*Loop checker
	std::cout << "Vector Temp Start:";
	for (unsigned long i = 0; i < temp.size(); i++) 
	{
		std::cout << temp[i] << " ";
	}
	std::cout << std::endl;
	*/

	size_t count = 1;
	int ind = 2;
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
	
	std::cout << "Indexes" << std::endl;
	for (unsigned long i = 0; i < index.size(); i++) 
	{
		std::cout << index[i] << " ";
	}
	std::cout << std::endl;

	//Everything below this needs to be fixed ughhhh
	int n = 2;
	int last = 1;
	int jacob = ((1 << (n + 1)) + ((n % 2 == 0) ? 1 : -1)) / 3;
	int lastjaco = jacob;

	while (!pend.empty())
	{
		// Special case: only one element left
		if (pend.size() == 1 || index.size() == 1)
		{
			for (size_t j = 0; j < main.size(); j++)
			{
				if (main[j].back() >= pend[0].back())
				{
					main.insert(main.begin() + j, pend[0]);
					com++;
					pend.erase(pend.begin());
					index.erase(index.begin());
					break;
				}
				else if (main[main.size()-1].back() <= pend[0].back())
				{
					main.push_back(pend[0]);
					com++;
					pend.erase(pend.begin());
					index.erase(index.begin());
					break;
				}
			}
			break;
		}

		// General merge using Jacobsthal
		size_t i = 0;
		while (i < pend.size())
		{
			if (index[i] == jacob)
			{
				if (pend.size() == 1)
					break ;
				//std::cout << "jacob " << jacob << " Last " << last << " jacob last:" << lastjaco << std::endl;
				
				// Find insertion point in main
				size_t j = 0;
				while (j < main.size() && main[j].back() <= pend[i].back())
					j++;

				main.insert(main.begin() + j, pend[i]);
				com++;

				// erase safely
				pend.erase(pend.begin() + i);
				index.erase(index.begin() + i);

				jacob--;

				// Check if we need to compute next Jacobsthal
				if (jacob == last)
				{
					n++;
					last = lastjaco;
					jacob = ((1 << (n + 1)) + ((n % 2 == 0) ? 1 : -1)) / 3;
					lastjaco = jacob;
				}
				
				break;
			}
			else
				i++;
		}
		if (jacob > index.back())
		{
			break ;
		}
		/*if (jacob < index.back() && i == pend.size() - 1)
		{
			jacob = index.back();
		}*/
	}
	int sub = 0;
	while (sub < (int)pend.size())
	{
		std::vector<std::vector<int> > merged;
		size_t i = 0;
		while (i < main.size())
		{
			if (main[i].back() >= pend[sub].back())
			{
				size_t j = 0;
				while (j != i) 
				{
					merged.push_back(main[j]);
					j++;
				}
				merged.push_back(pend[sub]);
				while (i < main.size())
				{
					merged.push_back(main[i]);
					i++;
				}
				pend.erase(pend.begin() + (sub));
				main = merged;
				com++;
				break ;
			}
			i++;
		}
		if (i == main.size())
		{
			main.push_back(pend[sub]);
			pend.erase(pend.begin() + (sub));
			main = merged;
			com++;
			break ;
		}
		sub++;	
	}

	
	left = nonpar;
	type1 = main;
	if (num == 1)
	{
		return (0);
	}
	else if (num == 2)
		jacobsten(num/2, type1, left, com);
	else 
	 	jacobsten(num - 2, type1, left, com);
	return (0);
}

//3 = +1
//6 = +1
//Old One
/*
	int sub = 1;
	int n = 2;
	int jacob = ((1 << (n+1)) + ((n % 2 == 0) ? 1 : -1)) / 3;
	int last = jacob;
	while (!pend.empty()) //Adding something in the case there is only one element left in the vector 
	{
		std::vector<std::vector<int> > merged;
		size_t i = 0;
		while (i < main.size())
		{
			if (pend.size() == 1)
			{	//I think add the better comparison here
				if (main[main.size()-1].back() <= pend[0].back())
				{
					//std::cout << "Position: " << i << " Number/pair: " << pend[0].back() << " Back: " << main[main.size()-1].back() << std::endl;
					size_t j = 0;
					while (j < i) 
					{
						merged.push_back(main[j]);
						j++;
					}
					merged.push_back(pend[0]);
					pend.erase(pend.begin());
					main = merged;
					com++;
					break ;
				}
				else if (main[i].back() >= pend[0].back())
				{
					//std::cout << "Crash A" << std::endl;
					//std::cout << "Position: " << i << " Number/pair: " << pend[0].back() << " Back: " << main[i].back() << std::endl;
					size_t j = 0;
					while (j != i) 
					{
						merged.push_back(main[j]);
						j++;
					}
					merged.push_back(pend[0]);
					while (i < main.size())
					{
						merged.push_back(main[i]);
						i++;
					}
					pend.erase(pend.begin());
					main = merged;
					com++;
					break ;
				}
			}
			else if (sub < 0 || pend.empty()) // issue is with this
			{
				break ;
			}
			else if (main[i].back() >= pend[sub].back())
			{
				//std::cout << "Crash B" << std::endl;
			//	std::cout << "Position: " << i << " Number/pair: " << pend[sub].back() << " Back: " << main[i].back() << std::endl;
				size_t j = 0;
				while (j != i) 
				{
					merged.push_back(main[j]);
					j++;
				}
				merged.push_back(pend[sub]);
				while (i < main.size())
				{
					merged.push_back(main[i]);
					i++;
				}
				pend.erase(pend.begin() + (sub));
				main = merged;
				sub--;
				com++;
				break ;
			}
			i++;
		}
		if (pend.empty())
			break ;
		if (sub < 0 && !pend.empty())
		{
			n++;
			last = jacob; //stores the last number 3
			jacob = ((1 << (n+1)) + ((n % 2 == 0) ? 1 : -1)) / 3; // turns to 5
			sub = jacob - last;
			sub--;
			//std::cout << "Jacobs: " << jacob << " Sub: " << sub << std::endl;
			//std::cout << "Size of Pend: " << pend.size() << std::endl;
			if (sub > (int)pend.size())
				break ;
		}
	}
	sub = 0;
	while (sub < (int)pend.size())
	{
		std::vector<std::vector<int> > merged;
		size_t i = 0;
		while (i < main.size())
		{
			if (main[i].back() >= pend[sub].back())
			{
				size_t j = 0;
				while (j != i) 
				{
					merged.push_back(main[j]);
					j++;
				}
				merged.push_back(pend[sub]);
				while (i < main.size())
				{
					merged.push_back(main[i]);
					i++;
				}
				pend.erase(pend.begin() + (sub));
				main = merged;
				com++;
				break ;
			}
			else if (i == main.size() - 1)
			{
				main.push_back(pend[sub]);
				pend.erase(pend.begin() + (sub));
				main = merged;
				com++;
				break ;
			}
			i++;
		}
		sub++;	
	}
	left = nonpar;
	type1 = main;
	
	std::cout << "Vector End Rotation:";
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
	std::cout << std::endl;
	*/