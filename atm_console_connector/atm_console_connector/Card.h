#pragma once

#include <string>
#include <ostream>

namespace mdls {
	class Card {
	public:

		// constructor that's getting info from db
		Card(std::string pan);

		//constructor for creating new card in bank
		/*Card(std::string pan,size_t pin_code, size_t cvv);*/

		Card(const Card&) = default;
		Card& operator=(const Card&) = default;

		Card& operator=(Card&&) noexcept = default;
		Card(Card&&) noexcept = default;

		~Card() = default;

		void change_pin_code(size_t new_pin);

		inline const std::string& get_pan() const { return pan; };
		inline size_t get_pin_code() const { return pin_code; };
		inline const std::string& get_expr_date() const { return expr_date; };
		inline size_t get_cvv() const { return cvv; };
		inline const std::string& get_given_date() const { return given_date; };

		friend mdls::Card& Bank::get_card(std::string pan);

	private:
		Card(void) = default;

		Card(
			std::string pan, size_t pin_code,
			std::string expr_date, size_t cvv,
			std::string given_date, size_t id = 0,
			size_t acc_id = 0, size_t clnt_id = 0);

		inline size_t get_id() const { return id; };
		inline size_t get_acc_id() const { return acc_id; };
		inline size_t get_clnt_id() const { return clnt_id; };
		
		size_t id;
		size_t acc_id;
		size_t clnt_id;

		std::string pan;
		size_t pin_code;
		std::string expr_date;
		size_t cvv;
		std::string given_date;
	};
}

std::ostream& operator<<(std::ostream& os, const mdls::Card& off);

//id	int unsigned	NO	PRI		auto_increment
//pan	varchar(20)	NO	UNI
//acc_id	int unsigned	NO	MUL
//clnt_id	int unsigned	NO	MUL
//pin_code	int unsigned	NO
//expr_date	date	NO
//cvv	int unsigned	NO
//given_date	date	NO

