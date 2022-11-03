#include "Acc.h"

#include <string>




Acc::Acc()
	: acc_id(0), dgt_code(0), off_id(0),
	clnt_id(0), acc_type(0), acc_num(nullptr),
	balance(0), open_date(nullptr), is_blocked(0),
	atm_fee(0), intrest(0) {};

Acc::Acc(int acc_id, int dgt_code,
		 int off_id, int clnt_id,
		 int acc_type, std::string acc_num,
		 int balance, std::string  open_date,
		 bool is_blocked, double atm_fee,
		 double intrest)
	: acc_id(acc_id), dgt_code(dgt_code),
	  off_id(off_id),clnt_id(clnt_id),
	  acc_type(acc_type), acc_num(acc_num),
	  balance(balance), open_date(open_date),
	  is_blocked(0),atm_fee(0), intrest(0) {};

Acc::~Acc() {};


std::ostream& operator<<(std::ostream& os, const Acc& acc)
{
	
	os << acc.getAccId(); os << acc.getDgtCode();
	os << acc.getOffId(); os << acc.getClntId();
	os << acc.getAccType(); os << acc.getAccNum();
	os << acc.getBalance(); os << acc.getOpenDate();
	os << acc.getIsBlocked(); os << acc.getAtmFee();
	os << acc.getIntrest();

	return os;
}

//int acc_id;
//int dgt_code;
//int off_id;
//int clnt_id;
//int acc_type;
//std::string acc_num;
//double balance;
//std::string open_date;
//bool is_blocked;
//double atm_fee;
//double intrest;
