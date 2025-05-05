/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:06:24 by aruckenb          #+#    #+#             */
/*   Updated: 2025/04/01 10:42:01 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	private:
	std::string idea[100];

	public:
	Brain();
	Brain(const Brain& type);
	Brain &operator=(const Brain& type);
	~Brain();

	void IdeasAdder(std::string idea1);
	std::string GetIdea(int i);
};

#endif