#pragma once

#include "ATM.h"

#include <mysql/jdbc.h>

class ATM {
public:
	ATM(void) = default;

	ATM(
		std::string num,
		std::string city, 
		std::string street);

	ATM(const ATM&) = default;
	ATM& operator=(const ATM&) = default;

	~ATM() = default;

	inline std::string get_num() const { return num; };
	inline std::string get_city() const { return city; };
	inline std::string get_street() const { return street; };

private:
	std::string num;
	std::string city;
	std::string street;
};

std::ostream& operator<<(std::ostream& os, const ATM& off);
