#include "databasequizloader.h"
#include <QDebug>

DatabaseQuizLoader::DatabaseQuizLoader(DatabaseQuiz* quizModel)
    : m_quizModel(quizModel) {}

void DatabaseQuizLoader::execute(const QString& quizFile) {
    qDebug() << "db quiz loader executing";
    m_quizModel->loadQuiz(quizFile);  // Calls the receiver's load method
}
