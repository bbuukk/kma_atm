#include "Bank.h"

#include "Savings.h"

mdls::Savings::Savings(Account& acc, size_t trans_lim)
	: Account(
		acc.get_num(), acc.get_digital_code(),
		acc.get_balance(), acc.get_open_date(),
		acc.is_blocked(), acc.get_atm_fee(),
		acc.get_intrest()), trans_lim(trans_lim) {};

mdls::Savings::Savings(
	std::string num, size_t dgt_code,
	double balance, std::string  open_date,
	bool blocked, double atm_fee,
	double intrest, size_t trans_lim)
	: Account(
		num, dgt_code, balance,
		open_date, blocked,
		atm_fee, intrest),
		trans_lim(trans_lim) {};

std::ostream& mdls::Savings::print(std::ostream& os) const {
	return Account::print(os) << "Transaction limit is: " << trans_lim << "\n";
}


