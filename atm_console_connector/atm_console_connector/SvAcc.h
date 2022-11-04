#pragma once

#include "Account.h"

#include <mysql/jdbc.h>

class SvAcc : public Account {
public:
	SvAcc(void);

	SvAcc(Account&, size_t trans_lim);

	SvAcc(size_t acc_id, size_t dgt_code,
		size_t off_id, size_t clnt_id,
		size_t acc_type, std::string acc_num,
		double balance, std::string  open_date,
		bool is_blocked, double atm_fee,
		double intrest, size_t trans_lim);

	~SvAcc() = default;

	inline size_t getTransLim() const { return trans_lim; };


private:
	std::ostream& print(std::ostream& os) const override;

	size_t trans_lim;
};