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

		
		/*ATM(mdls::Card);*/

		ATM(const ATM&) = delete;
		ATM& operator=(const ATM&) = delete;

		~ATM() = default;

		inline const std::unique_ptr<mdls::Account>& get_account() const { return account_; };
		inline const std::unique_ptr<mdls::Card>& get_card() const { return card_; };

	private:

		std::unique_ptr<mdls::Account> account_;
		std::unique_ptr<mdls::Card> card_;
	};
}



