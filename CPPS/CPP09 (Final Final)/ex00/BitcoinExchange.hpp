/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:00:32 by aruckenb          #+#    #+#             */
/*   Updated: 2025/09/09 13:01:09 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <bits/stdc++.h>
#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cctype>

class BitCoinExchange
{
	private:
	std::map<std::string, float> exchange;

	public:
	BitCoinExchange();
	~BitCoinExchange();
	BitCoinExchange(const BitCoinExchange&type);
	//BitCoinExchange operator=(const BitCoinExchange& type1);

	int exchangeconvert(BitCoinExchange &Type);
	int insertmap(std::ifstream &Myfile, int num, BitCoinExchange &Type);
	bool isleap(int year);
	bool ValidDate(int d, int m, int y);
	
};

#endif