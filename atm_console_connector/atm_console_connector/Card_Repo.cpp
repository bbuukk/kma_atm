#include "Bank.h"

#include "Card.h"

mdls::Card& Bank::get_card(const std::string& pan) {

    std::string query = "call get_card(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        Bank::get_connection()->
        prepareStatement(query));

    pstmt->setString(1, pan);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    mdls::Card* card;

    do {
        while (res->next()) {
            card = new mdls::Card(
                res->getString("pan"),
                res->getUInt("pin_code"),
                res->getString("expr_date"),
                res->getUInt("cvv"),
                res->getString("given_date"));
        }
    } while (pstmt->getMoreResults());

    return *card;
}

void Bank::change_pin_code(
    const size_t id, const size_t pin_code) {

    std::string query = "call change_pin_code(?,?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        Bank::get_connection()->
        prepareStatement(query));

    pstmt->setUInt(1, id);
    pstmt->setUInt(2, pin_code);
    pstmt->execute();

    //Card(
//    std::string pan, size_t pin_code,
//    std::string expr_date, size_t cvv,
//    std::string given_date);
}



