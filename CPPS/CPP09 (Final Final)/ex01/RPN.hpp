/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:59:24 by aruckenb          #+#    #+#             */
/*   Updated: 2025/09/10 11:31:01 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <list>

class RPN
{
	private:
	std::stack<double, std::list<double> > type; //this might have to be a double
	
	public: //Add the various constructor
	RPN();
	~RPN();
	RPN(const RPN &type);
	RPN operator=(const RPN& type1);
	
	class Error:public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("Error!");
		}
	};

	void check_value(char *argv);
	double result();

};

#endif