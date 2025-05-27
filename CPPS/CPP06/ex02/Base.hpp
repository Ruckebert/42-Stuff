/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:38:03 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/15 13:48:53 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base
{
	private:
	
	public:
	Base();
	Base(const Base& type);
	Base &operator=(const Base& type);
	virtual ~Base();
	
	
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif