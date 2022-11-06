#pragma once

#include "Bank.h"

Bank::Bank(void) {
	this->connect();
};

void Bank::connect()
{
	sql::ConnectOptionsMap connection_properties;

	connection_properties["hostName"] = sql::SQLString("tcp://automatedmachinetellerdb.cuccuzhaeiiv.eu-central-1.rds.amazonaws.com:3306");
	connection_properties["userName"] = sql::SQLString("tgd_nWaA");
	connection_properties["password"] = sql::SQLString("ba9s5JNgN3d4AkQ");
	connection_properties["CLIENT_MULTI_STATEMENTS"] = (true);

	sql::Driver* driver(get_driver_instance());
	this->con.reset(driver->connect(connection_properties));
	con->setSchema("atm");

	std::cout << "Successfully connected" << "\n";
};
