#include "Repo.h"

mdls::ATM& Repo::get_atm(std::string num) const {

    std::string query = "call get_atm(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement(query));
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


//ATM(
//    std::string num,
//    std::string city,
//    std::string street);