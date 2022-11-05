#include "ATM.h"

ATM::ATM(
	std::string street)
	: street(street) {};

std::ostream& operator<<(std::ostream& os, const ATM& atm) {
	return os << "ATM street:" << atm.get_street() << "\n";
}



