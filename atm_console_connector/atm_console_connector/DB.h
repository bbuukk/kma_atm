#pragma once

#include <string>
#include <memory>

#include <mysql/jdbc.h>

class DB {
public:

	DB() = default;

	~DB() = default;

	sql::Connection*& get_connection();

private:
};