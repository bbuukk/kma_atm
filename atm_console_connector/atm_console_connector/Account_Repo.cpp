#include "Bank.h"

#include "Account.h"
#include "Office.h"
#include "Transaction.h"

mdls::Account& Bank::get_account(std::string num){

    std::string query = "call get_acc(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        Bank::get_connection()->prepareStatement(query));
    pstmt->setString(1, num);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    mdls::Account* acc;

    do {
        while (res->next()) {
            acc = new mdls::Account(
                res->getString("num"),
                res->getUInt("dgt_code"),
                res->getDouble("balance"),

                res->getString("open_date"),
                res->getBoolean("is_blocked"),
                res->getDouble("atm_fee"),
                res->getDouble("intrest"),

                res->getUInt("id"),
                res->getUInt("off_id"),
                res->getUInt("clnt_id"),
                res->getUInt("acc_type"));
        }
    } while (pstmt->getMoreResults());

    return *acc;
}

mdls::Office& Bank::get_acc_office(size_t id) {
    
    std::string query = "call get_office(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        Bank::get_connection()->prepareStatement(query));
    pstmt->setUInt(1, id);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    mdls::Office* off;

    do {
        while (res->next()) {
            off = new mdls::Office(
                res->getBoolean("head_off"),
                res->getString("city"),
                res->getString("street"),
                res->getString("postal"));
        }
    } while (pstmt->getMoreResults());

    return *off;
}

void Bank::block_account(size_t id) {

    std::string query = "call block_acc(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        Bank::get_connection()->prepareStatement(query));
    pstmt->setUInt(1, id);

    pstmt->execute();
}

void Bank::unblock_account(size_t id) {

    std::string query = "call unblock_account(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        Bank::get_connection()->prepareStatement(query));
    pstmt->setUInt(1, id);

    pstmt->execute();
}

std::vector <mdls::Transaction>& Bank::get_acc_transactions(std::string num) {

    std::string query("call get_all_acc_trans(?);");

    std::unique_ptr<sql::PreparedStatement> pstmt(
        Bank::get_connection()->prepareStatement(query));
    pstmt->setString(1, num);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    std::vector <mdls::Transaction>* transs(new std::vector<mdls::Transaction>);

    do {
        while (res->next()) {
            (*transs).push_back(
                mdls::Transaction(
                res->getString("num"),
                res->getString("acc_from"),
                res->getString("acc_to"),
                res->getUInt("sum"),

                res->getString("date"),
                res->getBoolean("is_successful"),
                res->getString("atm_num"),
                res->getString("descript")));
        }
    } while (pstmt->getMoreResults());

    return *transs;
}


//int Repo::count_acc_transactions(std::string num) const {
//
//    std::string query = "call count_all_acc_trans(?);";
//
//    std::unique_ptr<sql::PreparedStatement> pstmt(
//        this->con->prepareStatement(query));
//    pstmt->setString(1, num);
//
//    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
//
//    int amount_of_trans;
//
//    do {
//        while (res->next()) {
//            amount_of_trans = res->getUInt("t_amount");
//        }
//    } while (pstmt->getMoreResults());
//
//    return amount_of_trans;
//}
