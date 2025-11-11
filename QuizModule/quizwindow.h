#ifndef QUIZWINDOW_H
#define QUIZWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QStringList>
#include "quizquestion.h"
#include "../Database/databasequiz.h"
#include <QPushButton>
#include "QuizModule/ui_quizwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui {
}
QT_END_NAMESPACE

class QuizMenu;
//class QuizCreate;

class QuizWindow : public QMainWindow
{
    Q_OBJECT

public:
    QuizWindow(QWidget *parent = nullptr);
    ~QuizWindow();

    // db Access functions for the subpages to use
    DatabaseQuiz* getQuizDB() { return quizDB; }
    void setQuizDB(DatabaseQuiz* db) { quizDB = db; }

    QPushButton* getLoadButton() const { return ui->pushButtonLoad; }

private slots:
    // menu to subpage buttons
    void on_pushButtonCreatePage_clicked();
    void on_pushButtonStudyPage_clicked();

    // back to menu buttons
    void on_pushButtonReturn_clicked();
    void on_pushButtonReturn_2_clicked();
    void on_pushButtonReturn_3_clicked();
    void on_pushButtonReturn_4_clicked();

    // study quiz page buttons
    //void on_pushButtonNextQuestion_2_clicked();
    //void on_pushButtonPreviousQuestion_2_clicked();
    // study page -> results
    // study page -> results
    //void on_pushButtonSubmitQuiz_clicked();
    void on_pushButtonReview_clicked();

    //study review page buttons
    void on_pushButtonNextQuestion_3_clicked();
    void on_pushButtonPreviousQuestion_3_clicked();

private:
    QuizMenu* quizMenu = nullptr;
    //QuizCreate* quizCreate = nullptr;

    // current idea for question storage management
    QVector<QuizQuestion> questionBank;
    int questionCurrent = -1;

    // current idea for displaying stored questions to study
    int questionStudyIndex = 0;
    void showStudyQuestion(int i);
    void showStudyQuestionReview(int i);

    // radio button helper
    int currentStudySelection() const;

protected:
    Ui::QuizWindow *ui = nullptr;
    DatabaseQuiz* quizDB = nullptr;

    // basic helper functions
    bool readCreateForm(QuizQuestion &out, QString &err) const;
    void writeCreateForm(const QuizQuestion &q);
    void clearCreateForm();
};
#endif // QUIZWINDOW_H
