#include "quizqbuilder.h"

// Will set the text prompt for the question
QuizQBuilder& QuizQBuilder::prompt(const QString& p) {
    q.prompt = p;

    return *this;
}

// Will set the answer text at the appropriate index if valid
QuizQBuilder& QuizQBuilder::answer(int index, const QString& a) {
    if (index >= 0 && index < 6) {
        q.answers[index] = a;
    }

    return *this;
}

// Current method to keep sure index stays within bounds
QuizQBuilder& QuizQBuilder::correctIndex(int index) {
    if (index < 0) {
        index = 0;
    }

    if (index > 5) {
        index = 5;
    }

    q.correctIndex = index;

    return *this;
}

// performs validation on the constructed QuizQuestion
// if any requiremen fails an error message will be displayed
bool QuizQBuilder::build(QuizQuestion& out, QString& err) const {
    // Prompt must not be empty
    if (q.prompt.isEmpty()) {
        err = "Question prompt cannot be empty.";
        return false;
    }

    // At least two non-empty answers
    int filledOut = 0;
    for (int i = 0; i < 6; ++i) {
        if (!q.answers[i].isEmpty()) {
            ++filledOut;
        }
    }
    if (filledOut < 2) {
        err = "Provide at least two answer choices.";
        return false;
    }

    // Correct answer must be non-empty
    if (q.answers[q.correctIndex].isEmpty()) {
        err = "The correct answer is empty.";
        return false;
    }

    // Success: copy built object out
    err.clear();
    out = q;
    return true;
}
