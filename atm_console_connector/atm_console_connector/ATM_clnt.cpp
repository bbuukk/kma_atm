
#include <memory>

#include "ATM_clnt.h"
#include "Account.h"
#include "Card.h"
#include "Transaction.h"
#include "ATM.h"

class no_card : public std::exception{};

//card is nullptr, because account can have 
//lots of cards, no idea which to pick
clnt::ATM::ATM(
	const std::string& num,
	mdls::Account& account,
	std::unique_ptr<mdls::Card> card)
	: num_(num)
	, city_(""), street_("")
	, account_(account)
	, card_(card.release())
{
	mdls::ATM atm = Bank::get_atm(num);
	city_ = atm.city();
	street_ = atm.street();
};

bool clnt::ATM::transfer(
	const std::string& acc_to_num,
	size_t sum, const std::string& descript) {

	mdls::Account account_to = Bank::get_account(acc_to_num);

	mdls::Transaction transfer(num(),
		std::make_unique<mdls::Account>(account()),
		std::make_unique<mdls::Account>(account_to),
		sum, descript);
	return transfer.make();
};

bool clnt::ATM::deposit(size_t sum) {
	mdls::Transaction deposit(num(),nullptr,
		std::make_unique<mdls::Account>(account()), sum);
	return deposit.make();
};

bool clnt::ATM::withdraw(size_t sum) {
	mdls::Transaction withdraw(num(),
		std::make_unique<mdls::Account>(account()),
		nullptr, sum);
	return withdraw.make();
};

std::string clnt::ATM::info() {
	return city() + ", " + street();
};

bool clnt::ATM::change_pin(const size_t new_pin) {
	
	if (card() == nullptr)
		throw no_card();

	return (*card_).change_pin_code(new_pin);
};
