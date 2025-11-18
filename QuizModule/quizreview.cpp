#include "quizreview.h"
#include "quizwindow.h"
#include <QDebug>

// for pageQuizReview in quizwindow.ui

QuizReview::QuizReview(QuizWindow* quizWin, QWidget *parent)
    : QWidget(parent), quizWindow(quizWin)
{
    connect(quizWindow->getNextQuestion3Button(), &QPushButton::clicked,
            this, &QuizReview::on_pushButtonNextQuestion_3_clicked);

    connect(quizWindow->getPreviousQuestion3Button(), &QPushButton::clicked,
            this, &QuizReview::on_pushButtonPreviousQuestion_3_clicked);
}

void QuizReview::showStudyQuestionReview(int i) {
    if (!quizWindow->getQuizSession()->hasQuestions())
        return;
    if (i < 0) i = 0;

    qDebug() << "Triggered quizreview.cpp/showStudyQuestionReview";

    const int count = quizWindow->getQuizSession()->questionCount();
    if (reviewIndex < 0) reviewIndex = i;
    if (reviewIndex >= count) reviewIndex = count - 1;

    const QuizQuestion &q = quizWindow->getQuizSession()->questionAt(reviewIndex);
    const int userIndex = quizWindow->getQuizSession()->userAnswerFor(reviewIndex);
    //const int correctIndex = q.correctIndex;

    QString QNumber = QString::number(i+1) + "/" + QString::number(quizWindow->getQuizBank()->getQuestions().size());

    quizWindow->getUI()->textDisplayQuestionNumber_2->setPlainText(QNumber);

    //const QuizQuestion& q = quizWindow->getQuizBank()->getQuestions()[i];

    // Question
    quizWindow->getUI()->textDisplayQuestion_2->setPlainText(q.prompt);

    // Display answers
    quizWindow->getUI()->textDisplayAnswer1->setPlainText(q.answers[0]);
    quizWindow->getUI()->textDisplayAnswer2->setPlainText(q.answers[1]);
    quizWindow->getUI()->textDisplayAnswer3->setPlainText(q.answers[2]);
    quizWindow->getUI()->textDisplayAnswer4->setPlainText(q.answers[3]);
    quizWindow->getUI()->textDisplayAnswer5->setPlainText(q.answers[4]);
    quizWindow->getUI()->textDisplayAnswer6->setPlainText(q.answers[5]);

    // Answers (exactly six slots; empties allowed)
    QPlainTextEdit* answers[6] = {
        quizWindow->getUI()->textDisplayAnswer1_2,
        quizWindow->getUI()->textDisplayAnswer2_2,
        quizWindow->getUI()->textDisplayAnswer3_2,
        quizWindow->getUI()->textDisplayAnswer4_2,
        quizWindow->getUI()->textDisplayAnswer5_2,
        quizWindow->getUI()->textDisplayAnswer6_2,
    };

    QLabel* checkmarks[6] = {
        quizWindow->getUI()->labelCheck1,
        quizWindow->getUI()->labelCheck2,
        quizWindow->getUI()->labelCheck3,
        quizWindow->getUI()->labelCheck4,
        quizWindow->getUI()->labelCheck5,
        quizWindow->getUI()->labelCheck6
    };

    for (int j = 0; j < 6; ++j) {
        answers[j]->setStyleSheet("border: none;");
        checkmarks[j]->setText("");
    }
    /*
    for (int j = 0; j < 6; ++j) {
        answers[j]->setPlainText(q.answers[j]);
        if (quizWindow->getQuizBank()->getQuestions()[i].userIndex && quizWindow->getQuizBank()->getQuestions()[i].correctIndex) {
            checkmarks[j]->setText(" ✅");
        }
        if (quizWindow->getQuizBank()->getQuestions()[i].userIndex && !quizWindow->getQuizBank()->getQuestions()[i].correctIndex) {
            checkmarks[j]->setText(" ❌");
        }
        if (!quizWindow->getQuizBank()->getQuestions()[i].userIndex && quizWindow->getQuizBank()->getQuestions()[i].correctIndex) {
            answers[j]->setStyleSheet("border: 3px solid lightgreen;");
        }

    }

    if (correctIndex >= 0 && correctIndex < 6) {
        answers[correctIndex]->setStyleSheet("border: 3px solid lightgreen;");
    }
    */
}

void QuizReview::on_pushButtonNextQuestion_3_clicked() {
    if (!quizWindow->getQuizSession()->hasQuestions()) return;
    qDebug() << "Clicked quizreview.cpp / Next Question";
    if (questionStudyIndex + 1 < quizWindow->getQuizBank()->getQuestions().size()) {
        ++questionStudyIndex;
        showStudyQuestionReview(questionStudyIndex);
    }
}

void QuizReview::on_pushButtonPreviousQuestion_3_clicked() {
    if (!quizWindow->getQuizSession()->hasQuestions()) return;
    qDebug() << "Clicked quizreview.cpp / Previous Question";
    if (questionStudyIndex > 0) {
        --questionStudyIndex;
        showStudyQuestionReview(questionStudyIndex);
    }
}
