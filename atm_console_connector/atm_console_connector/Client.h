#pragma once

#include "Client.h"

#include <mysql/jdbc.h>

class Client {
public:
	Client(void) = default;

	Client(
		std::string f_name,
		std::string l_name,
		std::string mobile_phone);

	Client(const Client&) = default;
	Client& operator=(const Client&) = default;

	~Client() = default;

	inline std::string get_first_name() const { return f_name; };
	inline std::string get_last_name() const { return l_name; };
	inline std::string get_mobile_phone() const { return mobile_phone; };

private:
	std::string f_name;
	std::string l_name;
	std::string mobile_phone;
};

std::ostream& operator<<(std::ostream& os, const Client& off);

