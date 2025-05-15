/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:47:39 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/07 14:32:36 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubbyCreationForm.hpp"


Intern::Intern()
{
	std::cout << "Intern Constructor" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor" << std::endl;
}

Intern::Intern(const Intern &type1)
{
	std::cout << "Copy constructor called\n";
}

Intern &Intern::operator=(const Intern& type)
{
	std::cout << "Copy assignment called\n";
	if (this != &type)
	{
	}
	return (*this);
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	AForm *formexe = nullptr;
	std::string FormType[] = {"Presidential Pardon", "Robotomy Request", "Shrubby Creation"};
	AForm* (*formCreator[3])(std::string target) = {
        [](std::string target) -> AForm* { return new PresidentialPardonForm(target); },
        [](std::string target) -> AForm* { return new RobotomyRequestForm(target); },
        [](std::string target) -> AForm* { return new ShrubbyCreationForm(target); }
    };
	
	int i = 0;
	while (i < 3)
	{
		if (FormType[i].compare(form) == 0)
		{
			std::cout << "Intern has created " << form << std::endl;
			formexe = formCreator[i](target);
			return (formexe);
		}
	}
	std::cout << "Intern has failed at creating " << form << std::endl;
	return (nullptr);
}

