#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QMessageBox> commented out, but may be used for pop up messages

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizMenu);
}

MainWindow::~MainWindow()
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
void MainWindow::clearCreateForm() {
    ui->lineEditQuestion->clear();
    ui->lineEditAnswer1->clear();
    ui->lineEditAnswer2->clear();
    ui->lineEditAnswer3->clear();
    ui->lineEditAnswer4->clear();
    ui->lineEditAnswer5->clear();
    ui->lineEditAnswer6->clear();
    ui->comboBoxCorrect->setCurrentIndex(0);
}

void MainWindow::writeCreateForm(const QuizQuestion &q) {
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

bool MainWindow::readCreateForm(QuizQuestion &out, QString &err) const {
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
    out.correctIndex = index;

    return true;
}

// menu -> create page
void MainWindow::on_pushButtonCreatePage_clicked() {
    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizCreate);
}

// menu -> study page
void MainWindow::on_pushButtonStudyPage_clicked() {
    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizStudy);
    if (!questionBank.isEmpty()) {
        questionStudyIndex = 0;
        showStudyQuestion(questionStudyIndex);
    }
}

// "non-menu page" -> menu
void MainWindow::on_pushButtonReturn_clicked() {
    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizMenu);
}

void MainWindow::on_pushButtonReturn_2_clicked() {
    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizMenu);
}

void MainWindow::on_pushButtonReturn_3_clicked() {
    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizMenu);
}

// button functionality
// create page (add better error handling later)

// create question
void MainWindow::on_pushButtonCreateQuestion_clicked() {
    QuizQuestion q; QString err;
    if (!readCreateForm(q, err)) {
        return;
    }
    questionBank.push_back(q);
    questionCurrent = questionBank.size() - 1;
}

// overwrite question
void MainWindow::on_pushButtonOverwriteQuestion_clicked() {
    if (questionCurrent < 0 || questionCurrent >= questionBank.size()) {  // temp fix for out of bounds errors
        return;
    }
    QuizQuestion q; QString err;
    if (!readCreateForm(q, err)) return;
    questionBank[questionCurrent] = q;

    writeCreateForm(questionBank[questionCurrent]);
}

void MainWindow::on_pushButtonDeleteQuestion_clicked() {
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

void MainWindow::on_pushButtonPreviousQuestion_clicked() {
    if (questionBank.isEmpty()) return;
    if (questionCurrent <= 0) {             // temp fix for out of bounds errors? something would cause app to crash
        questionCurrent = 0;
    } else {
        --questionCurrent;
    }
    writeCreateForm(questionBank[questionCurrent]);
}

void MainWindow::on_pushButtonNextQuestion_clicked() {
    if (questionBank.isEmpty()) return;
    if (questionCurrent + 1 >= questionBank.size()) {       // temp fix for out of bounds errors? something would cause app to crash
        questionCurrent = questionBank.size() - 1;
    } else {
        ++questionCurrent;
    }
    writeCreateForm(questionBank[questionCurrent]);
}


// study page

void MainWindow::showStudyQuestion(int i) {
    if (questionBank.isEmpty()) return;
    if (i < 0) i = 0;
    if (i >= questionBank.size()) i = questionBank.size() - 1;

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

void MainWindow::on_pushButtonNextQuestion_2_clicked() {
    if (questionBank.isEmpty()) return;

    questionBank[questionStudyIndex].userIndex = currentStudySelection();

    if (questionStudyIndex + 1 < questionBank.size()) {
        ++questionStudyIndex;
        showStudyQuestion(questionStudyIndex);
    }
}

void MainWindow::on_pushButtonPreviousQuestion_2_clicked() {
    if (questionBank.isEmpty()) return;

    questionBank[questionStudyIndex].userIndex = currentStudySelection();

    if (questionStudyIndex > 0) {
        --questionStudyIndex;
        showStudyQuestion(questionStudyIndex);
    }
}

int MainWindow::currentStudySelection() const {
    if (ui->radioButtonAnswer1->isChecked()) return 0;
    if (ui->radioButtonAnswer2->isChecked()) return 1;
    if (ui->radioButtonAnswer3->isChecked()) return 2;
    if (ui->radioButtonAnswer4->isChecked()) return 3;
    if (ui->radioButtonAnswer5->isChecked()) return 4;
    if (ui->radioButtonAnswer6->isChecked()) return 5;
    return -1;
}

// study page -> results
void MainWindow::on_pushButtonSubmitQuiz_clicked() {
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
