
#include <memory>

#include "ATM_clnt.h"
#include "Account.h"
#include "Card.h"
#include "Transaction.h"
#include "ATM.h"

//card is nullptr, because account can have 
//lots of cards, no idea which to pick
clnt::ATM::ATM(
	std::string& num, mdls::Account& account)
	: account_(account)
	, card_(nullptr)
	, num_(num)
{};

clnt::ATM::ATM(
	std::string& num, mdls::Card& card)
	: card_(std::make_unique<mdls::Card>(card))
	, account_(Bank::get_account(card))
	, num_(num)
{};

//maybe it's worth to make deposit using Transaction
//object in order to make syncronization simplier in future
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
//transfer
//Transaction(
//	const std::string& atm_num
//	, std::unique_ptr<mdls::Account>& acc_from
//	, std::unique_ptr<mdls::Account>& acc_to
//	, size_t sum);

//bool clnt::ATM::transfer(
//	const std::string& acc_to,
//	size_t sum, const std::string& descript) {
//
//	mdls::Transaction transfer(num(), account().num(), acc_to, sum, descript);
//	transfer.make();
//};



