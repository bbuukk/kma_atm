#include "Repo.h"

Card& Repo::get_card(std::string pan) {

    std::string query = "call get_card(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement(query));
    pstmt->setString(1, pan);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    Card* card;

    do {
        while (res->next()) {
            card = new Card(0, 0, 0,
                res->getString("pan"),
                res->getUInt("pin_code"),
                res->getString("expr_date"),
                res->getUInt("cvv"),
                res->getString("given_date"));
        }
    } while (pstmt->getMoreResults());

    return *card;
}


//card_id	int unsigned	NO	PRI		auto_increment
//acc_id	int unsigned	NO	MUL
//clnt_id	int unsigned	NO	MUL
//pan	varchar(20)	NO	UNI
//pin_code	int unsigned	NO
//expr_date	date	NO
//cvv	int unsigned	NO
//given_date	date	NO

