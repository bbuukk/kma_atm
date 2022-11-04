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

void Repo::update_card(
    size_t card_id, size_t acc_id,
    size_t clnt_id, std::string pan,
    size_t pin_code, std::string expr_date,
    size_t cvv, std::string given_date) {

    std::string query = "call update_card(?,?,?,?,?,?,?,?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement(query));
    pstmt->setUInt(1, card_id);
    pstmt->setUInt(2, acc_id);
    pstmt->setUInt(3, clnt_id);
    pstmt->setString(4, pan);

    pstmt->setUInt(5, pin_code);
    pstmt->setString(6, expr_date);
    pstmt->setUInt(7, cvv);
    pstmt->setString(8, given_date);

    pstmt->execute();
}


//card_id	int unsigned	NO	PRI		auto_increment
//acc_id	int unsigned	NO	MUL
//clnt_id	int unsigned	NO	MUL
//pan	varchar(20)	NO	UNI
//pin_code	int unsigned	NO
//expr_date	date	NO
//cvv	int unsigned	NO
//given_date	date	NO

