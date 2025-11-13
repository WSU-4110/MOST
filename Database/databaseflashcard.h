#ifndef DATABASEFLASHCARD_H
#define DATABASEFLASHCARD_H

#include "database.h"
#include <QVector>
#include <QString>

struct Flashcard {
    int id;
    QString front;
    QString back;
};

class DatabaseFlashcard : public Database
{
public:
    DatabaseFlashcard();

    bool createFlashcardSet(QString setName);
    QVector<Flashcard> getAllFlashcards(QString dbName);
    bool addFlashcard(const QString &dbName, const QString &front, const QString &back);
    bool deleteFlashcard(QString dbName, int id);
    int getFlashcardCount(QString dbName);
};

#endif // DATABASEFLASHCARD_H
