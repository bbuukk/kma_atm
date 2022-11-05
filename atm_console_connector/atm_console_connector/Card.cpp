
#include "Card.h"

Card::Card(
	std::string pan, size_t pin_code,
	std::string expr_date, size_t cvv,
	std::string given_date)
	: pan(pan),pin_code(pin_code),
	  expr_date(expr_date), cvv(cvv),
	  given_date(given_date) {};

std::ostream& operator<<(std::ostream& os, const Card& card) {
	return os
		<< "PAN:" << card.get_pan() << "\n"
		<< "Pin code:" << card.get_pin_code() << "\n"
		<< "Expiration date:" << card.get_expr_date() << "\n"
		<< "CVV:" << card.get_cvv() << "\n"
		<< "Given date:" << card.get_given_date() << "\n";
}



