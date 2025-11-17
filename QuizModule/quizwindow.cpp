#include "quizwindow.h"
#include "QuizModule/ui_quizwindow.h"
#include <QMessageBox> // back in for error messages 10/30/2025--KhaliphP
#include "quizqbuilder.h"
#include "quizbank.h"
#include "quizsession.h"

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
    quizStudy = new QuizStudy(this, nullptr);

    //from merge (fix later?)
    ui->radioButtonCorrect1->setAutoExclusive(false);
    ui->radioButtonCorrect2->setAutoExclusive(false);
    ui->radioButtonCorrect3->setAutoExclusive(false);
    ui->radioButtonCorrect4->setAutoExclusive(false);
    ui->radioButtonCorrect5->setAutoExclusive(false);
    ui->radioButtonCorrect6->setAutoExclusive(false);

    //FOR TESTING:
    QVector<QuizQuestion> testQuestions;
    QuizQuestion q1;
    q1.prompt = "Test question 1";
    q1.answers[0] = "Answer 1";
    q1.answers[1] = "Answer 2";
    q1.answers[2] = "Answer 3";
    q1.answers[3] = "Answer 4";
    q1.answers[4] = "Answer 5";
    q1.answers[5] = "Answer 6";
    q1.correctIndex = 0;
    QuizQuestion q2;
    q2.prompt = "2 + 2 = ?";
    q2.answers[0] = "1";
    q2.answers[1] = "2";
    q2.answers[2] = "3";
    q2.answers[3] = "4";
    q2.answers[4] = "5";
    q2.answers[5] = "6";
    q2.correctIndex = 3;
    QuizQuestion q3;
    q3.prompt = "KFmkdsfmksfmmfks";
    q3.answers[0] = "1";
    q3.answers[1] = "2";
    q3.answers[2] = "3";
    q3.answers[3] = "4";
    q3.answers[4] = "5";
    q3.answers[5] = "6";
    q3.correctIndex = 1;
    quizBank->addQuestion(q1);
    quizBank->addQuestion(q2);
    quizBank->addQuestion(q3);
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
    quizStudy->showStudyQuestion();
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
    //showStudyQuestionReview();
}

/* Comment out for now
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
*/

void QuizWindow::on_pushButtonNextQuestion_3_clicked() {
    if (!quizSession->hasQuestions()) return;

    if (reviewIndex + 1 < quizSession->questionCount()) {
        ++reviewIndex;
        //showStudyQuestionReview();
    }
}

void QuizWindow::on_pushButtonPreviousQuestion_3_clicked() {
    if (!quizSession->hasQuestions()) return;

    if (reviewIndex > 0) {
        --reviewIndex;
        //showStudyQuestionReview();
    }
}



