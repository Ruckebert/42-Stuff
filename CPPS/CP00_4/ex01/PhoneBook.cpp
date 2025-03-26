/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:35:31 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/07 10:03:50 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"


Contact *PhoneBook::GetContact(int index) {return (&contacts[index]);}

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}