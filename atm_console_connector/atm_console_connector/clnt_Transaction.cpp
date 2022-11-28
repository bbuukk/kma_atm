#include "Bank.h"

#include "clnt_Transaction.h"
#include "Account.h"

clnt::Transaction::Transaction(
	  const std::string& atm_num
	, const mdls::Account& payer
	, const mdls::Account& payee
	, size_t sum, const std::string& descript)
	: payer_(std::make_unique<mdls::Account>(payer))
	, payee_(std::make_unique<mdls::Account>(payee))
	, sum_(sum), atm_num_(atm_num), descript_(descript)
{};

clnt::Transaction::Transaction(
	  const std::string& atm_num
	, std::unique_ptr<mdls::Account> payer
	, std::unique_ptr<mdls::Account> payee
	, size_t sum)
	: payer_(payer.release())
	, payee_(payee.release())
	, sum_(sum), atm_num_(atm_num), descript_("")
{};

bool clnt::Transaction::make() {
	return Bank::make_transaction(*this);
};

std::ostream& operator<<(std::ostream& os, const clnt::Transaction& trans) {
	return os
		<< ((trans.payer() == nullptr) ? "\n" 
			: "Payer account number: " + (*trans.payer()).num()) + "\n"
		<< ((trans.payee() == nullptr) ? "\n"
			: "Payee account number: " + (*trans.payee()).num()) + "\n"
		<< "Transaction sum: " << trans.sum() << "\n"
		<< "ATM number: " << trans.atm_num() << "\n"
		<< "Description: " << trans.descript() << "\n";
};