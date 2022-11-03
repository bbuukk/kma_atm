#pragma once

#include "Acc.h"

class CheckAcc : public Acc {
public:
	CheckAcc();

	~CheckAcc();


private:

	int overdraft_lim;
	
};