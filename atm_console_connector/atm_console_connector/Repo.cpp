
#include "Repo.h"

#include <ostream>


Repo::Repo() 
    : con(nullptr) {};

Repo::Repo(sql::Connection*& con) 
    : con(con) {};

Repo::~Repo() {};

void Repo::getAccInfo(int acc_id) {

    pstmt.reset(con->prepareStatement("call get_acc_info(?)"));
    pstmt->setInt(1, acc_id);
    
    res.reset(pstmt->executeQuery());



    while (res->next()) {
        std::cout << "acc_num =" << res->getString("acc_num") << " ";
        std::cout << "open_date = " << res->getString("open_date") << " ";
        std::cout << "balance = " << res->getDouble("balance") << "\n";
        std::cout << "is_blocked = " << res->getBoolean("is_blocked") << "\n";
        //std::cout << "last_name = " << res->getBoolean("name") << "\n";

    }
        
        

}
