#include "Bank.h"

#include "ATM.h"

mdls::ATM& Bank::get_atm(const std::string& num){

    std::string query = "call get_atm1(?);";

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

mdls::ATM& Bank::get_atm(const size_t id) {

    std::string query = "call get_atm2(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        Bank::get_connection()->prepareStatement(query));
    pstmt->setUInt(1, id);

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



//ATM(
//    std::string num,
//    std::string city,
//    std::string street);