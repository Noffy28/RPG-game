#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QCoreApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


bool openDatabase(QSqlDatabase& db){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/christofferbj/Workspace/Database/test1.db;");

    if (!db.open()) {
        qWarning() << "Failed to open database:" << db.lastError().text();
        return false;
    }

    qDebug() << "Database opened";
    return true;
}

void closeDatabase(QSqlDatabase& db){
    db.close();
    qDebug() << "Database closed";
}







#endif // DATAMANAGER_H
