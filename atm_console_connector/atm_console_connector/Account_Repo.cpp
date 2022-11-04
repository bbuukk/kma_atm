#include "Repo.h"

Account& Repo::get_acc(size_t acc_id) {

    std::string query = "call get_acc(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement(query));
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

    std::string query = "call block_acc(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement(query));
    pstmt->setUInt(1, acc_id);

    pstmt->execute();
}

void Repo::unblock_acc(size_t acc_id) {

    std::string query = "call unblock_acc(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement(query));
    pstmt->setUInt(1, acc_id);

    pstmt->execute();
}

bool Repo::is_acc_blocked(size_t acc_id) {

    std::string query = "call is_acc_blocked(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement(query));
    pstmt->setInt(1, acc_id);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    bool is_blocked;

    do {
        while (res->next()) {
            is_blocked = res->getBoolean("is_blocked");
        }
    } while (pstmt->getMoreResults());

    return is_blocked;
}

double Repo::get_acc_balance(size_t acc_id) {

    std::string query = "call get_acc_blnc(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement(query));
    pstmt->setInt(1, acc_id);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    double balance;

    do {
        while (res->next()) {
            balance = res->getDouble("balance");
        }
    } while (pstmt->getMoreResults());

    return balance;
}

double Repo::get_acc_atm_fee(size_t acc_id) {

    std::string query = "call get_acc_atm_fee(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement(query));
    pstmt->setInt(1, acc_id);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    double atm_fee;

    do {
        while (res->next()) {
            atm_fee = res->getDouble("atm_fee");
        }
    } while (pstmt->getMoreResults());

    return atm_fee;
}

size_t Repo::get_acc_type(size_t acc_id) {

    std::string query = "call get_acc_tp(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement(query));
    pstmt->setInt(1, acc_id);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    size_t acc_type;

    do {
        while (res->next()) {
            acc_type = res->getDouble("acc_type");
        }
    } while (pstmt->getMoreResults());

    return acc_type;
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

