#ifndef DATABASE2_H
#define DATABASE2_H

#include <QString>
#include <QSqlDatabase>
#include <QApplication>

class Database2 {
public:
    QString dirPath = QCoreApplication::applicationDirPath();
    QString savesPath = dirPath + "/Saves";
    QString cardsPath = savesPath + "/Cards";
    QString quizPath = savesPath + "/Quiz";

    Database2();
    ~Database2();

    bool createSaveDirectories();
    bool createDatabase(QString dbNameInput);
    bool openDatabase(QString dbNameInput);
    void closeDatabase();

protected:
    QSqlDatabase db;
    QString dbName;
};

#endif // DATABASE2_H


