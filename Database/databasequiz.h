#ifndef DATABASEQUIZ_H
#define DATABASEQUIZ_H

#include "database.h"
#include <QString>
#include <QList>

class DatabaseQuiz : public Database {
public:
    DatabaseQuiz(QString dbName);

    void testing();
    bool addQuizQuestion(QString question,
                        QString answer1,
                        QString answer2,
                        QString answer3,
                        QString answer4,
                        int correct);

    QList<QList<QVariant>> getAllQuizEntries();
    QList<QVariant> getQuizEntry(int id);

    bool editQuizEntry(int id,
                       QString question,
                       QString answer1,
                       QString answer2,
                       QString answer3,
                       QString answer4,
                       int correct);

    QString getName();
private:
    QString quizName;
};

#endif // DATABASEQUIZ_H
