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

		inline const std::string& get_num() const { return num; };
		inline const std::string& get_city() const { return city; };
		inline const std::string& get_street() const { return street; };

		friend mdls::ATM& Bank::get_atm(const std::string& num);

	private:
		ATM(
			const std::string& num,
			const std::string& city,
			const std::string& street);

		ATM(void) = default;

		std::string num;
		std::string city;
		std::string street;
	};
}

std::ostream& operator<<(std::ostream& os, const mdls::ATM& off);


