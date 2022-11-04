#include "Repo.h"

Account& Repo::get_acc(size_t acc_id) {

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement("call get_acc(?);"));
    pstmt->setInt(1, acc_id);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    Account* acc;

    do {
        while (res->next()) {
            acc = new Account(0, 0, 0, 0, 0,
                res->getString("acc_num"),
                res->getDouble("balance"),
                res->getString("open_date"),
                res->getBoolean("is_blocked"),
                0, 0);
        }
    } while (pstmt->getMoreResults());

    return *acc;
}

void Repo::block_acc(size_t acc_id) {

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement("call block_acc(?);"));
    pstmt->setUInt(1, acc_id);

    pstmt->execute();
}

void Repo::unblock_acc(size_t acc_id) {

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement("call unblock_acc(?);"));
    pstmt->setUInt(1, acc_id);

    pstmt->execute();
}


//Account& Repo::get_acc_balance(size_t acc_id) {
//
//    Account acc;
//    return acc;
//}

//todo
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

