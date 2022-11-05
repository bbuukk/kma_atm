#pragma once

#include <string>
#include <ostream>
#include <memory>

#include <mysql/jdbc.h>

#include "Account.h"
#include "Office.h"
#include "Card.h"
#include "Transaction.h"
#include "ATM.h"



class Repo {
public:

	Repo(void) = default;

	inline Repo(sql::Connection*& con)
		: con(con) {};

	~Repo() = default;


	//Account repo =============================
	Account& get_acc(std::string num);

	Office& get_acc_office(std::string num);
	void block_acc(std::string num);
	void unblock_acc(std::string num);
	bool is_acc_blocked(size_t acc_id);
	double get_acc_balance(size_t acc_id);
	double get_acc_atm_fee(size_t acc_id);
	size_t get_acc_type(size_t acc_id);
	//Account& get_acc_balance(size_t acc_id);

	//ATM repo =============================
	ATM& get_atm(std::string num);

	//Card repo =============================
	Card& get_card(std::string pan);
	void change_pin_code(
		std::string pan, size_t pin_code);


	//Transaction repo =============================
	Transaction& get_transaction(std::string trans_num);

private:
	std::unique_ptr<sql::Connection> con;
};

