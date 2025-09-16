/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:23:32 by aruckenb          #+#    #+#             */
/*   Updated: 2025/09/10 09:57:53 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ostream>

bool checker(int argc, char **argv)
{
	int i = 1;
	while (i < argc)
	{
		std::string str = argv[i];
		if (str.length() > 10)
        {
            throw (false);
        }
        if (str.length() == 10 && str > "2147483647")
        {
           	throw (false);
        }
		if (atoi(argv[i]) < 0)
        {
			throw (false);
        }
		size_t j = 0;
		while (argv[i][j])
		{
			if (!std::isdigit(argv[i][j]))
				throw (false);
			j++;
		}
		i++;
	}
	return (true);
}

int jacobsthal(int n) 
{
    int power_of_2 = 1 << (n + 1);
    int sign = (n % 2 == 0) ? 1 : -1;
    return (power_of_2 + sign) / 3;
}

