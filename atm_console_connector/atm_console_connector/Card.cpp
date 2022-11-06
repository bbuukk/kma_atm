#include "Bank.h"

#include "Card.h"

mdls::Card::Card(std::string pan)
	: Card(Bank::get_card(pan)) {}

void mdls::Card::change_pin_code(size_t new_pin) {
	Bank::change_pin_code(this->id, new_pin);
	this->pin_code = pin_code;
};

std::ostream& operator<<(std::ostream& os, const mdls::Card& card) {
	return os
		<< "PAN:" << card.get_pan() << "\n"
		<< "Pin code:" << card.get_pin_code() << "\n"
		<< "Expiration date:" << card.get_expr_date() << "\n"
		<< "CVV:" << card.get_cvv() << "\n"
		<< "Given date:" << card.get_given_date() << "\n";
}

//TODO same as in account, question: "do we really need default arguments here?"
mdls::Card::Card(
	std::string pan, size_t pin_code,
	std::string expr_date, size_t cvv,
	std::string given_date, size_t id,
	size_t acc_id, size_t clnt_id)
	: pan(pan), pin_code(pin_code),
	expr_date(expr_date), cvv(cvv),
	given_date(given_date), id(id),
	acc_id(acc_id), clnt_id(clnt_id) {};
