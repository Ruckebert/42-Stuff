/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:56:56 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/07 11:05:35 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
	std::string target;

	public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string type);
	PresidentialPardonForm(const PresidentialPardonForm& type);
	PresidentialPardonForm &operator=(const PresidentialPardonForm& type);
	~PresidentialPardonForm();

	void execute(class Bureaucrat const &executor) const;

};

#endif