#include "Bank.h"

#include "Client.h"

mdls::Client::Client(
	std::string f_name,
	std::string l_name,
	std::string mobile_phone)
	: f_name(f_name),
	  l_name(l_name),
	  mobile_phone(mobile_phone) {};


std::ostream& operator<<(std::ostream& os, const mdls::Client& client) {
	return os
		<< "First name: " << client.get_first_name() << "\n"
		<< "Last name:" << client.get_last_name() << "\n"
		<< "Mobile phone:" << client.get_mobile_phone() << "\n";
}