#ifndef QUIZQUESTION_H
#define QUIZQUESTION_H

#include <QString>

// porting over to this header file to separate structure creation from the rest of the ui logic
struct QuizQuestion {
    QString prompt;
    QString answers[6];
    int correctIndex = 0;
    int userIndex = -1;
};

#endif // QUIZQUESTION_H
