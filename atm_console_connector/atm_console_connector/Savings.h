#pragma once

#include "Account.h"

#include <mysql/jdbc.h>

class Savings : public Account {
public:
	Savings(void) = default;

	Savings(Account&, size_t trans_lim);

	Savings(std::string num, size_t dgt_code,
		double balance, std::string  open_date,
		bool blocked, double atm_fee,
		double intrest, size_t trans_lim);

	Savings(const Savings&) = default;
	Savings& operator=(const Savings&) = default;

	~Savings() = default;

	inline size_t get_trans_limit() const { return trans_lim; };

private:
	std::ostream& print(std::ostream& os) const override;

	size_t trans_lim;
};