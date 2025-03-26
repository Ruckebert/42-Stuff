/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:31:06 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/07 14:17:15 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contacts.hpp"
#include <cstdlib>

class PhoneBook
{
	private:
	Contact contacts[8];
	
	public:
	PhoneBook();
	~PhoneBook();

	Contact *GetContact(int index);
} ;


void	Add(PhoneBook &book, int &i, int &k);
void	DisplayAd(Contact &contacts, int i);
void	Search(PhoneBook &book, int i);

#endif