#ifndef QUIZMENU_H
#define QUIZMENU_H

#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include "quizbank.h"

class QuizWindow;

class QuizMenu : public QWidget
{
    Q_OBJECT

public:
    explicit QuizMenu(QuizWindow* quizWin, QWidget *parent);

private slots:
    void onLoadButtonClicked();
    void onSaveButtonClicked();
private:
    void loadDbToQuizBank(QuizBank* bank);
    QuizWindow* quizWindow;
};

#endif // QUIZMENU_H
