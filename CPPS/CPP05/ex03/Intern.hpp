/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:47:09 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/07 13:58:01 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	private:

	public:
	Intern();
	Intern(const Intern& type);
	Intern &operator=(const Intern& type);
	~Intern();

	class AForm *makeForm(std::string form, std::string target);
};

#endif