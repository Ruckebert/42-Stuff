/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:32:46 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/07 10:04:45 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

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
	Contact();
	~Contact();

	//Setters
	void FirstNameSetter(std::string &input);
	void LastNameSetter(std::string input);
	void NicknameSetter(std::string input);
	void PhoneNumberSetter(long input);
	void DarkestSetter(std::string input);

	//Getters
	std::string FirstNameGetter();
	std::string LastNameGetter();
	std::string NicknameGetter();
	long PhoneNumberGetter();
	std::string DarkestGetter();

} ;

#endif