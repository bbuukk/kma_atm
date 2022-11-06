#include "Bank.h"

#include "Checking.h"

mdls::Checking::Checking(
	std::string num, size_t dgt_code,
	double balance, std::string open_date,
	bool blocked, double atm_fee,
	double intrest, size_t overdraft_lim,
	size_t id, size_t off_id,
	size_t clnt_id, size_t acc_type)
	: Account(
		num, dgt_code,
		balance, open_date,
		blocked, atm_fee,
		intrest, id,
		off_id, clnt_id, acc_type),
		overdraft_lim(overdraft_lim) {};

//mdls::Checking::Checking(std::string num)
//	: Cheking(Bank::get_checking(num)) {};


std::ostream& mdls::Checking::print(std::ostream& os) const {
	return Account::print(os) << "Overdraft limit is: " << overdraft_lim << "\n";
}



