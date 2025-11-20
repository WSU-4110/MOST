#include "databaseflashcard.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseFlashcard::DatabaseFlashcard() : Database() {}

bool DatabaseFlashcard::createFlashcardSet(QString setName)
{
    QString dbName = "flashcards_" + setName + ".db";
    return createDatabase(dbName);
}

QVector<Flashcard> DatabaseFlashcard::getAllFlashcards(QString dbName)
{
    QVector<Flashcard> flashcards;

    if (!openDatabase(dbName))
        return flashcards;

    QSqlQuery query("SELECT id, front, back FROM flashcards",db);
    while (query.next()) {
        Flashcard card;
        card.id = query.value(0).toInt();
        card.front = query.value(1).toString();
        card.back = query.value(2).toString();

        flashcards.append(card);
    }

    closeDatabase();
    return flashcards;
}

bool DatabaseFlashcard::addFlashcard(QString dbName, QString front,QString back){
    if (!openDatabase(dbName)) return false;

    QSqlQuery query(db);
    query.prepare("INSERT INTO flashcards (front, back) VALUES (:front, :back)");
    query.bindValue(":front", front);
    query.bindValue(":back", back);

    if(!query.exec()){
        qDebug() << "Failed to insert flashcard:" << query.lastError();
        closeDatabase();
        return false;
    }

    closeDatabase();
    return true;
}

bool DatabaseFlashcard::deleteFlashcard(QString dbName, int id)
{
    if (!openDatabase(dbName))
        return false;

    QSqlQuery query;
    query.prepare("DELETE FROM flashcards WHERE id = :id");
    query.bindValue(":id", id);

    bool success = query.exec();
    if (!success)
        qDebug() << "Failed to delete flashcard:" << query.lastError();

    closeDatabase();
    return success;
}

int DatabaseFlashcard::getFlashcardCount(QString dbName)
{
    int count = 0;
    if (!openDatabase(dbName))
        return 0;

    QSqlQuery query("SELECT COUNT(*) FROM flashcards");
    if (query.next()) {
        count = query.value(0).toInt();
    }

    closeDatabase();
    return count;
}
