#pragma once

#include "Transaction.h"

#include <mysql/jdbc.h>

class Transaction {
public:
	Transaction(void) = default;

	Transaction(
		size_t id, size_t mach_id,
		size_t acc_from, size_t acc_to,
		size_t t_sum, std::string t_date,
		bool successful, std::string t_descript);

	Transaction(const Transaction&) = default;
	Transaction& operator=(const Transaction&) = default;

	~Transaction() = default;

	inline size_t get_id() const { return id; };
	inline size_t get_machine_id() const { return mach_id; };
	inline size_t get_account_from_id() const { return acc_from; };
	inline size_t get_account_to_id() const { return acc_to; };

	inline size_t get_sum() const { return t_sum; };
	inline std::string get_date() const { return t_date; };
	inline bool is_successful() const { return successful; };
	inline std::string get_descript() const { return t_descript; }; //description

private:
	size_t id;
	size_t mach_id;
	size_t acc_from;
	size_t acc_to;

	size_t t_sum;
	std::string t_date;
	bool successful;
	std::string t_descript;
};

std::ostream& operator<<(std::ostream& os, const Transaction& off);

//id	int unsigned	NO	PRI		auto_increment
//mach_id	int unsigned	YES	MUL
//acc_from	int unsigned	NO	MUL
//acc_to	int unsigned	YES	MUL

//t_sum	int unsigned	NO
//t_date	date	NO
//successful	tinyint	NO
//t_descript	tinytext	NO