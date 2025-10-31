#ifndef QUIZWINDOW_H
#define QUIZWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QStringList>
#include "../Database/databasequiz.h"
#include "../Database/databasequizloader.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

// current idea for formatting questions/answers in a storeable format
struct QuizQuestion {
    QString prompt;
    QString answers[6];
    int correctIndex = 0;
    int userIndex = -1;
};

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

    void on_pushButtonLoad_clicked();

private:
    Ui::MainWindow *ui;

    // current idea for question storage management
    QVector<QuizQuestion> questionBank;
    int questionCurrent = -1;

    // current idea for displaying stored questions to study
    int questionStudyIndex = 0;
    void showStudyQuestion(int i);
    void showStudyQuestionReview(int i);

    // basic helper functions
    bool readCreateForm(QuizQuestion &out, QString &err) const;
    void writeCreateForm(const QuizQuestion &q);
    void clearCreateForm();

    // radio button helper
    int currentStudySelection() const;

    DatabaseQuizLoader* m_quizLoader;  // Command object
    DatabaseQuiz* m_quizModel;  // Receiver class (DatabaseQuiz)
};
#endif // QUIZWINDOW_H
