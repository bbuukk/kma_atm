#pragma once

#include "Account.h"

#include <mysql/jdbc.h>

class Checking : public Account {
public:
	Checking(void) = default;

	Checking(Account&, size_t overdraft_lim);

	Checking(size_t id, size_t dgt_code,
			 size_t off_id, size_t clnt_id,
			 size_t acc_type, std::string acc_num,
			 double balance, std::string  open_date,
			 bool is_blocked, double atm_fee,
			 double intrest, size_t overdraft_lim);


	Checking(const Checking&) = default;
	Checking& operator=(const Checking&) = default;
	
	~Checking() = default;

	inline size_t get_overdraft_lim() const { return overdraft_lim; };


private:
	std::ostream& print(std::ostream& os) const override;

	size_t overdraft_lim;
};