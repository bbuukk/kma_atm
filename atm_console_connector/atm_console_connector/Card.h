#pragma once

#include "Card.h"

#include <mysql/jdbc.h>

namespace mdls {
	class Card {
	public:
		Card(void) = default;

		Card(
			std::string pan, size_t pin_code,
			std::string expr_date, size_t cvv,
			std::string given_date);

		Card(const Card&) = default;
		Card& operator=(const Card&) = default;

		Card& operator=(Card&&) noexcept = default;
		Card(Card&&) noexcept = default;

		~Card() = default;

		inline const std::string& get_pan() const { return pan; };
		inline size_t get_pin_code() const { return pin_code; };
		inline const std::string& get_expr_date() const { return expr_date; };
		inline size_t get_cvv() const { return cvv; };
		inline const std::string& get_given_date() const { return given_date; };

	private:
		std::string pan;
		size_t pin_code;
		std::string expr_date;
		size_t cvv;
		std::string given_date;
	};
}

std::ostream& operator<<(std::ostream& os, const mdls::Card& off);

