#ifndef QUIZMENU_H
#define QUIZMENU_H

#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>

class QuizWindow;

class QuizMenu : public QWidget
{
    Q_OBJECT

public:
    explicit QuizMenu(QuizWindow* quizWin, QWidget *parent);

private slots:
    void onLoadButtonClicked();

private:
    QuizWindow* quizWindow;
};

#endif // QUIZMENU_H
