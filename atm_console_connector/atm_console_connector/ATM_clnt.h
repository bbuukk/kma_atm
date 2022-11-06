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

		ATM(mdls::Account);
		ATM(mdls::Card);

		ATM(const ATM&) = delete;
		ATM& operator=(const ATM&) = delete;

		~ATM() = default;

		inline const mdls::Account& get_account() const { return account; };
		inline const mdls::Card& get_card() const { return card; };

	private:

		mdls::Account account;
		mdls::Card card;
	};
}



