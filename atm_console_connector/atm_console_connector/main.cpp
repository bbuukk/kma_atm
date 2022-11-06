
#include "Bank.h"
#include "Account.h"
#include "ATM_clnt.h"

#include <ostream>
#include <QtCore/QCoreApplication>

int main(int argc, char* argv[]) {
	QCoreApplication a(argc, argv);

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
