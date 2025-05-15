/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:56:23 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/07 11:08:04 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
	std::string target;

	public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string type);
	RobotomyRequestForm(const RobotomyRequestForm& type);
	RobotomyRequestForm &operator=(const RobotomyRequestForm& type);
	~RobotomyRequestForm();

	void execute(class Bureaucrat const &executor) const;

};


#endif