/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:53:54 by aruckenb          #+#    #+#             */
/*   Updated: 2025/08/29 09:55:01 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <cmath>

//The two types of containers im gonna use
#include <ostream>
#include <vector>
#include <deque> // worry about the deque later


int function(std::vector<std::vector<int> > &type1, std::vector<int> &left, int &count, int &com);
int jacobsten(int num, std::vector<std::vector<int> > &type1, std::vector<int> &left, int &com);

#endif