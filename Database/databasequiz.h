#ifndef DATABASEQUIZ_H
#define DATABASEQUIZ_H

#include "database.h"
#include <QSqlQuery>
#include <QString>
#include <QList>

class DatabaseQuiz : public Database {
public:
    DatabaseQuiz();
    DatabaseQuiz(QString dbName);

    int insertQuestion(QString question);
    int insertAnswer(int questionID, QString answer);
    int insertCorrect(int questionID, int answerID);

    bool updateQuestion(int questionID, QString newQuestion);
    bool updateAnswer(int answerID, QString newAnswer);
    bool updateCorrect(int questionId, QList<int> correctAnswerIDs);

    bool deleteQuestion(int questionID);
    bool deleteAnswer(int answerID);
    bool deleteCorrect(int questionID, int answerID);
    bool deleteAnswersForQuestion(int questionID);
    bool deleteCorrectForQuestion(int questionID);

    QVector<QPair<int, QString>> getAllQuestions();
    QList<QPair<QString, bool>> getQuestionAnswers(int questionID);
    int getQuestionIDByOrder(int index);
    int getAnswerIdByIndex(int questionID, int index);
    QSet<int> getCorrectAnswerIDs(int questionID);

    bool questionExists(int id);
    bool answerExists(int id);

    void setName(QString quizNameInput);
    QString getName();

    bool loadQuiz(const QString& quizFile);

    int lastInsertId() { return QSqlQuery().lastInsertId().toInt(); }
private:
    QString quizName;
};

#endif // DATABASEQUIZ_H
