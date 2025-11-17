#include "quizwindow.h"
#include "QuizModule/ui_quizwindow.h"
#include <QMessageBox> // back in for error messages 10/30/2025--KhaliphP
#include "quizqbuilder.h"

QuizWindow::QuizWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QuizWindow)
{
    ui->setupUi(this);
    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizMenu);

    // Initialize
    quizDB = nullptr;
    quizBank = new QuizBank();
    quizSession = new QuizSession();

    // Subpages of quizwindow.ui
    quizMenu = new QuizMenu(this, nullptr);
    quizCreate = new QuizCreate(this, nullptr);
    //quizStudy = new QuizStudy(this, nullptr);
    ui->radioButtonCorrect1->setAutoExclusive(false);
    ui->radioButtonCorrect2->setAutoExclusive(false);
    ui->radioButtonCorrect3->setAutoExclusive(false);
    ui->radioButtonCorrect4->setAutoExclusive(false);
    ui->radioButtonCorrect5->setAutoExclusive(false);
    ui->radioButtonCorrect6->setAutoExclusive(false);
}

QuizWindow::~QuizWindow()
{
    delete ui;
    delete quizDB;
    delete quizMenu;
}

/*
// this will allow popup messages to convey action success/failure
void MainWindow::showInfo(const QString& msg) {
    QMessageBox::information(this, tr("Quiz"), msg);
}
*/

/*
// this will clear the fields from the create page
void QuizWindow::clearCreateForm() {
    ui->lineEditQuestion->clear();
    ui->lineEditAnswer1->clear();
    ui->lineEditAnswer2->clear();
    ui->lineEditAnswer3->clear();
    ui->lineEditAnswer4->clear();
    ui->lineEditAnswer5->clear();
    ui->lineEditAnswer6->clear();

    ui->radioButtonCorrect1->setChecked(false);
    ui->radioButtonCorrect2->setChecked(false);
    ui->radioButtonCorrect3->setChecked(false);
    ui->radioButtonCorrect4->setChecked(false);
    ui->radioButtonCorrect5->setChecked(false);
    ui->radioButtonCorrect6->setChecked(false);

}

void QuizWindow::writeCreateForm(const QuizQuestion &q) {
    ui->lineEditQuestion->setText(q.prompt);
    ui->lineEditAnswer1->setText(q.answers[0]);
    ui->lineEditAnswer2->setText(q.answers[1]);
    ui->lineEditAnswer3->setText(q.answers[2]);
    ui->lineEditAnswer4->setText(q.answers[3]);
    ui->lineEditAnswer5->setText(q.answers[4]);
    ui->lineEditAnswer6->setText(q.answers[5]);

    ui->radioButtonCorrect1->setChecked(q.correctIndex[0]);
    ui->radioButtonCorrect2->setChecked(q.correctIndex[1]);
    ui->radioButtonCorrect3->setChecked(q.correctIndex[2]);
    ui->radioButtonCorrect4->setChecked(q.correctIndex[3]);
    ui->radioButtonCorrect5->setChecked(q.correctIndex[4]);
    ui->radioButtonCorrect6->setChecked(q.correctIndex[5]);


}

bool QuizWindow::readCreateForm(QuizQuestion &out, QString &err) const {
    out.prompt       = ui->lineEditQuestion->text();
    out.answers[0]   = ui->lineEditAnswer1->text();
    out.answers[1]   = ui->lineEditAnswer2->text();
    out.answers[2]   = ui->lineEditAnswer3->text();
    out.answers[3]   = ui->lineEditAnswer4->text();
    out.answers[4]   = ui->lineEditAnswer5->text();
    out.answers[5]   = ui->lineEditAnswer6->text();

    out.correctIndex[0] = ui->radioButtonCorrect1->isChecked();
    out.correctIndex[1] = ui->radioButtonCorrect2->isChecked();
    out.correctIndex[2] = ui->radioButtonCorrect3->isChecked();
    out.correctIndex[3] = ui->radioButtonCorrect4->isChecked();
    out.correctIndex[4] = ui->radioButtonCorrect5->isChecked();
    out.correctIndex[5] = ui->radioButtonCorrect6->isChecked();


    return true;
}
*/

// menu -> create page
void QuizWindow::on_pushButtonCreatePage_clicked() {
    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizCreate);
}

