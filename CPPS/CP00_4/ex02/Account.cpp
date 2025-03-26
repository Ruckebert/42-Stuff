/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:48:34 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/18 09:37:03 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	time_t timestamp = time(NULL);
	std::tm* localtime = std::localtime(&timestamp);

	std::cout << "[" << localtime->tm_year + 1900;
	if (localtime->tm_mon < 10)
		std:: cout << "0" << localtime->tm_mon;
	else
		std:: cout << localtime->tm_mon;
	if (localtime->tm_mday < 10)
		std::cout << "0" << localtime->tm_mday;
	else
		std::cout << localtime->tm_mday;
	if (localtime->tm_hour < 10)
		std::cout << "_0" << localtime->tm_hour;
	else
		std::cout << "_" << localtime->tm_hour;
	if (localtime->tm_min < 10)
		std::cout << "0" << localtime->tm_min;
	else
		std::cout << localtime->tm_min;
	if (localtime->tm_sec < 10)
		std::cout << "0" << localtime->tm_sec << "]";
	else
		std::cout << localtime->tm_sec << "]";
}

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<  ";";
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	std::cout << "amount:" << _amount << ";";
	std::cout << "created";
	std::cout << std::endl;
}

Account::~Account (void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<  ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed\n";
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ';';
	std::cout << "total:" << getTotalAmount() << ';';
	std::cout << "deposits:" << getNbDeposits() << ';';
	std::cout << "withdrawals:" << getNbWithdrawals() << ';';
	std::cout << std::endl;
}

int	Account::getNbAccounts( void )
{
	return(_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);	
}
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);	
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void Account::makeDeposit( int deposit )
{
	_nbAccounts++;
	_totalAmount += deposit;
	_nbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<  ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "desposit:" <<  deposit << ";";
	_amount = _amount + deposit;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << ";\n";
	_totalNbDeposits++;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	_nbAccounts++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<  ";";
	std::cout << "p_amount:" << _amount << ";";
	if ((_amount - withdrawal) > 0)
	{
		_totalAmount -= withdrawal;
		std::cout << "withdrawal:" <<  withdrawal << ";";
		_amount = _amount - withdrawal;
		std::cout << "amount:" << _amount << ";";
		_nbWithdrawals++;
		std::cout << "nb_withdrawal:" << _nbWithdrawals << ";\n";
		_totalNbWithdrawals++;
	}
	else
	{
		std::cout << "withdrawal:refused\n";
		return (false);
	}
	return (true);

}
int		Account::checkAmount( void ) const
{
	std::cout << "I dont know what to use this function for so its just gonna chill here\n";
	return (1);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<  ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "desposits:" <<  _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << ";";
	std::cout << std::endl;
}