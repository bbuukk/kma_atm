#include <QtCore/QCoreApplication>

#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

using namespace std;

//for demonstration only. never save your password in the code!
const string server = "tcp://automatedmachinetellerdb.cuccuzhaeiiv.eu-central-1.rds.amazonaws.com:3306";
const string username = "tgd_nWaA";
const string password = "tgd32tgdWA";

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    sql::Driver* driver;
    sql::Connection* con;

    sql::Statement* stmt;
    sql::PreparedStatement* pstmt;

    sql::ResultSet* res;

    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
        cout << "Successfully connected" << endl;
    }
    catch (sql::SQLException e)
    {
        cout << "Could not connect to server. Error message: " << e.what() << endl;
        system("pause");
        exit(1);
    }

    con->setSchema("atm");

    stmt = con->createStatement();

    res = stmt->executeQuery("SELECT client_id, first_name, last_name FROM Clients ORDER BY client_id ASC");
    while (res->next()) {
        
        cout << "id = " << res->getInt("client_id") << " ";
        cout << "first_name = " << res->getString("first_name") << " ";
        cout << "last_name = " << res->getString("last_name") << endl;

      
    }

    delete res;
    delete stmt;
    delete con;

    system("pause");
    return a.exec();
}



