#include "Bank.h"

#include "Transaction.h"

mdls::Transaction& Bank::get_transaction(std::string trans_num) {

    std::string query = "call get_transaction(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        Bank::get_connection()->
        prepareStatement(query));

    pstmt->setString(1, trans_num);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    mdls::Transaction* trans;

    do {
        while (res->next()) {
            trans = new mdls::Transaction(

                res->getString("num"),
                res->getString("acc_from"),
                res->getString("acc_to"),
                res->getUInt("sum"),

                res->getString("date"),
                res->getBoolean("successful"),
                res->getString("atm_num"),
                res->getString("descript"));
        }
    } while (pstmt->getMoreResults());

    return *trans;
}

bool Bank::transfer(
    std::string atm_num,
    std::string acc_from,
    std::string acc_to,
    size_t sum,
    std::string description) {

    std::string query = "call transfer(?,?,?,?,?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        Bank::get_connection()->
        prepareStatement(query));

    pstmt->setString(1, atm_num);
    pstmt->setString(2, acc_from);
    pstmt->setString(3, acc_to);
    pstmt->setUInt(4, sum);
    pstmt->setString(5, description);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    bool is_successful;

    do {
        while (res->next())
            is_successful = res->getBoolean("is_successful");
    } while (pstmt->getMoreResults());

    return is_successful;
}

bool Bank::withdraw(
    std::string atm_num,
    std::string acc_from,
    size_t sum,
    std::string description) {

    std::string query = "call withdraw(?,?,?,?,?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        Bank::get_connection()->
        prepareStatement(query));

    pstmt->setString(1, atm_num);
    pstmt->setString(2, acc_from);
    pstmt->setUInt(3, sum);
    pstmt->setString(4, description);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    bool is_successful;

    do {
        while (res->next()) 
            is_successful = res->getBoolean("is_successful"); 
    } while (pstmt->getMoreResults());

    return is_successful;
}
