#ifndef QUIZQUESTION_H
#define QUIZQUESTION_H

#include <QString>
#include <QVector>
#include <QDebug>

// QuizQuestion object stores the question prompt, choices in answers[], vector of correctIndexes, vector of userIndexes
struct QuizQuestion {
    QString prompt;
    QString answers[6];
    QVector<int> correctIndexes;
    QVector<int> userIndexes;

    // If dbID = -1, not saved to DB file
    int dbID = -1;

    // Debug - Print contents
    void debug() const {
        QStringList ansList;
        for (int i = 0; i < 6; ++i) {
            if (!answers[i].isEmpty())
                ansList << QString("\"%1\"").arg(answers[i]);
        }
        qDebug().noquote() << QString(
                                  "{ prompt: \"%1\", answers: [%2], correctIndexes: [%3], userIndexes: [%4] }")
                                  .arg(prompt)
                                  .arg(ansList.join(", "))
                                  .arg(QVectorToString(correctIndexes))
                                  .arg(QVectorToString(userIndexes));
    }
private:
    // Help to convert QVector<int> to string
    QString QVectorToString(const QVector<int>& vec) const {
        QStringList list;
        for (int i : vec) list << QString::number(i);
        return list.join(", ");
    }
};



#endif // QUIZQUESTION_H
