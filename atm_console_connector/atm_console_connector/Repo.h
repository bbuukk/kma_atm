#pragma once

#include "Acc.h"

#include <string>

#include <memory>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

class Repo {
public:

	Repo();
	Repo(sql::Connection*& con);
	~Repo();

	Acc& getAccInfo(int acc_id);
	Acc& getAccBalanceInfo(size_t acc_id);



private:
	std::unique_ptr<sql::Connection> con;
	std::unique_ptr<sql::PreparedStatement> pstmt;
	std::unique_ptr<sql::ResultSet> res;
};