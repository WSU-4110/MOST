#ifndef QUIZWINDOW_H
#define QUIZWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "quizquestion.h"
#include "quizbank.h"
#include "quizsession.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/*
// current idea for formatting questions/answers in a storeable format
struct QuizQuestion {
    QString prompt;
    QString answers[6];
    int correctIndex = 0;
    int userIndex = -1;
};
*/

class QuizWindow : public QMainWindow
{
    Q_OBJECT

public:
    QuizWindow(QWidget *parent = nullptr);
    ~QuizWindow();

    // add buttons
private slots:
    // menu to subpage buttons
    void on_pushButtonCreatePage_clicked();
    void on_pushButtonStudyPage_clicked();

    // back to menu buttons
    void on_pushButtonReturn_clicked();
    void on_pushButtonReturn_2_clicked();
    void on_pushButtonReturn_3_clicked();
    void on_pushButtonReturn_4_clicked();

    // quiz create page buttons
    void on_pushButtonCreateQuestion_clicked();
    void on_pushButtonOverwriteQuestion_clicked();
    void on_pushButtonDeleteQuestion_clicked();
    void on_pushButtonNextQuestion_clicked();
    void on_pushButtonPreviousQuestion_clicked();

    // study quiz page buttons
    void on_pushButtonNextQuestion_2_clicked();
    void on_pushButtonPreviousQuestion_2_clicked();
    void on_pushButtonSubmitQuiz_clicked();
    void on_pushButtonReview_clicked();

    //study review page buttons
    void on_pushButtonNextQuestion_3_clicked();
    void on_pushButtonPreviousQuestion_3_clicked();

private:
    Ui::MainWindow *ui;


    QuizBank quizBank;
    QuizSession quizSession;

    int reviewIndex = 0;

    // current idea for displaying stored questions to study
    int questionStudyIndex = 0;
    void showStudyQuestion();
    void showStudyQuestionReview();

    // basic helper functions
    bool readCreateForm(QuizQuestion &out, QString &err) const;
    void writeCreateForm(const QuizQuestion &q);
    void clearCreateForm();

    // radio button helper
    int currentStudySelection() const;


};
#endif // QUIZWINDOW_H
