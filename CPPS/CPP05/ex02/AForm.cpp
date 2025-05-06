/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:25 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/06 15:31:39 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name("No_Name"), sinGrade(150), exeGrade(150)
{
	std::cout << "Form Constructor" << std::endl;
	sign = false;
}

AForm::AForm(std::string name, unsigned int grade1, unsigned int grade2): name(name), sinGrade(grade1), exeGrade(grade2)
{
	std::cout << "Form Constructor" << std::endl;
	if (grade1 > 150 || grade2 > 150)
		throw FormGradeTooLowException();
	else if (grade1 < 0 || grade2 < 0)
		throw FormGradeTooHighException();
	sign = false;
}

AForm::~AForm()
{
	std::cout << "Form Destructor" << std::endl;
}

AForm::AForm(const AForm &type1): name(type1.name), sinGrade(type1.sinGrade), exeGrade(type1.exeGrade)
{
	std::cout << "Copy constructor called\n";
}

AForm &AForm::operator=(const AForm& type)
{
	return (*this);
}

//Getters
std::string AForm::getName() const
{
	return (name);
}

unsigned int AForm::getSignGrade() const
{
	return (sinGrade);
}

unsigned int AForm::getExeGrade() const
{
	return (exeGrade);
}

void AForm::beSigned(Bureaucrat &type1)
{
	if (type1.getGrade() <= this->sinGrade)
		this->sign = true;
	else if (type1.getGrade() > this->sinGrade)
		throw FormGradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& type)
{
	os << type.getName() << ", Form Sign grade " << type.getSignGrade() << " and Execute Grade " << type.getExeGrade() << ".";
	return (os);
}