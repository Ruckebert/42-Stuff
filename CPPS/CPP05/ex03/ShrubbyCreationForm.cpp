/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubbyCreationForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:55:03 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/07 11:10:00 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubbyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubbyCreationForm::ShrubbyCreationForm(): AForm("ShrubbyCreationForm", 145, 137)
{
	std::cout << "ShrubbyCreationFormConstructor" << std::endl;
	target = "Null";
}

ShrubbyCreationForm::ShrubbyCreationForm(std::string type): AForm("ShrubbyCreationForm", 145, 137)
{
	std::cout << "ShrubbyCreationForm Constructor" << std::endl;
	target = type;
}

ShrubbyCreationForm::~ShrubbyCreationForm()
{
	std::cout << "ShrubbyCreationForm Destructor" << std::endl;
}

ShrubbyCreationForm::ShrubbyCreationForm(const ShrubbyCreationForm &type1): AForm(type1)
{
	std::cout << "ShrubbyCreationForm Copy constructor called\n";
}

ShrubbyCreationForm &ShrubbyCreationForm::operator=(const ShrubbyCreationForm& type)
{
	if (this != &type)
	{
		AForm::operator=(type);
	}
	return (*this);
}

void ShrubbyCreationForm::execute(Bureaucrat const &executor) const
{

	if (executor.getGrade() <= this->getExeGrade() && this->getSigned() == true)// check if the form has been signed or not
	{
		std::string file_name = target + "_shrubbery";
		std::ofstream File(file_name.c_str());
		File << "       #\n"
		<< "      ###\n"
		<< "     #####\n"
		<< "    #######\n"
		<< "   #########\n"
		<< "  ###########\n"
		<< " #############\n"
		<< "###############\n"
		<< "     H\n"
		<< "     H\n"
		<< "     H\n";
		File.close();
	}
	else if (executor.getGrade() > this->getExeGrade() && this->getSigned() == false)
		throw FormGradeTooLowException();
	else if (this->getSigned() == false)
		throw FormNotSigned();
	else
		throw FormGradeTooLowException();
}
