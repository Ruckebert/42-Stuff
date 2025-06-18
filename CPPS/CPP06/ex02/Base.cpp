/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:37:13 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/20 11:11:07 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstddef>
#include <typeinfo>

Base::Base()
{
	std::cout << "Base Constructor" << std::endl;
}


Base::~Base()
{
	std::cout << "Base Destructor" << std::endl;
}

Base::Base(const Base &type1) 
{
	*this = type1;
}

Base &Base::operator=(const Base& type1)
{
	if (this != &type1)
	{
		*this = type1;
	}
	return (*this);
}

Base *generate(void)
{
	srand(time(0));
	unsigned int randomNum = rand() % 3;
	Base *type = NULL;
	
	if (randomNum == 0)
		type = new A();
	else if (randomNum == 1)
		type = new B();
	else
		type = new C();
	return (type);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer: Type A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer: Type B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer: Type C\n";
	else
	 	std::cout << "Pointer: Unknown Type\n";
}

void identify(Base &p)
{
	try 
	{
		A& a = dynamic_cast<A&>(p);
		p = a;
		std::cout << "Refernce: Type A\n";
		return ;
	}
	catch (const std::bad_cast&)
	{}
	try 
	{
		B& b = dynamic_cast<B&>(p);
		p = b;
		std::cout << "Refernce: Type B\n";
		return ;
	}
	catch (const std::bad_cast&)
	{}
	try 
	{
		C& c = dynamic_cast<C&>(p);
		p = c;
		std::cout << "Refernce: Type C\n";
		return ;
	}
	catch (const std::bad_cast&)
	{}
	std::cout << "Refernce: Unknown Type\n";
}