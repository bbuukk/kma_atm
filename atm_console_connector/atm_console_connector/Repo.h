#pragma once

#include "Acc.h"

#include <string>
#include <ostream>
#include <memory>

#include <mysql/jdbc.h>

class Repo {
public:

	Repo();
	Repo(sql::Connection*& con);
	~Repo();

	Acc& getAccInfo(int acc_id);
	void test(size_t acc_id);
	Acc& getAccBalanceInfo(size_t acc_id);



private:
	std::unique_ptr<sql::Connection> con;
	/*std::unique_ptr<sql::PreparedStatement> pstmt;
	std::unique_ptr<sql::Statement> stmt;
	std::unique_ptr<sql::ResultSet> res;*/
};