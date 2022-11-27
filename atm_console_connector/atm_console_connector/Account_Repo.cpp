#include "Bank.h"

#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include "LOC.h"
#include "Office.h"
#include "Transaction.h"
#include "Card.h"

#define CHECKING 1
#define STUDENT_CHECKING 2
#define SAVINGS 3
#define LOCC 4

class bad_account : public std::exception {};

mdls::Account& Bank::get_account(const std::string& num){

    std::string query = "call acc_by_num(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        Bank::get_connection()->prepareStatement(query));
    pstmt->setString(1, num);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    return extract_account(res, pstmt);
}

mdls::Account& Bank::extract_account(
    std::unique_ptr<sql::ResultSet>& res,
    std::unique_ptr<sql::PreparedStatement>& pstmt) {

    mdls::Account* account(nullptr);

    do {
        while (res->next()) {
            mdls::Account acc(
                res->getString("num"),
                res->getUInt("dgt_code"),
                res->getDouble("balance"),

                res->getString("open_date"),
                res->getBoolean("is_blocked"),
                res->getDouble("atm_fee"),
                res->getDouble("intrest"),

                res->getUInt("id"),
                res->getUInt("off_id"),
                res->getUInt("clnt_id"),
                res->getUInt("acc_type"));

            switch (acc.type()) {
            case CHECKING:
            case STUDENT_CHECKING:
                account = new mdls::Checking(
                    acc, res->getUInt("overdraft_lim"));
                break;
            case SAVINGS:
                account = new mdls::Savings(
                    acc, res->getUInt("trans_lim"));
                break;
            case LOCC:
                account = new mdls::LOC(
                    acc,
                    res->getUInt("crd_taken"),
                    res->getUInt("loc_lim"),
                    res->getUInt("crd_return"));
                break;
            default:
                throw bad_account();
            }
        }
    } while (pstmt->getMoreResults());

    return *account;
};

mdls::Account& Bank::get_account(const mdls::Card& card) {

    std::string query = "call acc_by_card_id(?);";
    
    std::unique_ptr<sql::PreparedStatement> pstmt(
        Bank::get_connection()->prepareStatement(query));
    pstmt->setUInt(1, card.id());

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    return extract_account(res, pstmt);
};

mdls::Office& Bank::get_acc_office(const size_t id) {
    
    std::string query = "call acc_office(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        Bank::get_connection()->prepareStatement(query));
    pstmt->setUInt(1, id);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    mdls::Office* off;

    do {
        while (res->next()) {
            off = new mdls::Office(
                res->getBoolean("head_off"),
                res->getString("city"),
                res->getString("street"),
                res->getString("postal"));
        }
    } while (pstmt->getMoreResults());

    return *off;
}

void Bank::block_account(const size_t id) {

    std::string query = "call block_acc(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        Bank::get_connection()->prepareStatement(query));
    pstmt->setUInt(1, id);

    pstmt->execute();
}

void Bank::unblock_account(const size_t id) {

    std::string query = "call unblock_acc(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        Bank::get_connection()->prepareStatement(query));
    pstmt->setUInt(1, id);

    pstmt->execute();
}

std::vector <mdls::Transaction>& Bank::get_transactions(const mdls::Account& acc) {

    std::string query("call acc_trans(?);");

    std::unique_ptr<sql::PreparedStatement> pstmt(
        Bank::get_connection()->prepareStatement(query));
    pstmt->setUInt(1, acc.id());

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    std::vector <mdls::Transaction>* transs(new std::vector<mdls::Transaction>);

    do {
        while (res->next()) {
            mdls::Account acc_from(res->getString("acc_from"));
            mdls::Account acc_to(res->getString("acc_to"));

            (*transs).push_back(
                mdls::Transaction(
                res->getString("num"),
                std::make_unique<mdls::Account>(acc_to),
                std::make_unique<mdls::Account>(acc_from),
                res->getUInt("sum"),

                res->getString("date"),
                res->getBoolean("is_successful"),
                res->getString("atm_num"),
                res->getString("descript")));
        }
    } while (pstmt->getMoreResults());

    return *transs;
}

size_t Bank::get_acc_type(const std::string& num) {

    std::string query = "call acc_type(?);";

    std::unique_ptr<sql::PreparedStatement> pstmt(
        Bank::get_connection()->prepareStatement(query));
    pstmt->setString(1, num);
    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    size_t acc_type(0);

    do {
        while (res->next()) {
            acc_type = res->getUInt("acc_type");
        }
    } while (pstmt->getMoreResults());

    return acc_type;
}


