
#include "Repo.h"

#include <ostream>




Repo::Repo() 
    : con(nullptr) {};

Repo::Repo(sql::Connection*& con) 
    : con(con) {};

Repo::~Repo() {};

Acc& Repo::getAccInfo(int acc_id) {

    this->pstmt.reset(this->con->prepareStatement("call get_acc_info(?)"));
    this->pstmt->setInt(1, acc_id);
    
    res.reset(this->pstmt->executeQuery());


    std::string acc_num = res->getString("acc_num");
    double balance = res->getDouble("balance");
    std::string open_date = res->getString("open_date");
    bool is_blocked = res->getBoolean("is_blocked");

    std::cout << "acc_num =" << acc_num << " ";
    std::cout << "balance = " << balance << "\n";
    std::cout << "open_date = " << open_date << " ";
    std::cout << "is_blocked = " << is_blocked << "\n";

     Acc account( 0, 0, 0, 0, 0, acc_num, balance, open_date, is_blocked, 0 ,0);


   /* Acc account( 0, 0, 0, 0, 0,
                res->getString("acc_num"),
                res->getDouble("balance"),
                res->getString("open_date"),
                res->getBoolean("is_blocked"),
                0 ,0);*/

    return account;
}

//int acc_id;
//int dgt_code;
//int off_id;
//int clnt_id;
//int acc_type;
//std::string acc_num;
//double balance;
//std::string open_date;
//bool is_blocked;
//double atm_fee;
//double intrest;
