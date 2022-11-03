//#include <QtCore/QCoreApplication>
//
//#include <stdlib.h>
//#include <iostream>
//
//#include <memory>
//
//#include "mysql_connection.h"
//#include <cppconn/driver.h>
//#include <cppconn/exception.h>
//#include <cppconn/prepared_statement.h>
//
//
////for demonstration only. never save your password in the code!
//const std::string server = "tcp://automatedmachinetellerdb.cuccuzhaeiiv.eu-central-1.rds.amazonaws.com:3306";
//const std::string username = "tgd_nWaA";
//const std::string password = "ba9s5JNgN3d4AkQ";
//
//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);
//
//
//    sql::Driver* driver;
//    sql::Connection* con;
//
//    /*std::unique_ptr<sql::Connection> con = std::make_unique<sql::Connection>();*/
//
//    sql::Statement* stmt;
//    sql::PreparedStatement* pstmt;
//
//    sql::ResultSet* res;
//
//    try
//    {
//        driver = get_driver_instance();
//        con = driver->connect(server, username, password);
//
//        std::cout << "Successfully connected" << "\n";
//    }
//    catch (sql::SQLException& e)
//    {
//        std::cout << "Could not connect to server. Error message: " << e.what() << "\n";
//        system("pause");
//        exit(1);
//        //return EXIT_FAILURE;
//    }
//
//    con->setSchema("atm");
//
//    stmt = con->createStatement();
//
//    res = stmt->executeQuery("SELECT * FROM Clients ORDER BY clnt_id ASC");
//    while (res->next()) {
//        
//        std::cout << "id = " << res->getInt("clnt_id") << " ";
//        std::cout << "first_name = " << res->getString("f_name") << " ";
//        std::cout << "last_name = " << res->getString("l_name") << "\n";
//
//    }
//
//    delete res;
//    delete stmt;
//    delete con;
//
//    system("pause");
//    return a.exec();
//}
//
//
//

///*
//     MySQL Connector/C++ throws three different exceptions:

//     - sql::MethodNotImplementedException (derived from sql::SQLException)
//     - sql::InvalidArgumentException (derived from sql::SQLException)
//     - sql::SQLException (derived from std::runtime_error)
//   */
//cout << "# ERR: SQLException in " << __FILE__;
//cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
///* what() (derived from std::runtime_error) fetches error message */
//cout << "# ERR: " << e.what();
//cout << " (MySQL error code: " << e.getErrorCode();
//cout << ", SQLState: " << e.getSQLState() << " )" << endl;

//return EXIT_FAILURE;



