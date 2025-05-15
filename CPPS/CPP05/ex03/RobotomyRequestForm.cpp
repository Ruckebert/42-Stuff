/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:56:27 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/07 11:07:59 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm Constructor" << std::endl;
	target = "Null";
}

RobotomyRequestForm::RobotomyRequestForm(std::string type): AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm Constructor" << std::endl;
	target = type;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &type1): AForm(type1)
{
	std::cout << "RobotomyRequestForm Copy constructor called\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& type)
{
	if (this != &type)
	{
		AForm::operator=(type);
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= this->getExeGrade() && this->getSigned() == true)// check if the form has been signed or not
	{
		int num = rand() % 2;
		std::cout << "*Drill Noises*" << std::endl;
		if (num == 0)
			std::cout << target << " has been robotomized!" << std::endl;
		else
			std::cout << target << " robotomized has failed!" << std::endl;
	}
	else if (executor.getGrade() > this->getExeGrade() && this->getSigned() == false)
		throw FormGradeTooLowException();
	else if (this->getSigned() == false)
		throw FormNotSigned();
	else
		throw FormGradeTooLowException();
}