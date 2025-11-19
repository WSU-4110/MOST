#ifndef QUIZBANK_H
#define QUIZBANK_H

#include <QVector>
#include "quizquestion.h"

class QuizBank
{
public:
    void addQuestion(const QuizQuestion &q);
    bool overwriteCurrent(const QuizQuestion &q);
    bool deleteCurrent();
    bool hasQuestions() const;
    int  size() const;
    int  currentIndex() const;
    const QuizQuestion* current() const;
    bool next();
    bool previous();

    const QVector<QuizQuestion>& all() const {
        return questions;
    }

    QVector<QuizQuestion> getQuestions() const { return questions; }
    QuizQuestion getQuestions(int i) const { return questions.at(i); }

    void setName(QString name) { quizName = name; }
    QString getName() const { return quizName; }

    void clear();
    void debugAll() const;

private:
    QString quizName;
    QVector<QuizQuestion> questions;
    int currentIn = -1;
};

#endif // QUIZBANK_H
