/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:31:01 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/27 11:29:18 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	int numbersA[6] = {1, 2, 3, 4 ,5, 6};
	std::vector<int> numbersV(numbersA, numbersA + 6);
	
	int num = easyfind(numbersA, 4);
	std::cout << "Array Test: " << num << std::endl;

	num = *easyfind(numbersV, 0);
	std::cout << "Vector Test: " << num << std::endl;
	
}