/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:59:59 by aruckenb          #+#    #+#             */
/*   Updated: 2025/09/15 10:30:33 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

//Note: I think itll be fine 
int main(int argc, char **argv)
{
	BitCoinExchange Type;
	int num = 0;
	
	if (argc == 1)
		return (std::cerr << "Error: No Arguments" <<std::endl , 1);
	std::ifstream Myfile(argv[1]);
	if (!Myfile)
		return (std::cerr << "Error: Invalid File" <<std::endl , 1);

	//Inserting elements into list and Checking them
	if (Type.insertmap(Myfile, num, Type) == 1)
		return (std::cerr << "Error: Invalid Format" <<std::endl , 1);
	Myfile.close();

	//Exchanges and maps everything
	Type.exchangeconvert(Type);
}