// menu -> study page
void QuizWindow::on_pushButtonStudyPage_clicked() {
    if (!quizBank->hasQuestions()) {
        QMessageBox::information(this, tr("Study Quiz"),tr("There are no questions to study yet."));
        return;
    }

    // Start a new study session using the current contents of the bank
    quizSession->start(quizBank->all());

    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizStudy);
    showStudyQuestion();
}

// "non-menu page" -> menu
void QuizWindow::on_pushButtonReturn_clicked() {
    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizMenu);
}

void QuizWindow::on_pushButtonReturn_2_clicked() {
    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizMenu);
}

void QuizWindow::on_pushButtonReturn_3_clicked() {
    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizMenu);
}

void QuizWindow::on_pushButtonReturn_4_clicked() {
    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizMenu);
}

// button functionality

// study page

void QuizWindow::showStudyQuestion() {
    if (!quizSession->hasQuestions()) {
        return;
    }

    const QuizQuestion &q = quizSession->currentQuestion();
    const int userIndex = quizSession->userAnswerFor(quizSession->currentIndex());
    QString QNumber = QString::number(i+1) + "/" + QString::number(questionBank.size());
    ui->textDisplayQuestionNumber->setPlainText(QNumber);

    const QuizQuestion& q = questionBank[i];

    // Question
    ui->textDisplayQuestion->setPlainText(q.prompt);

    // Answers (exactly six slots; empties allowed)
    ui->textDisplayAnswer1->setPlainText(q.answers[0]);
    ui->textDisplayAnswer2->setPlainText(q.answers[1]);
    ui->textDisplayAnswer3->setPlainText(q.answers[2]);
    ui->textDisplayAnswer4->setPlainText(q.answers[3]);
    ui->textDisplayAnswer5->setPlainText(q.answers[4]);
    ui->textDisplayAnswer6->setPlainText(q.answers[5]);

    // Restore radio selection

    ui->radioButtonAnswer1->setAutoExclusive(false);
    ui->radioButtonAnswer2->setAutoExclusive(false);
    ui->radioButtonAnswer3->setAutoExclusive(false);
    ui->radioButtonAnswer4->setAutoExclusive(false);
    ui->radioButtonAnswer5->setAutoExclusive(false);
    ui->radioButtonAnswer6->setAutoExclusive(false);

    ui->radioButtonAnswer1->setChecked(q.userIndex[0]);
    ui->radioButtonAnswer2->setChecked(q.userIndex[1]);
    ui->radioButtonAnswer3->setChecked(q.userIndex[2]);
    ui->radioButtonAnswer4->setChecked(q.userIndex[3]);
    ui->radioButtonAnswer5->setChecked(q.userIndex[4]);
    ui->radioButtonAnswer6->setChecked(q.userIndex[5]);
}

void QuizWindow::on_pushButtonNextQuestion_2_clicked() {
    if (!quizSession->hasQuestions()) return;

    // Save current selection
    quizSession->answerCurrent(currentStudySelection());

    if (quizSession->next()) {
        showStudyQuestion();
    }
}

void QuizWindow::on_pushButtonPreviousQuestion_2_clicked() {
    if (!quizSession->hasQuestions()) return;

    // Save current selection
    quizSession->answerCurrent(currentStudySelection());

    if (quizSession->previous()) {
        showStudyQuestion();
    }
}

void QuizWindow::on_pushButtonShuffle_clicked() {
    if (questionBank.isEmpty()) return;

    QVector<QuizQuestion> tempBank;
    std::srand(std::time(NULL));
    int size = questionBank.size();
    while (size > 0) {
        int rng = std::rand() % size;
        tempBank.append(questionBank[rng]);
        questionBank.removeAt(rng);
        size--;
    }
    questionBank = tempBank;
    showStudyQuestion(questionStudyIndex);
}


QVector<bool> QuizWindow::currentStudySelection() const {
    QVector<bool> indexes{
        ui->radioButtonAnswer1->isChecked(),
        ui->radioButtonAnswer2->isChecked(),
        ui->radioButtonAnswer3->isChecked(),
        ui->radioButtonAnswer4->isChecked(),
        ui->radioButtonAnswer5->isChecked(),
        ui->radioButtonAnswer6->isChecked(),
    };
    return indexes;
}

