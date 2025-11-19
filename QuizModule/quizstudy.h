#ifndef QUIZSTUDY_H
#define QUIZSTUDY_H

#include <QWidget>

class QuizWindow;

class QuizStudy : public QWidget
{
public:
    explicit QuizStudy(QuizWindow* quizWin, QWidget *parent);
    void showStudyQuestion();

private slots:
    // study quiz page buttons
    void on_pushButtonNextQuestion_2_clicked();
    void on_pushButtonPreviousQuestion_2_clicked();
    void on_pushButtonShuffle_clicked();
    void on_pushButtonSubmitQuiz_clicked();

private:
    QVector<bool> currentStudySelection() const;
    void updateQuestionDisplayLabel();

    QuizWindow* quizWindow;
};

#endif // QUIZSTUDY_H
