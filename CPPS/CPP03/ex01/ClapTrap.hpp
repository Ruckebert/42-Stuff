/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:27:58 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/26 11:16:48 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
 
#include <iostream>
#include <string>

class ClapTrap
{
	private:
	std::string className;
	std::string name;
	int atkDmg;
	int eng;
	unsigned int hp;

	public:
	ClapTrap();
	ClapTrap(std::string name);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	//Setters
	void SetAttackDamage(int type);
	void SetHp(unsigned int type);
	void SetEnergy(int type);
	std::string NameGetter(void);
	
	void SetClassname(std::string type);
	std::string classNameGetter(void);
};


#endif