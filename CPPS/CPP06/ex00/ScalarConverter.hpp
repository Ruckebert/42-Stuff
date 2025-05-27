/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:39:04 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/14 13:45:10 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <cstdlib>

class ScalarConverter
{
	private:
	public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& type);
	ScalarConverter &operator=(const ScalarConverter& type);
	~ScalarConverter();
	
	static void convert(std::string str);
};


#endif