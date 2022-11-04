#pragma once

#include <string>
#include <memory>

#include <mysql/jdbc.h>

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