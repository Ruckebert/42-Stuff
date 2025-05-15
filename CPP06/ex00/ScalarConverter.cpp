/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:38:55 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/14 15:36:16 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"
#include <sstream>

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Constructor" << std::endl;
}


ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &type1) 
{
	std::cout << "Copy constructor called\n";
	*this = type1;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& type1)
{
	std::cout << "Copy assignment called\n";
	if (this != &type1)
	{
		*this = type1;
	}
	return (*this);
}

enum Type 
{
	typeInt, typeFloat, typeDouble, typeChar
};

template <typename T>
void intConvert(T data, Type type)
{
	int result = 0;
	if (type != typeInt)
		result = static_cast<int>(data);
	else
	 	result = data;
	std::cout << "int: " << result << std::endl;
}

template <typename T>
void charConvert(T data, Type type)
{
	char result = 0;
	if (type != typeChar)
	{
		int intVal = static_cast<int>(data);
		if (intVal > 126 || intVal < 33)
		{
			if (intVal > 255 || intVal < 0)
				std::cout << "char: Impossible" << result << std::endl;
			else
				std::cout << "char: Non displayable" << result << std::endl;
			return ;
		}
		result = static_cast<char>(data);
	}
	else 
		result = data;
	std::cout << "char: " << result << std::endl;
}

template <typename T>
void floatConvert(T data, Type type)
{
	float result = 0;
	if (type != typeFloat)
		result = static_cast<float>(data);
	else
	 	result = data;
	std::cout << "float: " << std::fixed << std::setprecision(1) << result << "f" << std::endl;
}

template <typename T>
void doubleConvert(T data, Type type)
{
	double result = 0;
	if (type != typeChar)
		result = static_cast<double>(data);
	else
	 	result = data;
	std::cout << "double: " << result << std::endl;
}

template <typename T>
void typeConvert(T data, Type type)
{
	charConvert(data, type);
	intConvert(data, type);
	floatConvert(data, type);
	doubleConvert(data, type);
}
void ScalarConverter::convert(std::string str)
{
	//Check the type
	Type type;
	std::stringstream ss(str);
	int typeI = 0;
	float typeF = 0;
	double typeD = 0;
	char typeC = 0;
	
	if (str.length() == 1)
	{
		if (isprint(str[0]))
		{
			if (isdigit(str[0]))
				type = typeInt;
			else
				type = typeChar;
		}
	}

	//Unique Cases
	if (str == "-inf" || str == "nan" || str == "+inf")
	{
		type = typeDouble;
		typeConvert(typeD, type);
		return ;
	}
	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		type = typeFloat;
		typeConvert(typeF, type);
		return ;
	}
	
	if (type != typeChar)
	{
		int i = 0;
		int dot = 0;
		while (str[i]) //Checks if theirs no digit 
		{	
			if (i == 0 && (str[i] == '-' || str[i] == '+'))
				i++;
			if (isdigit(str[i]) || (str[i] == 'f' && (str.length() - 1) == (size_t)i) || str[i] == '.')
			{
				if (str[i] == '.')
				{
					dot++;
					if (!isdigit(str[i - 1]))
						dot++;
				}
				else if (str[i] == 'f' && dot == 1)
					type = typeFloat;
			}
			else 
			{
				std::cout << "Error!\n";
				return ;
			}
			i++;
		}
		if (dot >= 2)
			return ; //Print an error message
		else if (dot == 1 && type != typeFloat)
			type = typeDouble;
		else if (type != typeFloat)
			type = typeInt;
	}

	std::string ov;
	
	switch (type)
	{
		case typeInt:
			ss >> typeI;
			if (ss.fail())
				break ;
			typeConvert(typeI, type);
			break;
		case typeChar:
			ss >> typeC;
			//std::cout << "Char Type!\n";
			typeConvert(typeC, type);
			break ;
		case typeFloat:
			ss >> typeF;
			//std::cout << "Float Type!\n";
			typeConvert(typeF, type);
			break ;
		case typeDouble:
			ss >> typeD;
			//std::cout << "Double Type!\n";
			typeConvert(typeD, type);
			break ;	
	}
}
