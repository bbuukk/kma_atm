#pragma once

#include <string>
#include <ostream>

namespace mdls {
	class Transaction {
	public:

		// constructor that's getting info from db
		Transaction(std::string num);

		//constructor for creating new transaction,
		//but not making it, for this use make()
		Transaction(
			std::string num,
			std::string acc_from,
			std::string acc_to,
			size_t sum,
			std::string descript);

		Transaction(const Transaction&) = default;
		Transaction& operator=(const Transaction&) = default;

		Transaction& operator=(Transaction&&) noexcept = default;
		Transaction(Transaction&&) noexcept = default;

		~Transaction() = default;

		inline const std::string& get_num() const { return num; }
		inline const std::string& get_account_from() const { return acc_from; };
		inline const std::string& get_account_to() const { return acc_to; };
		inline size_t get_sum() const { return sum; };

		inline const std::string& get_date() const { return date; };
		inline bool is_successful() const { return successful; };
		inline const std::string& get_atm_num() const { return atm_num; };
		inline const std::string& get_descript() const { return descript; }; //description

		friend mdls::Transaction& Bank::get_transaction(std::string trans_num);
		friend std::vector <mdls::Transaction>& Bank::get_acc_transactions(size_t id);

		//make transaction
		bool make() const;

	private:
		Transaction(void) = default;

		Transaction(
			std::string num,
			std::string acc_from,
			std::string acc_to,
			size_t sum, std::string date,
			bool successful, std::string atm_num,
			std::string descript);

		std::string num;
		std::string acc_from;
		std::string acc_to;
		size_t sum;

		std::string date;
		bool successful;
		std::string atm_num;
		std::string descript;
	};
}

std::ostream& operator<<(std::ostream& os, const mdls::Transaction& off);

