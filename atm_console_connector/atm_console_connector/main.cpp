//
//#include "DB.h"
//#include "Acc.h"
//#include "Repo.h"
//
//#include <QtCore/QCoreApplication>
//
//
//const std::string server = "tcp://automatedmachinetellerdb.cuccuzhaeiiv.eu-central-1.rds.amazonaws.com:3306";
//const std::string username = "tgd_nWaA";
//const std::string password = "ba9s5JNgN3d4AkQ";
//
//int main(int argc, char* argv[]) {
//	QCoreApplication a(argc, argv);
//
//	DB db(server, username, password);
//
//	Repo repo(db.getConnection());
//
//	Acc acc = repo.getAccInfo(1);
//
//	std::cout << "Account is :" << acc;
//
//
//	system("pause");
//	return a.exec();
//}