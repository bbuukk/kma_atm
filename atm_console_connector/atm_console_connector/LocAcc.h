#pragma once

#include "Account.h"

#include <mysql/jdbc.h>

class LocAcc : public Account {
public:
	LocAcc(void) = default;

	LocAcc(
		Account& acc, size_t crd_taken,
		size_t loc_lim, double crd_return);

	LocAcc(
		int acc_id, int dgt_code,
		int off_id, int clnt_id,
		int acc_type, std::string acc_num,
		int balance, std::string  open_date,
		bool is_blocked, double atm_fee,
		double intrest, size_t crd_taken,
		size_t loc_lim, double crd_return);

	LocAcc(const LocAcc&) = default;
	LocAcc& operator=(const LocAcc&) = default;

	~LocAcc() = default;

	inline size_t getCrdTaken() const { return crd_taken; };
	inline size_t getLocLimit() const { return loc_lim; };
	inline double getCrdReturned() const { return crd_return; };

private:
	std::ostream& print(std::ostream& os) const override;

	size_t crd_taken;
	size_t loc_lim;
	double crd_return;
};