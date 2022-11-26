#pragma once

#include "Bank.h"

#include <string>
#include <ostream>
#include <vector>

namespace mdls {

	class Account {
	public:
		
		Account(const Account&) = default;
		Account& operator=(const Account&) = default;
		Account& operator=(Account&&) noexcept = default;
		Account(Account&&) noexcept = default;

		virtual ~Account() = default;

		Office& get_office();

		void block();
		void unblock();

		std::vector<Transaction>& get_transactions();

		//getters
		inline const std::string& num() const { return num_; };
		inline size_t digital_code() const { return dgt_code_; }; //get currency digital code
		inline double balance() const { return balance_; };
		inline const std::string& open_date() const { return open_date_; };
		inline bool is_blocked() const { return blocked_; };
		inline double atm_fee() const { return atm_fee_; };
		inline double intrest() const { return intrest_; };

		friend std::ostream& operator<<(std::ostream& os, const Account& acc) {
			return acc.print(os);
		}

		friend mdls::Account& Bank::get_account(const std::string& num);

		//TODO worth to replace this by making friend 
		//every method from Bank, that needs to?

		friend class Bank;
		
		friend class Checking;
		friend class Savings;
		friend class LOC;

	protected:
		Account(void) = default;
		Account(
			const std::string& num, size_t dgt_code,
			double balance, const std::string& open_date,
			bool blocked, double atm_fee,
			double intrest,	size_t id = 0, size_t off_id = 0,
			size_t clnt_id = 0, size_t acc_type = 0);

		virtual std::ostream& print(std::ostream& os) const;

		inline size_t id() const { return id_; }; 
		inline size_t office_id() const { return off_id_; }; 
		inline size_t client_id() const { return clnt_id_; }; 
		inline size_t type() const { return acc_type_; };

		size_t id_;
		size_t off_id_;
		size_t clnt_id_;
		size_t acc_type_;

		std::string num_;
		size_t dgt_code_;
		double balance_;
		std::string open_date_;
		bool blocked_;
		double atm_fee_;
		double intrest_;
	};
}