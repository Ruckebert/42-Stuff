/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:23:32 by aruckenb          #+#    #+#             */
/*   Updated: 2025/09/08 10:36:21 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ostream>

int jacobsthal(int n) 
{
    int power_of_2 = 1 << (n + 1);
    int sign = (n % 2 == 0) ? 1 : -1;
    return (power_of_2 + sign) / 3;
}

