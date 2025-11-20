#include "quizstudy.h"
#include "quizwindow.h"

#include "quizquestion.h"
#include "quizqbuilder.h"
#include "quizbank.h"

// For pageQuizStudy in quizwindow.ui

QuizStudy::QuizStudy(QuizWindow* quizWin, QWidget *parent)
    : QWidget(parent), quizWindow(quizWin)
{
    // Connect buttons from pageQuizStudy in quizwindow.ui
    connect(quizWindow->getNextQuestion2Button(), &QPushButton::clicked,
            this, &QuizStudy::on_pushButtonNextQuestion_2_clicked);

    connect(quizWindow->getPreviousQuestion2Button(), &QPushButton::clicked,
            this, &QuizStudy::on_pushButtonPreviousQuestion_2_clicked);

    connect(quizWindow->getShuffleButton(), &QPushButton::clicked,
            this, &QuizStudy::on_pushButtonShuffle_clicked);

    connect(quizWindow->getSubmitQuizButton(), &QPushButton::clicked,
            this, &QuizStudy::on_pushButtonSubmitQuiz_clicked);

}

void QuizStudy::showStudyQuestion() {
    if (!quizWindow->getQuizSession()->hasQuestions()) {
        return;
    }
    qDebug() << "Triggered quizstudy.cpp/showStudyQuestion()";

    const QuizQuestion &q = quizWindow->getQuizSession()->currentQuestion();
    QVector<bool> userIndex = quizWindow->getQuizSession()->userAnswerFor(quizWindow->getQuizSession()->currentIndex());

    updateQuestionDisplayLabel();

    // Question
    quizWindow->getUI()->textDisplayQuestion->setPlainText(q.prompt);

    // Answers (exactly six slots; empties allowed)
    quizWindow->getUI()->textDisplayAnswer1->setPlainText(q.answers[0]);
    quizWindow->getUI()->textDisplayAnswer2->setPlainText(q.answers[1]);
    quizWindow->getUI()->textDisplayAnswer3->setPlainText(q.answers[2]);
    quizWindow->getUI()->textDisplayAnswer4->setPlainText(q.answers[3]);
    quizWindow->getUI()->textDisplayAnswer5->setPlainText(q.answers[4]);
    quizWindow->getUI()->textDisplayAnswer6->setPlainText(q.answers[5]);

    // Restore radio selection

    QRadioButton* radios[6] = {
        quizWindow->getUI()->radioButtonAnswer1,
        quizWindow->getUI()->radioButtonAnswer2,
        quizWindow->getUI()->radioButtonAnswer3,
        quizWindow->getUI()->radioButtonAnswer4,
        quizWindow->getUI()->radioButtonAnswer5,
        quizWindow->getUI()->radioButtonAnswer6
    };

    const QVector<bool>& selection = quizWindow->getQuizSession()->getUserAnswers()[quizWindow->getQuizSession()->currentIndex()];
    for (int i = 0; i < 6; ++i) {
        radios[i]->setAutoExclusive(false);
        radios[i]->setChecked(selection[i]);
    }

}

// Return QVector<bool> of current question's radio selections
QVector<bool> QuizStudy::currentStudySelection() const {
    QVector<bool> indexes{
        quizWindow->getUI()->radioButtonAnswer1->isChecked(),
        quizWindow->getUI()->radioButtonAnswer2->isChecked(),
        quizWindow->getUI()->radioButtonAnswer3->isChecked(),
        quizWindow->getUI()->radioButtonAnswer4->isChecked(),
        quizWindow->getUI()->radioButtonAnswer5->isChecked(),
        quizWindow->getUI()->radioButtonAnswer6->isChecked(),
    };
    return indexes;
}

void QuizStudy::updateQuestionDisplayLabel() {
    qDebug() << "quizstudy.cpp / Update question display label";
    int total = quizWindow->getQuizSession()->questionCount();
    int cur = quizWindow->getQuizSession()->currentIndex();
    QString text = QString("Question %1 / %2")
                       .arg(cur + 1)
                       .arg(total);
    quizWindow->getUI()->labelDisplayQuestionNumber->setText(text);
}

void QuizStudy::on_pushButtonNextQuestion_2_clicked() {
    if (!quizWindow->getQuizSession()->hasQuestions()) return;
    qDebug() << "quizstudy.cpp / Clicked next question";

    // Save current selection
    quizWindow->getQuizSession()->answerCurrent(currentStudySelection());

    if (quizWindow->getQuizSession()->next()) {
        showStudyQuestion();
    }
}

void QuizStudy::on_pushButtonPreviousQuestion_2_clicked() {
    if (!quizWindow->getQuizSession()->hasQuestions()) return;
    qDebug() << "quizstudy.cpp / Clicked previous question";

    // Save current selection
    quizWindow->getQuizSession()->answerCurrent(currentStudySelection());

    if (quizWindow->getQuizSession()->previous()) {
        showStudyQuestion();
    }
}

void QuizStudy::on_pushButtonShuffle_clicked() {
    if (quizWindow->getQuizBank()->getQuestions().isEmpty()) return;

    QVector<QuizQuestion> tempBank;
    std::srand(std::time(NULL));
    int size = quizWindow->getQuizBank()->getQuestions().size();
    while (size > 0) {
        int rng = std::rand() % size;
        tempBank.append(quizWindow->getQuizBank()->getQuestions()[rng]);
        quizWindow->getQuizBank()->getQuestions().removeAt(rng);
        size--;
    }
    quizWindow->getQuizBank()->getQuestions() = tempBank;
    //showStudyQuestion(questionStudyIndex);
}

void QuizStudy::on_pushButtonSubmitQuiz_clicked() {
    if (!quizWindow->getQuizSession()->hasQuestions()) {
        QMessageBox::information(this, tr("Submit Quiz"),tr("There are no questions in this quiz."));
        return;
    }

    // Save the current question's selection before scoring
    quizWindow->getQuizSession()->answerCurrent(currentStudySelection());

    quizWindow->getUI()->stackedQuizWidget->setCurrentWidget(quizWindow->getUI()->pageQuizResults);

    const int correct = quizWindow->getQuizSession()->correctCount();
    const int total   = quizWindow->getQuizSession()->questionCount();
    const double percentage = quizWindow->getQuizSession()->percentage();

    quizWindow->getUI()->textResultNum->setPlainText(QString::number(correct));
    quizWindow->getUI()->textResultDen->setPlainText(QString::number(total));
    quizWindow->getUI()->textResultPer->setPlainText(QString::number(percentage, 'f', 2));
}
