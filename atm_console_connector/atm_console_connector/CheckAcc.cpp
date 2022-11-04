#include "CheckAcc.h"

CheckAcc::CheckAcc(void)
	: Acc(), overdraft_lim(0) {};

CheckAcc::CheckAcc(Acc& acc, size_t overdraft_lim )
	: Acc(
		acc.getAccId(), acc.getDgtCode(),
		acc.getOffId(), acc.getClntId(),
		acc.getAccType(), acc.getAccNum(),
		acc.getBalance(), acc.getOpenDate(),
		acc.getIsBlocked(), acc.getAtmFee(),
		acc.getIntrest()), overdraft_lim(overdraft_lim) {};

CheckAcc::CheckAcc(
	size_t acc_id, size_t dgt_code,
	size_t off_id, size_t clnt_id,
	size_t acc_type, std::string acc_num,
	double balance, std::string  open_date,
	bool is_blocked, double atm_fee,
	double intrest, size_t overdraft_lim)
	: Acc(
		acc_id, dgt_code, off_id,
		clnt_id, acc_type, acc_num,
		balance, open_date, is_blocked,
		atm_fee, intrest),
		overdraft_lim(overdraft_lim) {};


std::ostream& CheckAcc::print(std::ostream& os) const {
	
	
	
	return Acc::print(os) << "Overdraft limit is: " << overdraft_lim << "\n";;
}



