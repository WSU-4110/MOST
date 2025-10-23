#include "database.h"
#include <QDir>
#include <QSqlQuery>
#include <QFile>
#include <QDebug>
#include <QApplication>

Database::Database() {
    db = QSqlDatabase::addDatabase("QSQLITE");
}

Database::~Database() {
    closeDatabase();
}

// Make sure that directories exist
bool Database::createSaveDirectories() {
    QDir cardsDir(cardsPath);
    if (!cardsDir.exists()) {
        qDebug() << cardsPath << "does not exists, creating directory...";
        if (!cardsDir.mkpath(cardsPath)) {
            qDebug() << "Failed to create directory";
            return false;
        }
    }
    QDir quizDir(quizPath);
    if (!quizDir.exists()) {
        qDebug() << quizPath << "does not exists, creating directory";
        if (!cardsDir.mkpath(quizPath)) {
            qDebug() << "Failed to create directory";
            return false;
        }
    }
    return true;
}

// Create database for either flashcards or quiz type
bool Database::createDatabase(QString dbName) {
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

bool Database::openDatabase(QString dbName) {
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
    qDebug() << "Opened database " + dbName;
    return true;
}

void Database::closeDatabase() {
    if (db.open()) {
        db.close();
        QSqlDatabase::removeDatabase("QSQLITE");
        qDebug() << "Closed database" + dbName;
    }
}
