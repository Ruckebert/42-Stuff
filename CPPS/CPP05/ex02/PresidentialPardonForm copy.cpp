/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm copy.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:56:53 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/06 16:03:50 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm Constructor" << std::endl;
	target = "Null";
}

PresidentialPardonForm::PresidentialPardonForm(std::string type): AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "SPresidentialPardonForm Constructor" << std::endl;
	target = type;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &type1): AForm(type1)
{
	std::cout << "PresidentialPardonFormCopy constructor called\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& type)
{
	if (this != &type)
	{
		AForm::operator=(type);
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor)
{
	if (executor.getGrade() <= this->getExeGrade())// check if the form has been signed or not
	{
		std::cout << target << " you have been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}