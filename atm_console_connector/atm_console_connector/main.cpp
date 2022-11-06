
#include "Account.h"
#include "Checking.h"
#include "Savings.h"
#include "LOC.h"
#include "ATM.h"
#include "Card.h"
#include "Client.h"
#include "Transaction.h"
#include "Bank.h"

#include "ATM_sbs.h"

#include <QtCore/QCoreApplication>

int main(int argc, char* argv[]) {
	QCoreApplication a(argc, argv);

	/*sbs::ATM atm;*/

	mdls::Account account("01234");

	std::cout << account << "\n";


	system("pause");
	return a.exec();
}
