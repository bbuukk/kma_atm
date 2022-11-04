#pragma once

#include "DB.h"




DB::DB()
	: server(nullptr),
	  username(nullptr),
	  password(nullptr){};

DB::DB(
	std::string server,
	std::string username,
	std::string password)
	: server(server),
	  username(username),
	  password(password) {};

DB::~DB(){}

sql::Connection*& DB::getConnection()
{

    sql::Connection* con;

    sql::Driver* driver;

    driver = get_driver_instance();
    con = driver->connect(server, username, password);
    con->setSchema("atm");

	std::cout << "Successfully connected" << "\n";

    return con;
    
 
}
