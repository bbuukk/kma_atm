#include "Repo.h"

std::string& Repo::get_atm_info(size_t mach_id) {

    std::string query = "call get_atm_info(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement(query));
    pstmt->setInt(1, mach_id);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    std::string* atm_info = new std::string;

    do {
        while (res->next()) {
            *atm_info = res->getString("atm_info");
        }
    } while (pstmt->getMoreResults());

    return *atm_info;
}
