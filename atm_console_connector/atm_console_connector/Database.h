#pragma once

#include "Repo.h"

#include <string>
#include <memory>

#include <mysql/jdbc.h>

class Database {
public:

	Database(const Database&) = delete;
	Database& operator=(const Database&) = delete;

	~Database() = default;

	static Database& get() {
		static Database db;
		return db;
	}

	static inline const Repo& get_repository(){
		return get().in_get_repository(); 
	};
		
private:
	inline const Repo& in_get_repository() const { return repo; };

	Database(void) = default;

	sql::Connection*& get_connection();
	Repo repo = this-> get_connection();
};