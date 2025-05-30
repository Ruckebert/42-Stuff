/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:42 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/06 15:32:01 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Form
{
	private:
	const std::string name;
	bool sign;
	const unsigned int sinGrade;
	const unsigned int exeGrade;

	public:
	Form();
	Form(std::string name, unsigned int grade1, unsigned int grade2);
	Form(const Form& type);
	Form &operator=(const Form& type);
	~Form();

	class FormGradeTooHighException: public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("Form Number is past the Greatest possible Number!");
		}
	};

	class FormGradeTooLowException: public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("Form Number is past the lowest possible Number!");
		}
	};

	//Getters
	std::string getName() const;
	unsigned int getSignGrade() const;
	unsigned int getExeGrade() const;

	void beSigned(class Bureaucrat &type1);
};

std::ostream& operator<<(std::ostream& os, const Form& type);

#endif