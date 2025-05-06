/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubbyCreationForm copy.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:55:03 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/06 15:54:57 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubbyCreationForm.hpp"
#include "Bureaucrat.hpp"

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

#include <iostream>
#include <fstream>

void ShrubbyCreationForm::execute(Bureaucrat const &executor)
{
	if (executor.getGrade() <= this->getExeGrade())// check if the form has been signed or not
	{
		target = target.append("_shrubbery");
		std::ofstream File(target);
		File << R"(       #
      ###
     #####
    #######
   #########
  ###########
 #############
###############
       H
       H
       H
)";
		File.close();
	}
	
}