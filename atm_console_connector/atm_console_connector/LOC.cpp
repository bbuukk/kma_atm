#include "Bank.h"

#include "LOC.h"

mdls::LOC::LOC(
	const std::string& num, size_t dgt_code,
	double balance, const std::string& open_date,
	bool blocked, double atm_fee,
	double intrest, size_t crd_taken,
	size_t loc_lim, double crd_return,
	size_t id, size_t off_id,
	size_t clnt_id, size_t acc_type)
	: Account(
		num, dgt_code, balance,
		open_date, blocked,
		atm_fee, intrest,
		id, off_id, clnt_id,
		acc_type), crd_taken(crd_taken),
		loc_lim(loc_lim), crd_return(crd_return) {};

mdls::LOC::LOC(
	const Account& acc, size_t crd_taken,
	size_t loc_lim, size_t crd_return)
	: LOC(
		acc.num(), acc.digital_code(),
		acc.balance(), acc.open_date(),
		acc.is_blocked(), acc.atm_fee(),
		acc.intrest(), crd_taken,
		loc_lim, crd_return,
		acc.id(), acc.office_id(),
		acc.client_id(), acc.type()) {};

//mdls::LOC::LOC(std::string num)
//	: LOC(Bank::get_loc(num)) {};

std::ostream& mdls::LOC::print(std::ostream& os) const {
	return Account::print(os) 
		<< "Credit is: " << crd_taken << "\n"
		<< "Creditn limit is: " << loc_lim << "\n"
		<< "Credit returned: " << crd_return << "\n";
}


