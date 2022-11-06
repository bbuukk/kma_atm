#include "ATM.h"

mdls::ATM::ATM(
	std::string num,
	std::string city,
	std::string street)
	: num(num), city(city), street(street) {};

mdls::ATM::ATM(std::string num) 
	: ATM(Bank::get_atm(num)) {};

std::ostream& operator<<(std::ostream& os, const mdls::ATM& atm) {
	return os
		<< "ATM number" << atm.get_num() << "\n"
		<< "ATM city:" << atm.get_city() << "\n"
		<< "ATM street:" << atm.get_street() << "\n";

}



