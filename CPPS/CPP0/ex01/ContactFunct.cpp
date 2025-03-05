/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactFunct.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:30:39 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/05 10:36:13 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

//Setters
void Contact::FirstNameSetter(std::string &input){FirstName = input;}
void Contact::LastNameSetter(std::string input){LastName = input;}
void Contact::NicknameSetter(std::string input){Nickname = input;}
void Contact::PhoneNumberSetter(long input){PhoneNumber = input;}
void Contact::DarkestSetter(std::string input){DarkestSecret= input;}

//Getters
std::string Contact::FirstNameGetter(){return FirstName;}
std::string Contact::LastNameGetter(){return LastName;}
std::string Contact::NicknameGetter(){return Nickname;}
long Contact::PhoneNumberGetter(){return PhoneNumber;}
std::string Contact::DarkestGetter(){return DarkestSecret;}