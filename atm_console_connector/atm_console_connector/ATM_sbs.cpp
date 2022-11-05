#include "ATM_sbs.h"

void sbs::ATM::foo() {


	Repo repo(this->get_bank().get_database().get_repository());
}

std::ostream& operator<<(std::ostream& os, const sbs::ATM& atm) {
	return os << "not_implemented_yet";
}



