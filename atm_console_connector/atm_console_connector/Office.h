#pragma once

#include <string>
#include <ostream>

namespace mdls {
	class Office {
	public:
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
		inline const std::string& get_city() const { return city; };
		inline const std::string& get_street() const { return street; };
		inline const std::string& get_postal() const { return postal; };

	private:
		Office(void) = default;

		bool head_off;
		std::string city;
		std::string street;
		std::string postal;
	};
}

std::ostream& operator<<(std::ostream& os, const mdls::Office& off);

