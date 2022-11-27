#include "Bank.h"

#include "ATM.h"

mdls::ATM& Bank::get_atm(const std::string& num){

    std::string query = "call atm_by_num(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        Bank::get_connection()->prepareStatement(query));
    pstmt->setString(1, num);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    mdls::ATM* atm;

    do {
        while (res->next()) {
            atm = new mdls::ATM(
                res->getString("num"),
                res->getString("city"),
                res->getString("street"));
        }
    } while (pstmt->getMoreResults());

    return *atm;
}

size_t Bank::get_atm_id(const std::string& num) {

    std::string query = "call atm_by_id(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        Bank::get_connection()->prepareStatement(query));
    pstmt->setString(1, num);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    size_t id;

    do {
        while (res->next()) {
            id = res->getUInt("id");
        }
    } while (pstmt->getMoreResults());

    return id;
}

