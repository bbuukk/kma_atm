
#include "DB.h"
#include "Acc.h"
#include "CheckAcc.h"
#include "Repo.h"
#include "SvAcc.h"
#include "LocAcc.h"

#include <QtCore/QCoreApplication>

int main(int argc, char* argv[]) {
	QCoreApplication a(argc, argv);

	DB db;

	Repo repo(db.getConnection());



	Acc acc(repo.getAccInfo(2));
	
	std::cout << "=========Acc=========" << std::endl;
	std::cout << acc << "\n";
	std::cout << "==================";

	

	system("pause");
	return a.exec();
}