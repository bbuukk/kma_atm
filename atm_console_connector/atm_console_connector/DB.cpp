#pragma once

#include "DB.h"

#include <string>
#include <memory>

#include "mysql_connection.h"
#include <cppconn/driver.h>


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

void DB::init()
{

    //std::unique_ptr<sql::Connection> con;

    //sql::Driver* driver;

    //try
    //{

    //    driver = get_driver_instance();
    //    con.reset(driver->connect(server, username, password));

    //    std::cout << "Successfully connected" << "\n";
    //}
    //catch (sql::SQLException& e)
    //{
    //    std::cout << "Could not connect to server. Error message: " << e.what() << "\n";
    //    system("pause");
    //    return EXIT_FAILURE;
    //}

    //con->setSchema("atm");

}
