#pragma once

#include <string>

//Account
class Acc {
public:
	Acc();
	virtual ~Acc();




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