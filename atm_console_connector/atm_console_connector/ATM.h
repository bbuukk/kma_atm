#pragma once

#include "ATM.h"

#include <mysql/jdbc.h>

class ATM {
public:
	ATM(void) = default;

	ATM(
		size_t mach_id,
		size_t off_id,
		std::string atm_street);

	ATM(const ATM&) = default;
	ATM& operator=(const ATM&) = default;

	~ATM() = default;

	inline size_t get_machine_id() const { return mach_id; };
	inline size_t get_office_id() const { return off_id; };
	inline std::string get_atm_street() const { return atm_street; };


private:
	size_t mach_id;
	size_t off_id;
	std::string atm_street;
};

std::ostream& operator<<(std::ostream& os, const ATM& off);
