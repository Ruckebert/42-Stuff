/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:31:06 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/04 14:07:22 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <ios>

class Contact
{
	private:
	std::string FirstName ;
	std::string LastName ;
	std::string Nickname ;
	long PhoneNumber ;
	std::string DarkestSecret ;
	
	public:
	Contact() {}
	~Contact() {}

	//Setters
	void FirstNameSetter(std::string &input){FirstName = input;}
	void LastNameSetter(std::string input){LastName = input;}
	void NicknameSetter(std::string input){Nickname = input;}
	void PhoneNumberSetter(long input){PhoneNumber = input;}
	void DarkestSetter(std::string input){DarkestSecret= input;}

	//Getters
	std::string FirstNameGetter(){return FirstName;}
	std::string LastNameGetter(){return LastName;}
	std::string NicknameGetter(){return Nickname;}
	long PhoneNumberGetter(){return PhoneNumber;}
	std::string DarkestGetter(){return DarkestSecret;}

} ;

class PhoneBook
{
	private:
	Contact contacts[8];
	
	public:
	PhoneBook() {}
	~PhoneBook() {}
	Contact *GetContact(int index) {return (&contacts[index]);}
} ;


void	Add(PhoneBook &book, int &i, int &k);
void	DisplayAd(Contact &contacts, int i);
void	Search(PhoneBook &book, int i);

#endif