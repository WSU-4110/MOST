#ifndef DATABASEQUIZ_H
#define DATABASEQUIZ_H

#include "database.h"
#include <QString>
#include <QList>

class DatabaseQuiz : public Database {
public:
    DatabaseQuiz();
    DatabaseQuiz(QString dbName);

    bool insertQuestion(QString question);
    bool insertAnswer(int questionID, QString answer);
    bool insertCorrect(int questionID, int answerID);

    bool updateQuestion(int questionID, QString newQuestion);
    bool updateAnswer(int answerID, QString newAnswer);
    bool updateCorrect(int questionId, QList<int> correctAnswerIDs);

    bool deleteQuestion(int questionID);
    bool deleteAnswer(int answerID);
    bool deleteCorrect(int questionID, int answerID);

    QList<QPair<QString, bool>> getQuestionAnswers(int questionID);
    QList<QString> getAllQuestions();

    void setName(QString quizNameInput);
    QString getName();

    void loadQuiz(const QString& quizFile);

private:
    QString quizName;
};

#endif // DATABASEQUIZ_H
