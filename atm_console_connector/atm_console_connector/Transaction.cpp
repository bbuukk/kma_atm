
#include "Transaction.h"
#include "Database.h"

mdls::Transaction::Transaction(
	std::string num,
	std::string acc_from,
	std::string acc_to,
	size_t sum, std::string date,
	bool successful, std::string atm_num,
	std::string descript)
	: num(num), acc_from(acc_from), acc_to(acc_to),
	  sum(sum), date(date), successful(successful),
	  atm_num(atm_num), descript(descript) {};

mdls::Transaction::Transaction(std::string num)
	: Transaction(Database::get_repository()
		.get_transaction(num)) {};

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
}