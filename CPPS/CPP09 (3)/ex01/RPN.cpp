/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:59:16 by aruckenb          #+#    #+#             */
/*   Updated: 2025/08/29 13:22:32 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int RPN::result()
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