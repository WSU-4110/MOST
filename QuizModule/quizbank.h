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
private:
    QVector<QuizQuestion> questions;
    int currentIn = -1;
};

#endif // QUIZBANK_H
