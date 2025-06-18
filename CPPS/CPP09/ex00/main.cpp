/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:59:59 by aruckenb          #+#    #+#             */
/*   Updated: 2025/06/18 09:01:40 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	std::string line;
	std::ifstream Myfile(argv[2]);
	
	while (getline(Myfile, line))
	{
		
	}
	Myfile.close();
	
}