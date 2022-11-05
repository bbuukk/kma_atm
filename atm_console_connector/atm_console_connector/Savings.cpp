#include "Savings.h"

Savings::Savings(Account& acc, size_t trans_lim)
	: Account(
		acc.get_account_id(), acc.get_digital_code(),
		acc.get_office_id(), acc.get_client_id(),
		acc.get_account_type(), acc.get_account_num(),
		acc.get_balance(), acc.get_open_date(),
		acc.get_is_blocked(), acc.get_atm_fee(),
		acc.get_intrest()), trans_lim(trans_lim) {};

Savings::Savings(
	size_t id, size_t dgt_code,
	size_t off_id, size_t clnt_id,
	size_t acc_type, std::string acc_num,
	double balance, std::string  open_date,
	bool is_blocked, double atm_fee,
	double intrest, size_t trans_lim)
	: Account(
		id, dgt_code, off_id,
		clnt_id, acc_type, acc_num,
		balance, open_date, is_blocked,
		atm_fee, intrest),
		trans_lim(trans_lim) {};


std::ostream& Savings::print(std::ostream& os) const {
	return Account::print(os) << "Transaction limit is: " << trans_lim << "\n";
}


