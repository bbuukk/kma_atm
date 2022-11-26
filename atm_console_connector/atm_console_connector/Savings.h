#pragma once

#include "Account.h"

namespace mdls {

	class Savings : public Account {
	public:

		// constructor that's getting info from db
		Savings(const std::string& num);

		Savings(const Savings&) = default;
		Savings& operator=(const Savings&) = default;

		Savings& operator=(Savings&&) noexcept = default;
		Savings(Savings&&) noexcept = default;

		~Savings() = default;

		inline size_t trans_lim() const { return trans_lim_; };

		//TODO delete?
		/*friend mdls::Account& Bank::get_account(const std::string& num);*/
		friend class Bank;
		
	private:
		Savings(void) = default;

		Savings(const Account& acc, size_t trans_lim);

		Savings(
			const std::string& num, size_t dgt_code,
			double balance, const std::string& open_date,
			bool blocked, double atm_fee,
			double intrest, size_t trans_lim,
			size_t id = 0, size_t off_id = 0,
			size_t clnt_id = 0, size_t acc_type = 0);

		std::ostream& print(std::ostream& os) const override;

		size_t trans_lim_;
	};
}