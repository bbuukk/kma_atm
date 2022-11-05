#pragma once

#include "Office.h"

#include <mysql/jdbc.h>

namespace mdls {
	class Office {
	public:
		Office(void) = default;

		Office(
			bool head_off,
			std::string city,
			std::string street,
			std::string postal);

		Office(const Office&) = default;
		Office& operator=(const Office&) = default;

		Office& operator=(Office&&) noexcept = default;
		Office(Office&&) noexcept = default;

		~Office() = default;

		inline bool is_head_office() const { return head_off; };
		inline std::string get_city() const { return city; };
		inline std::string get_street() const { return street; };
		inline std::string get_postal() const { return postal; };

	private:

		bool head_off;
		std::string city;
		std::string street;
		std::string postal;
	};
}

std::ostream& operator<<(std::ostream& os, const mdls::Office& off);

