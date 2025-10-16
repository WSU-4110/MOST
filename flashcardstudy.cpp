#include "flashcardstudy.h"
#include "ui_flashcardstudy.h"

FlashCardStudy::FlashCardStudy(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FlashCardStudy)
{
    ui->setupUi(this);
    displayQuestion = "whats a process";
    displayAnswer = "executing program in computer";

    // Show the question initially
    ui->questionLabel->setText(displayQuestion);
}

FlashCardStudy::~FlashCardStudy()
{
    delete ui;
}
void FlashCardStudy::setFlashCard(const QString &question, const QString &answer)
{
    displayQuestion = question;
    displayAnswer = answer;
    showingQuestion = true;

    ui->questionLabel->setText(displayQuestion);
}
void FlashCardStudy::on_flipButton_clicked()
{
    if (showingQuestion)
    {
        ui->questionLabel->setText(displayAnswer);
        showingQuestion = false;
    }
    else
    {
        ui->questionLabel->setText(displayQuestion);
        showingQuestion = true;
    }
}
