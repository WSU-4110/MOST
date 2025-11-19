#ifndef QUIZCREATE_H
#define QUIZCREATE_H

#include <QWidget>
#include "quizquestion.h"

class QuizWindow;

class QuizCreate : public QWidget
{
public:
    explicit QuizCreate(QuizWindow* quizWin, QWidget *parent);
    void writeCreateForm(const QuizQuestion &q);
private slots:
    // quiz create page buttons
    void on_pushButtonCreateQuestion_clicked();
    void on_pushButtonOverwriteQuestion_clicked();
    void on_pushButtonDeleteQuestion_clicked();
    void on_pushButtonNextQuestion_clicked();
    void on_pushButtonPreviousQuestion_clicked();
    void on_pushButtonSetName_clicked();

private:
    QuizWindow* quizWindow;

protected:
    // basic helper functions
    bool readCreateForm(QuizQuestion &out, QString &err) const;
    void clearCreateForm();
    void updateQuestionCountLabel();
};

#endif // QUIZCREATE_H
