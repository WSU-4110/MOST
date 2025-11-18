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
    q.correctIndexes.append(index);
    return *this;
}

// Set the QuizQuestion's correctIndexes to indexes in one go
QuizQBuilder& QuizQBuilder::correctIndex(const QVector<int>& indexes) {
    q.correctIndexes.clear();
    for (int idx : indexes) {
        if (idx < 0) idx = 0;
        if (idx > 5) idx = 5;
        if (!q.correctIndexes.contains(idx)) {
            q.correctIndexes.append(idx);
        }
    }
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

    // At least ONE correct index must exist
    if (q.correctIndexes.isEmpty()) {
        err = "Select at least one correct answer.";
        return false;
    }

    // All correct answers must be not empty
    for (int idx : q.correctIndexes) {
        if (q.answers[idx].isEmpty()) {
            err = QString("Correct answer at index %1 is empty.").arg(idx + 1);
            return false;
        }
    }

    // Success: copy built object out
    err.clear();
    out = q;
    return true;
}

