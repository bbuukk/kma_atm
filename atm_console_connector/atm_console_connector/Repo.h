#pragma once

#include <string>
#include <ostream>
#include <memory>

#include <mysql/jdbc.h>

#include "Account.h"
#include "Office.h"


class Repo {
public:

	Repo(void) = default;

	inline Repo(sql::Connection*& con)
		: con(con) {};

	~Repo() = default;


	//Account repo
	Account& get_acc(size_t acc_id);
	void block_acc(size_t acc_id);
	void unblock_acc(size_t acc_id);
	bool is_acc_blocked(size_t acc_id);
	double get_acc_balance(size_t acc_id);
	double get_acc_atm_fee(size_t acc_id);
	size_t get_acc_type(size_t acc_id);
	//Account& get_acc_balance(size_t acc_id);

	//Office repo
	Office& get_acc_off(size_t acc_id);

	//ATM repo
	std::string& get_atm_info(size_t mach_id);

private:
	std::unique_ptr<sql::Connection> con;
};

