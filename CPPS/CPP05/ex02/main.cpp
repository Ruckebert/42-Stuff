/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:59:19 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/05 13:39:35 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat Diplomat1(12, "Martin");
	std::cout << Diplomat1 << std::endl;
	
	Diplomat1.increment();
	std::cout << Diplomat1 << std::endl;
	
	Diplomat1.decrement();
	std::cout << Diplomat1 << std::endl;

	std::cout << "Diplomat Ryan!\n"; //Highest Grade
	Bureaucrat Diplomat2(1, "Ryan");
	std::cout << Diplomat2 << std::endl;
	
	Diplomat1.increment();
	std::cout << Diplomat2 << std::endl;
	
	Diplomat1.decrement();
	std::cout << Diplomat2 << std::endl;

	std::cout << "Diplomat Donald!\n"; //Lowest Grade
	Bureaucrat Diplomat3(151, "Donald");
	std::cout << Diplomat3 << std::endl;
	
	Diplomat3.increment();
	std::cout << Diplomat3 << std::endl;
	
	Diplomat1.decrement();
	std::cout << Diplomat3 << std::endl;
	
	return 0;
}