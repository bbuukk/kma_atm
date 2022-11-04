#pragma once

#include "Acc.h"

#include <string>
#include <ostream>
#include <memory>

#include <mysql/jdbc.h>

namespace epo {
	void test(void);
}


class Repo {
public:

	Repo(void) = default;

	inline Repo(sql::Connection*& con)
		: con(con) {};

	~Repo() = default;

	Acc& getAccInfo(size_t acc_id);
	void test(size_t acc_id);
	Acc& getAccBalanceInfo(size_t acc_id);

private:
	std::unique_ptr<sql::Connection> con;
};