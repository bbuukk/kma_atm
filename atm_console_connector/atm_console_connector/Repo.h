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

	Repo(const Repo&) = default;
	Repo& operator=(const Repo&) = default;

	/*Repo& operator=(Repo&&) noexcept = default;
	Repo(Repo&&) noexcept = default;*/

	~Repo() = default;

	//Account repo =============================
	mdls::Account& get_acc(std::string num);

	mdls::Office& get_acc_office(std::string num);
	void block_acc(std::string num);
	void unblock_acc(std::string num);

	std::vector <mdls::Transaction>&
		get_all_acc_trans(std::string num);
	int count_all_acc_trans(std::string num);
	//Account& get_acc_balance(size_t acc_id);

	//ATM repo =============================
	mdls::ATM& get_atm(std::string num);

	//Card repo =============================
	mdls::Card& get_card(std::string pan);
	void change_pin_code(
		std::string pan, size_t pin_code);

	//Transaction repo =============================
	mdls::Transaction& get_transaction(std::string trans_num);
	bool transact(
		std::string atm_num,
		std::string acc_from,
		std::string acc_to,
		size_t sum,
		std::string description);
	bool withdraw(
		std::string atm_num,
		std::string acc_from,
		size_t sum,
		std::string description);

private:
	std::unique_ptr<sql::Connection> con;
};

