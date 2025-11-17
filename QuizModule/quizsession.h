#ifndef QUIZSESSION_H
#define QUIZSESSION_H

#include "quizquestion.h"
#include <QVector>

class QuizSession {
public:
    QuizSession() {};

    // Initialize session from current question bank
    void start(const QVector<QuizQuestion> &questions);

    bool hasQuestions() const;
    int questionCount() const;
    int currentIndex() const;

    const QuizQuestion& currentQuestion() const;
    const QuizQuestion& questionAt(int index) const;

    // Record the user's answer for the current question
    void answerCurrent(QVector<bool> answerIndex);

    // This should read back which answer was picked for a given question
    QVector<bool> userAnswerFor(int questionIndex) const;

    bool next();
    bool previous();

    int correctCount() const;
    double percentage() const;

private:
    QVector<QuizQuestion> questionsCopy; // this is a copy of the questions passed into the start function
    QVector<QVector<int>> userAnswers; // this vector is parallel to the question copy bank and is used to keep track of answers
    int currentIn = 0;
};

#endif // QUIZSESSION_H
