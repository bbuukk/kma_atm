#pragma once

#include "Database.h"
#include "Repo.h"

#include <mysql/jdbc.h>

//TODO for now i decided, that it bank is namespace, for now...
namespace bank 
{

	bool transact(
        std::string atm_num,
        std::string acc_from,
        std::string acc_to,
        size_t sum,
        std::string description)
    {
        return Database::get_repository()
                .transact(atm_num, acc_from,
                          acc_to, sum, description);
	}

    bool withdraw(
        std::string atm_num,
        std::string acc_from,
        size_t sum,
        std::string description)
    {
        return Database::get_repository()
            .withdraw(atm_num, acc_from,
                      sum, description);
    }




}




