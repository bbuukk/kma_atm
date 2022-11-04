#include "Office.h"

Office::Office(
	size_t off_id,
	bool head_off,
	std::string off_city,
	std::string off_street,
	std::string postal)
	: off_id(off_id), head_off(head_off),
	  off_city(off_city), off_street(off_street),
	  postal(postal) {};

std::ostream& operator<<(std::ostream& os, const Office& off) {
	return os
		<< "Office id: " << off.getOfficeId() << "\n"
		<< "Is Head office: " << off.getHeadOffice() << "\n"
		<< "Office city: " << off.getOfficeCity() << "\n"
		<< "Office street: " << off.getOfficeStreet() << "\n"
		<< "Postal: " << off.getPostal() << "\n";
}



