
#include "Bank.h"
#include "Account.h"
#include "ATM_clnt.h"

#include <ostream>
#include <QtCore/QCoreApplication>

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
	

	/*clnt::ATM atm;*/

	system("pause");
	return a.exec();
}

