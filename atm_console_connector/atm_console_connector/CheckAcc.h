#pragma once

#include "Acc.h"

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

class CheckAcc : public Acc {
public:
	CheckAcc();

	CheckAcc(int acc_id, int dgt_code,
			 int off_id, int clnt_id,
			 int acc_type, std::string acc_num,
			 int balance, std::string  open_date,
			 bool is_blocked, double atm_fee,
			 double intrest, int overdraft_lim);

	~CheckAcc();


private:

	int overdraft_lim;
	
};