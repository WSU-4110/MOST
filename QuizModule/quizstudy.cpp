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
    const int userIndex = quizWindow->getQuizSession()->userAnswerFor(quizWindow->getQuizSession()->currentIndex());

    /* From merge to fix later
    QString QNumber = QString::number(i+1) + "/" + QString::number(questionBank.size());
    ui->textDisplayQuestionNumber->setPlainText(QNumber);

    const QuizQuestion& q = questionBank[i];*/

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

    quizWindow->getUI()->radioButtonAnswer1->setAutoExclusive(false);
    quizWindow->getUI()->radioButtonAnswer2->setAutoExclusive(false);
    quizWindow->getUI()->radioButtonAnswer3->setAutoExclusive(false);
    quizWindow->getUI()->radioButtonAnswer4->setAutoExclusive(false);
    quizWindow->getUI()->radioButtonAnswer5->setAutoExclusive(false);
    quizWindow->getUI()->radioButtonAnswer6->setAutoExclusive(false);

    /* Merge to fix
    ui->radioButtonAnswer1->setChecked(q.userIndex[0]);
    ui->radioButtonAnswer2->setChecked(q.userIndex[1]);
    ui->radioButtonAnswer3->setChecked(q.userIndex[2]);
    ui->radioButtonAnswer4->setChecked(q.userIndex[3]);
    ui->radioButtonAnswer5->setChecked(q.userIndex[4]);
    ui->radioButtonAnswer6->setChecked(q.userIndex[5]);
    */
}

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

void QuizStudy::on_pushButtonNextQuestion_2_clicked() {
    if (!quizWindow->getQuizSession()->hasQuestions()) return;
    qDebug() << "quizstudy.cpp / Clicked next question";
    // Save current selection
    //quizWindow->getQuizSession()->answerCurrent(currentStudySelection());

    if (quizWindow->getQuizSession()->next()) {
        showStudyQuestion();
    }
}

void QuizStudy::on_pushButtonPreviousQuestion_2_clicked() {
    if (!quizWindow->getQuizSession()->hasQuestions()) return;
    qDebug() << "quizstudy.cpp / Clicked previous question";
    // Save current selection
    //quizWindow->getQuizSession()->answerCurrent(currentStudySelection());

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
    //quizWindow->getQuizSession()->answerCurrent(currentStudySelection());

    quizWindow->getUI()->stackedQuizWidget->setCurrentWidget(quizWindow->getUI()->pageQuizResults);

    //const int correct = quizWindow->getQuizSession()->correctCount();
    const int total   = quizWindow->getQuizSession()->questionCount();
    const double percentage = quizWindow->getQuizSession()->percentage();

    //quizWindow->getUI()->textResultNum->setPlainText(QString::number(correct));
    quizWindow->getUI()->textResultDen->setPlainText(QString::number(total));
    quizWindow->getUI()->textResultPer->setPlainText(QString::number(percentage * 100.0, 'f', 2));
}
