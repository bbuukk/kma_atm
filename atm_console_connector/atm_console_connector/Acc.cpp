#include "Acc.h"

#include <string>

Acc::Acc()
	: acc_id(0), dgt_code(0), off_id(0),
	clnt_id(0), acc_type(0), acc_num(0),
	balance(0), open_date(0), is_blocked(0),
	atm_fee(0), intrest(0) {};

Acc::Acc(int acc_id, int dgt_code,
		 int off_id, int clnt_id,
		 int acc_type, std::string acc_num,
		 double balance, std::string  open_date,
		 bool is_blocked, double atm_fee,
		 double intrest)
	: acc_id(acc_id), dgt_code(dgt_code),
	  off_id(off_id),clnt_id(clnt_id),
	  acc_type(acc_type), acc_num(acc_num),
	  balance(balance), open_date(open_date),
	  is_blocked(0), atm_fee(0), intrest(0) {};


Acc::Acc(const Acc& a)
	: Acc(a.getAccId(), a.getDgtCode(),
		  a. getOffId(), a.getClntId(),
		  a.getAccType(), a.getAccNum(),
		  a.getBalance(), a.getOpenDate(),
		  a.getIsBlocked(), a.getAtmFee(),
		  a.getIntrest()) {};

Acc::~Acc() {};


std::ostream& operator<<(std::ostream& os, const Acc& acc)
{
	os << "=====================================" << "\n";
	os << "Account id is: " << acc.getAccId() << "\n";
	os << "Digital code is:" << acc.getDgtCode() << "\n";
	os << "Office id is: " << acc.getOffId() << "\n";
	os << "Client id is: " << acc.getClntId() << "\n";
	os << "Account type is: " << acc.getAccType() << "\n";
	os << "Account number is: " << acc.getAccNum() << "\n";
	os << "Balance is: " << acc.getBalance() << "\n";
	os << "Open date is: " << acc.getOpenDate() << "\n";
	os << "Is Blocked: " << acc.getIsBlocked() << "\n";
	os << "ATM fee is:: " << acc.getAtmFee() << "\n";
	os << "Intrest is: " << acc.getIntrest() << "\n";
	os << "=====================================" << "\n";

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
