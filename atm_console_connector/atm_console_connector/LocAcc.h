#pragma once

#include "Acc.h"

class CheckAcc : public Acc {
public:
	CheckAcc();

private:

	int crd_taken;
	int loc_lim;
	int crd_return;

};