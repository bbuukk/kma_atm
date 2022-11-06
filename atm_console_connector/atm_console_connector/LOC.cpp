#include "Bank.h"

#include "LOC.h"

mdls::LOC::LOC(
	std::string num, size_t dgt_code,
	double balance, std::string open_date,
	bool blocked, double atm_fee,
	double intrest, size_t crd_taken,
	size_t loc_lim, double crd_return,
	size_t id = 0, size_t off_id = 0,
	size_t clnt_id = 0, size_t acc_type = 0)
	: Account(
		num, dgt_code, balance,
		open_date, blocked,
		atm_fee, intrest,
		id, off_id, clnt_id,
		acc_type), crd_taken(crd_taken),
		loc_lim(loc_lim), crd_return(crd_return) {};

//mdls::LOC::LOC(std::string num)
//	: LOC(Bank::get_loc(num)) {};

std::ostream& mdls::LOC::print(std::ostream& os) const {
	return Account::print(os) 
		<< "Credit is: " << crd_taken << "\n"
		<< "Creditn limit is: " << loc_lim << "\n"
		<< "Credit returned: " << crd_return << "\n";
}


