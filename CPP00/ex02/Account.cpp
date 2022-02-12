#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
	this->_accountIndex = 0;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	std::cout 	<< "index:"
				<< this->_accountIndex
				<< ";amount:"
				<< checkAmount()
				<< ";created"
				<< std::endl;
	Account::_totalAmount += this->_amount;
	Account::_nbAccounts++;
}

/* The order to call destructors in an array of objects is not
	standardized and depends on the implementation in each compiler */
Account::~Account(void){
	Account::_displayTimestamp();
	std::cout	<< "index:"
				<< this->_accountIndex
				<< ";amount:"
				<< checkAmount()
				<< ";closed"
				<< std::endl;
	Account::_nbAccounts--;
}

void	Account::displayAccountsInfos(void){
	Account::_displayTimestamp();
	std::cout	<< "accounts:"
				<< getNbAccounts()
				<< ";total:"
				<< getTotalAmount()
				<< ";deposits:"
				<< getNbDeposits()
				<< ";withdrawals:"
				<< getNbWithdrawals()
				<< std::endl;
}

void	Account::displayStatus(void) const{
	Account::_displayTimestamp();
	std::cout 	<< "index:"
				<< this->_accountIndex 
				<< ";amount:"
				<< checkAmount()
				<< ";deposits:"
				<< this->_nbDeposits
				<< ";withdrawals:"
				<< this->_nbWithdrawals
				<< std::endl;
}

void	Account::makeDeposit(int deposit){
	Account::_displayTimestamp();
	std::cout	<< "index:"
				<< this->_accountIndex
				<< ";p_amount:"
				<< checkAmount()
				<< ";deposit:"
				<< deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	std::cout	<< ";amount:"
				<< checkAmount()
				<< ";nb_deposits:" << this->_nbDeposits
				<< std::endl;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal){
	Account::_displayTimestamp();
	std::cout	<< "index:"
				<< this->_accountIndex
				<< ";p_amount:"
				<< checkAmount()
				<< ";withdrawal:";
	if(this->_amount - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout	<< withdrawal
				<< ";amount:"
				<< checkAmount() 
				<< ";nb_withdrawals:"
				<< this->_nbWithdrawals
				<< std::endl;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;	
	return (true);
}

int	Account::checkAmount(void) const{
	return (this->_amount);
}

int	Account::getNbAccounts(void){
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void){
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void){
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void){
	return (Account::_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void){
	time_t timestamp = time(NULL);
	std::tm *time = std::localtime(&timestamp);
	std::cout << std::setfill('0')
		<< "["
		<< time->tm_year + 1900
		<< std::setw(2)
		<< time->tm_mon + 1
		<< std::setw(2) 
		<< time->tm_mday
		<< "_"
		<< std::setw(2)
		<< time->tm_hour
		<< std::setw(2)
		<< time->tm_min
		<< std::setw(2)
		<< time->tm_sec
		<< "] ";
}