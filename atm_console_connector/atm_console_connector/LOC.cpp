#include "LOC.h"

LOC::LOC(
	Account& acc, size_t crd_taken,
	size_t loc_lim, double crd_return)
	: Account(
		acc.get_account_id(), acc.get_digital_code(),
		acc.get_office_id(), acc.get_client_id(),
		acc.get_account_type(), acc.get_account_num(),
		acc.get_balance(), acc.get_open_date(),
		acc.get_is_blocked(), acc.get_atm_fee(),
		acc.get_intrest()), crd_taken(crd_taken),
		loc_lim(loc_lim), crd_return(crd_return) {};

LOC::LOC(
	int id, int dgt_code,
	int off_id, int clnt_id,
	int acc_type, std::string acc_num,
	int balance, std::string  open_date,
	bool is_blocked, double atm_fee,
	double intrest, size_t crd_taken,
	size_t loc_lim, double crd_return)
	: Account(
		id, dgt_code, off_id,
		clnt_id, acc_type, acc_num,
		balance, open_date, is_blocked,
		atm_fee, intrest), crd_taken(crd_taken),
		loc_lim(loc_lim), crd_return(crd_return) {};

std::ostream& LOC::print(std::ostream& os) const {
	return Account::print(os) 
		<< "Credit is: " << crd_taken << "\n"
		<< "Creditn limit is: " << loc_lim << "\n"
		<< "Credit returned: " << crd_return << "\n";
}


