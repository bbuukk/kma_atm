#pragma once

#include <string>
#include <ostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

//Account
class Acc {
public:
	Acc();
	Acc(int acc_id, int dgt_code,
		int off_id, int clnt_id,
		int acc_type, std::string acc_num,
		int balance, std::string  open_date,
		bool is_blocked, double atm_fee,
		double intrest);

	


	virtual ~Acc();


	//getters
	inline int getAccId() const { return acc_id; };
	inline int getDgtCode() const { return dgt_code; }; //get currency digital code
	inline int getOffId() const { return off_id; }; // get office id
	inline int getClntId() const { return clnt_id; }; //get client id
	inline int getAccType() const { return acc_type; };

	inline std::string getAccNum() const { return acc_num; };
	inline double getBalance() const { return balance; };
	inline std::string getOpenDate() const { return open_date; };
	inline bool getIsBlocked() const { return is_blocked; };

	inline double getAtmFee() const { return atm_fee; };
	inline double getIntrest() const { return intrest; };

protected:
	int acc_id;
	int dgt_code;
	int off_id;
	int clnt_id;
	int acc_type;

	std::string acc_num;
	double balance;
	std::string open_date;
	bool is_blocked;
	
	double atm_fee;
	double intrest;
};

std::ostream& operator<<(std::ostream&, const Acc&);
