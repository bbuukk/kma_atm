#include "Bank.h"

#include "Office.h"

mdls::Office::Office(
	bool head_off, std::string city,
	std::string street, std::string postal)
	: head_off(head_off), city(city),
	street(street), postal(postal) {};

std::ostream& operator<<(std::ostream& os, const mdls::Office& off) {
	return os
		<< "Is Head office: " << off.is_head_office() << "\n"
		<< "Office city: " << off.get_city() << "\n"
		<< "Office street: " << off.get_street() << "\n"
		<< "Postal: " << off.get_postal() << "\n";
}



