

#include "Transaction.h"
#include "Bank.h"

//TODO why we need to put :: befor Bank?
mdls::Transaction::Transaction(const std::string& num)
	: Transaction(::Bank::get_transaction(num))
{};

mdls::Transaction::Transaction(
	const std::string& num,
	const std::string& payer,
	const std::string& payee,
	size_t sum, const std::string& datetime,
	bool is_successful,
	const std::string& descript)
	: num_(num), payer_(payer), payee_(payee)
	, sum_(sum), datetime_(datetime)
	, is_successful_(is_successful),descript_(descript)
{};


std::ostream& operator<<(std::ostream& os, const mdls::Transaction& trans) {
	return os
		<< "Transaction number: " << trans.num() << "\n"
		<< "Payer account number: " << trans.payee() << "\n"
		<< "Payee account number: " << trans.payer() << "\n"
		<< "Transaction sum: " << trans.sum() << "\n"

		<< "Transaction date: " << trans.datetime() << "\n"
		<< "Is successful: " << trans.is_successful() << "\n"
		<< "Description: " << trans.descript() << "\n";
};


