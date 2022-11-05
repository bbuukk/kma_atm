#include "ATM.h"

ATM::ATM(
	std::string num,
	std::string city,
	std::string street)
	: num(num), city(city), street(street) {};

std::ostream& operator<<(std::ostream& os, const ATM& atm) {
	return os
		<< "ATM number" << atm.get_num() << "\n"
		<< "ATM city:" << atm.get_city() << "\n"
		<< "ATM street:" << atm.get_street() << "\n";

}



