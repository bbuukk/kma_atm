
#include "DB.h"
#include "Acc.h"
#include "CheckAcc.h"
#include "Repo.h"

#include <QtCore/QCoreApplication>


const std::string server = "tcp://automatedmachinetellerdb.cuccuzhaeiiv.eu-central-1.rds.amazonaws.com:3306";
const std::string username = "tgd_nWaA";
const std::string password = "ba9s5JNgN3d4AkQ";

int main(int argc, char* argv[]) {
	QCoreApplication a(argc, argv);

	DB db(server, username, password);

	Repo repo(db.getConnection());


	repo.test(1); 

	repo.test(1);

	/*Acc acc(repo.getAccInfo(2));*/
	
	//std::cout << "=========Acc=========" << std::endl;
	//std::cout << acc << "\n";
	//std::cout << "==================";

	//Acc acc2(repo.getAccInfo(2));

	//std::cout << "=========Acc=========" << std::endl;
	//std::cout << acc2 << "\n";
	//std::cout << "==================";

	//CheckAcc checking(acc2, 0);

	//std::cout << "=======Checking======" << std::endl;
	//std::cout << checking << "\n";
	//std::cout << "==================";

	system("pause");
	return a.exec();
}