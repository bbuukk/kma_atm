#pragma once

#include "ATM.h"

#include <mysql/jdbc.h>

class ATM {
public:
	ATM(void) = default;

	ATM(
		size_t id,
		size_t off_id,
		std::string street);

	ATM(const ATM&) = default;
	ATM& operator=(const ATM&) = default;

	~ATM() = default;

	inline size_t get_id() const { return id; };
	inline size_t get_office_id() const { return off_id; };
	inline std::string get_street() const { return street; };


private:
	size_t id;
	size_t off_id;
	std::string street;
};

std::ostream& operator<<(std::ostream& os, const ATM& off);
