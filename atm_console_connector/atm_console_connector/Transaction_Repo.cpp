#include "Repo.h"

Transaction& Repo::get_transaction(std::string trans_num) {

    std::string query = "call get_transaction(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement(query));
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

bool Repo::transact(
    std::string atm_num,
    std::string acc_from,
    std::string acc_to,
    size_t sum,
    std::string description) {

    std::string query = "call transact(?,?,?,?,?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement(query));
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

bool Repo::withdraw(
    std::string atm_num,
    std::string acc_from,
    size_t sum,
    std::string description) {

    std::string query = "call withdraw(?,?,?,?,?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement(query));
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


//in atm_num nvarchar(10),
//in acc_from nvarchar(30),
//in sum int unsigned,
//in descript tinytext)



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