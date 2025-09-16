/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:00:14 by aruckenb          #+#    #+#             */
/*   Updated: 2025/09/16 10:55:24 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Use a Set Container for this excerise 

#include "BitcoinExchange.hpp"

BitCoinExchange::BitCoinExchange() {};
BitCoinExchange::~BitCoinExchange(){};
BitCoinExchange::BitCoinExchange(const BitCoinExchange &type)
{
	*this = type;
};
BitCoinExchange &BitCoinExchange:: operator=(const BitCoinExchange& type1)
{
	if (this != &type1)
	{
		*this = type1;
	}
	return (*this);
};

//Main Functions
bool BitCoinExchange::isleap(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

bool BitCoinExchange::ValidDate(int d, int m, int y)
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

int BitCoinExchange::insertmap(std::ifstream &Myfile, int num, BitCoinExchange &Type)
{
	std::string value;
	std::string line;

	//getline(Myfile, line);
	while (getline(Myfile, line))
	{
		if (line == "date | value" || line[0] == '\0') //idk if this fixes the empty line issue
			continue ;
		int count = 0;
		int i = 0;
		while (line[i]) // Format Checker
		{
			if (line[i] == '.')
				count++;
			if (count == 2)
				return (1);
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
			if (i > 13 && line[i] == '1' && line.length() > 17)
			{
				size_t j = i;
				while (line[j])
				{
					if (line[j] == '0' || line[j] == '.')
						j++;
					else if (line[j] == '\0' || line[j] == '\n')
						break ;
					else
					{
						line[17] = '1';
						break ;
					}
				}
				break ;
			}
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
		if (convert.fail()) //checks if numbers are greater or not using a float
			date[date.length() - 1] = 'a';
		if (floater > 1000)
			date[date.length() - 1] = 'a';	
		if (line.length() == 13 || line.length() <= 5)
			date[date.length() - 1] = 'b';
		Type.exchange.insert(std::make_pair(date, floater));
	}
	return (0);
}

int BitCoinExchange::exchangeconvert(BitCoinExchange &Type)
{
	std::map<std::string, float>::iterator it;
	std::string line;

	for (it = Type.exchange.begin(); it != Type.exchange.end(); ++it)
	{
		//check if the value is valid or not
		std::string rl_date;
		if (it->first[it->first.length() - 1] == 'a') //checks if the number is greater then 1000
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}
		else if (it->first[it->first.length() - 1] == 'b')
		{
			std::cerr << "Error: Empty Date or Number" << std::endl;
			continue ;
		}
		else
			rl_date = it->first.substr(0, 10);

		//Check if its a valid date
		std::string year = rl_date.substr(0, 4);
		std::string month = rl_date.substr(5, 2);
		std::string day = rl_date.substr(8, 2);
		if (ValidDate(atoi(day.c_str()), atoi(month.c_str()), atoi(year.c_str())) == false)
		{
			std::cerr << "Error: bad input => " << rl_date << std::endl;
			continue ;
		}

		if (it->second < 0) //Checks if the number is negative or not
		{
			std::cerr << "Error: not a positive number." << std::endl;
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
			if (line[0] == '\0')
				continue ;
			std::string date = line.substr(0,10);
			std::string value = line.substr(11,(line.length() - 11));
			float exchange = 0.0;
			std::stringstream convert(value);
			convert >> exchange;
			data.insert(std::make_pair(date, exchange));
		}
		BitExchange.close();

		//Checking the exchange
		std::map<std::string, float>::iterator check = data.lower_bound(rl_date);
		if (check == data.begin())
		{
			std::cerr << "Error: date is out of bounds!" << std::endl;
			continue;
		}
		else if (check == data.end() || check->first != rl_date)
		{
			check--;
		}
		float exrate = check->second * it->second;
		std::cout << rl_date << " => " << it->second << " = " << exrate << std::endl;
	}
	return (0);
}