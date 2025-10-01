#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QStringList>

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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // add buttons
private slots:
    // menu to subpage buttons
    void on_pushButtonCreatePage_clicked();
    void on_pushButtonStudyPage_clicked();

    // back to menu buttons
    void on_pushButtonReturn_clicked();
    void on_pushButtonReturn_2_clicked();
    void on_pushButtonReturn_3_clicked();

    // quiz create page buttons
    void on_pushButtonCreateQuestion_clicked();
    void on_pushButtonOverwriteQuestion_clicked();
    void on_pushButtonDeleteQuestion_clicked();
    void on_pushButtonNextQuestion_clicked();
    void on_pushButtonPreviousQuestion_clicked();

    // study quiz page buttons
    void on_pushButtonNextQuestion_2_clicked();
    void on_pushButtonPreviousQuestion_2_clicked();

private:
    Ui::MainWindow *ui;

    // current idea for question storage management
    QVector<QuizQuestion> questionBank;
    int questionCurrent = -1;

    // current idea for displaying stored questions to study
    int questionStudyIndex = 0;
    void showStudyQuestion(int i);

    // basic helper functions
    bool readCreateForm(QuizQuestion &out, QString &err) const;
    void writeCreateForm(const QuizQuestion &q);
    void clearCreateForm();

    // radio button helper
    int currentStudySelection() const;


};
#endif // MAINWINDOW_H
