/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:59:16 by aruckenb          #+#    #+#             */
/*   Updated: 2025/09/15 13:04:59 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {};
RPN::~RPN(){};
RPN::RPN(const RPN &type)
{
	*this = type;
};

RPN &RPN::operator=(const RPN& type1)
{
	if (this != &type1)
	{
		*this = type1;
	}
	return (*this);
};

double RPN::result()
{
	return (type.top());
};

void RPN::check_value(char *argv)
{
	try 
	{
		int i = 0;
		while (argv[i])
		{
			if (isdigit(argv[i]) && argv[i + 1] == ' ')
				type.push(argv[i] - 48);
			else if (isdigit(argv[i]) && isdigit(argv[i + 1])) //Here to check if the number is between 0 and 9
				throw Error();
			if (argv[i] == '+' && (argv[i + 1] == ' ' || argv[i + 1] == '\0'))
			{
				if (type.size() >= 2)
				{
					double second = type.top(); type.pop();
					double first = type.top(); type.pop();
					type.push(second + first);
				}
				else
					throw Error();
			}
			else if (argv[i] == '-' && (argv[i + 1] == ' ' || argv[i + 1] == '\0'))
			{
				if (type.size() >= 2)
				{
					double second = type.top(); type.pop();
					double first = type.top(); type.pop();
					type.push(first - second);
				}
				else
					throw Error();
			}
			else if (argv[i] == '*' && (argv[i + 1] == ' ' || argv[i + 1] == '\0'))
			{
				if (type.size() >= 2)
				{
					double second = type.top(); type.pop();
					double first = type.top(); type.pop();
					type.push(second * first);
				}
				else
					throw Error();
			}
			else if (argv[i] == '/' && (argv[i + 1] == ' ' || argv[i + 1] == '\0'))
			{
				if (type.size() >= 2)
				{
					double second = type.top(); type.pop();
					if (second == 0)
						throw Error();
					double first = type.top(); type.pop();
					type.push(first / second);
				}
				else
					throw Error();
			}
			if (!isdigit(argv[i]) && (argv[i] != '+' && argv[i] != ' ' && argv[i] != '-' && argv[i] != '*' && argv[i] != '/'))
				throw Error();
			if (argv[i] == '-' && isdigit(argv[i + 1]))
				throw Error();
			i++;
		}
		if (type.size() > 1)
			throw Error();
	}
	catch (const RPN::Error& e)
	{
		std::cerr << e.what() << std::endl;
		return ;
	}
	std::cout << result() << std::endl;
};