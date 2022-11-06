#include "Account.h"

mdls::Account::Account(
		 std::string num, size_t dgt_code,
		 double balance, std::string open_date,
		 bool blocked, double atm_fee,
		 double intrest)
	   : num(num), dgt_code(dgt_code),
	     balance(balance), open_date(open_date),
	     blocked(blocked), atm_fee(atm_fee), intrest(intrest) {};

mdls::Account::Account(std::string num)
	: Account(Bank::get_account(num)) {};

mdls::Office& mdls::Account::get_office() {
	return Bank::get_acc_office(this->num);
}

void mdls::Account::block() {
	this->blocked = 1;
	Bank::block_account(this->num);	
}

void mdls::Account::unblock() {
	this->blocked = 0;
	Bank::unblock_account(this->num);
}

std::vector<mdls::Transaction>&
mdls::Account::get_transactions() {
	return Bank::get_acc_transactions(this->num);
}

std::ostream& mdls::Account::print(std::ostream& os) const {
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
