/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:48:34 by aruckenb          #+#    #+#             */
/*   Updated: 2025/02/27 15:13:49 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account( int initial_deposit )
{
	Account account[8];
	int i = 0;

	while (i <= 8)
	{
		account[i]._accountIndex = i;
		std::cout << "index:" << account[i]._accountIndex <<  ";";
		account[i]._amount = initial_deposit;
		std::cout << "amount:" << account[i]._amount << ";";
		std::cout << "created";
		std::cout << std::endl;
		i++;
	}
}

Account::~Account (void)
{
	Account account[8];
	int i = 0;

	while (i <= 8)
	{
		std::cout << "index:" << account[i]._accountIndex <<  ";";
		std::cout << "amount:" << account[i]._amount << ";";
		std::cout << "closed";
		std::cout << std::endl;
		i++;
	}
}

static void	displayAccountsInfos( void )
{
	std::cout << "accounts:" + getNbAccounts() + ';';
	std::cout << "total:" + getTotalAmount() + ';';
	std::cout << "deposits:" + getNbDeposits() + ';';
	std::cout << "withdrawals:" + getNbWithdrawals() + ';';
	std::cout << std::endl;
}

static int	getNbAccounts( void )
{
	static int AccountNum = 0;
	
	return (AccountNum);
}

static int	getTotalAmount( void )
{
	static int total_amount = 0;
		
	return (total_amount);	
}
static int	getNbDeposits( void )
{
	static int total_amount = 0;
		
	return (total_amount);	
	
}

static int	getNbWithdrawals( void )
{
	static int total_amount = 0;
		
	return (total_amount);	
	
}

void	makeDeposit( int deposit )
{
	int i = 0;
	while (i <= 8)
	
}
bool	makeWithdrawal( int withdrawal )
{
	
	
}
int		checkAmount( void )
{

	
}
void	displayStatus( void )
{
	Account account[8];
	int i = 0;

	while (i <= 8)
	{
		std::cout << "index:" << account[i]._accountIndex <<  ";";
		std::cout << "amount:" << account[i]._amount << ";";
		std::cout << "desposits:" <<  account[i]._nbDeposits << ";";
		std::cout << "withdrawals:" << account[i]._nbWithdrawals << ";";
		std::cout << "created";
		std::cout << std::endl;
		i++;
	}

	
}