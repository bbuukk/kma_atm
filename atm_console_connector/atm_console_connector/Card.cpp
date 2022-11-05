
#include "Card.h"

Card::Card(
	size_t id, size_t acc_id,
	size_t clnt_id, std::string pan,
	size_t pin_code, std::string expr_date,
	size_t cvv, std::string given_date)
	: id(id), acc_id(acc_id),
	  clnt_id(clnt_id), pan(pan),
	  pin_code(pin_code), expr_date(expr_date),
	  cvv(cvv), given_date(given_date) {};

std::ostream& operator<<(std::ostream& os, const Card& card) {
	return os
		<< "Card id:" << card.get_id() << "\n"
		<< "Account id: " << card.get_id() << "\n"
		<< "Client id:" << card.get_client_id() << "\n"
		<< "PAN:" << card.get_pan() << "\n"
		<< "Pin code:" << card.get_pin_code() << "\n"
		<< "Expiration date:" << card.get_expr_date() << "\n"
		<< "CVV:" << card.get_cvv() << "\n"
		<< "Given date:" << card.get_given_date() << "\n";
}



