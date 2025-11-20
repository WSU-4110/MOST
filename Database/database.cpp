#include "database.h"
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDebug>
#include <QApplication>

Database::Database() {

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
        QString connectionName = dbPath;
        if(QSqlDatabase::contains(connectionName)) {
            db = QSqlDatabase::database(connectionName);
        } else {
            db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
            db.setDatabaseName(dbPath);
            if (!db.open()) {
                qDebug() << "Error: Could not open" << dbName << ":" << db.lastError().text();
                return false;
            }
        }

        QSqlQuery query(db);
        query.exec("PRAGMA foreign_keys = ON;");

        if (dbName.startsWith("flashcards_")) {
            if (!query.exec("CREATE TABLE IF NOT EXISTS flashcards (id INTEGER PRIMARY KEY, front TEXT, back TEXT)")) {
                qDebug() << "Failed to create flashcard table";
            }

        } else if (dbName.startsWith("quiz_")) {
            // The quiz database will have 3 tables questions, answers, correct
            if (!query.exec("CREATE TABLE IF NOT EXISTS questions (id INTEGER PRIMARY KEY, question TEXT)")) {
                qDebug() << "Failed to make quiz db questions table: " << query.lastError().text();
            }
            if (!query.exec("CREATE TABLE IF NOT EXISTS answers (id INTEGER PRIMARY KEY, question_id INTEGER, answer TEXT, FOREIGN KEY (question_id) REFERENCES questions(id) ON DELETE CASCADE)")) {
                qDebug() << "Failed to make quiz db answers table:" << query.lastError().text();
            }
            if (!query.exec("CREATE TABLE IF NOT EXISTS correct (question_id INTEGER, answer_id INTEGER, PRIMARY KEY (question_id, answer_id), FOREIGN KEY (question_id) REFERENCES questions(id) ON DELETE CASCADE, FOREIGN KEY (answer_id) REFERENCES answers(id) ON DELETE CASCADE)")) {
                qDebug() << "Failed to make quiz db correct table" << query.lastError().text();
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
    QString connectionName = "CONN_" + QFileInfo(dbPath).completeBaseName();
    qDebug() << "database.cpp / connectionName is" << connectionName;

    if (QSqlDatabase::contains(connectionName)) {
        db = QSqlDatabase::database(connectionName);
    }
    else {
        db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
        db.setDatabaseName(dbPath);
    }

    if (!db.isOpen()) {
        if(!db.open()) {
            qDebug() << "Failed to open database";
            return false;
        }
    }
    qDebug() << "Opened database " + dbName;
    return true;
}

void Database::closeDatabase() {
    if (db.isOpen()) {
        QString connectionName = db.connectionName();
        db.close();

        qDebug() << "Closed database " + dbName;
    } else {
        qDebug() << "No database open to close";
    }
}

