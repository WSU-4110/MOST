#ifndef QUIZWINDOW_H
#define QUIZWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "quizbank.h"
#include "quizsession.h"
#include <QStringList>
#include <cstdlib>
#include <ctime>
#include "../Database/databasequiz.h"
#include <QPushButton>
#include "QuizModule/ui_quizwindow.h"

//Subpages
#include "quizmenu.h"
#include "quizcreate.h"
#include "quizstudy.h"
#include "quizreview.h"

QT_BEGIN_NAMESPACE
namespace Ui {
}
QT_END_NAMESPACE

/*
// current idea for formatting questions/answers in a storeable format
struct QuizQuestion {
    QString prompt;
    QString answers[6];
    QVector<bool> correctIndex{false, false, false, false, false, false};
    QVector<bool> userIndex{false, false, false, false, false, false};
};
*/

class QuizWindow : public QMainWindow
{
    Q_OBJECT

public:
    QuizWindow(QWidget *parent = nullptr);
    ~QuizWindow();

    // Access functions for the subpages to use
    Ui::QuizWindow* getUI() { return ui; }
    DatabaseQuiz* getQuizDB() { return quizDB; }
    QuizBank* getQuizBank() { return quizBank; }
    QuizSession* getQuizSession() { return quizSession; }

    void setQuizDB(DatabaseQuiz* db) { quizDB = db; }

    // Get pageQuizMenu buttons for quizmenu
    QPushButton* getLoadButton() const { return ui->pushButtonLoad; }

    // Get pageQuizCreate buttons for quizcreate
    QPushButton* getCreateQuestionButton() const { return ui->pushButtonCreateQuestion; }
    QPushButton* getOverwriteQuestionButton() const { return ui->pushButtonOverwriteQuestion; }
    QPushButton* getDeleteQuestionButton() const { return ui->pushButtonDeleteQuestion; }
    QPushButton* getPreviousQuestionButton() const { return ui->pushButtonPreviousQuestion; }
    QPushButton* getNextQuestionButton() const { return ui->pushButtonNextQuestion; }

    // Get pageQuizStudy buttons for quizstudy
    QPushButton* getNextQuestion2Button() const { return ui->pushButtonNextQuestion_2; }
    QPushButton* getPreviousQuestion2Button() const { return ui->pushButtonPreviousQuestion_2; }
    QPushButton* getShuffleButton() const { return ui->pushButtonShuffle; }
    QPushButton* getSubmitQuizButton() const { return ui->pushButtonSubmitQuiz; }

    // Get pageQuizReview buttons for quizReview
    QPushButton* getNextQuestion3Button() const { return ui->pushButtonNextQuestion_3; }
    QPushButton* getPreviousQuestion3Button() const { return ui->pushButtonPreviousQuestion_3; }

private slots:
    // menu to subpage buttons
    void on_pushButtonCreatePage_clicked();
    void on_pushButtonStudyPage_clicked();

    // back to menu buttons
    void on_pushButtonReturn_clicked();
    void on_pushButtonReturn_2_clicked();
    void on_pushButtonReturn_3_clicked();
    void on_pushButtonReturn_4_clicked();

    // study page -> results
    void on_pushButtonReview_clicked();

private:
    // Subpages
    QuizMenu* quizMenu = nullptr;
    QuizCreate* quizCreate = nullptr;
    QuizStudy* quizStudy = nullptr;
    QuizReview* quizReview = nullptr;

    QuizBank* quizBank = nullptr;
    QuizSession* quizSession = nullptr;

    // radio button helper
    QVector<bool> currentStudySelection() const;

protected:
    Ui::QuizWindow *ui = nullptr;
    DatabaseQuiz* quizDB = nullptr;
};
#endif // QUIZWINDOW_H
