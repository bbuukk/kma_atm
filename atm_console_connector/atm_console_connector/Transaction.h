#pragma once

#include <string>
#include <ostream>

namespace mdls {
	class Transaction {
	public:

		//get transaction by it's num
		Transaction(const std::string& num);

		Transaction(const Transaction&) = default;
		Transaction& operator=(const Transaction&) = default;
		Transaction& operator=(Transaction&&) noexcept = default;
		Transaction(Transaction&&) noexcept = default;

		~Transaction() = default;

		inline const std::string& num() const { return num_; }
		inline const std::string& payer() const { return payer_; };
		inline const std::string& payee() const { return payee_; };
		inline size_t sum() const { return sum_; };

		inline const std::string& datetime() const { return datetime_; };
		inline bool is_successful() const { return is_successful_; };
		inline const std::string& descript() const { return descript_; };

		friend class Bank;

	private:
		Transaction(void) = default;

		Transaction(
			const std::string& num,
			const std::string& payer,
			const std::string& payee,
			size_t sum, const std::string& datetime,
			bool is_successful, 
			const std::string& descript);

		std::string num_;
		std::string payer_;
		std::string payee_;
		size_t sum_;

		std::string datetime_;
		bool is_successful_;
		std::string descript_;
	};
}

std::ostream& operator<<(std::ostream& os, const mdls::Transaction& trans);



