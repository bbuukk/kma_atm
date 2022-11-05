#include "Client.h"

Client::Client(
	size_t clnt_id,
	std::string f_name,
	std::string l_name,
	std::string mobile_phone)
	: clnt_id(clnt_id), f_name(f_name),
	  l_name(l_name), mobile_phone(mobile_phone) {};


std::ostream& operator<<(std::ostream& os, const Client& client) {
	return os
		<< "Client id:" << client.get_client_id() << "\n"
		<< "First name: " << client.get_first_name() << "\n"
		<< "Last name:" << client.get_last_name() << "\n"
		<< "Mobile phone:" << client.get_mobile_phone() << "\n";
}