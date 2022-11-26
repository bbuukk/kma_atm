
#include "Bank.h"

#include "Transaction.h"

mdls::Transaction::Transaction(
	const std::string& num,
	const std::string& acc_from,
	const std::string& acc_to,
	size_t sum, const std::string& date,
	bool successful, const std::string& atm_num,
	const std::string& descript)
	: num(num), acc_from(acc_from), acc_to(acc_to),
	  sum(sum), date(date), successful(successful),
	  atm_num(atm_num), descript(descript) {};

mdls::Transaction::Transaction(const std::string& num)
	: Transaction(Bank::get_transaction(num)) {};

//TODO make check for empty acc_to better
bool mdls::Transaction::make() const {
	return acc_to == "" ?
		  Bank::withdraw(atm_num, acc_from, sum, descript)
		: Bank::transfer(atm_num, acc_from, acc_to, sum, descript);
};

std::ostream& operator<<(std::ostream& os, const mdls::Transaction& trans) {
	return os
		<< "Transaction number: " << trans.get_num() << "\n"
		<< "Payer account number: " << trans.get_account_from() << "\n"
		<< "Payee account number: " << trans.get_account_to() << "\n"
		<< "Transaction sum: " << trans.get_sum() << "\n"

		<< "Transaction date: " << trans.get_date() << "\n"
		<< "Is successful: " << trans.is_successful() << "\n"
		<< "ATM number: " << trans.get_atm_num() << "\n"
		<< "Description: " << trans.get_descript() << "\n";
};