/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:43:43 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 20:10:07 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount= 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created" << std::endl;
}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "closed" << std::endl;
	this->_nbAccounts--;
}

void
Account::_displayTimestamp( void )
{
	std::time_t	time;

	time = std::time(NULL);
	std::cout << std::right << std::setfill('0') << "["
		<< std::setw(4) << std::localtime(&time)->tm_year + 1900
		<< std::setw(2) << std::localtime(&time)->tm_mon + 1
		<< std::setw(2) << std::localtime(&time)->tm_mday
		<< "_"
		<< std::setw(2) << std::localtime(&time)->tm_hour
		<< std::setw(2) << std::localtime(&time)->tm_min
		<< std::setw(2) << std::localtime(&time)->tm_sec
		<< "] " << std::flush;
}

int	
Account::checkAmount(void) const
{
	return (this->_amount);
}

void
Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}

void
Account::displayStatus(void) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}

void
Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";"
		<< "deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_totalAmount += deposit;
	std::cout << "amount:" << this->_amount << ";"
		<< "nb_deposits:" << ++this->_nbDeposits
		<< std::endl;
	this->_totalNbDeposits++;
}

bool
Account::makeWithdrawal(int withdrawal)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";"
		<< "withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";";
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	std::cout << "amount:" << this->_amount << ";"
		<< "nb_withdrawals:" << ++this->_nbWithdrawals
		<< std::endl;
	this->_totalNbWithdrawals++;
	return (true);
}

int	
Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	
Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	
Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

int	
Account::getTotalAmount(void)
{
	return (_totalAmount);
}
