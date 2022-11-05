#pragma once

#include "Database.h"
#include "Repo.h"
#include "Bank_sbs.h"

#include <mysql/jdbc.h>

namespace sbs {

	class ATM {
	public:
		ATM(void) = default;

		ATM(const ATM&) = default;
		ATM& operator=(const ATM&) = default;

		ATM& operator=(ATM&&) noexcept = default;
		ATM(ATM&&) noexcept = default;

		~ATM() = default;

		inline const Bank& get_bank() const { return bank; };

		void foo();

		
	private:
		Bank bank;
	};
}

std::ostream& operator<<(std::ostream& os, const mdls::ATM& off);


