#include "Repo.h"

Transaction& Repo::get_transaction(std::string trans_num) {

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement("call get_transaction(?);"));
    pstmt->setString(1, trans_num);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    Transaction* trans;

    do {
        while (res->next()) {
            trans = new Transaction(

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

//Transaction(
//    std::string num,
//    std::string acc_from,
//    std::string acc_to,
//    size_t sum, std::string date,
//    bool successful, std::string descript);

//select t.num,
//a1.num as acc_from,
//a2.num as acc_to,
//t.sum, t.date,
//t.successful,
//t.atm_num,
//t.descript

//trans_id	int unsigned	NO	PRI		auto_increment
//mach_id	int unsigned	YES	MUL
//acc_from	int unsigned	NO	MUL
//acc_to	int unsigned	YES	MUL
//t_sum	int unsigned	NO
//t_date	date	NO
//successful	tinyint	NO
//t_descript	tinytext	NO