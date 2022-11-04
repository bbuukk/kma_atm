
#include "DB.h"
#include "Account.h"
#include "CheckAcc.h"
#include "Repo.h"
#include "SvAcc.h"
#include "LocAcc.h"

#include <QtCore/QCoreApplication>

int main(int argc, char* argv[]) {
	QCoreApplication a(argc, argv);

	DB db;

	Repo repo(db.getConnection());

	//Account acc(repo.get_acc(2));
	//
	//std::cout << "=========Account=========" << std::endl;
	//std::cout << acc << "\n";
	//std::cout << "==================";

	//Office off(repo.get_acc_off(2));
	//
	//std::cout << "=========Office=========" << std::endl;
	//std::cout << off << "\n";
	//std::cout << "==================";


	

	std::cout << repo.get_acc_atm_fee(1) << "\n";

	std::cout << repo.get_acc_type(1);





	

	system("pause");
	return a.exec();
}