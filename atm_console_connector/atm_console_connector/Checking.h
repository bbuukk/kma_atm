#pragma once

#include "Account.h"

#include <mysql/jdbc.h>

class Checking : public Account {
public:
	Checking(void) = default;

	Checking(Account&, size_t overdraft_lim);

	Checking(
		std::string num, size_t dgt_code,
		double balance, std::string  open_date,
		bool blocked, double atm_fee,
		double intrest, size_t overdraft_lim);


	Checking(const Checking&) = default;
	Checking& operator=(const Checking&) = default;

	Checking& operator=(Checking&&) noexcept = default;
	Checking(Checking&&) noexcept = default;
	
	~Checking() = default;

	inline size_t get_overdraft_lim() const { return overdraft_lim; };

private:
	std::ostream& print(std::ostream& os) const override;

	size_t overdraft_lim;
};