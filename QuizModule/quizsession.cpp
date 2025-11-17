#include "quizsession.h"

void QuizSession::start(const QVector<QuizQuestion> &questions) {
    questionsCopy = questions;  // using a copy so that if the original quiz is modified, it wont affect the current study session
    userAnswers.resize(questionsCopy.size());
    userAnswers[0].fill(0);   // initializing with -1 to act as "no answer selected"
    currentIn = 0;
}

bool QuizSession::hasQuestions() const {
    return !questionsCopy.isEmpty();
}

int QuizSession::questionCount() const {
    return questionsCopy.size();
}

int QuizSession::currentIndex() const {
    return currentIn;
}

const QuizQuestion& QuizSession::currentQuestion() const {
    return questionsCopy[currentIn];
}

void QuizSession::answerCurrent(QVector<bool> answerIndex) {
    if (!hasQuestions()) {
        return;
    }

    if (currentIn < 0 || currentIn >= userAnswers.size()) {
        return;
    }
    for (int i=0; i < 6, i++;) {
        userAnswers[currentIn][i] = answerIndex[i];
    }

}

QVector<bool> QuizSession::userAnswerFor(int questionIndex) const {
    if (questionIndex < 0 || questionIndex >= userAnswers.size()) {
        return {false};
    }
    QVector<bool> temp = {false, false, false, false, false};
    for (int i=0; i < 6, i++;) {
        temp[i] = userAnswers[questionIndex][i];
    }
    return temp;
}

bool QuizSession::next() {
    if (currentIn + 1 < questionsCopy.size()) {
        ++currentIn;
        return true;
    }

    return false;
}

bool QuizSession::previous() {
    if (currentIn - 1 >= 0) {
        --currentIn;
        return true;
    }

    return false;
}

const QuizQuestion& QuizSession::questionAt(int index) const {
    return questionsCopy[index];
}

int QuizSession::correctCount() const {
    if (!hasQuestions()) {
        return 0;
    }

    int count = 0;
    for (int i = 0; i < questionsCopy.size(); ++i) {
        for (int j = 0; j < questionsCopy.size(); ++j) {
            const int userIdx = userAnswers[i][j];
            if (userIdx >= 0 && userIdx < 6 && userIdx == questionsCopy[i].correctIndex[j]) {
                ++count;
            }
        }
    }
    return count;
}

double QuizSession::percentage() const {
    const int total = questionCount();
    if (total == 0)
        return 0.0;

    return static_cast<double>(correctCount()) / static_cast<double>(total);
}
