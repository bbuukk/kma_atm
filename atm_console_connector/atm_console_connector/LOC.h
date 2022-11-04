#pragma once

#include "Account.h"

#include <mysql/jdbc.h>

class LOC : public Account {
public:
	LOC(void) = default;

	LOC(
		Account& acc, size_t crd_taken,
		size_t loc_lim, double crd_return);

	LOC(
		int acc_id, int dgt_code,
		int off_id, int clnt_id,
		int acc_type, std::string acc_num,
		int balance, std::string  open_date,
		bool is_blocked, double atm_fee,
		double intrest, size_t crd_taken,
		size_t loc_lim, double crd_return);

	LOC(const LOC&) = default;
	LOC& operator=(const LOC&) = default;

	~LOC() = default;

	inline size_t get_credit_taken() const { return crd_taken; };
	inline size_t get_loc_limit() const { return loc_lim; };
	inline double get_credit_returned() const { return crd_return; };

private:
	std::ostream& print(std::ostream& os) const override;

	size_t crd_taken;
	size_t loc_lim;
	double crd_return;
};