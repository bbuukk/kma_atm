#include "Checking.h"

mdls::Checking::Checking(Account& acc, size_t overdraft_lim )
	: Account(
		acc.get_num(), acc.get_digital_code(),
		acc.get_balance(), acc.get_open_date(),
		acc.is_blocked(), acc.get_atm_fee(),
		acc.get_intrest()), overdraft_lim(overdraft_lim) {};

mdls::Checking::Checking(
	std::string num, size_t dgt_code,
	double balance, std::string  open_date,
	bool blocked, double atm_fee,
	double intrest, size_t overdraft_lim)
	: Account(
		num, dgt_code, balance,
		open_date, blocked,
		atm_fee, intrest),
		overdraft_lim(overdraft_lim) {};


std::ostream& mdls::Checking::print(std::ostream& os) const {
	return Account::print(os) << "Overdraft limit is: " << overdraft_lim << "\n";
}



