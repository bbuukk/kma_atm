
#include "Repo.h"

Repo::Repo(void) 
    : con(nullptr) {};

Repo::Repo(sql::Connection*& con) 
    : con(con) {};


Acc& Repo::getAccInfo(size_t acc_id) {

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement("call get_acc_info(?);"));
    pstmt->setInt(1, acc_id);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    Acc* acc;

    do {
        while (res->next()) {  
            acc = (new Acc(0, 0, 0, 0, 0,
                res->getString("acc_num"),
                res->getDouble("balance"),
                res->getString("open_date"),
                res->getBoolean("is_blocked"),
                0, 0));
        }
    } while (pstmt->getMoreResults());

    return *acc;
}

Acc& Repo::getAccBalanceInfo(size_t acc_id) {

    Acc acc;
    return acc;
}


//int acc_id;
//int dgt_code;
//int off_id;
//int clnt_id;
//int acc_type;
//std::string acc_num;
//double balance;
//std::string open_date;
//bool is_blocked;
//double atm_fee;
//double intrest;
