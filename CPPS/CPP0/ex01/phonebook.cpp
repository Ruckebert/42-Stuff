/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:35:31 by aruckenb          #+#    #+#             */
/*   Updated: 2025/02/26 14:48:48 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Contact
{
	private:
	
	public:
	std::string FirstName ;
	std::string LastName ;
	std::string Nickname ;
	long PhoneNumber ;
	std::string DarkestSecret ;
} ;

class PhoneBook
{
	private:
	
	public:
	Contact contacts[8];

} ;

void	adding_str(std::string &type, int i)
{
	while (1)
	{
		if (i == 1)
			std::cout << "Please input the first name below" << std::endl;
		else if (i == 2)
			std::cout << "Please input the last name below" << std::endl;
		else if (i == 3)
			std::cout << "Please input the nickname below" << std::endl;
		else if (i == 4)
			std::cout << "Please input their darkest secrets below" << std::endl;
		std::cout << "Input: " ;
		if (std::cin.peek() == '\n')
			std::cin.ignore();
		std::getline(std::cin, type);
		if (type.empty())
			std::cout << "Invalid Input!! Try Again" << std::endl;
		else
		{
			std::cout << std::endl;
			return ;
		}
		std::cout << std::endl;
	}
}

void	adding_phone(long &type)
{
	std::string check;

	while (1)
	{
		std::cout << "Please input the phone number below" << std::endl;
		std::cout << "Input: " ;
		if (std::cin.peek() == '\n')
			std::cin.ignore();
		std::getline(std::cin, check);

		int i = 0;
		bool isnumber = true;
		while (check[i])
		{
			if (check[i] >= '0' && check[i] <= '9')
				i++;
			else
			{
				isnumber = false;
				break ;
			}
		}
		if (isnumber == false)
			std::cout << "Please only enter numbers!" << std::endl;
		else
		{
			if (check.length() > 10)
				std::cout << "Invalid Phone Number!! Try Again" << std::endl;
			else
			{
				type = std::stol(check);
				std::cout << std::endl;
				return ;
			}
		}
		std::cout << std::endl;
	}
}

void	adding(Contact &contacts)
{
	adding_str(contacts.FirstName, 1);
	adding_str(contacts.LastName, 2);
	adding_str(contacts.Nickname, 3);
	adding_phone(contacts.PhoneNumber);
	adding_str(contacts.DarkestSecret, 4);
}

void	display_ad(Contact &contacts, int i)
{
	std::cout << "Displaying Contact Number " << i + 1 << std::endl;
	std::cout << "First Name: " << contacts.FirstName << std::endl;
	std::cout << "Last Name: " << contacts.LastName << std::endl;
	std::cout << "Nickname: " << contacts.Nickname << std::endl;
	std::cout << "Phonenumber: " << contacts.PhoneNumber << std::endl;
	std::cout << "Darkest Secret: " << contacts.DarkestSecret << std::endl;
	std::cout << std::endl;
}

void	char_check_and_print(std::string type)
{
	int i = 0;
	if (type.length() >= 10)
	{
		while (i <= 8)
		{
			std::cout << type[i];
			i++;
		}
		std::cout << "." << " | ";	
	}
	else
	{
		while (i < (10 - type.length()))
		{
			std::cout << " ";
			i++;
		}
		i = 0;
		while (i <= type.length())
		{
			std::cout << type[i];
			i++;
		}
		std::cout << " | ";
	}
}

void	display_search(Contact &contacts, int i)
{
	std::cout << "Contact Number:          " << i + 1 << " | ";
	char_check_and_print(contacts.FirstName);
	char_check_and_print(contacts.LastName);
	char_check_and_print(contacts.Nickname);
	std::cout << std::endl;
}

int	valid_input(std::string input, int total)
{
	int i = 0;
	while (input[i])
	{
		if (input[i] >= '0' && input[i] <= '9')
			i++;
		else
			return (1);
	}
	i = std::stoi(input);
	if (i > total || i < 0)
		return (1);
	return (0);
}

int main()
{
	PhoneBook book ;
	int i = 0;
	int k = 0;

	while (1)
	{
		std::string option;
		std::cout << "Please Enter One of the Options Below" << std::endl;
		std::cout << "1: ADD" << std::endl;
		std::cout << "2: SEARCH" << std::endl;
		std::cout << "3: EXIT" << std::endl;
		std::cout << "Input: " ;
		std::cin >> option;
	
		if (option.empty() == 1)
			continue ;
		std::cout << std::endl;
		
		if (option.compare("ADD")  == 0)
		{
			if (i == 8)
			{
				if (k == 8)
					k = 0;
				std::cout << "Phonebook full!!" << std::endl;
				std::cout << "Replacing Oldest Element!" << std::endl;
				i = k;
				adding(book.contacts[i]);
				display_ad(book.contacts[i], i);
				i = 8;
				k++;
			}
			else
			{
				adding(book.contacts[i]);
				display_ad(book.contacts[i], i);
				i++;
			}
			continue ;
		}
		else if (option.compare("SEARCH")  == 0)
		{
			int j = 0;
			while (j < i)
			{
				display_search(book.contacts[j], j);
				j++;
			}
			if (j == 0)
				std::cout << "Phonebook is empty! Please add a contact" << std::endl;
			else
			{
				std::string input;
				std::cout << std::endl;
				std::cout << "Please enter the contact number you want to display!" << std::endl;
				std::cout << "Input: " ;
				std::cin >> input;
				if (valid_input(input, i) == 1)
				{
					std::cout << std::endl;
					std::cout << "Invalid Contact Number!" << std::endl;
				}
				else
				{
					std::cout << std::endl;
					j = std::stoi(input);
					display_ad(book.contacts[j - 1], j - 1);
				}			
			}
		}
		else if (option.compare("EXIT") == 0)
			return (0);
		std::cout << std::endl;
	}
}
