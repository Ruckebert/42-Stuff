/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:55:15 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/05 13:42:34 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <stdexcept>

Bureaucrat::Bureaucrat(): name("No_Name")
{
	std::cout << "Bureaucrat Constructor" << std::endl;
	grade = 1;
}


Bureaucrat::Bureaucrat(int Num, std::string new_name): name(new_name)
{
	std::cout << "Bureaucrat Constructor" << std::endl;
	if (Num < 0 || Num > 150)
	{
		std::cout << "invalid Number!" << std::endl;
		std::cout << "Giving Lowest Possible Grade!" << std::endl;
		grade = 150;
	}	
	else
		grade = Num;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &type1) 
{
	std::cout << "Copy constructor called\n";
	grade = type1.grade;
	(std::string)name = type1.name;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& type1)
{
	std::cout << "Copy assignment called\n";
	if (this != &type1)
	{
		grade = type1.grade;
		(std::string)name = type1.name;
	}
	return (*this);
}

//Getters 
std::string Bureaucrat::getName(void) const
{
	return (name);
}

unsigned int Bureaucrat::getGrade(void) const
{
	return (grade);
}

#include <stdexcept>

void Bureaucrat::increment() //increment Bureaucrat
{
	try 
	{
		if (grade == 1)
			throw std::runtime_error("Grade is Highest");
		else 
			grade--;
	} 
	catch (std::exception & e)
	{
		std::cout << "Bureacrat Number has reach the greatest possible Decrement!" << std::endl;
	}
}

void Bureaucrat::decrement() //Decrement Bureaucrat
{
	try 
	{
		if (grade == 150)
			throw std::runtime_error("Grade is Lowest");
		else 
			grade++;
	} 
	catch (std::exception & e)
	{
		std::cout << "Bureacrat Number has reach the lowest possible Decrement!" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& type)
{
	os << type.getName() << ", bureaucrat grade " << type.getGrade() << ".";
	return (os);
}
