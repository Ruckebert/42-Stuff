/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:01:46 by aruckenb          #+#    #+#             */
/*   Updated: 2025/05/29 13:34:40 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

class MutantStack
{
	private:

	public:
	void push();
	void pop();
	void top();
	void size();

	void begin(); //iterator
	void end(); //iterator
};

#endif