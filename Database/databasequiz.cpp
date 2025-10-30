#include "databasequiz.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QApplication>
#include <QFile>

// Create a database file quiz_quizName.db
DatabaseQuiz::DatabaseQuiz(QString quizNameInput) {
    quizName = quizNameInput;
    dbName = "quiz_" + quizName + ".db";

    createDatabase(dbName);
    openDatabase(dbName);
}

// Add a quiz question, its answers, and which one is correct
// 'correct' should be the number of the correct answer, as in if answer3 is correct then correct value is 3
bool DatabaseQuiz::addQuizQuestion(QString question,
                                   QString answer1,
                                   QString answer2,
                                   QString answer3,
                                   QString answer4,
                                   int correct) {
    QSqlQuery query;
    query.prepare("INSERT INTO quiz (question, answer1, answer2, answer3, answer4, correct) "
                  "VALUES (:question, :answer1, :answer2, :answer3, :answer4, :correct)");
    query.bindValue(":question", question);
    query.bindValue(":answer1", answer1);
    query.bindValue(":answer2", answer2);
    query.bindValue(":answer3", answer3);
    query.bindValue(":answer4", answer4);
    query.bindValue(":correct", correct);

    if (!query.exec()) {
        qDebug() << "Error adding quiz question";
        return false;
    }
    return true;
}

// Gets all entries in database and returns a QList of entries with QList of questions and answers for that entry
QList<QList<QVariant>> DatabaseQuiz::getAllQuizEntries() {
    QList<QList<QVariant>> questions;
    \
    QSqlQuery query("SELECT * FROM quiz");
    while (query.next()) {
        QList<QVariant> question;
        question.append(query.value("id"));
        question.append(query.value("question"));
        question.append(query.value("answer1"));
        question.append(query.value("answer2"));
        question.append(query.value("answer3"));
        question.append(query.value("answer4"));
        question.append(query.value("correct"));

        questions.append(question);
    }
    return questions;
}

// Gets a single quiz entry by id and returns the QList of question and answers
QList<QVariant> DatabaseQuiz::getQuizEntry(int id) {
    QList<QVariant> entry;

    QSqlQuery query;
    query.prepare("SELECT * FROM quiz WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        entry.append(query.value("id"));
        entry.append(query.value("question"));
        entry.append(query.value("answer1"));
        entry.append(query.value("answer2"));
        entry.append(query.value("answer3"));
        entry.append(query.value("answer4"));
        entry.append(query.value("correct"));
    }
    return entry;
}

// Edits a single quiz entry by its id
bool DatabaseQuiz::editQuizEntry(int id,
                                 QString question,
                                 QString answer1,
                                 QString answer2,
                                 QString answer3,
                                 QString answer4,
                                 int correct) {
    QSqlQuery query;
    query.prepare("UPDATE quiz SET question = :question, answer1 = :answer1, "
                  "answer2 = :answer2, answer3 = :answer3, answer4 = :answer4, "
                  "correct = :correct WHERE id = :id");
    query.bindValue(":question", question);
    query.bindValue(":answer1", answer1);
    query.bindValue(":answer2", answer2);
    query.bindValue(":answer3", answer3);
    query.bindValue(":answer4", answer4);
    query.bindValue(":correct", correct);
    query.bindValue(":id", id);  // Update entry with this id

    if (!query.exec()) {
        qDebug() << "Failed to update quiz entry";
        return false;
    }

    qDebug() << "Quiz entry updated successfully";
    return true;
}

// Get the name of the quiz (NOT the quiz filename)
QString DatabaseQuiz::getName() {
    return quizName;
}

// to add later
// delete question
// is true
