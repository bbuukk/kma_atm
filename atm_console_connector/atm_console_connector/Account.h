#pragma once

#include <string>
#include <ostream>

#include <mysql/jdbc.h>

//Account
class Account {
public:
	Account(void) = default;

	Account(
		std::string num, size_t dgt_code,
		double balance, std::string open_date,
		bool blocked, double atm_fee,
		double intrest);
	
	Account(const Account&) = default;
	Account& operator=(const Account&) = default;

	Account& operator=(Account&&) = default;
	Account(Account&&) noexcept = default;
	
	virtual ~Account() = default;

	//getters
	inline std::string get_num() const { return num; };
	inline size_t get_digital_code() const { return dgt_code; }; //get currency digital code
	inline double get_balance() const { return balance; };
	inline std::string get_open_date() const { return open_date; };
	inline bool is_blocked() const { return blocked; };
	inline double get_atm_fee() const { return atm_fee; };
	inline double get_intrest() const { return intrest; };

	friend std::ostream& operator<<(std::ostream& os, const Account& acc) {
		return acc.print(os);
	}

protected:
	virtual std::ostream& print(std::ostream& os) const;

	std::string num;
	size_t dgt_code;
	double balance;
	std::string open_date;
	bool blocked;
	double atm_fee;
	double intrest;
};

