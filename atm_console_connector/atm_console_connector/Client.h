#pragma once

#include <string>
#include <ostream>

namespace mdls {
	class Client {
	public:

		Client(
			std::string f_name,
			std::string l_name,
			std::string mobile_phone);

		Client(const Client&) = default;
		Client& operator=(const Client&) = default;

		Client& operator=(Client&&) noexcept = default;
		Client(Client&&) noexcept = default;

		~Client() = default;

		inline const std::string& get_first_name() const { return f_name; };
		inline const std::string& get_last_name() const { return l_name; };
		inline const std::string& get_mobile_phone() const { return mobile_phone; };

	private:
		Client(void) = default;

		std::string f_name;
		std::string l_name;
		std::string mobile_phone;
	};
}

std::ostream& operator<<(std::ostream& os, const mdls::Client& off);

