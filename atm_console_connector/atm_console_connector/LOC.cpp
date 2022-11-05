#include "LOC.h"

LOC::LOC(
	Account& acc, size_t crd_taken,
	size_t loc_lim, double crd_return)
	: Account(
		acc.get_num(), acc.get_digital_code(),
		acc.get_balance(), acc.get_open_date(),
		acc.is_blocked(), acc.get_atm_fee(),
		acc.get_intrest()), crd_taken(crd_taken),
		loc_lim(loc_lim), crd_return(crd_return) {};

LOC::LOC(
	std::string num, int dgt_code,
	int balance, std::string  open_date,
	bool blocked, double atm_fee,
	double intrest, size_t crd_taken,
	size_t loc_lim, double crd_return)
	: Account(
		num, dgt_code, balance,
		open_date, blocked, atm_fee,
		intrest), crd_taken(crd_taken),
		loc_lim(loc_lim), crd_return(crd_return) {};

std::ostream& LOC::print(std::ostream& os) const {
	return Account::print(os) 
		<< "Credit is: " << crd_taken << "\n"
		<< "Creditn limit is: " << loc_lim << "\n"
		<< "Credit returned: " << crd_return << "\n";
}


