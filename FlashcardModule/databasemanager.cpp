#include "DatabaseManager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager instance;
    return instance;
}

bool DatabaseManager::connect(const QString& dbPath)
{
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        m_db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        m_db = QSqlDatabase::addDatabase("QSQLITE");
    }

    m_db.setDatabaseName(dbPath);
    if (!m_db.open()) {
        qDebug() << "Database error:" << m_db.lastError().text();
        return false;
    }

    return true;
}

bool DatabaseManager::setupTables()
{
    QSqlQuery query(m_db);
    QString createTable = R"(
        CREATE TABLE IF NOT EXISTS flashcards (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            set_name TEXT NOT NULL,
            question TEXT NOT NULL,
            answer TEXT NOT NULL
        )
    )";

    if (!query.exec(createTable)) {
        qDebug() << "Failed to create table:" << query.lastError().text();
        return false;
    }

    return true;
}

QSqlDatabase DatabaseManager::database() const
{
    return m_db;
}
