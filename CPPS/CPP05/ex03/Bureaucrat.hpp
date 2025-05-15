/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:55:18 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/07 10:27:24 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
	private:
	const std::string name;
	unsigned int grade;

	public:
	Bureaucrat();
	Bureaucrat(int Num, std::string new_name);
	Bureaucrat(const Bureaucrat& type);
	Bureaucrat &operator=(const Bureaucrat& type);
	~Bureaucrat();
	
	void increment(); //increment Bureaucrat
	void decrement(); //Decrement Bureaucrat

	class GradeTooHighException: public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("Bureacrat Number is past the Greatest possible Number!");
		}
	};

	class GradeTooLowException: public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("Bureacrat Number is past the lowest possible Number!");
		}
	};

	std::string getName(void) const;
	unsigned int getGrade(void) const;

	void signForm(class AForm& type1);
	void executeForm(AForm const &form) const;
	
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& type);

#endif