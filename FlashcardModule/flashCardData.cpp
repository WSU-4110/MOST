#include "flashCardData.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QApplication>
#include <QFile>

// Create a database file flashCard_flashCardSetName.db
flashCardData::flashCardData(QString flashCardSetNameInput) {
    CardSetName = flashCardSetNameInput;
    dbName = "flashCard_" + CardSetName + ".db";

    createDatabase(dbName);
    openDatabase(dbName);
}

// Add a flashCard question, its answer
bool flashCardData:: addCard(QString question, QString answer) {
    QSqlQuery query;
    query.prepare("INSERT INTO flashCard (question, answer)"
                  "VALUES (:question, :answer)");
    query.bindValue(":question", question);
    query.bindValue(":answer", answer);


    if (!query.exec()) {
        qDebug() << "Error adding flashcard question";
        return false;
    }
    return true;
}

// Gets all entries in database and returns a QList of entries with QList of questions and answers for that entry
QList<QList<QVariant>> flashCardData::getAllCardEntries() {
    QList<QList<QVariant>> questions;
    \
        QSqlQuery query("SELECT * FROM flashCard");
    while (query.next()) {
        QList<QVariant> question;
        question.append(query.value("id"));
        question.append(query.value("question"));
        question.append(query.value("answer"));
        questions.append(question);
    }
    return questions;
}

// Gets a single quiz entry by id and returns the QList of question and answers
QList<QVariant> flashCardData::getCardEntry(int id) {
    QList<QVariant> entry;

    QSqlQuery query;
    query.prepare("SELECT * FROM flashCard WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        entry.append(query.value("id"));
        entry.append(query.value("question"));
        entry.append(query.value("answer"));
    }
    return entry;
}

// Edits a single quiz entry by its id
bool flashCardData::editCardEntry(int id, QString question, QString answer) {
    QSqlQuery query;
    query.prepare("UPDATE flashCard SET question = :question, answer = :answer  "
                  "WHERE id = :id");
    query.bindValue(":question", question);
    query.bindValue(":answer1", answer);
    query.bindValue(":id", id);  // Update entry with this id

    if (!query.exec()) {
        qDebug() << "Failed to update flashCard entry";
        return false;
    }

    qDebug() << "flashCard entry updated successfully";
    return true;
}

// Get the name of the flashcardset
QString flashCardData::getName() {
    return CardSetName;
}

// to add later
// delete question
// is true
