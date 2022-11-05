#pragma once

#include "Repo.h"

#include <string>
#include <memory>

#include <mysql/jdbc.h>

class Database {
public:

	Database() = default;

	~Database() = default;

	sql::Connection*& get_connection();

	inline const Repo& get_repository() const { return repo; };

private:
	Repo repo = this-> get_connection();
};