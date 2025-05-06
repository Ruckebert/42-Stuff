/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:55:15 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/06 14:47:02 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): name("No_Name")
{
	std::cout << "Bureaucrat Constructor" << std::endl;
	grade = 1;
}


Bureaucrat::Bureaucrat(int Num, std::string new_name): name(new_name)
{
	std::cout << "Bureaucrat Constructor" << std::endl;
	if (Num < 0)
	{
		std::cout << "Error: Bureaucrat Grade is Too High!" << std::endl;
		throw GradeTooHighException();
	}
	else if (Num > 150)
	{
		std::cout << "Error: Bureaucrat Grade is Too Low!" << std::endl;
		throw GradeTooLowException();
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

void Bureaucrat::increment() //increment Bureaucrat
{
	try 
	{
		if (grade == 1)
		{
			throw GradeTooHighException();
		}
		else 
			grade--;
	} 
	catch (const GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::decrement() //Decrement Bureaucrat
{
	try 
	{
		if (grade == 150)
			throw GradeTooLowException();
		else 
			grade++;
	} 
	catch (const GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(Form& type1)
{
	try 
	{
		type1.beSigned(*this);	
	}
	catch (const Form::FormGradeTooLowException& e)
	{
		std::cout << type1.getName() << " couldn't sign " << this->name << " because Grade is too low" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& type)
{
	os << type.getName() << ", bureaucrat grade " << type.getGrade() << ".";
	return (os);
}