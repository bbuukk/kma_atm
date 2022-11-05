#pragma once

#include "ATM.h"

#include <mysql/jdbc.h>

class ATM {
public:
	ATM(void) = default;

	ATM(std::string street);

	ATM(const ATM&) = default;
	ATM& operator=(const ATM&) = default;

	~ATM() = default;

	inline std::string get_street() const { return street; };


private:
	std::string street;
};

std::ostream& operator<<(std::ostream& os, const ATM& off);
