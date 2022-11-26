#pragma once

#include <string>
#include <ostream>

namespace mdls {

	class ATM {
	public:

		ATM(const std::string& num);

		ATM(const ATM&) = default;
		ATM& operator=(const ATM&) = default;

		ATM& operator=(ATM&&) noexcept = default;
		ATM(ATM&&) noexcept = default;

		~ATM() = default;

		inline const std::string& num() const { return num_; };
		inline const std::string& city() const { return city_; };
		inline const std::string& street() const { return street_; };

		friend mdls::ATM& Bank::get_atm(const std::string& num);

	private:
		ATM(
			const std::string& num,
			const std::string& city,
			const std::string& street);

		ATM(void) = default;

		std::string num_;
		std::string city_;
		std::string street_;
	};
}

std::ostream& operator<<(std::ostream& os, const mdls::ATM& off);


