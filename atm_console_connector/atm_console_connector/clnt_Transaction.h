#pragma once

#include <string>
#include <ostream>

namespace clnt {
	class Transaction {
	public:

		//for transfer only
		Transaction(
			const std::string& atm_num
			, mdls::Account& payer
			, mdls::Account& payee
			, size_t sum, const std::string& descript = "");

		//for deposit or withdraw
		Transaction(
			const std::string& atm_num
			, std::unique_ptr<mdls::Account>& acc_from
			, std::unique_ptr<mdls::Account>& acc_to
			, size_t sum, const std::string& descript = "");

		//deleted for now(no need)
		Transaction(const Transaction&) = delete;
		Transaction& operator=(const Transaction&) = delete;
		/*Transaction& operator=(Transaction&&) noexcept = delete;
		Transaction(Transaction&&) noexcept = delete;*/

		~Transaction() = default;

		inline const std::unique_ptr<mdls::Account>& payer() const { return payer_; };
		inline const std::unique_ptr<mdls::Account>& payee() const { return payee_; };
		inline size_t sum() const { return sum_; };

		inline const std::string& atm_num() const { return atm_num_; };
		inline const std::string& descript() const { return descript_; }; 

		//make transaction happen
		bool make();

		friend class Bank;

	private:
		Transaction(void);

		/*std::string num_;*/
		std::unique_ptr<mdls::Account> payer_;
		std::unique_ptr<mdls::Account> payee_;
		size_t sum_;
		std::string atm_num_;
		std::string descript_;
	};
}

std::ostream& operator<<(std::ostream& os, const mdls::Transaction& trans);



