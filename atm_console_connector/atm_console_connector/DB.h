#pragma once

#include <string>


#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

class DB {
public:

	DB();
	DB(std::string server,
	   std::string username,
	   std::string password);
	~DB();

	sql::Connection*& getConnection();


private:
	std::string server;
	std::string username;
	std::string password;
};