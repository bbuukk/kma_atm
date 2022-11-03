#pragma once

#include <string>

class DB {
public:

	DB();
	DB(std::string server,
	   std::string username,
	   std::string password);
	~DB();

	void init();


private:
	std::string server;
	std::string username;
	std::string password;
};