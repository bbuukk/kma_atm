#include "ATM_sbs.h"


    bool transact(
        std::string atm_num,
        std::string acc_from,
        std::string acc_to,
        size_t sum,
        std::string description)
    {
        return Bank:: transact(
            atm_num, acc_from,
            acc_to, sum, description);
    }

    bool withdraw(
        std::string atm_num,
        std::string acc_from,
        size_t sum,
        std::string description)
    {
        return Bank::withdraw(atm_num, acc_from,
                sum, description);
    }

