#pragma once

#include <string>
#include <ostream>

namespace mdls {
	class Transaction {
	public:

		// constructor that's getting info from db
		Transaction(const std::string& num);


		//constructor for creating new transaction,
		//but not making it, for this use make()
		
		//transfer
		Transaction(
			const std::string& atm_num
			, std::unique_ptr<mdls::Account> acc_from
			, std::unique_ptr<mdls::Account> acc_to
			, size_t sum);

		Transaction(const Transaction&) = default;
		Transaction& operator=(const Transaction&) = default;
		Transaction& operator=(Transaction&&) noexcept = default;
		Transaction(Transaction&&) noexcept = default;

		~Transaction() = default;

		inline const std::string& num() const { return num_; }
		inline const mdls::Account& account_from() const { return *acc_from_; };
		inline const mdls::Account& account_to() const { return *acc_to_; };
		inline size_t sum() const { return sum_; };

		inline const std::string& datetime() const { return datetime_; };
		inline bool is_successful() const { return successful_; };
		inline const std::string& atm_num() const { return atm_num_; };
		inline const std::string& descript() const { return descript_; }; //description

		/*friend mdls::Transaction& Bank::get_transaction(const std::string& trans_num);
		friend std::vector <mdls::Transaction>& Bank::get_acc_transactions(const size_t id);*/

		//make transaction
		bool make() const;

		friend class Bank;

	private:
		Transaction(void) = default;

		Transaction(
			const std::string& num,
			const std::shared_ptr<mdls::Account> acc_from,
			const std::shared_ptr<mdls::Account> acc_to,
			size_t sum, const std::string& datetime,
			bool successful, const std::string& atm_num,
			const std::string& descript);

		std::string num_;
		std::unique_ptr<mdls::Account> acc_from_;
		std::unique_ptr<mdls::Account> acc_to_;
		size_t sum_;

		std::string datetime_;
		bool successful_;
		std::string atm_num_;
		std::string descript_;
	};
}

std::ostream& operator<<(std::ostream& os, const mdls::Transaction& off);

