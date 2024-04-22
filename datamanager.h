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

void saveCharacter(std::string _name, int _xp, int _level, int _hp, int _strength){
    QString name = QString::fromStdString(_name);

    QSqlQuery query;
    query.prepare("INSERT INTO gametest (_name, _xp, _level, _hp, _strength) VALUES(:name, :xp, :level, :hp, :strength)");
    query.bindValue(":name", name);
    query.bindValue(":xp", _xp);
    query.bindValue(":level", _level);
    query.bindValue(":hp", _hp);
    query.bindValue(":strength", _strength);

    if (!query.exec()) {
        qWarning() << "Failed to insert test data:" << query.lastError().text();
    }


}

void deleteCharacter(std::string _name){
    QString name = QString::fromStdString(_name);

    QSqlQuery query;
    query.prepare("DELETE FROM gametest WHERE _name = :name");
    query.bindValue(":name", name);

    if (!query.exec()) {
        qDebug() << "Failed to delete character:" << query.lastError().text();

    }
    qDebug() << "Character deleted successfully.";
}



#endif // DATAMANAGER_H
