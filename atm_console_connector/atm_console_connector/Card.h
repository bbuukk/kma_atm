#pragma once

#include "Card.h"

#include <mysql/jdbc.h>

class Card {
public:
	Card(void) = default;

	Card(
		std::string pan, size_t pin_code,
		std::string expr_date, size_t cvv,
		std::string given_date);

	Card(const Card&) = default;
	Card& operator=(const Card&) = default;

	~Card() = default;

	inline std::string get_pan() const { return pan; };
	inline size_t get_pin_code() const { return pin_code; };
	inline std::string get_expr_date() const { return expr_date; };
	inline size_t get_cvv() const { return cvv; };
	inline std::string get_given_date() const { return given_date; };

private:
	std::string pan;
	size_t pin_code;
	std::string expr_date;
	size_t cvv;
	std::string given_date;
};

std::ostream& operator<<(std::ostream& os, const Card& off);

//todo
//id	int unsigned	NO	PRI		auto_increment
//acc_id	int unsigned	NO	MUL
//clnt_id	int unsigned	NO	MUL
//pan	varchar(20)	NO	UNI
//pin_code	int unsigned	NO
//expr_date	date	NO
//cvv	int unsigned	NO
//given_date	date	NO