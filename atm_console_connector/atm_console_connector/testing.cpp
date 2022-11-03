
//
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
///*
//         The JDBC API throws three different exceptions:
//
//       - sql::MethodNotImplementedException (derived from sql::SQLException)
//       - sql::InvalidArgumentException (derived from sql::SQLException)
//       - sql::SQLException (derived from std::runtime_error)
//*/
//
//
////for demonstration only. never save your password in the code!
//const std::string server = "tcp://automatedmachinetellerdb.cuccuzhaeiiv.eu-central-1.rds.amazonaws.com:3306";
//const std::string username = "tgd_nWaA";
//const std::string password = "tgd32tgdWA";
//
//int main(int argc, char* argv[])
//{
//    QCoreApplication a(argc, argv);
//
//    std::unique_ptr<sql::Connection> con;
//
//    std::unique_ptr<sql::Driver> driver;
//
//    try
//    {
//        driver = std::make_unique<sql::Driver>(get_driver_instance());
//        con = driver->connect(server, username, password);
//
//        std::cout << "Successfully connected" << "\n";
//    }
//    catch (sql::SQLException& e)
//    {
//        std::cout << "Could not connect to server. Error message: " << e.what() << "\n";
//        system("pause");
//        exit(1);
//    }
//
//    con->setSchema("atm");
//
//    std::uniequ<sql::PreparedStatement>  pstmt;
//    std::auto_ptr< sql::ResultSet > res;
//
//    pstmt.reset(con->prepareStatement("CALL get_data()"));
//    res.reset(pstmt->executeQuery());
//
//    for (;;)
//    {
//        while (res->next()) {
//            cout << "Name: " << res->getString("Name")
//                << " Population: " << res->getInt("Population")
//                << endl;
//        }
//        if (pstmt->getMoreResults())
//        {
//            res.reset(pstmt->getResultSet());
//            continue;
//        }
//        break;
//    }
//
//    delete res;
//    delete stmt;
//    delete con;
//
//    system("pause");
//    return a.exec();
//}




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



