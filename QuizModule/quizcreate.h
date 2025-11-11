/* Commented out until functional
#ifndef QUIZCREATE_H
#define QUIZCREATE_H

#include <QWidget>
#include "quizwindow.h"
#include "quizquestion.h"

class QuizWindow;

class QuizCreate : public QWidget
{
public:
    explicit QuizCreate(QWidget *parent, QuizWindow* mainWin);

private slots:
    // quiz create page buttons
    void on_pushButtonCreateQuestion_clicked();
    void on_pushButtonOverwriteQuestion_clicked();
    void on_pushButtonDeleteQuestion_clicked();
    void on_pushButtonNextQuestion_clicked();
    void on_pushButtonPreviousQuestion_clicked();

private:
    QuizWindow* quizWindow;
};

#endif // QUIZCREATE_H
*/
