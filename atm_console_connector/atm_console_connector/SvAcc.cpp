#include "SvAcc.h"

SvAcc::SvAcc(void)
	: Acc(), trans_lim(0) {};

SvAcc::SvAcc(Acc& acc, size_t trans_lim)
	: Acc(
		acc.getAccId(), acc.getDgtCode(),
		acc.getOffId(), acc.getClntId(),
		acc.getAccType(), acc.getAccNum(),
		acc.getBalance(), acc.getOpenDate(),
		acc.getIsBlocked(), acc.getAtmFee(),
		acc.getIntrest()), trans_lim(trans_lim) {};

SvAcc::SvAcc(
	size_t acc_id, size_t dgt_code,
	size_t off_id, size_t clnt_id,
	size_t acc_type, std::string acc_num,
	double balance, std::string  open_date,
	bool is_blocked, double atm_fee,
	double intrest, size_t trans_lim)
	: Acc(
		acc_id, dgt_code, off_id,
		clnt_id, acc_type, acc_num,
		balance, open_date, is_blocked,
		atm_fee, intrest),
		trans_lim(trans_lim) {};


