
#include "DB.h"
#include "Acc.h"
#include "CheckAcc.h"
#include "Repo.h"
#include "SvAcc.h"
#include "LocAcc.h"

#include <QtCore/QCoreApplication>


const std::string server = "tcp://automatedmachinetellerdb.cuccuzhaeiiv.eu-central-1.rds.amazonaws.com:3306";
const std::string username = "tgd_nWaA";
const std::string password = "ba9s5JNgN3d4AkQ";

int main(int argc, char* argv[]) {
	QCoreApplication a(argc, argv);

	DB db(server, username, password);

	Repo repo(db.getConnection());

	Acc acc(repo.getAccInfo(2));
	
	std::cout << "=========Acc=========" << std::endl;
	std::cout << acc << "\n";
	std::cout << "==================";

	Acc acc2(repo.getAccInfo(2));

	std::cout << "=========Acc=========" << std::endl;
	std::cout << acc2 << "\n";
	std::cout << "==================";

	CheckAcc checking(acc2, 236);

	std::cout << "=======Checking======" << std::endl;
	std::cout << checking << "\n";
	std::cout << "==================";

	SvAcc savings(acc2, 278);

	std::cout << "=======Checking======" << std::endl;
	std::cout << savings << "\n";
	std::cout << "==================";

	LocAcc loc(acc2, 236,2,0);

	std::cout << "=======Checking======" << std::endl;
	std::cout << loc << "\n";
	std::cout << "==================";

	system("pause");
	return a.exec();
}