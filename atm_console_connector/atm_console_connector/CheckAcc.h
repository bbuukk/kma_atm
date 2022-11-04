#pragma once

#include "Acc.h"

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

class CheckAcc : public Acc {
public:
	CheckAcc(void);

	CheckAcc(Acc&, size_t overdraft_lim);

	CheckAcc(size_t acc_id, size_t dgt_code,
			 size_t off_id, size_t clnt_id,
			 size_t acc_type, std::string acc_num,
			 double balance, std::string  open_date,
			 bool is_blocked, double atm_fee,
			 double intrest, size_t overdraft_lim);
	
	~CheckAcc() = default;

	inline size_t getOverdraftLim() const { return overdraft_lim; };




private:
	std::ostream& print(std::ostream& os) const override;

	size_t overdraft_lim;
};