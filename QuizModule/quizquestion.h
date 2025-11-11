#ifndef QUIZQUESTION_H
#define QUIZQUESTION_H

#include <QString>

// current idea for formatting questions/answers in a storeable format
struct QuizQuestion {
    QString prompt;
    QString answers[6];
    int correctIndex = 0;
    int userIndex = -1;
};

#endif // QUIZQUESTION_H
