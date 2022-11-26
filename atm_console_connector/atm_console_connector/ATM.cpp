#include "Bank.h"

#include "ATM.h"

mdls::ATM::ATM(
	const std::string& num,
	const std::string& city,
	const std::string& street)
	: num_(num)
	, city_(city)
	, street_(street)
{};

mdls::ATM::ATM(const std::string& num)
	: ATM(Bank::get_atm(num)) {};

std::ostream& operator<<(std::ostream& os, const mdls::ATM& atm) {
	return os
		<< "ATM number" << atm.num() << "\n"
		<< "ATM city:" << atm.city() << "\n"
		<< "ATM street:" << atm.street() << "\n";

}



