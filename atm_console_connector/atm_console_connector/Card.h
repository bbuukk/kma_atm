#pragma once

#include "Card.h"

#include <mysql/jdbc.h>

class Card {
public:
	Card(void) = default;

	Card(
		size_t card_id, size_t acc_id,
		size_t clnt_id, std::string pan,
		size_t pin_code, std::string expr_date,
		size_t cvv, std::string given_date);

	Card(const Card&) = default;
	Card& operator=(const Card&) = default;

	~Card() = default;

	inline size_t get_card_id() const { return card_id; };
	inline size_t get_account_id() const { return acc_id; };
	inline size_t get_client_id() const { return clnt_id; };
	inline std::string get_pan() const { return pan; };
	inline size_t get_pin_code() const { return pin_code; };
	inline std::string get_expr_date() const { return expr_date; };
	inline size_t get_cvv() const { return cvv; };
	inline std::string get_given_date() const { return given_date; };

private:
	size_t card_id;
	size_t acc_id;
	size_t clnt_id;
	std::string pan;
	size_t pin_code;
	std::string expr_date;
	size_t cvv;
	std::string given_date;
};

std::ostream& operator<<(std::ostream& os, const Card& off);

//todo
//card_id	int unsigned	NO	PRI		auto_increment
//acc_id	int unsigned	NO	MUL
//clnt_id	int unsigned	NO	MUL
//pan	varchar(20)	NO	UNI
//pin_code	int unsigned	NO
//expr_date	date	NO
//cvv	int unsigned	NO
//given_date	date	NO