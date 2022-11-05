#pragma once

#include "Transaction.h"

#include <mysql/jdbc.h>

class Transaction {
public:
	Transaction(void) = default;

	Transaction(
		std::string num,
		std::string acc_from,
		std::string acc_to,
		size_t sum, std::string date,
		bool successful, std::string atm_num,
		std::string descript);

	Transaction(const Transaction&) = default;
	Transaction& operator=(const Transaction&) = default;

	~Transaction() = default;

	inline std::string get_num() const { return num; }
	inline std::string get_account_from() const { return acc_from; };
	inline std::string get_account_to() const { return acc_to; };
	inline size_t get_sum() const { return sum; };

	inline std::string get_date() const { return date; };
	inline bool is_successful() const { return successful; };
	inline std::string get_atm_num() const { return atm_num; };
	inline std::string get_descript() const { return descript; }; //description

private:
	std::string num;
	std::string acc_from;
	std::string acc_to;
	size_t sum;

	std::string date;
	bool successful;
	std::string atm_num;
	std::string descript;
};

std::ostream& operator<<(std::ostream& os, const Transaction& off);

