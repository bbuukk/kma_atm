#include "Acc.h"




Acc::Acc() 
	: acc_id(0), dgt_code(0), off_id(0),
	  clnt_id(0), acc_type(0), acc_num(nullptr),
	  balance(0), open_date(nullptr), is_blocked(0),
	  atm_fee(0), intrest(0) {}

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
