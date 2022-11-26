
#include "Bank.h"
#include "Account.h"
#include "ATM_clnt.h"

#include <ostream>
#include <QtCore/QCoreApplication>

int main(int argc, char* argv[]) {
	QCoreApplication a(argc, argv);

	/* 1	01234	840	20	1	1	1250	2020 - 12 - 01	0	2500	0.98	3.7485048652*/

	std::string account_number("");

	std::cout << "Please enter account number: ";
	std::cin >> account_number;
	std::cout << "\n";
	
	mdls::Account account(account_number);

	std::cout << account << "\n";

	/*clnt::ATM atm;*/

	system("pause");
	return a.exec();
}
