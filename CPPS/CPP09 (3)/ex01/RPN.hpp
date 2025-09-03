/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:59:24 by aruckenb          #+#    #+#             */
/*   Updated: 2025/08/29 13:22:40 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <stack>
#include <iostream>
#include <cstdlib>

class RPN
{
	private:
	std::stack<int> type;
	//double result1; //the result can also be a decimnal when you divide it
	
	//Should i use a try and catch for the errors?
	public:

	void check_value(char *argv);
	int result();
	
	class Error:public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("Error!");
		}
	};

};

#endif