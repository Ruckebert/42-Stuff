/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:42 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/07 11:07:05 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm
{
	private:
	const std::string name;
	bool sign;
	const unsigned int sinGrade;
	const unsigned int exeGrade;

	public:
	AForm();
	AForm(std::string name, unsigned int grade1, unsigned int grade2);
	AForm(const AForm& type);
	AForm &operator=(const AForm& type);
	virtual ~AForm();

	//Exceptions 
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

	class FormNotSigned: public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("Form has not been signed!");
		}
	};

	//Getters
	std::string getName() const;
	unsigned int getSignGrade() const;
	unsigned int getExeGrade() const;
	bool getSigned() const;

	void beSigned(class Bureaucrat &type1);

	virtual void execute(class Bureaucrat const &executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& type);

#endif