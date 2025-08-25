/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:59:24 by aruckenb          #+#    #+#             */
/*   Updated: 2025/06/12 10:31:42 by aruckenb         ###   ########.fr       */
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
	class Error:public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("Error!");
		}
	};

	//Checks the value and adds them together, do split them however
	void check_value(char *argv)
	{
		try 
		{
			int i = 0;
			while (argv[i])
			{
				if (isdigit(argv[i]) && argv[i + 1] == ' ')
					type.push(argv[i] - 48);
				else if (isdigit(argv[i]) && isdigit(argv[i + 1]))
					throw Error();
				if (argv[i] == '+' && (argv[i + 1] == ' ' || argv[i + 1] == '\0'))
				{
					if (type.size() >= 2)
					{
						int second = type.top(); type.pop();
						int first = type.top(); type.pop();
						type.push(second + first);
					}
					else
						throw Error();
				}
				else if (argv[i] == '-' && (argv[i + 1] == ' ' || argv[i + 1] == '\0'))
				{
					if (type.size() >= 2)
					{
						int second = type.top(); type.pop();
						int first = type.top(); type.pop();
						type.push(second - first);
					}
					else
						throw Error();
				}
				else if (argv[i] == '*' && (argv[i + 1] == ' ' || argv[i + 1] == '\0'))
				{
					if (type.size() >= 2)
					{
						int second = type.top(); type.pop();
						int first = type.top(); type.pop();
						type.push(second * first);
					}
					else
						throw Error();
				}
				else if (argv[i] == '/' && (argv[i + 1] == ' ' || argv[i + 1] == '\0'))
				{
					if (type.size() >= 2)
					{
						int second = type.top(); type.pop();
						if (second == 0)
							throw Error();
						int first = type.top(); type.pop();
						type.push(second / first);
					}
					else
						throw Error();
				}
				if (!isdigit(argv[i]) && (argv[i] != '+' && argv[i] != ' ' && argv[i] != '-' && argv[i] != '*' && argv[i] != '/'))
					throw Error();
				i++;
			}
		}
		catch (const RPN::Error& e)
		{
			std::cout << e.what() << std::endl;
		}
		
	};
	
	int result()
	{
		return (type.top());
	};
};

#endif