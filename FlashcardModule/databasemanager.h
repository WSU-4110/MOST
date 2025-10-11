#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QString>

class DatabaseManager
{
public:
    static DatabaseManager& instance();         // Singleton accessor

    bool connect(const QString& dbPath);        // Opens DB connection
    bool setupTables();                         // Creates tables if needed
    QSqlDatabase database() const;              // Accessor for DB

private:
    DatabaseManager() = default;                // Constructor is private
    ~DatabaseManager() = default;
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;

    QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_H
