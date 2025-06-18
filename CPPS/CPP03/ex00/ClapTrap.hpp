/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:27:58 by aruckenb          #+#    #+#             */
/*   Updated: 2025/04/15 10:09:30 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
 
#include <iostream>
#include <string>

class ClapTrap
{
	private:
	std::string name;
	int atkDmg;
	int eng;
	unsigned int hp;

	public:
	ClapTrap();
	ClapTrap(std::string& name);
	ClapTrap(const ClapTrap& type);
	ClapTrap &operator=(const ClapTrap& type);
	~ClapTrap();

	//Setters and Getters
	void SetAttackDamage(int type);
	void SetHp(unsigned int type);
	void SetEnergy(int type);
	int GetAttackDamage(void);
	unsigned int GetHp(void);
	int GetEng(void);
	std::string NameGetter(void);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


#endif