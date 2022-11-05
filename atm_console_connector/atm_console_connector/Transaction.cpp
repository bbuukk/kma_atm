
#include "Transaction.h"

Transaction::Transaction(
	size_t id, size_t mach_id,
	size_t acc_from, size_t acc_to,
	size_t t_sum, std::string t_date,
	bool successful, std::string t_descript)
	: id(id), mach_id(mach_id),
	  acc_from(acc_from), acc_to(acc_to),
	  t_sum(t_sum), t_date(t_date),
	  successful(successful), t_descript(t_descript) {};

std::ostream& operator<<(std::ostream& os, const Transaction& trans) {
	return os
		<< "Transaction id: " << trans.get_id() << "\n"
		<< "Machine id: " << trans.get_machine_id() << "\n"
		<< "Account from id: " << trans.get_account_from_id() << "\n"
		<< "Account to id: " << trans.get_account_to_id() << "\n"

		<< "Transaction sum: " << trans.get_sum() << "\n"
		<< "Transaction date: " << trans.get_date() << "\n"
		<< "Is successful: " << trans.is_successful() << "\n"
		<< "Description: " << trans.get_descript() << "\n";
}