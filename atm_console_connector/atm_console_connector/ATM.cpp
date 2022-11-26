#include "Bank.h"

#include "ATM.h"

mdls::ATM::ATM(
	const std::string& num,
	const std::string& city,
	const std::string& street)
	: num(num), city(city), street(street) {};

mdls::ATM::ATM(const std::string& num)
	: ATM(Bank::get_atm(num)) {};

std::ostream& operator<<(std::ostream& os, const mdls::ATM& atm) {
	return os
		<< "ATM number" << atm.get_num() << "\n"
		<< "ATM city:" << atm.get_city() << "\n"
		<< "ATM street:" << atm.get_street() << "\n";

}