// study page -> results
void QuizWindow::on_pushButtonSubmitQuiz_clicked() {
    if (!quizSession->hasQuestions()) {
        QMessageBox::information(this, tr("Submit Quiz"),tr("There are no questions in this quiz."));
        return;
    }

    // Save the current question's selection before scoring
    quizSession->answerCurrent(currentStudySelection());

    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizResults);

    const int correct = quizSession->correctCount();
    const int total   = quizSession->questionCount();
    const double percentage = quizSession->percentage();

    ui->textResultNum->setPlainText(QString::number(correct));
    ui->textResultDen->setPlainText(QString::number(total));
    ui->textResultPer->setPlainText(QString::number(percentage * 100.0, 'f', 2));
}


/*
void QuizWindow::on_pushButtonSubmitQuiz_clicked() {
    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizResults);
    int correct = 0;
    int totalPoints = 0;
    for (int i = 0; i < questionBank.size(); i++) {
        for(int j = 0; j < 6; j++) {
            if (questionBank[i].correctIndex[j]) {
                totalPoints++;
                if (questionBank[i].userIndex[j]) {
                    correct++;
                }
            }
        }
    }
    double percentage = static_cast<double>(correct) / totalPoints;

    QString numerator = QString::number(correct);
    QString denominator = QString::number(totalPoints);
    QString result = QString::number(percentage*100, 'f', 2);
    ui->textResultNum->setPlainText(numerator);
    ui->textResultDen->setPlainText(denominator);
    ui->textResultPer->setPlainText(result);
}
*/

// results -> review
void QuizWindow::on_pushButtonReview_clicked() {
    if (!quizSession->hasQuestions()) return;

    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizReview);

    reviewIndex = 0;
    showStudyQuestionReview();
}

void QuizWindow::showStudyQuestionReview() {
    if (!quizSession->hasQuestions())
        return;

    const int count = quizSession->questionCount();
    if (reviewIndex < 0) reviewIndex = 0;
    if (reviewIndex >= count) reviewIndex = count - 1;

    const QuizQuestion &q = quizSession->questionAt(reviewIndex);
    const int userIndex = quizSession->userAnswerFor(reviewIndex);
    const int correctIndex = q.correctIndex;
    QString QNumber = QString::number(i+1) + "/" + QString::number(questionBank.size());
    ui->textDisplayQuestionNumber_2->setPlainText(QNumber);

    const QuizQuestion& q = questionBank[i];

    // Question
    ui->textDisplayQuestion_2->setPlainText(q.prompt);

    // Answers (exactly six slots; empties allowed)
    QPlainTextEdit* answers[6] = {
        ui->textDisplayAnswer1_2,
        ui->textDisplayAnswer2_2,
        ui->textDisplayAnswer3_2,
        ui->textDisplayAnswer4_2,
        ui->textDisplayAnswer5_2,
        ui->textDisplayAnswer6_2,
    };

    QLabel* checkmarks[6] = {
        ui->labelCheck1,
        ui->labelCheck2,
        ui->labelCheck3,
        ui->labelCheck4,
        ui->labelCheck5,
        ui->labelCheck6
    };

    for (int j = 0; j < 6; ++j) {
        answers[j]->setStyleSheet("border: none;");
        checkmarks[j]->setText("");
    }

    for (int j = 0; j < 6; ++j) {
        answers[j]->setPlainText(q.answers[j]);
        if (questionBank[i].userIndex[j] && questionBank[i].correctIndex[j]) {
            checkmarks[j]->setText(" ✅");
        }
        if (questionBank[i].userIndex[j] && !questionBank[i].correctIndex[j]) {
            checkmarks[j]->setText(" ❌");
        }
        if (!questionBank[i].userIndex[j] && questionBank[i].correctIndex[j]) {
            answers[j]->setStyleSheet("border: 3px solid lightgreen;");
        }

    }

    if (correctIndex >= 0 && correctIndex < 6) {
        answers[correctIndex]->setStyleSheet("border: 3px solid lightgreen;");
    }

}

void QuizWindow::on_pushButtonNextQuestion_3_clicked() {
    if (!quizSession->hasQuestions()) return;

    if (reviewIndex + 1 < quizSession->questionCount()) {
        ++reviewIndex;
        showStudyQuestionReview();
    }
}

void QuizWindow::on_pushButtonPreviousQuestion_3_clicked() {
    if (!quizSession->hasQuestions()) return;

    if (reviewIndex > 0) {
        --reviewIndex;
        showStudyQuestionReview();
    }
}



