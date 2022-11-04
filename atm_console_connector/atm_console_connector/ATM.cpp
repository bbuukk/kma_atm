#include "ATM.h"

ATM::ATM(
	size_t mach_id,
	size_t off_id,
	std::string atm_street)
	: mach_id(mach_id),
	  off_id(off_id),
	  atm_street(atm_street) {};

std::ostream& operator<<(std::ostream& os, const ATM& atm) {
	return os
		<< "Machine id:" << atm.get_machine_id() << "\n"
		<< "Office id: " << atm.get_office_id() << "\n"
		<< "ATM street:" << atm.get_atm_street() << "\n";
}



