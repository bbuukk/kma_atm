#pragma once

namespace mdls {
	class Account;
	class Checking;
	class Savings;
	class LOC;
	class Office;
	class Card;
	class Transaction;
	class Client;
	class ATM;
};

#include <string>
#include <ostream>
#include <memory>
#include <vector>

#include <mysql/jdbc.h>

class Bank {
public:

	Bank(const Bank&) = delete;
	Bank& operator=(const Bank&) = delete;

	~Bank() = default;

	static Bank& get() {
		static Bank db;
		return db;
	}

	//Account repo =============================
	static mdls::Account& get_account(std::string num);

	static mdls::Office& get_acc_office(size_t id);
	static void block_account(size_t id);
	static void unblock_account(size_t id);

	std::vector <mdls::Transaction>&
		get_acc_transactions(size_t id);
	static size_t count_acc_transactions(std::string num);
	//Account& get_acc_balance(size_t acc_id);

	//ATM repo =============================
	static mdls::ATM& get_atm(std::string num);

	//Card repo =============================
	static mdls::Card& get_card(std::string pan);
	static void change_pin_code(
		std::string pan, size_t pin_code);

	//Transaction repo =============================
	static mdls::Transaction& get_transaction(std::string trans_num);
	static bool transact(
		std::string atm_num,
		std::string acc_from,
		std::string acc_to,
		size_t sum,
		std::string description);
	static bool withdraw(
		std::string atm_num,
		std::string acc_from,
		size_t sum,
		std::string description);


	static inline const std::unique_ptr<sql::Connection>& get_connection() {
		return get().in_get_connection();
	};

private:
	Bank(void);

	inline const std::unique_ptr<sql::Connection>& in_get_connection() const { return con; };

	std::unique_ptr<sql::Connection> con;
	void connect();
};