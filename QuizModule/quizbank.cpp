#include "quizbank.h"

void QuizBank::addQuestion(const QuizQuestion &q) {
    questions.push_back(q);
    currentIn = questions.size() - 1;
}

bool QuizBank::overwriteCurrent(const QuizQuestion &q) {
    // fail safe for out of bounds index
    if (currentIn < 0 || currentIn >= questions.size()) {
        return false;
    }

    questions[currentIn] = q;
    return true;
}

bool QuizBank::deleteCurrent() {
    // fail safe for out of bounds index
    if (currentIn < 0 || currentIn >= questions.size()) {
        return false;
    }

    questions.removeAt(currentIn);

    if (questions.isEmpty()) {
        currentIn = -1;
        return true;
    }

    if (currentIn >= questions.size()) {
        currentIn = questions.size() - 1;
    }
    return true;
}

bool QuizBank::hasQuestions() const {
    return !questions.isEmpty();
}

int QuizBank::size() const {
    return questions.size();
}

int QuizBank::currentIndex() const {
    return currentIn;
}

const QuizQuestion* QuizBank::current() const {
    if (currentIn < 0 || currentIn >= questions.size()) {
        return nullptr;
    }

    return &questions[currentIn];
}

bool QuizBank::next() {
    if (currentIn + 1 < questions.size()) {
        ++currentIn;
        return true;
    }
    return false;
}

bool QuizBank::previous() {
    if (currentIn - 1 >= 0) {
        --currentIn;
        return true;
    }
    return false;
}
