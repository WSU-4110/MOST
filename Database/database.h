#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QtSql/QSqlDatabase>
#include <QApplication>

class Database {
public:
    QString dirPath = QCoreApplication::applicationDirPath();
    QString savesPath = dirPath + "/Saves";
    QString cardsPath = savesPath + "/Cards";
    QString quizPath = savesPath + "/Quiz";

    Database();
    ~Database();

    bool createSaveDirectories();
    bool createDatabase(QString dbName);
    bool openDatabase(QString dbName);
    void closeDatabase();

protected:
    QSqlDatabase db;
    QString dbName;
};

#endif // DATABASE_H

