#pragma once

#include <string>
#include <ostream>

#include <mysql/jdbc.h>

//Account
class Account {
public:
	Account(void) = default;

	Account(size_t acc_id, size_t dgt_code,
		size_t off_id, size_t clnt_id,
		size_t acc_type, std::string acc_num,
		double balance, std::string open_date,
		bool is_blocked, double atm_fee,
		double intrest);
	
	Account(const Account&) = default;
	Account& operator=(const Account&) = default;

	Account& operator=(Account&&) = default;
	Account(Account&&) noexcept = default;
	
	virtual ~Account() = default;

	//getters
	inline size_t get_account_id() const { return acc_id; };
	inline size_t get_digital_code() const { return dgt_code; }; //get currency digital code
	inline size_t get_office_id() const { return off_id; }; // get office id
	inline size_t get_client_id() const { return clnt_id; }; //get client id
	inline size_t get_account_type() const { return acc_type; };

	inline std::string get_account_num() const { return acc_num; };
	inline double get_balance() const { return balance; };
	inline std::string get_open_date() const { return open_date; };
	inline bool get_is_blocked() const { return is_blocked; };

	inline double get_atm_fee() const { return atm_fee; };
	inline double get_intrest() const { return intrest; };

	friend std::ostream& operator<<(std::ostream& os, const Account& acc) {
		return acc.print(os);
	}

protected:
	virtual std::ostream& print(std::ostream& os) const;

	size_t acc_id;
	size_t dgt_code;
	size_t off_id;
	size_t clnt_id;
	size_t acc_type;

	std::string acc_num;
	double balance;
	std::string open_date;
	bool is_blocked;
	
	double atm_fee;
	double intrest;
};

