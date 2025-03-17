/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:38:08 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/05 12:41:21 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
	private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

	public:
	Harl();
	~Harl();

	void complain(std::string level);
} ;

#endif