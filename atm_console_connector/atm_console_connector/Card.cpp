
#include "Card.h"

Card::Card(
	size_t card_id, size_t acc_id,
	size_t clnt_id, std::string pan,
	size_t pin_code, std::string expr_date,
	size_t cvv, std::string given_date)
	: card_id(card_id), acc_id(acc_id),
	  clnt_id(clnt_id), pan(pan),
	  pin_code(pin_code), expr_date(expr_date),
	  cvv(cvv), given_date(given_date) {};

std::ostream& operator<<(std::ostream& os, const Card& card) {
	return os
		<< "Machine id:" << card.get_card_id() << "\n"
		<< "Office id: " << card.get_account_id() << "\n"
		<< "Card street:" << card.get_pan() << "\n"
		<< "Card street:" << card.get_pin_code() << "\n"
		<< "Card street:" << card.get_expr_date() << "\n"
		<< "Card street:" << card.get_cvv() << "\n"
		<< "Card street:" << card.get_given_date() << "\n";
}



