#include "Repo.h"

Office& Repo::get_acc_off(size_t acc_id){

    std::unique_ptr<sql::PreparedStatement> pstmt(
        this->con->prepareStatement("call get_acc_off(?);"));
    pstmt->setInt(1, acc_id);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    Office* off;

    do {
        while (res->next()) {
            off = new Office(0, 
                res->getBoolean("head_off"),
                res->getString("off_city"),
                res->getString("off_street"),
                res->getString("postal"));
        }
    } while (pstmt->getMoreResults());

    return *off;
}

//todo
//off_id	int unsigned	NO	PRI		auto_increment
//head_off	tinyint	NO
//off_city	varchar(100)	NO
//off_street	varchar(100)	NO
//postal	varchar(10)	NO
