
#include "Bank.h"

#include "Transaction.h"
#include "Account.h"

mdls::Transaction::Transaction(
	const std::string& num,
	const std::shared_ptr<mdls::Account> acc_from,
	const std::shared_ptr<mdls::Account> acc_to,
	size_t sum, const std::string& datetime,
	bool successful, const std::string& atm_num,
	const std::string& descript)
	: num_(num), acc_from_(acc_from), acc_to_(acc_to)
	, sum_(sum), datetime_(datetime), successful_(successful)
	, atm_num_(atm_num), descript_(descript) 
{};

mdls::Transaction::Transaction(
	const std::string& atm_num,
	std::unique_ptr<mdls::Account> acc_from,
	std::unique_ptr<mdls::Account> acc_to,
	size_t sum)
	: num_("")
	, acc_from_(acc_to.release())
	, acc_to_(acc_to.release())
	, sum_(sum), datetime_(""), successful_(0)
	, atm_num_(atm_num), descript_("") 
{};

////transef
//mdls::Transaction::Transaction(
//	const std::string& atm_num,
//	const std::string& acc_to,
//	size_t sum)
//	: Transaction(
//		atm_num, "", acc_to
//		, sum, "")
//{};
//
////transef
//mdls::Transaction::Transaction(
//	const std::string& atm_num,
//	const std::string& acc_from,
//	const std::string& acc_to,
//	size_t sum,
//	const std::string& descript)
//	: Transaction(
//		"", acc_from, acc_to, sum, "",
//		false, atm_num, descript)
//{};
//
////withdraw
//mdls::Transaction::Transaction(
//	const std::string& atm_num,
//	const std::string& acc_from,
//	size_t sum)
//	: Transaction(
//		atm_num, acc_from, ""
//		, sum, "")
//{};




mdls::Transaction::Transaction(const std::string& num)
	: Transaction(Bank::get_transaction(num)) {};

//TODO make check for empty acc_to better
//TOOD we have 3 types of transaction, one condition check isn't enough
bool mdls::Transaction::make() const {
	return Bank::make_transaction(*this);
};

std::ostream& operator<<(std::ostream& os, const mdls::Transaction& trans) {
	return os
		<< "Transaction number: " << trans.num() << "\n"
		<< "Payer account number: " << trans.account_from() << "\n"
		<< "Payee account number: " << trans.account_to() << "\n"
		<< "Transaction sum: " << trans.sum() << "\n"

		<< "Transaction date: " << trans.date() << "\n"
		<< "Is successful: " << trans.is_successful() << "\n"
		<< "ATM number: " << trans.atm_num() << "\n"
		<< "Description: " << trans.descript() << "\n";
};