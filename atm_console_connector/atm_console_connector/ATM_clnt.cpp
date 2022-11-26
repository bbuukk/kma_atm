
#include "ATM_clnt.h"
#include "Account.h"
#include "Card.h"

//card is nullptr, because account can have 
//lots of cards, no idea which to pick
clnt::ATM::ATM(mdls::Account& account) 
	: account_(account), card_(nullptr)
{};

clnt::ATM::ATM(mdls::Card& card)
	: card_(std::make_unique<mdls::Card>(card))
	, account_(Bank::get_account(card))
{};

//maybe it's worth to make deposit using Transaction
//object in order to make syncronization simplier in future
bool clnt::ATM::deposit(size_t sum) {
	this->account_.deposit(sum);
};

bool clnt::ATM::deposit(size_t sum) {
	this->account_.withdrawal(sum);
};


