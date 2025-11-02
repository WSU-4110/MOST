#include "database2.h"
#include <QDir>
#include <QSqlQuery>
#include <QFile>
#include <QDebug>
#include <QApplication>
#include <qsqlerror.h>

Database2::Database2() {
}
Database2::~Database2() {
    closeDatabase();
}
// Make sure that directories exist
bool Database2::createSaveDirectories() {
    QDir cardsDir(cardsPath);
    if (!cardsDir.exists()) {
        if (!cardsDir.mkpath(cardsPath)) {
            qDebug() << "Failed to create directory"<<cardsPath;
            return false;
        }
    }
    QDir quizDir(quizPath);
    if (!quizDir.exists()) {
        if (!cardsDir.mkpath(quizPath)) {
            qDebug() << "Failed to create directory"<<quizPath;
            return false;
        }
    }
    return true;
}

// Create database for either flashcards or quiz type
bool Database2::createDatabase(QString dbNameInput) {
    dbName=dbNameInput;
    if (!createSaveDirectories()) {
        return false;
    }

    QDir dir;
    if (dbName.startsWith("flashcards_")) {
        dir.setPath(cardsPath);
    } else if (dbName.startsWith("quiz_")) {
        dir.setPath(quizPath);
    } else {
        qDebug() << "Error: dbName does not start with 'flashcards_' or 'quiz_'";
        return false;
    }

    QString dbPath = dir.filePath(dbName);
    bool alreadyExists = QFile::exists(dbPath);
    db = QSqlDatabase::addDatabase("QSQLITE", dbName);
    db.setDatabaseName(dbPath);
    if(!db.open()){
        qDebug()<<"failed to open database: "<< db.lastError().text();
        return false;
    }
    if(!alreadyExists){
        QSqlQuery query(db);
        if(dbName.startsWith("flashcards_")){
            if(!query.exec("CREATE TABLE IF NOT EXISTS flashcards (id INTEGER PRIMARY KEY AUTOINCREMENT, question TEXT, answer TEXT)"))
                qDebug() << "Failed to create flashcards table:" << query.lastError().text();
        } else if (dbName.startsWith("quiz_")) {
            if (!query.exec("CREATE TABLE IF NOT EXISTS quiz (id INTEGER PRIMARY KEY AUTOINCREMENT, question TEXT, answer1 TEXT, answer2 TEXT, answer3 TEXT, answer4 TEXT, correct INTEGER)"))
                qDebug() << "Failed to create quiz table:" << query.lastError().text();
        }
    }
    return true;
}


/*
    QFile dbFile(dbPath);
    if (dbFile.exists()) {
        qDebug() << "Database" << dbName << "already exists.";
    }
    else {
        qDebug() << dbName << "doesn't exist. Creating...";
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(dbPath);
        if (!db.open()) {
            qDebug() << "Error: Could not open" << dbName;
            return false;
        }

        QSqlQuery query;

        if (dbName.startsWith("flashcards_")) {
            if (!query.exec("CREATE TABLE IF NOT EXISTS flashcards (id INTEGER PRIMARY KEY, front TEXT, back TEXT)")) {
                qDebug() << "Failed to create flashcard table";
            }

        } else if (dbName.startsWith("quiz_")) {
            if (!query.exec("CREATE TABLE IF NOT EXISTS quiz (id INTEGER PRIMARY KEY, question TEXT, answer1 TEXT, answer2 TEXT, answer3 TEXT, answer4 TEXT, correct INTEGER)")) {
                qDebug() << "Failed to create quiz table";
            }

        } else {
            qDebug() << "Error: dbName does not start with 'flashcards_' or 'quiz_'";
            return false;
        }
        qDebug() << "Created database" << dbName;
    }
    return true;
}
*/
bool Database2::openDatabase(QString dbNameInput) {
    dbName=dbNameInput;
    if(QSqlDatabase::contains(dbName)){
        db = QSqlDatabase::database(dbName);
    }
    else{
        db = QSqlDatabase::addDatabase("SQLITE",dbName);
    }

    QDir dir;
    if (dbName.startsWith("flashcards_")) {
        dir.setPath(cardsPath);
    } else if (dbName.startsWith("quiz_")) {
        dir.setPath(quizPath);
    } else {
        qDebug() << "Error: dbName does not start with 'flashcards_' or 'quiz_'";
        return false;
    }

    QString dbPath = dir.filePath(dbName);
    db.setDatabaseName(dbPath);

    if (!db.open()) {
        qDebug() << "Failed to open database";
        return false;
    }
    qDebug() << "Opened database "+ dbName;
    return true;
}

void Database2::closeDatabase() {
    if (db.isOpen()) {
        QString name = db.connectionName();
        db.close();
        QSqlDatabase::removeDatabase(name);
        qDebug() << "Closed database" + dbName;
    }
}
