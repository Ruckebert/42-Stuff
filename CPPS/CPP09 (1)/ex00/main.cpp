/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:59:59 by aruckenb          #+#    #+#             */
/*   Updated: 2025/08/25 14:47:16 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <cctype>

//Valid Date Checkers
bool isleap(int year)
{
	return (((year % 4) && (year % 100 != 0)) || (year % 400 == 0));
}

bool ValidDate(int d, int m, int y)
{
	const int max_valid_year = 9999;
	const int min_valid_year = 1000;
	if (y > max_valid_year || y < min_valid_year)
		return (false);
	if (m < 1 || m > 12 || d < 1 || d > 31)
		return (false);
	if (m == 2)
	{
		if (isleap(y))
			return (d <= 29);
		else
		 	return (d <= 28);
	}
	if (m == 4 || m == 6 || m == 9 || m == 11)
		return (d <= 30);
	return (true);
}

//Note: Big issue i am facing right now is that i do not check the formatttt :(, so do that
int main(int argc, char **argv)
{
	BitCoinExchange Type;
	std::string value;
	int num = 0;
	
	if (argc == 1)
		return (1);
	
	std::string line;
	std::ifstream Myfile(argv[1]);
	if (!Myfile)
		return (1);
	getline(Myfile, line);
	while (getline(Myfile, line))
	{
		int i = 0;
		while (line[i])
		{
			if (i == 4 || i == 7)
			{
				if (line[i] != '-')
					return (1);
			}
			if ((i == 10 || i == 12) && line[i] != ' ')
				return (1);
			if (i == 11 && line[i] != '|')
				return (1);
			if (i > 12 && line[i] >= 33 && line[i] <= 44)
				return (1);
			if (i > 12 && line[i] == 47)
				return (1);
			if (i > 12 && line[i] >= 58 && line[i] <= 126)
				return (1);
			i++;
		}
		std::string date = line.substr(0, 10);
		std::stringstream ss;
		ss << ++num;
		std::string date_num = "_" + ss.str();
		
		date.append(date_num);
		int value_length = line.length() - 13;
		if (value_length <= 0)
			value_length = 0;
		if (line.length() > 13)
			value = line.substr(13, value_length);

		//Inserting everything into the map
		float floater = 0.0;
		std::stringstream convert(value);
		convert >> floater;
		if (ss.fail()) //checks if numbers are greater or not
			date[date.length() - 1] = 'a';	
		if (floater > 1000)
			date[date.length() - 1] = 'a';	
		Type.exchange.insert(std::make_pair(date, floater));
	}
	Myfile.close();

	//Checks the values
	std::map<std::string, float>::iterator it;
	for (it = Type.exchange.begin(); it != Type.exchange.end(); ++it)
	{
		//check if the value is valid or not
		std::string rl_date;
		if (it->first[it->first.length() - 1] == 'a')
		{
			std::cout << "Error: too large a number." << std::endl;
			continue ;
		}
		else
			rl_date = it->first.substr(0, 10);

		//Check if its a valid date
		//Note gotta create my own date checker
		std::string year = rl_date.substr(0, 4);
		std::string month = rl_date.substr(5, 2);
		std::string day = rl_date.substr(8, 2);
		if (ValidDate(atoi(day.c_str()), atoi(month.c_str()), atoi(year.c_str())) == false)
		{
			std::cout << "Error: bad input => " << rl_date << std::endl;
			continue ;
		}

		if (it->second < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue ;
		}
		
		//Storing the exchange data into a container
		std::ifstream BitExchange("data.csv");
		if (!BitExchange)
			return (1);
		getline(BitExchange, line);
		std::map<std::string, float> data;
		while (getline(BitExchange, line))
		{
			std::string date = line.substr(0,10);
			std::string value = line.substr(11,(line.length() - 11));
			float exchange = 0.0;
			std::stringstream convert(value);
			convert >> exchange;
			data.insert(std::make_pair(date, exchange));
		}
		BitExchange.close();

		//Checking the exchange
		//Check the last date and anything before the first date is seen as invalid
		std::map<std::string, float>::iterator check = data.lower_bound(rl_date);
		if (check == data.begin())
		{
			std::cout << "Error: date is out of bounds!" << std::endl;
			continue;
		}
		--check;
		float exrate = check->second * it->second;
		std::cout << rl_date << " => " << it->second << " = " << exrate << std::endl;
	}
}