/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:39:08 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/17 11:09:07 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	Harl program;
	std::string typeStr[] = {"debug", "info", "warning", "error"};
	void (Harl::*function[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int i = 0;
	while (i < 4)
	{
		int debug = level.compare(typeStr[i]);
		switch (debug)
		{
			case 0:
			{
				std::cout << "LEVEL: " << typeStr[i] << std::endl;
				(program.*function[i])();
				i++;
				while (i < 4)
				{
					std::cout << std::endl;
					std::cout << "LEVEL: " << typeStr[i] << std::endl;
					(program.*function[i])();
					i++;
				}
				return ;
			}
		}
		i++;
	}
	std::cout << "Invalid Level" << std::endl;
	return ;
}