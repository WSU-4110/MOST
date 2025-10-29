#include "flashcardstudy.h"
#include "ui_flashcardstudy.h"

FlashCardStudy::FlashCardStudy(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FlashCardStudy)
{
    ui->setupUi(this);
    displayQuestion = "What's a process?";
    displayAnswer = "Executing a program in a computer";

    // Show the question initially
    ui->questionLabel->setText(displayQuestion);

    // Ensure the next button is connected to the correct slot
    connect(ui->nextButton, &QPushButton::clicked, this, &FlashCardStudy::on_nextButton_clicked);

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

void FlashCardStudy::on_nextButton_clicked()
{
    setFlashCard("What's a variable?", "A container for storing data");
}

void FlashCardStudy::on_homeButton_clicked()
{
    emit goHome();
    this->close();
}
