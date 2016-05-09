/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 19:59:37 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/03 11:03:04 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>
#include <ctime>

// Special Member Method
Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;
}

Account::~Account(void)
{
	Account::_nbAccounts -= 1;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";closed"
		<< std::endl;
}

// Member Method
void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";deposit:" << deposit;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	std::cout << ";amount:" << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits
		<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";withdrawal:";
	if (withdrawal <= this->_amount)
	{
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals += 1;
		Account::_totalNbWithdrawals += 1;
		std::cout << withdrawal
			<< ";amount:" << this->_amount
			<< ";nb_withdrawals:" << this->_nbWithdrawals
			<< std::endl;
		return (true);
	}
	std::cout << "refused"
		<< std::endl;
	return (false);
}

int		Account::checkAmount(void) const {return this->_amount;}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}

// Non-Member Methods
// Getter
int	Account::getNbAccounts(void) {return Account::_nbAccounts;}
int	Account::getTotalAmount(void) {return Account::_totalAmount;}
int	Account::getNbDeposits(void) {return Account::_totalNbDeposits;}
int	Account::getNbWithdrawals(void) {return Account::_totalNbWithdrawals;}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
		<< ";total:" << Account::getTotalAmount()
		<< ";deposits:" << Account::getNbDeposits()
		<< ";withdrawals:" << Account::getNbWithdrawals()
		<< std::endl;
}

// Non-Member Attributes
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	time_t t = time(0);
	struct tm *now = localtime(&t);

	std::cout << "["
		<< (now->tm_year + 1900);
	if (now->tm_mon + 1 < 10)
		std::cout << "0";
	std::cout << (now->tm_mon + 1);
	if (now->tm_mday < 10)
		std::cout << "0";
	std::cout <<  now->tm_mday << "_";
	if (now->tm_hour < 10)
		std::cout << "0";
	std::cout <<  now->tm_hour;
	if (now->tm_min < 10)
		std::cout << "0";
	std::cout <<  now->tm_min;
	if (now->tm_sec < 10)
		std::cout << "0";
	std::cout <<  now->tm_sec << "] ";
}
