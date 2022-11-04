#include "Acc.h"

#include <memory> 
#include <string>

Acc::Acc(void)
	: acc_id(0), dgt_code(0), off_id(0),
	clnt_id(0), acc_type(0), acc_num(nullptr),
	balance(0), open_date(nullptr), is_blocked(0),
	atm_fee(0), intrest(0) {};


Acc::Acc(size_t acc_id, size_t dgt_code,
		 size_t off_id, size_t clnt_id,
		 size_t acc_type, std::string acc_num,
		 double balance, std::string open_date,
		 bool is_blocked, double atm_fee,
		 double intrest)
	: acc_id(acc_id), dgt_code(dgt_code),
	  off_id(off_id),clnt_id(clnt_id),
	  acc_type(acc_type), acc_num(std::move(acc_num)),
	  balance(balance), open_date(std::move(open_date)),
	  is_blocked(0), atm_fee(0), intrest(0) {};

std::ostream& Acc::print(std::ostream& os) const {
	os << "Account id is: " << acc_id<< "\n";
	os << "Digital code is:" << dgt_code<< "\n";
	os << "Office id is: " << off_id<< "\n";
	os << "Client id is: " << clnt_id << "\n";
	os << "Account type is: " << acc_type<< "\n";
	os << "Account number is: " << acc_num.c_str() << "\n";
	os << "Balance is: " << balance << "\n";
	os << "Open date is: " << open_date.c_str() << "\n";
	os << std::boolalpha;
	os << "Is Blocked: " << is_blocked << "\n";
	os << std::noboolalpha;
	os << "ATM fee is:: " << atm_fee << "\n";
	os << "Intrest is: " << intrest << "\n";
	return os;
}
