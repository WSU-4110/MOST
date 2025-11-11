#include "../QuizModule/quizwindow.h"
#include "QuizModule/ui_quizwindow.h"
#include <QMessageBox> // back in for error messages 10/30/2025--KhaliphP
#include "quizqbuilder.h"

QuizWindow::QuizWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizMenu);
}

QuizWindow::~QuizWindow()
{
    delete ui;
}

/*
// this will allow popup messages to convey action success/failure
void MainWindow::showInfo(const QString& msg) {
    QMessageBox::information(this, tr("Quiz"), msg);
}
*/

// this will clear the fields from the create page
void QuizWindow::clearCreateForm() {
    ui->lineEditQuestion->clear();
    ui->lineEditAnswer1->clear();
    ui->lineEditAnswer2->clear();
    ui->lineEditAnswer3->clear();
    ui->lineEditAnswer4->clear();
    ui->lineEditAnswer5->clear();
    ui->lineEditAnswer6->clear();
    ui->comboBoxCorrect->setCurrentIndex(0);
}

void QuizWindow::writeCreateForm(const QuizQuestion &q) {
    ui->lineEditQuestion->setText(q.prompt);
    ui->lineEditAnswer1->setText(q.answers[0]);
    ui->lineEditAnswer2->setText(q.answers[1]);
    ui->lineEditAnswer3->setText(q.answers[2]);
    ui->lineEditAnswer4->setText(q.answers[3]);
    ui->lineEditAnswer5->setText(q.answers[4]);
    ui->lineEditAnswer6->setText(q.answers[5]);

    int index = (q.correctIndex >= 0 && q.correctIndex < 6) ? q.correctIndex : 0;
    ui->comboBoxCorrect->setCurrentIndex(index);
}

/*
bool QuizWindow::readCreateForm(QuizQuestion &out, QString &err) const {
    out.prompt       = ui->lineEditQuestion->text();
    out.answers[0]   = ui->lineEditAnswer1->text();
    out.answers[1]   = ui->lineEditAnswer2->text();
    out.answers[2]   = ui->lineEditAnswer3->text();
    out.answers[3]   = ui->lineEditAnswer4->text();
    out.answers[4]   = ui->lineEditAnswer5->text();
    out.answers[5]   = ui->lineEditAnswer6->text();

    int index = ui->comboBoxCorrect->currentIndex();
    if (index < 0) index = 0;
    if (index > 5) index = 5;
    out.correctIndex = index-1;

    return true;
}
*/

bool QuizWindow::readCreateForm(QuizQuestion &out, QString &err) const {

    QuizQBuilder b;

    const int correct = ui->comboBoxCorrect->currentIndex();

    const bool cr = b
        .prompt(ui->lineEditQuestion->text())
        .answer(0, ui->lineEditAnswer1->text())
        .answer(1, ui->lineEditAnswer2->text())
        .answer(2, ui->lineEditAnswer3->text())
        .answer(3, ui->lineEditAnswer4->text())
        .answer(4, ui->lineEditAnswer5->text())
        .answer(5, ui->lineEditAnswer6->text())
        .correctIndex(correct)
        .build(out, err);

    return cr;
}

// menu -> create page
void QuizWindow::on_pushButtonCreatePage_clicked() {
    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizCreate);
}

