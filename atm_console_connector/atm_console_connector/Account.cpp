#include "Account.h"

#include <memory> 
#include <string>

Account::Account(
		 std::string num, size_t dgt_code,
		 double balance, std::string open_date,
		 bool blocked, double atm_fee,
		 double intrest)
	   : num(num), dgt_code(dgt_code),
	     balance(balance), open_date(open_date),
	     blocked(blocked), atm_fee(atm_fee), intrest(intrest) {};

std::ostream& Account::print(std::ostream& os) const {
	os << "Account number: " << num.c_str() << "\n";
	os << "Digital code:" << dgt_code<< "\n";
	os << "Balance: " << balance << "\n";
	os << "Open data: " << open_date.c_str() << "\n";
	os << std::boolalpha;
	os << "Is Blocked: " << blocked << "\n";
	os << std::noboolalpha;
	os << "ATM fee: " << atm_fee << "\n";
	os << "Intrest: " << intrest << "\n";
	return os;
}
