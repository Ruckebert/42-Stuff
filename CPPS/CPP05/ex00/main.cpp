/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:59:19 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/06 13:43:19 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try 
	{
		Bureaucrat Diplomat1(12, "Martin");
		std::cout << Diplomat1 << std::endl;
		
		Diplomat1.increment();
		std::cout << Diplomat1 << std::endl;
		
		Diplomat1.decrement();
		std::cout << Diplomat1 << std::endl;

		std::cout << "\nDiplomat Ryan!\n"; //Highest Grade
		Bureaucrat Diplomat2(1, "Ryan");
		std::cout << Diplomat2 << std::endl;
		
		Diplomat2.increment();
		std::cout << Diplomat2 << std::endl;
		
		Diplomat2.decrement();
		std::cout << Diplomat2 << std::endl;

		std::cout << "\nDiplomat Donald!\n"; //Lowest Grade
		Bureaucrat Diplomat3(151, "Donald");
		std::cout << Diplomat3 << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}