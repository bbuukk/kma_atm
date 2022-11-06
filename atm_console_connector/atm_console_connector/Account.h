#pragma once

#include "Bank.h"

#include <string>
#include <ostream>
#include <vector>

namespace mdls {

	class Account {
	public:
		// constructor that's getting info from db
		Account(std::string num);

		//constructor for creating new account in bank
		/*Account(std::string num, size_t dgt_code,
				double atm_fee, double intrest);*/

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
		inline const std::string& get_num() const { return num; };
		inline size_t get_digital_code() const { return dgt_code; }; //get currency digital code
		inline double get_balance() const { return balance; };
		inline const std::string& get_open_date() const { return open_date; };
		inline bool is_blocked() const { return blocked; };
		inline double get_atm_fee() const { return atm_fee; };
		inline double get_intrest() const { return intrest; };

		friend std::ostream& operator<<(std::ostream& os, const Account& acc) {
			return acc.print(os);
		}

		friend mdls::Account& Bank::get_account(std::string num);

	protected:
		virtual std::ostream& print(std::ostream& os) const;

		Account(void) = default;
		Account(
			std::string num, size_t dgt_code,
			double balance, std::string open_date,
			bool blocked, double atm_fee,
			double intrest,	size_t id = 0, size_t off_id = 0,
			size_t clnt_id = 0, size_t acc_type = 0);

		inline size_t get_id() const { return id; }; 
		inline size_t get_office_id() const { return off_id; }; 
		inline size_t get_client_id() const { return clnt_id; }; 
		inline size_t get_type() const { return acc_type; };

		size_t id;
		size_t off_id;
		size_t clnt_id;
		size_t acc_type;

		std::string num;
		size_t dgt_code;
		double balance;
		std::string open_date;
		bool blocked;
		double atm_fee;
		double intrest;
	};
}