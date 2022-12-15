
#include "Bank.h"
#include "Account.h"
#include "clnt_ATM.h"
#include "Transaction.h"

#include <ostream>
#include <QtCore/QCoreApplication>
#include <string>
#include <iostream>

class Shape {
public:
	virtual double area() = 0;
private:
};

int main(int argc, char* argv[]) {
	QCoreApplication a(argc, argv);

	//banking account for tests
	//1	01234	840	20	1	1	1250	2020 - 12 - 01	0	2500	0.98	3.7485048652
	
	std::string account_num = "01234";
	mdls::Account& account = Bank::get_account(account_num);
	std::cout << account << "\n";

	std::cout << "|-----------------------------------------------------------|" << "\n";

	//initializating of ATM
	std::string atm_num = "01234";
	clnt::ATM atm(atm_num, account);

	std::cout << std::boolalpha;
	std::cout << atm.withdraw(30) << "\n";
	std::cout << atm.deposit(30) << "\n";
	std::cout << atm.transfer("43210", 10, "Never know, never know") << "\n";
	std::cout << std::noboolalpha;

	std::cout << "|-----------------------------------------------------------|" << "\n";

	std::string acc_balance = std::to_string(atm.balance());
	std::cout << "Account balance is: " << acc_balance << "\n";

	std::cout << "|-----------------------------------------------------------|" << "\n";

	//show card number if card not null 
	std::cout << atm.card() << "\n";

	std::cout << "|-----------------------------------------------------------|" << "\n";

	//info about atm location (city, street)
	std::string info = atm.info();
	std::cout << info << "\n";

	std::cout << "|-----------------------------------------------------------|" << "\n";

	std::string acc_info = atm.account_info();
	std::cout << acc_info << "\n";

	std::cout << "|-----------------------------------------------------------|" << "\n";

	for (mdls::Transaction& trans : atm.transactions_history()) {
		std::cout << trans << "\n";
	}

	std::cout << "|-----------------------------------------------------------|" << "\n";

	std::cout << std::boolalpha;
	std::cout << atm.block_account() << "\n";
	std::cout << atm.unblock_account() << "\n";
	std::cout << std::noboolalpha;

	std::cout << "|-----------------------------------------------------------|" << "\n";

	system("pause"); 
	return a.exec();
}

