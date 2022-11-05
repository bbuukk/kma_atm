#pragma once

#include "Database.h"

#include <mysql/jdbc.h>

namespace mdls {

	class ATM {
	public:
		ATM(void) = default;

		ATM(
			std::string num,
			std::string city,
			std::string street);

		ATM(std::string num);

		ATM(const ATM&) = default;
		ATM& operator=(const ATM&) = default;

		ATM& operator=(ATM&&) noexcept = default;
		ATM(ATM&&) noexcept = default;

		~ATM() = default;

		inline const std::string& get_num() const { return num; };
		inline const std::string& get_city() const { return city; };
		inline const std::string& get_street() const { return street; };

	private:
		std::string num;
		std::string city;
		std::string street;
	};
}

std::ostream& operator<<(std::ostream& os, const mdls::ATM& off);


