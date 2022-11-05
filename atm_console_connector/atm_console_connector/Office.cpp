#include "Office.h"

Office::Office(
	size_t id,
	bool head_off,
	std::string city,
	std::string street,
	std::string postal)
	: id(id), head_off(head_off),
	  city(city), street(street),
	  postal(postal) {};

std::ostream& operator<<(std::ostream& os, const Office& off) {
	return os
		<< "Office id: " << off.get_id() << "\n"
		<< "Is Head office: " << off.is_head_office() << "\n"
		<< "Office city: " << off.get_city() << "\n"
		<< "Office street: " << off.get_street() << "\n"
		<< "Postal: " << off.get_postal() << "\n";
}



