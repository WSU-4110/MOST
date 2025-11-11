#include "quizstudy.h"

// For pageQuizStudy in quizwindow.ui

/* Commented out until functional

QuizStudy::QuizStudy(QWidget *parent, QuizWindow* mainWin)
    : QWidget(parent), mainWindow(mainWin)
{
    ui->setupUi(this);
}

void QuizWindow::on_pushButtonNextQuestion_2_clicked() {
    if (questionBank.isEmpty()) return;

    questionBank[questionStudyIndex].userIndex = currentStudySelection();

    if (questionStudyIndex + 1 < questionBank.size()) {
        ++questionStudyIndex;
        showStudyQuestion(questionStudyIndex);
    }
}

void QuizWindow::on_pushButtonPreviousQuestion_2_clicked() {
    if (questionBank.isEmpty()) return;

    questionBank[questionStudyIndex].userIndex = currentStudySelection();

    if (questionStudyIndex > 0) {
        --questionStudyIndex;
        showStudyQuestion(questionStudyIndex);
    }
}

// study page -> results
void QuizWindow::on_pushButtonSubmitQuiz_clicked() {
    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizResults);
    int correct = 0;
    for (int i = 0; i < questionBank.size(); i++) {
        if (questionBank[i].userIndex == questionBank[i].correctIndex) {
            correct++;
        }
    }
    double percentage = static_cast<double>(correct) / questionBank.size();

    QString numerator = QString::number(correct);
    QString denominator = QString::number(questionBank.size());
    QString result = QString::number(percentage*100, 'f', 2);
    ui->textResultNum->setPlainText(numerator);
    ui->textResultDen->setPlainText(denominator);
    ui->textResultPer->setPlainText(result);
}
*/
