/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:30:43 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/17 11:07:27 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>
# include <string>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Not the Correct Amount of Arguements!" << std::endl;
		return (1);
	}
	
	std::string text;
	std::string replace;
	std::string first = argv[2];
	std::string second = argv[3];

	std::ifstream fileRead(argv[1]);
	text = argv[1];
	text = text.append(".replace");
	std::ofstream fileWrite(text.c_str());
	
	while (getline(fileRead, text))
	{
		int i = 0;
		while (text[i])
		{
			int k = 0;
			if (text[i] == first[k])
			{
				int j = 0;
				k = i;
				while (text[k])
				{
					if (text[k] == first[j])
					{
						j++;
						k++;
					}
					else
						break ;
				}
				if (first.length() == (unsigned long)j)
				{
					fileWrite << second;
					i = k;
				}
			}
			if (text.length() == (unsigned long)i)
				break ;
			fileWrite << text[i];
			i++;
		}
		fileWrite << std::endl;
	}
	fileRead.close();
	fileWrite.close();
}