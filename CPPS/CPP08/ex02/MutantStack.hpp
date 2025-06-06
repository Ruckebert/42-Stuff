/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:01:46 by aruckenb          #+#    #+#             */
/*   Updated: 2025/06/04 10:23:27 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T, class Container=std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
	private:
	public:
	MutantStack(){}; //contructor
	~MutantStack(){}; //destructor
	MutantStack(const MutantStack& type): std::stack<T, Container>(type) {}; //copy contructor
	MutantStack &operator=(const MutantStack& type1) //copy assignment
	{
		std::cout << "Copy assignment called\n";
		if (this != &type1)
		{
			std::stack<T, Container>::operator=(type1);
		}
		return (*this);
	};

	typedef typename Container::iterator iterator;
	iterator begin() //iterator
	{
		return (this->c.begin());
	}

	iterator end() //iterator
	{
		return (this->c.end());
	}
};

#endif