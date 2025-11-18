#include "quizcreate.h"
#include "quizquestion.h"
#include "quizqbuilder.h"
#include "quizwindow.h"
#include "../Database/databasequiz.h"
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

    qDebug() << quizWindow->getQuizDB();
}

bool QuizCreate::readCreateForm(QuizQuestion &out, QString &err) const {
    qDebug() << "quizcreate.cpp / readCreateForm";
    QuizQBuilder b;

    // Collect selected radio button(s) into QVector<int>
    QVector<int> selectedIndexes;
    QRadioButton* radios[6] = {
        quizWindow->getUI()->radioButtonCorrect1,
        quizWindow->getUI()->radioButtonCorrect2,
        quizWindow->getUI()->radioButtonCorrect3,
        quizWindow->getUI()->radioButtonCorrect4,
        quizWindow->getUI()->radioButtonCorrect5,
        quizWindow->getUI()->radioButtonCorrect6
    };
    for (int i = 0; i < 6; ++i) {
        if (radios[i]->isChecked()) {
            selectedIndexes.append(i);
        }
    }

    const bool cr = b
                        .prompt(quizWindow->getUI()->lineEditQuestion->text())
                        .answer(0, quizWindow->getUI()->lineEditAnswer1->text())
                        .answer(1, quizWindow->getUI()->lineEditAnswer2->text())
                        .answer(2, quizWindow->getUI()->lineEditAnswer3->text())
                        .answer(3, quizWindow->getUI()->lineEditAnswer4->text())
                        .answer(4, quizWindow->getUI()->lineEditAnswer5->text())
                        .answer(5, quizWindow->getUI()->lineEditAnswer6->text())
                        .correctIndex(selectedIndexes)
                        .build(out, err);

    qDebug() << cr;
    return cr;
}

// this will clear the fields from the create page
void QuizCreate::clearCreateForm() {
    qDebug() << "quizcreate.cpp / clearCreateForm";
    quizWindow->getUI()->lineEditQuestion->clear();
    quizWindow->getUI()->lineEditAnswer1->clear();
    quizWindow->getUI()->lineEditAnswer2->clear();
    quizWindow->getUI()->lineEditAnswer3->clear();
    quizWindow->getUI()->lineEditAnswer4->clear();
    quizWindow->getUI()->lineEditAnswer5->clear();
    quizWindow->getUI()->lineEditAnswer6->clear();
    // Clear radio button selections
    quizWindow->getUI()->radioButtonCorrect1->setChecked(false);
    quizWindow->getUI()->radioButtonCorrect2->setChecked(false);
    quizWindow->getUI()->radioButtonCorrect3->setChecked(false);
    quizWindow->getUI()->radioButtonCorrect4->setChecked(false);
    quizWindow->getUI()->radioButtonCorrect5->setChecked(false);
    quizWindow->getUI()->radioButtonCorrect6->setChecked(false);
}

void QuizCreate::writeCreateForm(const QuizQuestion &q) {
    clearCreateForm();
    qDebug() << "quizcreate.cpp / writeCreateForm ";
    quizWindow->getUI()->lineEditQuestion->setText(q.prompt);
    quizWindow->getUI()->lineEditAnswer1->setText(q.answers[0]);
    quizWindow->getUI()->lineEditAnswer2->setText(q.answers[1]);
    quizWindow->getUI()->lineEditAnswer3->setText(q.answers[2]);
    quizWindow->getUI()->lineEditAnswer4->setText(q.answers[3]);
    quizWindow->getUI()->lineEditAnswer5->setText(q.answers[4]);
    quizWindow->getUI()->lineEditAnswer6->setText(q.answers[5]);

    QRadioButton* checkboxes[6] = {
        quizWindow->getUI()->radioButtonCorrect1,
        quizWindow->getUI()->radioButtonCorrect2,
        quizWindow->getUI()->radioButtonCorrect3,
        quizWindow->getUI()->radioButtonCorrect4,
        quizWindow->getUI()->radioButtonCorrect5,
        quizWindow->getUI()->radioButtonCorrect6
    };
    for (int idx : q.correctIndexes) {
        if (idx >= 0 && idx < 6) {
            checkboxes[idx]->setChecked(true);
        }
    }
}

void QuizCreate::updateQuestionCountLabel() {
    QuizBank* bank = quizWindow->getQuizBank();
    int total = bank->size();
    int cur = bank->currentIndex();

    // No questions yet, showing an empty new page
    if (total == 0 || cur == -1) {
        quizWindow->getUI()->labelCreateQuestionIndex->setText("Question 0 / 0");
        return;
    }

    // Has questions
    QString text = QString("Question %1 / %2")
                       .arg(cur + 1)
                       .arg(total);
    quizWindow->getUI()->labelCreateQuestionIndex->setText(text);
}

// Create Question - Adds QuizQuestion q to quizBank
void QuizCreate::on_pushButtonCreateQuestion_clicked() {
    qDebug() << "quizcreate.cpp / Clicked create question";
    QuizQuestion q; QString err;
    if (!readCreateForm(q, err)) {
        QMessageBox::warning(this, tr("Create Question"), err);
        return;
    }
    quizWindow->getQuizBank()->addQuestion(q);
    if (const QuizQuestion* current = quizWindow->getQuizBank()->current()) {
        writeCreateForm(*current);
    }
    updateQuestionCountLabel();
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
    updateQuestionCountLabel();
}

// Delete question
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
    updateQuestionCountLabel();
}

void QuizCreate::on_pushButtonPreviousQuestion_clicked() {
    qDebug() << "quizcreate.cpp / Previous question";

    quizWindow->getQuizBank()->debugAll();

    if (!quizWindow->getQuizBank()->hasQuestions()) {
        clearCreateForm();
        return;
    }
    // If quizBank is at the beginning
    if (!quizWindow->getQuizBank()->previous()) {
        // Show the first question
        if (const QuizQuestion* current = quizWindow->getQuizBank()->current()) {
            writeCreateForm(*current);
        }
        return;
    }

    if (const QuizQuestion* current = quizWindow->getQuizBank()->current()) {
        writeCreateForm(*current);
    }
    updateQuestionCountLabel();
}

void QuizCreate::on_pushButtonNextQuestion_clicked() {
    qDebug() << "quizcreate.cpp / Next question";

    quizWindow->getQuizBank()->debugAll();

    if (!quizWindow->getQuizBank()->hasQuestions()) {
        clearCreateForm();
        return;
    }

    // If quizBank is at the end
    if (!quizWindow->getQuizBank()->next()) {
        // Clear for a new entry
        clearCreateForm();
        return;
    }

    if (const QuizQuestion* current = quizWindow->getQuizBank()->current()) {
        writeCreateForm(*current);
    }
    updateQuestionCountLabel();
}
