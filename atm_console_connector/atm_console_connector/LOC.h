#pragma once

#include "Account.h"

#include <mysql/jdbc.h>

namespace mdls {
	class LOC : public Account {
	public:
		LOC(void) = default;

		LOC(
			Account& acc, size_t crd_taken,
			size_t loc_lim, double crd_return);

		LOC(
			std::string acc_num, int dgt_code,
			int balance, std::string  open_date,
			bool blocked, double atm_fee,
			double intrest, size_t crd_taken,
			size_t loc_lim, double crd_return);

		LOC(const LOC&) = default;
		LOC& operator=(const LOC&) = default;

		LOC& operator=(LOC&&) noexcept = default;
		LOC(LOC&&) noexcept = default;

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
}