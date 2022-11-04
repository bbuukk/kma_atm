#include "LocAcc.h"

LocAcc::LocAcc(
	Account& acc, size_t crd_taken,
	size_t loc_lim, double crd_return)
	: Account(
		acc.getAccId(), acc.getDgtCode(),
		acc.getOffId(), acc.getClntId(),
		acc.getAccType(), acc.getAccNum(),
		acc.getBalance(), acc.getOpenDate(),
		acc.getIsBlocked(), acc.getAtmFee(),
		acc.getIntrest()), crd_taken(crd_taken),
		loc_lim(loc_lim), crd_return(crd_return) {};

LocAcc::LocAcc(
	int acc_id, int dgt_code,
	int off_id, int clnt_id,
	int acc_type, std::string acc_num,
	int balance, std::string  open_date,
	bool is_blocked, double atm_fee,
	double intrest, size_t crd_taken,
	size_t loc_lim, double crd_return)
	: Account(
		acc_id, dgt_code, off_id,
		clnt_id, acc_type, acc_num,
		balance, open_date, is_blocked,
		atm_fee, intrest), crd_taken(crd_taken),
		loc_lim(loc_lim), crd_return(crd_return) {};

std::ostream& LocAcc::print(std::ostream& os) const {
	return Account::print(os) 
		<< "Credit is: " << crd_taken << "\n"
		<< "Creditn limit is: " << loc_lim << "\n"
		<< "Credit returned: " << crd_return << "\n";
}


