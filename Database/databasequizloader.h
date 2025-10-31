#ifndef DATABASEQUIZLOAD_H
#define DATABASEQUIZLOAD_H

#include <QString>
#include "databasequiz.h"

class DatabaseQuizLoad {
public:
    virtual ~DatabaseQuizLoad() {}
    virtual void execute(const QString& quizFile) = 0;
};

#endif // DATABASEQUIZLOAD_H

#ifndef DATABASEQUIZLOADER_H
#define DATABASEQUIZLOADER_H

class DatabaseQuizLoader : public DatabaseQuizLoad {
private:
    DatabaseQuiz* m_quizModel;  // The receiver (DatabaseQuiz)

public:
    DatabaseQuizLoader(DatabaseQuiz* quizModel);  // Constructor to pass the receiver
    void execute(const QString& quizFile) override;  // Execute method to load the quiz
};

#endif // DATABASEQUIZLOADER_H
