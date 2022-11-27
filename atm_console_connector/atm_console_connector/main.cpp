
#include "Bank.h"
#include "Account.h"
#include "ATM_clnt.h"
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
	/* 1	01234	840	20	1	1	1250	2020 - 12 - 01	0	2500	0.98	3.7485048652*/

	/*std::string account_number("");

	std::cout << "Please enter account number: ";
	std::cin >> account_number;
	std::cout << "\n";*/
	
	mdls::Account& acc2 = Bank::get_account("01234");
	std::cout << acc2 << "\n";

	clnt::ATM atm("01234", acc2);
	atm.withdraw(30);
	atm.deposit(30);
	atm.transfer("43210", 300, "For cocaine");

	std::string info = atm.info();
	std::cout << info << "\n";

	std::string acc_info = atm.account_info();
	std::cout << acc_info << "\n";

	for (mdls::Transaction& trans : atm.transactions_history()) {
		std::cout << trans << "\n";
	}



	
	

	system("pause");
	return a.exec();
}

