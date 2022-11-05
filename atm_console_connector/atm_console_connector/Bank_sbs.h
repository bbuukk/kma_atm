#pragma once

#include "Database.h"
#include "Repo.h"

#include <mysql/jdbc.h>

namespace sbs {

	class Bank {
	public:
		Bank(void) = default;

		Bank(const Bank&) = default;
		Bank& operator=(const Bank&) = default;

		Bank& operator=(Bank&&) noexcept = default;
		Bank(Bank&&) noexcept = default;

		~Bank() = default;

		inline const Database& get_database() const { return db; };

	private:
		Database db;
	};
}

std::ostream& operator<<(std::ostream& os, const sbs::Bank& off);


