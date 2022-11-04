
#include "Repo.h"

#include <ostream>




Repo::Repo() 
    : con(nullptr) {};

Repo::Repo(sql::Connection*& con) 
    : con(con) {};

Repo::~Repo() {};

Acc* Repo::getAccInfo(int acc_id) {

    this->pstmt.reset(this->con->prepareStatement("call get_acc_info(?)"));
    this->pstmt->setInt(1, 1);
    
    res.reset(this->pstmt->executeQuery());

    res->next();

    std::string acc_num(res->getString("acc_num").c_str());
    double balance(res->getDouble("balance"));
    std::string open_date(res->getString("open_date").c_str());
    bool is_blocked(res->getBoolean("is_blocked"));    

    std::cout << "PRE: acc_num =" << acc_num << "\n";
    std::cout << "PRE: balance = " << balance << "\n";
    std::cout << "PRE: open_date = " << open_date << "\n";
    std::cout << "PRE: is_blocked = " << is_blocked << "\n";

    //Acc acc( 0, 0, 0, 0, 0, acc_num, balance, open_date, is_blocked, 0 ,0 );





   /* Acc acc( 0, 0, 0, 0, 0,
                res->getString("acc_num").c_str(),
                res->getDouble("balance"),
                res->getString("open_date").c_str(),
                res->getBoolean("is_blocked"),
                0 ,0);*/

    return new Acc (0, 0, 0, 0, 0, acc_num, balance, open_date, is_blocked, 0, 0);
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
