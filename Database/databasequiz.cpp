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

// Insert the text of a question to the question table
bool DatabaseQuiz::insertQuestion(QString question) {
    QSqlQuery query;
    query.prepare("INSERT INTO questions (question) VALUES (:question)");
    query.bindValue(":question", question);
    if (!query.exec()) {
        qDebug() << "Failed to insert question:" << query.lastError().text();
        return false;
    }
    return true;
}

// Insert the text of an answer to the answer table with for questionID
bool DatabaseQuiz::insertAnswer(int questionID, QString answer) {
    QSqlQuery query;
    query.prepare("INSERT INTO answers (question_id, answer) VALUES (:question_id, :answer)");
    query.bindValue(":question_id", questionID);
    query.bindValue(":answer", answer);

    if (!query.exec()) {
        qDebug() << "Failed to insert answer:" << query.lastError().text();
        return false;
    }
    return true;
}

// Mark an answerID correct for a questionID
bool DatabaseQuiz::insertCorrect(int questionID, int answerID) {
    QSqlQuery query;
    query.prepare("INSERT INTO correct (question_id, answer_id) VALUES (:question_id, :answer_id)");
    query.bindValue(":question_id", questionID);
    query.bindValue(":answer_id", answerID);

    if (!query.exec()) {
        qDebug() << "Failed to insert correct:" << query.lastError().text();
        return false;
    }
    return true;
}

// Update questionID to have text newQuestion
bool DatabaseQuiz::updateQuestion(int questionID, QString newQuestion) {
    QSqlQuery query;
    query.prepare("UPDATE questions SET question = :question WHERE id = :id");
    query.bindValue(":question", newQuestion);
    query.bindValue(":id", questionID);

    if (!query.exec()) {
        qDebug() << "Failed to update question:" << query.lastError().text();
        return false;
    }
    return true;
}

// Update answerID to have text newAnswer
bool DatabaseQuiz::updateAnswer(int answerID, QString newAnswer) {
    QSqlQuery query;
    query.prepare("UPDATE answers SET answer = :answer WHERE id = :id");
    query.bindValue(":answer", newAnswer);
    query.bindValue(":id", answerID);

    if (!query.exec()) {
        qDebug() << "Failed to update answer:" << query.lastError().text();
        return false;
    }
    return true;
}

// Update questionID's correct answers given a list of answerIDs to be marked correct
bool DatabaseQuiz::updateCorrect(int questionId, QList<int> correctAnswerIDs) {
    // Deletes existing correct answers for the question
    QSqlQuery query;
    query.prepare("DELETE FROM correct WHERE question_id = :question_id");
    query.bindValue(":question_id", questionId);

    if (!query.exec()) {
        qDebug() << "Failed to delete existing correct answers:" << query.lastError().text();
        return false;
    }

    // Inserts new correct answers for the question
    for (int answerId : correctAnswerIDs) {
        if (!insertCorrect(questionId, answerId)) {
            return false;  // If any insert fails return false
        }
    }
    return true;
}

// Delete questionID
bool DatabaseQuiz::deleteQuestion(int questionID) {
    QSqlQuery query;
    query.prepare("DELETE FROM questions WHERE id = :id");
    query.bindValue(":id", questionID);

    if (!query.exec()) {
        qDebug() << "Failed to delete question:" << query.lastError().text();
        return false;
    }
    return true;
}

// Delete answerID
bool DatabaseQuiz::deleteAnswer(int answerID) {
    QSqlQuery query;
    query.prepare("DELETE FROM answers WHERE id = :id");
    query.bindValue(":id", answerID);

    if (!query.exec()) {
        qDebug() << "Failed to delete answer:" << query.lastError().text();
        return false;
    }
    return true;
}

// Delete correct mark based on specific question id and answer id
bool DatabaseQuiz::deleteCorrect(int questionID, int answerID) {
    QSqlQuery query;
    query.prepare("DELETE FROM correct WHERE question_id = :question_id AND answer_id = :answer_id");
    query.bindValue(":question_id", questionID);
    query.bindValue(":answer_id", answerID);

    if (!query.exec()) {
        qDebug() << "Failed to delete correct answer:" << query.lastError().text();
        return false;
    }
    return true;
}

// Returns a QList of pairs of <Question text, Is it correct?> for a question id
QList<QPair<QString, bool>> DatabaseQuiz::getQuestionAnswers(int questionID) {
    QSqlQuery query;

    // Join the answers table with the correct table to get answer and correct values corresponding to question id
    query.prepare(R"(
        SELECT q.question, a.answer, c.answer_id IS NOT NULL AS is_correct
        FROM questions q
        JOIN answers a ON a.question_id = q.id
        LEFT JOIN correct c ON a.id = c.answer_id AND c.question_id = q.id
        WHERE q.id = :question_id
    )");
    query.bindValue(":question_id", questionID);

    if (!query.exec()) {
        qDebug() << "Failed to get answers:" << query.lastError().text();
        return {};  // Returns empty if error
    }

    // Put the results of the query into a list of questionAnswers that hold pairs of <Question text, Correct?>
    QList<QPair<QString, bool>> questionAnswers;
    while (query.next()) {
        QString questionText = query.value(0).toString();
        QString answerText = query.value(1).toString();
        bool isCorrect = query.value(2).toBool();
        questionAnswers.append(qMakePair(answerText, isCorrect));
    }

    return questionAnswers;
}

// Returns a QList of all the questions
QList<QString> DatabaseQuiz::getAllQuestions() {
    QList<QString> questions;
    QSqlQuery query("SELECT question FROM questions");
    if (query.exec()) {
        while (query.next()) {
            questions.append(query.value(0).toString());
        }
    } else {
        qDebug() << "Failed to get questions:" << query.lastError().text();
    }
    return questions;
}

// Get the name of the quiz (NOT the quiz filename)
QString DatabaseQuiz::getName() {
    return quizName;
}
