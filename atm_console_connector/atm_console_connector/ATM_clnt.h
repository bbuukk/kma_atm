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

namespace clnt {

	class ATM {
	public:
		ATM(void) = delete;

		ATM(mdls::Account);
		ATM(mdls::Card);

		ATM(const ATM&) = delete;
		ATM& operator=(const ATM&) = delete;

		~ATM() = default;

		inline const std::unique_ptr<mdls::Account>& get_account() const { return account; };
		inline const std::unique_ptr<mdls::Card>& get_card() const { return card; };

	private:

		std::unique_ptr<mdls::Account> account;
		std::unique_ptr<mdls::Card> card;

		
	};
}



