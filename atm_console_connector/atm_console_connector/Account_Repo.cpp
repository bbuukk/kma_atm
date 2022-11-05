#include "Repo.h"

Account& Repo::get_acc(std::string num) {

    std::string query = "call get_acc(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement(query));
    pstmt->setString(1, num);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    Account* acc;

    do {
        while (res->next()) {
            acc = new Account(
                res->getString("num"),
                res->getUInt("dgt_code"),
                res->getDouble("balance"),

                res->getString("open_date"),
                res->getBoolean("is_blocked"),
                res->getDouble("atm_fee"),
                res->getDouble("intrest"));
        }
    } while (pstmt->getMoreResults());

    return *acc;
}

Office& Repo::get_acc_office(std::string num) {
    
    std::string query = "call get_office(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement(query));
    pstmt->setString(1, num);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    Office* off;

    do {
        while (res->next()) {
            off = new Office(
                res->getBoolean("head_off"),
                res->getString("city"),
                res->getString("street"),
                res->getString("postal"));
        }
    } while (pstmt->getMoreResults());

    return *off;
}

void Repo::block_acc(std::string num) {

    std::string query = "call block_acc(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement(query));
    pstmt->setString(1, num);

    pstmt->execute();
}

void Repo::unblock_acc(std::string num) {

    std::string query = "call unblock_acc(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement(query));
    pstmt->setString(1, num);

    pstmt->execute();
}


//return vector
Transaction& Repo::get_all_acc_trans(std::string num) {

    std::string query = "call get_all_acc_trans(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement(query));
    pstmt->setString(1, num);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    

    do {
        while (res->next()) {
            trans = new Transaction(

                res->getString("num"),
                res->getString("acc_from"),
                res->getString("acc_to"),
                res->getUInt("sum"),

                res->getString("date"),
                res->getBoolean("is_successful"),
                res->getString("atm_num"),
                res->getString("descript"));
        }
    } while (pstmt->getMoreResults());

    return *trans;
}


int Repo::count_all_acc_trans(std::string num) {

    std::string query = "call count_all_acc_trans(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement(query));
    pstmt->setString(1, num);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    int amount_of_trans;

    do {
        while (res->next()) {
            amount_of_trans = res->getUInt("t_amount");
        }
    } while (pstmt->getMoreResults());

    return amount_of_trans;
}





//Account(
//    std::string num, size_t dgt_code,
//    double balance, std::string open_date,
//    bool blocked, double atm_fee,
//    double intrest);


