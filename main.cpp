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

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << "Starting new database" << endl;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    string ubuffer = "";
    string hbuffer = "";
    string pbuffer = "";
    string dbuffer = "";
    cout << "Please enter a database name" << endl;
    cin >> dbuffer;
    QString database = QString::fromStdString(dbuffer);
    db.setDatabaseName(database);

    cout << "Please enter a hostname" << endl;
    cin >> hbuffer;
    QString hostname = QString::fromStdString(hbuffer);
    db.setHostName(hostname);
    cout << "Please enter a username" << endl;
    cin >> ubuffer;
    QString username = QString::fromStdString(ubuffer);
    db.setUserName(username);
    cout << "Please enter a password" << endl;
    cin >> pbuffer;
    QString password = QString::fromStdString(pbuffer);
    db.setPassword(password);

    bool ok = db.open();
    if (ok == true){
        cout << "Connection successful" << endl;
    }
    else{
        cout << " Haven't Connected!" << endl;
    }
    return a.exec();
}
