#include "Bank.h"

#include "Card.h"

mdls::Card::Card(const std::string& pan)
	: Card(Bank::get_card(pan)) {}

bool mdls::Card::change_pin_code(const size_t new_pin) {
	bool is_successful = Bank::change_pin_code(id(), new_pin);
	this->pin_code_ = new_pin;
	return is_successful;
};

std::ostream& operator<<(std::ostream& os, const mdls::Card& card) {
	return os
		<< "PAN:" << card.pan() << "\n"
		<< "Pin code:" << card.pin_code() << "\n"
		<< "Expiration date:" << card.expr_date() << "\n"
		<< "CVV:" << card.cvv() << "\n"
		<< "Given date:" << card.given_date() << "\n";
}

//TODO same as in account, question: "do we really need default arguments here?"
mdls::Card::Card(
	const std::string& pan, size_t pin_code,
	const std::string& expr_date, size_t cvv,
	const std::string& given_date, size_t id,
	size_t acc_id, size_t clnt_id)
	: pan_(pan), pin_code_(pin_code),
	expr_date_(expr_date), cvv_(cvv),
	given_date_(given_date), id_(id),
	acc_id_(acc_id), clnt_id_(clnt_id) {};
