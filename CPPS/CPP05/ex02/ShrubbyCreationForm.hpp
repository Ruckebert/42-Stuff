/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubbyCreationForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:55:03 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/06 15:24:02 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBYCREATIONFORM_HPP
# define SHRUBBYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubbyCreationForm: public AForm
{
	private:
	std::string target;

	public:
	ShrubbyCreationForm();
	ShrubbyCreationForm(std::string type);
	ShrubbyCreationForm(const ShrubbyCreationForm& type);
	ShrubbyCreationForm &operator=(const ShrubbyCreationForm& type);
	~ShrubbyCreationForm();

	void execute(class Bureaucrat const &executor);

};


#endif