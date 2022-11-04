#pragma once

#include "DB.h"


sql::Connection*& DB::get_connection()
{
	sql::ConnectOptionsMap connection_properties;

	connection_properties["hostName"] = sql::SQLString("tcp://automatedmachinetellerdb.cuccuzhaeiiv.eu-central-1.rds.amazonaws.com:3306");
	connection_properties["userName"] = sql::SQLString("tgd_nWaA");
	connection_properties["password"] = sql::SQLString("ba9s5JNgN3d4AkQ");
	connection_properties["CLIENT_MULTI_STATEMENTS"] = (true);

	sql::Driver* driver(get_driver_instance());
    sql::Connection* con(driver->connect(connection_properties));
    con->setSchema("atm");

	std::cout << "Successfully connected" << "\n";

    return con;
    
 
}
