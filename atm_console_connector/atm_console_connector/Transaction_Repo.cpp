
#include <memory>

#include "Bank.h"
#include "Transaction.h"
#include "Account.h"

//Transaction(
//    const std::string& num,
//    std::unique_ptr<mdls::Account> acc_from,
//    std::unique_ptr<mdls::Account> acc_to,
//    size_t sum, const std::string& datetime,
//    bool successful, const std::string& atm_num,
//    const std::string& descript);

//TODO
mdls::Transaction& Bank::get_transaction(const std::string& trans_num) {

    std::string query = "call get_transaction(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        Bank::get_connection()->
        prepareStatement(query));

    pstmt->setString(1, trans_num);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    mdls::Transaction* trans;

    do {
        while (res->next()) {
            mdls::Account acc_from(res->getString("acc_from"));
            mdls::Account acc_to(res->getString("acc_to"));

            trans = new mdls::Transaction(
                res->getString("num"),
                std::make_unique<mdls::Account>(acc_to),
                std::make_unique<mdls::Account>(acc_from),
                res->getUInt("sum"),

                res->getString("date"),
                res->getBoolean("successful"),
                res->getString("atm_num"),
                res->getString("descript"));
        }
    } while (pstmt->getMoreResults());

    return *trans;
}

bool Bank::make_transaction(mdls::Transaction& trans) {

    if (trans.acc_from_ == nullptr) {
        return Bank::deposit(trans.atm_num(), *trans.account_to(), trans.sum());
    }
    if (trans.acc_to_ == nullptr) {
        return Bank::withdraw(trans.atm_num(), *trans.account_from(), trans.sum());
    }

    return Bank::transfer(trans.atm_num(), *trans.account_from(), *trans.account_to(), trans.sum(), trans.descript()); 
}

//Bank::deposit(atm_num(), account_to(), sum());
bool Bank::deposit(
    const std::string& atm_num,
    const mdls::Account& acc_to,
    const size_t sum) {
    try {

        std::string query = "call deposit(?,?,?);";

        std::unique_ptr<sql::PreparedStatement> pstmt(
            Bank::get_connection()->
            prepareStatement(query));

        pstmt->setString(1, atm_num);
        pstmt->setUInt(2, acc_to.id());
        pstmt->setUInt(3, sum);

        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        bool is_successful;

        do {
            while (res->next())
                is_successful = res->getBoolean("is_successful");
        } while (pstmt->getMoreResults());

        return is_successful;
    }
    catch (sql::SQLException e) {
        return false;
    }
}

bool Bank::withdraw(
    const std::string& atm_num,
    const mdls::Account& acc_from,
    const size_t sum) {

    try{
        std::string query = "call withdraw(?,?,?);";

        std::unique_ptr<sql::PreparedStatement> pstmt(
            Bank::get_connection()->
            prepareStatement(query));

        pstmt->setString(1, atm_num);
        pstmt->setUInt(2, acc_from.id());
        pstmt->setUInt(3, sum);

        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        bool is_successful;

        do {
            while (res->next())
                is_successful = res->getBoolean("is_successful");
        } while (pstmt->getMoreResults());

        return is_successful;

    }catch (sql::SQLException e) {
        return false;
    }
}


bool Bank::transfer(
    const std::string& atm_num,
    const mdls::Account& acc_from,
    const mdls::Account& acc_to,
    const size_t sum,
    const std::string& description){
    try {
        std::string query = "call transfer(?,?,?,?,?);";

        std::unique_ptr<sql::PreparedStatement> pstmt(
            Bank::get_connection()->
            prepareStatement(query));

        pstmt->setString(1, atm_num);
        pstmt->setUInt(2, acc_from.id());
        pstmt->setUInt(3, acc_to.id());
        pstmt->setUInt(4, sum);
        pstmt->setString(5, description);

        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        bool is_successful;

        do {
            while (res->next())
                is_successful = res->getBoolean("is_successful");
        } while (pstmt->getMoreResults());

        return is_successful;

    }catch (sql::SQLException e) {
        return false;
    }
}

