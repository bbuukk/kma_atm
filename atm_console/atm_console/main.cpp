#include <iostream>
#include <stdio.h> 

#include <QtCore/QCoreApplication>

#include <SQLAPI.h> 

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SAConnection con;

    try {
        con.Connect(_TSA("automatedmachinetellerdb.cuccuzhaeiiv.eu-central-1.rds.amazonaws.com"), _TSA("tgd_nWaA"), _TSA("tgd32tgdWA"), SA_Oracle_Client);
        printf("We are connected!\n");

 

        con.Disconnect();
        printf("We are disconnected!\n");
    }
    catch (SAException& x) {
        con.Rollback();
        printf("%s\n", x.ErrText().GetMultiByteChars());
    }

    return a.exec();
}
