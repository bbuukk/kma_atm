#include "ATM.h"

ATM::ATM(
	size_t id,
	size_t off_id,
	std::string street)
	: id(id),
	  off_id(off_id),
	  street(street) {};

std::ostream& operator<<(std::ostream& os, const ATM& atm) {
	return os
		<< "Machine id:" << atm.get_id() << "\n"
		<< "Office id: " << atm.get_office_id() << "\n"
		<< "ATM street:" << atm.get_street() << "\n";
}



