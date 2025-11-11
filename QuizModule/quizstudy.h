/* Commented out until functional
#ifndef QUIZSTUDY_H
#define QUIZSTUDY_H

#include <QWidget>
#include "quizwindow.h"

class QuizStudy : public QWidget
{
public:
    explicit QuizStudy(QWidget *parent, QuizWindow* mainWin);

private slots:
    // study quiz page buttons
    void on_pushButtonNextQuestion_2_clicked();
    void on_pushButtonPreviousQuestion_2_clicked();
    void on_pushButtonSubmitQuiz_clicked();

private:
    QuizWindow* mainWindow;
};

#endif // QUIZSTUDY_H
*/
