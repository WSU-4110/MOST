#include "quizcreate.h"
#include "quizquestion.h"

// For pageQuizCreate in quizwindow.ui

/* Commented out until functional

QuizCreate::QuizCreate(QWidget *parent, QuizWindow* mainWin)
    : QWidget(parent), quizWindow(mainWin)
{
}

// create page (add better error handling later)

// create question
void QuizCreate::on_pushButtonCreateQuestion_clicked() {
    QuizQuestion q; QString err;
    if (!readCreateForm(q, err)) {
        return;
    }
    questionBank.push_back(q);
    questionCurrent = questionBank.size() - 1;
}

// overwrite question
void QuizCreate::on_pushButtonOverwriteQuestion_clicked() {
    if (questionCurrent < 0 || questionCurrent >= questionBank.size()) {  // temp fix for out of bounds errors
        return;
    }
    QuizQuestion q; QString err;
    if (!readCreateForm(q, err)) return;
    questionBank[questionCurrent] = q;

    writeCreateForm(questionBank[questionCurrent]);
}

void QuizCreate::on_pushButtonDeleteQuestion_clicked() {
    if (questionCurrent < 0 || questionCurrent >= questionBank.size()) {  // temp fix for out of bounds errors
        return;
    }
    questionBank.removeAt(questionCurrent);

    if (questionBank.isEmpty()) {
        questionCurrent = -1;
        clearCreateForm();
        return;
    }
    if (questionCurrent >= questionBank.size())
        questionCurrent = questionBank.size() - 1;

    writeCreateForm(questionBank[questionCurrent]);
}

void QuizCreate::on_pushButtonPreviousQuestion_clicked() {
    if (questionBank.isEmpty()) return;
    if (questionCurrent <= 0) {             // temp fix for out of bounds errors? something would cause app to crash
        questionCurrent = 0;
    } else {
        --questionCurrent;
    }
    writeCreateForm(questionBank[questionCurrent]);
}

void QuizCreate::on_pushButtonNextQuestion_clicked() {
    if (questionBank.isEmpty()) return;
    if (questionCurrent + 1 >= questionBank.size()) {       // temp fix for out of bounds errors? something would cause app to crash
        questionCurrent = questionBank.size() - 1;
    } else {
        ++questionCurrent;
    }
    writeCreateForm(questionBank[questionCurrent]);
}
*/
