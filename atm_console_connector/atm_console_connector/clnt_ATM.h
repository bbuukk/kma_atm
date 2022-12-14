#pragma once

#include <memory>
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

#include "Account.h"
#include "Card.h"

namespace clnt {

	class ATM {
	public:
		ATM(void) = delete;

		//account can have lots of cards
		ATM(  const std::string& num
			, mdls::Account&
			, std::unique_ptr<mdls::Card> = nullptr);

		ATM(const ATM&) = delete;
		ATM& operator=(const ATM&) = delete;

		~ATM() = default;

		inline size_t balance() {
			return account_.balance();
		}

		bool deposit(size_t sum);
		bool withdraw(size_t sum);
		bool transfer(
			const std::string& acc_to_num,
			size_t sum, const std::string& descript);

		std::string info();
		std::string account_info();
		bool change_pin(const size_t new_pin);

		bool block_account();
		bool unblock_account();

		/*mdls::Transaction& transaction(std::string& num);*/
		std::vector <mdls::Transaction>& transactions_history();

		inline const std::string& num() const { return num_; };
		inline const std::string& city() const { return city_; };
		inline const std::string& street() const { return street_; };

		inline const mdls::Account& account() const { return account_; };
		inline const std::unique_ptr<mdls::Card>& card() const { return card_; };
	
	private:
		
		std::string num_;

		std::string city_;
		std::string street_;

		mdls::Account& account_;
		std::unique_ptr<mdls::Card> card_;
	};
}