// menu -> study page
void QuizWindow::on_pushButtonStudyPage_clicked() {
    if (!quizBank.hasQuestions()) {
        QMessageBox::information(this, tr("Study Quiz"),tr("There are no questions to study yet."));
        return;
    }

    // Start a new study session using the current contents of the bank
    quizSession.start(quizBank.all());

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
// create page (add better error handling later)

// create question
void QuizWindow::on_pushButtonCreateQuestion_clicked() {
    QuizQuestion q; QString err;
    if (!readCreateForm(q, err)) {
        QMessageBox::warning(this, tr("Create Question"), err);
        return;
    }

    quizBank.addQuestion(q);

    if (const QuizQuestion* current = quizBank.current()) {
        writeCreateForm(*current);
    }
}

// overwrite question
void QuizWindow::on_pushButtonOverwriteQuestion_clicked() {
    QuizQuestion q; QString err;
    if (!readCreateForm(q, err)) {
        QMessageBox::warning(this, tr("Overwrite Question"), err);
        return;
    }

    if (!quizBank.overwriteCurrent(q)) {
        QMessageBox::warning(this, tr("Overwrite Question"),tr("There is no current question to overwrite."));
        return;
    }

    if (const QuizQuestion* cur = quizBank.current()) {
        writeCreateForm(*cur);
    }
}

// delete question
void QuizWindow::on_pushButtonDeleteQuestion_clicked() {
    if (!quizBank.deleteCurrent()) {
        clearCreateForm();
        return;
    }

    // either show new current or clear form if none
    if (const QuizQuestion* current = quizBank.current()) {
        writeCreateForm(*current);
    } else {
        clearCreateForm();
    }
}

void QuizWindow::on_pushButtonPreviousQuestion_clicked() {
    if (!quizBank.hasQuestions()) return;

    quizBank.previous();  // if already at first, this returns false and index stays
    if (const QuizQuestion* current = quizBank.current()) {
        writeCreateForm(*current);
    }
}

void QuizWindow::on_pushButtonNextQuestion_clicked() {
    if (!quizBank.hasQuestions()) {
        return;
    }

    quizBank.next();  // if already at last, this returns false and index stays

    if (const QuizQuestion* current = quizBank.current()) {
        writeCreateForm(*current);
    }
}


// study page

void QuizWindow::showStudyQuestion() {
    if (!quizSession.hasQuestions()) {
        return;
    }

    const QuizQuestion &q = quizSession.currentQuestion();
    const int userIndex = quizSession.userAnswerFor(quizSession.currentIndex());

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

    ui->radioButtonAnswer1->setChecked(q.userIndex == 0);
    ui->radioButtonAnswer2->setChecked(q.userIndex == 1);
    ui->radioButtonAnswer3->setChecked(q.userIndex == 2);
    ui->radioButtonAnswer4->setChecked(q.userIndex == 3);
    ui->radioButtonAnswer5->setChecked(q.userIndex == 4);
    ui->radioButtonAnswer6->setChecked(q.userIndex == 5);

    ui->radioButtonAnswer1->setAutoExclusive(true);
    ui->radioButtonAnswer2->setAutoExclusive(true);
    ui->radioButtonAnswer3->setAutoExclusive(true);
    ui->radioButtonAnswer4->setAutoExclusive(true);
    ui->radioButtonAnswer5->setAutoExclusive(true);
    ui->radioButtonAnswer6->setAutoExclusive(true);
}

void QuizWindow::on_pushButtonNextQuestion_2_clicked() {
    if (!quizSession.hasQuestions()) return;

    // Save current selection
    quizSession.answerCurrent(currentStudySelection());

    if (quizSession.next()) {
        showStudyQuestion();
    }
}

void QuizWindow::on_pushButtonPreviousQuestion_2_clicked() {
    if (!quizSession.hasQuestions()) return;

    // Save current selection
    quizSession.answerCurrent(currentStudySelection());

    if (quizSession.previous()) {
        showStudyQuestion();
    }
}

int QuizWindow::currentStudySelection() const {
    if (ui->radioButtonAnswer1->isChecked()) return 0;
    if (ui->radioButtonAnswer2->isChecked()) return 1;
    if (ui->radioButtonAnswer3->isChecked()) return 2;
    if (ui->radioButtonAnswer4->isChecked()) return 3;
    if (ui->radioButtonAnswer5->isChecked()) return 4;
    if (ui->radioButtonAnswer6->isChecked()) return 5;
    return -1;
}

// study page -> results
void QuizWindow::on_pushButtonSubmitQuiz_clicked() {
    if (!quizSession.hasQuestions()) {
        QMessageBox::information(this, tr("Submit Quiz"),tr("There are no questions in this quiz."));
        return;
    }

    // Save the current question's selection before scoring
    quizSession.answerCurrent(currentStudySelection());

    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizResults);

    const int correct = quizSession.correctCount();
    const int total   = quizSession.questionCount();
    const double percentage = quizSession.percentage();

    ui->textResultNum->setPlainText(QString::number(correct));
    ui->textResultDen->setPlainText(QString::number(total));
    ui->textResultPer->setPlainText(QString::number(percentage * 100.0, 'f', 2));
}


/*
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

// results -> review
void QuizWindow::on_pushButtonReview_clicked() {
    if (!quizSession.hasQuestions()) return;

    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizReview);

    reviewIndex = 0;
    showStudyQuestionReview();
}

void QuizWindow::showStudyQuestionReview() {
    if (!quizSession.hasQuestions())
        return;

    const int count = quizSession.questionCount();
    if (reviewIndex < 0) reviewIndex = 0;
    if (reviewIndex >= count) reviewIndex = count - 1;

    const QuizQuestion &q = quizSession.questionAt(reviewIndex);
    const int userIndex = quizSession.userAnswerFor(reviewIndex);
    const int correctIndex = q.correctIndex;

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

        if (j == userIndex && j == correctIndex) {
            // User chose this and it was correct
            checkmarks[j]->setText(" ✅");
        }
        else if (j == userIndex && j != correctIndex) {
            checkmarks[j]->setText(" ❌");
            //answers[questionBank[i].correctIndex]->setStyleSheet("border: 3px solid lightgreen;");
        }
    }

    if (correctIndex >= 0 && correctIndex < 6) {
        answers[correctIndex]->setStyleSheet("border: 3px solid lightgreen;");
    }

}

void QuizWindow::on_pushButtonNextQuestion_3_clicked() {
    if (!quizSession.hasQuestions()) return;

    if (reviewIndex + 1 < quizSession.questionCount()) {
        ++reviewIndex;
        showStudyQuestionReview();
    }
}

void QuizWindow::on_pushButtonPreviousQuestion_3_clicked() {
    if (!quizSession.hasQuestions()) return;

    if (reviewIndex > 0) {
        --reviewIndex;
        showStudyQuestionReview();
    }
}
