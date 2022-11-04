#pragma once

#include "Account.h"

#include <mysql/jdbc.h>

class CheckAcc : public Account {
public:
	CheckAcc(void);

	CheckAcc(Account&, size_t overdraft_lim);

	CheckAcc(size_t acc_id, size_t dgt_code,
			 size_t off_id, size_t clnt_id,
			 size_t acc_type, std::string acc_num,
			 double balance, std::string  open_date,
			 bool is_blocked, double atm_fee,
			 double intrest, size_t overdraft_lim);
	
	~CheckAcc() = default;

	inline size_t getOverdraftLim() const { return overdraft_lim; };




private:
	std::ostream& print(std::ostream& os) const override;

	size_t overdraft_lim;
};