/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:06:22 by aruckenb          #+#    #+#             */
/*   Updated: 2025/04/01 10:43:44 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Constructor" << std::endl;
	idea[0] = "I Have No Idea\n";
}

Brain::~Brain()
{
	std::cout << "Brain Destructor" << std::endl;
}


Brain::Brain(const Brain &type1) 
{
	std::cout << "Copy Brain constructor called\n";
	int i = 0;
	while (i < 100)
	{
		idea[i] = type1.idea[i];
		i++;
	}
}

Brain &Brain::operator=(const Brain& type1)
{
	std::cout << "Copy Brain assignment called\n";
	if (this != &type1)
	{
		int i = 0;
		while (i < 100)
		{
			idea[i] = type1.idea[i];
			i++;
		}
	}
	return (*this);
}

void Brain::IdeasAdder(std::string idea1)
{
	int i = 0;
	while (!idea[i].empty())
		i++;
	idea[i] = idea1;
}

std::string Brain::GetIdea(int i)
{
	if (idea[i].empty())
		return ("Empty Idea\n");
	else
		return (idea[i]);
}