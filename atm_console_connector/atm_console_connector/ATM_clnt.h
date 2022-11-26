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

		ATM(mdls::Account&);
		ATM(mdls::Card&);

		ATM(const ATM&) = delete;
		ATM& operator=(const ATM&) = delete;

		~ATM() = default;

		inline const mdls::Account& account() const { return account_; };
		inline const std::unique_ptr<mdls::Card>& card() const { return card_; };

	private:

		mdls::Account& account_;
		std::unique_ptr<mdls::Card> card_;
	};
}



