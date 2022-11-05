#include "Repo.h"

Transaction& Repo::get_transaction(std::string trans_num) {

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement("call get_transaction(?);"));
    pstmt->setInt(1, trans_num);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    Transaction* trans;

    do {
        while (res->next()) {
            trans = new Transaction(
                0,
                res->getBoolean("head_off"),
                res->getString("off_city"),
                res->getString("off_street"),
                res->getString("postal"));
        }
    } while (pstmt->getMoreResults());

    return *trans;
}

//trans_id	int unsigned	NO	PRI		auto_increment
//mach_id	int unsigned	YES	MUL
//acc_from	int unsigned	NO	MUL
//acc_to	int unsigned	YES	MUL
//t_sum	int unsigned	NO
//t_date	date	NO
//successful	tinyint	NO
//t_descript	tinytext	NO