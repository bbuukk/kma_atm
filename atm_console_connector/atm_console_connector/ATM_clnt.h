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

		ATM(std::string& num, mdls::Account&);
		ATM(std::string& num, mdls::Card&);

		ATM(const ATM&) = delete;
		ATM& operator=(const ATM&) = delete;

		~ATM() = default;

		inline size_t balance() {
			return account_.balance();
		}

		bool deposit(size_t sum);
		bool withdraw(size_t sum);
		bool transfer(
			const std::string& acc_to,
			size_t sum, const std::string& descript);

		inline const mdls::Account& account() const { return account_; };
		inline const std::unique_ptr<mdls::Card>& card() const { return card_; };

		inline const std::string& num() const { return num_; };
		
	private:
		
		std::string num_;

		mdls::Account& account_;
		std::unique_ptr<mdls::Card> card_;
	};
}



