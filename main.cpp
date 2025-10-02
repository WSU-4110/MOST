#include "mainwindow.h"

#include <QApplication>

#include <QSqlDatabase>
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>

int main(int argc, char *argv[])

{
    QApplication a(argc, argv);

    //saves
        //flashcards
            //data 1
            //data 2... etc
        //quizzes
            //data 1
            //data 2... etc

    // sample
    // Path to the database file
    QString dbFilePath = QCoreApplication::applicationDirPath() + "/flashcards.db";

    if (!QFile::exists(dbFilePath)) {
        // If database doesnt exist make new sample
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(dbFilePath);

        if (!db.open()) {
            qDebug() << "Error: connection with database failed";
            return a.exec();
        } else {
            qDebug() << "Database created and connected";
        }

        // Create the table
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS flashcards (id INTEGER PRIMARY KEY, question TEXT, answer TEXT)");

        // Uses prepare and bind to prevent sql injection
        query.prepare("INSERT INTO flashcards (question, answer) VALUES (?, ?)");
        query.addBindValue("Front 1");
        query.addBindValue("Back 1");
        query.exec();
        query.prepare("INSERT INTO flashcards (question, answer) VALUES (?, ?)");
        query.addBindValue("Front 2");
        query.addBindValue("Back 2");
        query.exec();

        qDebug() << "Sample flashcards created";
    } else {
        qDebug() << "flashcards.db exists";
    }

    // Open the database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbFilePath);
    if (!db.open()) {
        qDebug() << "Error: connection with database failed";
        return a.exec();
    }

    MainWindow w;
    w.show();

    return a.exec();
}
