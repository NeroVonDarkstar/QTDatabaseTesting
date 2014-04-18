#include <QCoreApplication>
#include <iostream>
#include <QTextStream>
#include <QtDebug>
#include <QFile>
#include <QIODevice>
#include <QtSql>
#include <QCoreApplication>
#include <QSslCipher>
#include <QSslSocket>
#include <iostream>
#include <QTextStream>
#include <QDebug>
#include <QByteArray>
#include <QFile>
#include <QIODevice>
#include <QSslKey>
#include <QSslCertificate>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSsl>
#include <QHostAddress>

using namespace std;

bool createConnection();
void adduser();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << "Starting new database" << endl;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    string ubuffer = "";
    string pbuffer = "";
    db.setConnectOptions();
    db.setDatabaseName("test");
    db.setHostName("ephesus.cs.cf.ac.uk");
    db.setPort(3306);
    cout << "Please enter a username" << endl;
    cin >> ubuffer;
    QString username = QString::fromStdString(ubuffer);
    db.setUserName(username);
    cout << "Please enter a password" << endl;
    cin >> pbuffer;
    QString password = QString::fromStdString(pbuffer);
    db.setPassword(password);
    bool x = db.open();
    if (x == true){
        cout << "Connection successful" << endl;
        //adduser();
    }
    else{
        cout << "not yet jim" << endl;
    }
    return a.exec();
}
