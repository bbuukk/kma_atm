
#include "DB.h"
#include "Account.h"
#include "Checking.h"
#include "Repo.h"
#include "Savings.h"
#include "LOC.h"
#include "ATM.h"
#include "Card.h"

#include <QtCore/QCoreApplication>

int main(int argc, char* argv[]) {
	QCoreApplication a(argc, argv);

	DB db;

	Repo repo(db.get_connection());

	//Account acc(repo.get_acc(2));
	//
	//std::cout << "=========Account=========" << std::endl;
	//std::cout << acc << "\n";
	//std::cout << "==================";

	//Account acc2(repo.get_acc(1));
	//
	//std::cout << "=========Account=========" << std::endl;
	//std::cout << acc2 << "\n";
	//std::cout << "==================";

	//Office off(repo.get_acc_off(2));
	//
	//std::cout << "=========Office=========" << std::endl;
	//std::cout << off << "\n";
	//std::cout << "==================";

	Card card = repo.get_card("5313532532254855");

	std::cout << card << "\n";

	system("pause");
	return a.exec();
}