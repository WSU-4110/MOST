#ifndef QUIZQUESTION_H
#define QUIZQUESTION_H

#include <QString>
#include <QVector>

// porting over to this header file to separate structure creation from the rest of the ui logic
struct QuizQuestion {
    QString prompt;
    QString answers[6];
    QVector<bool> correctIndex{false, false, false, false, false, false};
    QVector<bool> userIndex{false, false, false, false, false, false};
};

#endif // QUIZQUESTION_H
