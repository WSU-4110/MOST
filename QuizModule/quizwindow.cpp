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
    quizReview = new QuizReview(this, nullptr);
}

QuizWindow::~QuizWindow()
{
    delete ui;
    delete quizDB;
    delete quizBank;
    delete quizSession;
    delete quizMenu;
    delete quizCreate;
    delete quizStudy;
    delete quizReview;
}

// menu -> create page
void QuizWindow::on_pushButtonCreatePage_clicked() {
    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizCreate);
    ui->radioButtonCorrect1->setAutoExclusive(false);
    ui->radioButtonCorrect2->setAutoExclusive(false);
    ui->radioButtonCorrect3->setAutoExclusive(false);
    ui->radioButtonCorrect4->setAutoExclusive(false);
    ui->radioButtonCorrect5->setAutoExclusive(false);
    ui->radioButtonCorrect6->setAutoExclusive(false);
    if (quizBank->hasQuestions()) {
        quizCreate->writeCreateForm(quizBank->getQuestions(0));
    }
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
    if (quizBank->getName() != nullptr) {
        ui->lineEditSetTitle->setText(quizBank->getName());
    }
    quizStudy->showStudyQuestion();
}

// "non-menu page" -> menu
void QuizWindow::on_pushButtonReturn_clicked() {
    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizMenu);
    if (quizBank->getName() != nullptr) {
        ui->labelMenuCurrentSet->setText(quizBank->getName());
    }
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


// results -> review
void QuizWindow::on_pushButtonReview_clicked() {
    if (!quizSession->hasQuestions()) return;

    ui->stackedQuizWidget->setCurrentWidget(ui->pageQuizReview);
    if (quizBank->getName() != nullptr) {
        ui->lineEditSetTitle_3->setText(quizBank->getName());
    }

    quizReview->setReviewIndex(0);
    quizReview->showStudyQuestionReview(0);
}



