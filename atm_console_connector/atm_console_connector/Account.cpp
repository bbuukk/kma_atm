#include "Bank.h"

#include "Account.h"

//constructor just for listing accounts via their numbers
mdls::Account::Account(const std::string& num)
	: Account(num, 0, 0, "", 0, 0, 0, 0, 0, 0, 0) {};

//TODO do we really need default arguments here? 
//test if we get sqlexception when we want get_account buy num,
//but it is not present in bank. if we get sqlException
//then default arguments are free to go
mdls::Account::Account(
	const std::string& num, size_t dgt_code,
	double balance, const std::string& open_date,
	bool blocked, double atm_fee,
	double intrest, size_t id, size_t off_id,
	size_t clnt_id, size_t acc_type)
	: num_(num), dgt_code_(dgt_code),
	balance_(balance), open_date_(open_date),
	blocked_(blocked), atm_fee_(atm_fee),
	intrest_(intrest), id_(id), off_id_(off_id),
	clnt_id_(clnt_id), acc_type_(acc_type) {};

mdls::Office& mdls::Account::get_office() {
	return Bank::get_acc_office(this->id());
}

bool mdls::Account::block() {
	if (Bank::block_account(this->id())) {
		this->blocked_ = 1;
		return true;
	}
	return false;
}

bool mdls::Account::unblock() {
	if (Bank::unblock_account(this->id())) {
		this->blocked_ = 0;
		return true;
	}
	return false;
}

//std::vector<mdls::Transaction>&
//mdls::Account::get_transactions() {
//	return Bank::get_acc_transactions(this->id());
//}

//TODO delete
//bool mdls::Account::deposit(size_t sum) {
//	bool is_successful = Bank::deposit(id(), sum);
//	balance_ += sum;
//
//	return is_successful;
//};
//
//bool mdls::Account::withdraw(size_t sum) {
//	bool is_successful = Bank::withdraw(id(), sum);
//	balance_ += sum;
//
//	return is_successful;
//};

std::ostream& mdls::Account::print(std::ostream& os) const {
	os << "Account number: " << num().c_str() << "\n";
	os << "Digital code:" << digital_code() << "\n";
	os << "Balance: " << balance() << "\n";
	os << "Open data: " << open_date().c_str() << "\n";
	os << std::boolalpha;
	os << "Is Blocked: " << is_blocked() << "\n";
	os << std::noboolalpha;
	os << "ATM fee: " << atm_fee() << "\n";
	os << "Intrest: " << intrest() << "\n";
	return os;
}

