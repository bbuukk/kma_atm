#pragma once

#include <string>
#include <ostream>

namespace mdls {
	class Card {
	public:

		// constructor that's getting info from db
		Card(const std::string& pan);

		//constructor for creating new card in bank
		/*Card(std::string pan,size_t pin_code, size_t cvv);*/

		Card(const Card&) = default;
		Card& operator=(const Card&) = default;

		Card& operator=(Card&&) noexcept = default;
		Card(Card&&) noexcept = default;

		~Card() = default;

		void change_pin_code(const size_t new_pin);

		inline const std::string& pan() const { return pan_; };
		inline size_t pin_code() const { return pin_code_; };
		inline const std::string& expr_date() const { return expr_date_; };
		inline size_t cvv() const { return cvv_; };
		inline const std::string& given_date() const { return given_date_; };

		//TODO delete?
		/*friend mdls::Card& Bank::get_card(const std::string& pan);*/

		friend class Bank;

	private:
		Card(void) = default;

		Card(
			const std::string& pan, size_t pin_code,
			const std::string& expr_date, size_t cvv,
			const std::string& given_date, size_t id = 0,
			size_t acc_id = 0, size_t clnt_id = 0);

		inline size_t id() const { return id_; };
		inline size_t acc_id() const { return acc_id_; };
		inline size_t clnt_id() const { return clnt_id_; };
		
		size_t id_;
		size_t acc_id_;
		size_t clnt_id_;

		std::string pan_;
		size_t pin_code_;
		std::string expr_date_;
		size_t cvv_;
		std::string given_date_;
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

