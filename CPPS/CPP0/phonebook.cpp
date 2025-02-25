/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:35:31 by aruckenb          #+#    #+#             */
/*   Updated: 2025/02/25 15:09:31 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Contact
{
	private:
	
	public:
	std::string first_name ;
	std::string last_name ;
	std::string nickname ;
	long phone_number ;
	std::string darkest_secret ;
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
		if (i == 4 || i == 3)
		{
			std::cin.ignore();
			std::getline(std::cin, type);	
		}
		else
			std::cin >> type;
		if (type.empty() == 1)
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
	while (1)
	{
		std::cout << "Please input the phone number below" << std::endl;
		std::cout << "Input: " ;
		std::cin >> type;
		if (std::to_string(type).length() > 10)
			std::cout << "Invalid Phone Number!! Try Again" << std::endl;
		else
		{
			std::cout << std::endl;
			return ;
		}
		std::cout << std::endl;
	}
}

void	adding_darksrc(std::string &type)
{
	while (1)
	{
		std::cout << "Please input their darkest secrets below" << std::endl;
		std::cout << "Input: " ;
		std::cin.ignore();
		std::getline(std::cin, type);
		
		if (type.empty() == 1)
			std::cout << "Invalid Input!! Try Again" << std::endl;
		else
		{
			std::cout << std::endl;
			return ;
		}
		std::cout << std::endl;
	}

}

void	adding(Contact &contacts)
{
	adding_str(contacts.first_name, 1);
	adding_str(contacts.last_name, 2);
	adding_str(contacts.nickname, 3);
	adding_phone(contacts.phone_number);
	adding_darksrc(contacts.darkest_secret);
}

void	display_ad(Contact &contacts, int i)
{
	std::cout << "Displaying Contact Number " << i + 1 << std::endl;
	std::cout << "First Name: " << contacts.first_name << std::endl;
	std::cout << "Last Name: " << contacts.last_name << std::endl;
	std::cout << "Nickname: " << contacts.nickname << std::endl;
	std::cout << "Phonenumber: " << contacts.phone_number << std::endl;
	std::cout << "Darkest Secret: " << contacts.darkest_secret << std::endl;
	std::cout << std::endl;
}

void	char_check_and_print(std::string type)
{
	int i = 0;
	if (type.length() >= 10)
	{
		while (i <= 9)
		{
			std::cout << type[i];
			i++;
		}
		std::cout << "." << " | ";	
	}
	else
		std::cout << type << " | ";
	
}

void	display_search(Contact &contacts, int i)
{
	std::cout << "Contact Number: " << i + 1 << " | ";
	char_check_and_print(contacts.first_name);
	char_check_and_print(contacts.last_name);
	char_check_and_print(contacts.nickname);
	std::cout << std::endl;
}

int main()
{
	PhoneBook book ;
	int i = 0;

	while (1)
	{
		std::string option;
		std::cout << "Please Enter One of the Options Below" << std::endl;
		std::cout << "1: ADD" << std::endl;
		std::cout << "2: SEARCH" << std::endl;
		std::cout << "3: EXIT" << std::endl;
		std::cout << "Input: " ;
		std::cin >> option;
		std::cout << std::endl;
		
		if (option.compare("ADD")  == 0)
		{
			adding(book.contacts[i]);
			display_ad(book.contacts[i], i);
			i++;
			if (i == 8)
			{
				std::cout << "Phonebook full exiting!!" << std::endl;
				return (1);
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
			j = 0;
			std::cout << "Please enter the contact number you want to display!" << std::endl;
			std::cout << "Input: " ;
			std::cin >> j;
			std::cout << std::endl;
			display_ad(book.contacts[j - 1], j - 1);
		}
		else if (option.compare("EXIT") == 0)
			return (0);
		std::cout << std::endl;
	}
}
