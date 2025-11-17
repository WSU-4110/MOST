#include "quizcreate.h"
#include "quizquestion.h"
#include "quizqbuilder.h"
#include "quizwindow.h"
#include <QPushButton>

// For pageQuizCreate in quizwindow.ui

QuizCreate::QuizCreate(QuizWindow* quizWin, QWidget *parent)
    : QWidget(parent), quizWindow(quizWin)
{
    // Connect buttons from pageQuizCreate in quizwindow.ui
    connect(quizWindow->getCreateQuestionButton(), &QPushButton::clicked,
            this, &QuizCreate::on_pushButtonCreateQuestion_clicked);

    connect(quizWindow->getOverwriteQuestionButton(), &QPushButton::clicked,
            this, &QuizCreate::on_pushButtonOverwriteQuestion_clicked);

    connect(quizWindow->getDeleteQuestionButton(), &QPushButton::clicked,
            this, &QuizCreate::on_pushButtonDeleteQuestion_clicked);

    connect(quizWindow->getPreviousQuestionButton(), &QPushButton::clicked,
            this, &QuizCreate::on_pushButtonPreviousQuestion_clicked);

    connect(quizWindow->getNextQuestionButton(), &QPushButton::clicked,
            this, &QuizCreate::on_pushButtonNextQuestion_clicked);
}

bool QuizCreate::readCreateForm(QuizQuestion &out, QString &err) const {
    qDebug() << "triggered readCreateForm";
    QuizQBuilder b;

    QVector<bool> correct = {false, false, false, false, false, false};
    correct[0] = quizWindow->getUI()->radioButtonCorrect1->isChecked();
    correct[1] = quizWindow->getUI()->radioButtonCorrect2->isChecked();
    correct[2] = quizWindow->getUI()->radioButtonCorrect3->isChecked();
    correct[3] = quizWindow->getUI()->radioButtonCorrect4->isChecked();
    correct[4] = quizWindow->getUI()->radioButtonCorrect5->isChecked();
    correct[5] = quizWindow->getUI()->radioButtonCorrect6->isChecked();

    const bool cr = b
                        .prompt(quizWindow->getUI()->lineEditQuestion->text())
                        .answer(0, quizWindow->getUI()->lineEditAnswer1->text())
                        .answer(1, quizWindow->getUI()->lineEditAnswer2->text())
                        .answer(2, quizWindow->getUI()->lineEditAnswer3->text())
                        .answer(3, quizWindow->getUI()->lineEditAnswer4->text())
                        .answer(4, quizWindow->getUI()->lineEditAnswer5->text())
                        .answer(5, quizWindow->getUI()->lineEditAnswer6->text())
                        .correctIndices(correct)
                        .build(out, err);

    return cr;
}

// this will clear the fields from the create page
void QuizCreate::clearCreateForm() {
    qDebug() << "triggered clearCreateForm";
    quizWindow->getUI()->lineEditQuestion->clear();
    quizWindow->getUI()->lineEditAnswer1->clear();
    quizWindow->getUI()->lineEditAnswer2->clear();
    quizWindow->getUI()->lineEditAnswer3->clear();
    quizWindow->getUI()->lineEditAnswer4->clear();
    quizWindow->getUI()->lineEditAnswer5->clear();
    quizWindow->getUI()->lineEditAnswer6->clear();
    quizWindow->getUI()->radioButtonCorrect1->setChecked(false);
    quizWindow->getUI()->radioButtonCorrect2->setChecked(false);
    quizWindow->getUI()->radioButtonCorrect3->setChecked(false);
    quizWindow->getUI()->radioButtonCorrect4->setChecked(false);
    quizWindow->getUI()->radioButtonCorrect5->setChecked(false);
    quizWindow->getUI()->radioButtonCorrect6->setChecked(false);
}

void QuizCreate::writeCreateForm(const QuizQuestion &q) {
    qDebug() << "triggered writeCreateForm";
    quizWindow->getUI()->lineEditQuestion->setText(q.prompt);
    quizWindow->getUI()->lineEditAnswer1->setText(q.answers[0]);
    quizWindow->getUI()->lineEditAnswer2->setText(q.answers[1]);
    quizWindow->getUI()->lineEditAnswer3->setText(q.answers[2]);
    quizWindow->getUI()->lineEditAnswer4->setText(q.answers[3]);
    quizWindow->getUI()->lineEditAnswer5->setText(q.answers[4]);
    quizWindow->getUI()->lineEditAnswer6->setText(q.answers[5]);

    quizWindow->getUI()->radioButtonCorrect1->setChecked(q.correctIndex[0]);
    quizWindow->getUI()->radioButtonCorrect2->setChecked(q.correctIndex[1]);
    quizWindow->getUI()->radioButtonCorrect3->setChecked(q.correctIndex[2]);
    quizWindow->getUI()->radioButtonCorrect4->setChecked(q.correctIndex[3]);
    quizWindow->getUI()->radioButtonCorrect5->setChecked(q.correctIndex[4]);
    quizWindow->getUI()->radioButtonCorrect6->setChecked(q.correctIndex[5]);
}

// create page (add better error handling later)

// create question
void QuizCreate::on_pushButtonCreateQuestion_clicked() {
    qDebug() << "clicked create question";
    QuizQuestion q; QString err;
    if (!readCreateForm(q, err)) {
        QMessageBox::warning(this, tr("Create Question"), err);
        return;
    }

    quizWindow->getQuizBank()->addQuestion(q);

    if (const QuizQuestion* current = quizWindow->getQuizBank()->current()) {
        writeCreateForm(*current);
    }
}

// overwrite question
void QuizCreate::on_pushButtonOverwriteQuestion_clicked() {
    qDebug() << "clicked overwrite question";
    QuizQuestion q; QString err;
    if (!readCreateForm(q, err)) {
        QMessageBox::warning(this, tr("Overwrite Question"), err);
        return;
    }

    if (!quizWindow->getQuizBank()->overwriteCurrent(q)) {
        QMessageBox::warning(this, tr("Overwrite Question"),tr("There is no current question to overwrite."));
        return;
    }

    if (const QuizQuestion* cur = quizWindow->getQuizBank()->current()) {
        writeCreateForm(*cur);
    }
}

// delete question
void QuizCreate::on_pushButtonDeleteQuestion_clicked() {
    qDebug() << "clicked delete question";
    if (!quizWindow->getQuizBank()->deleteCurrent()) {
        clearCreateForm();
        return;
    }

    // either show new current or clear form if none
    if (const QuizQuestion* current = quizWindow->getQuizBank()->current()) {
        writeCreateForm(*current);
    } else {
        clearCreateForm();
    }
}

void QuizCreate::on_pushButtonPreviousQuestion_clicked() {
    qDebug() << "clicked prev question";
    if (!quizWindow->getQuizBank()->hasQuestions()) return;

    quizWindow->getQuizBank()->previous();  // if already at first, this returns false and index stays
    if (const QuizQuestion* current = quizWindow->getQuizBank()->current()) {
        writeCreateForm(*current);
    }
}

void QuizCreate::on_pushButtonNextQuestion_clicked() {
    qDebug() << "clicked next question";
    if (!quizWindow->getQuizBank()->hasQuestions()) {
        return;
    }

    quizWindow->getQuizBank()->next();  // if already at last, this returns false and index stays

    if (const QuizQuestion* current = quizWindow->getQuizBank()->current()) {
        writeCreateForm(*current);
    }
}
