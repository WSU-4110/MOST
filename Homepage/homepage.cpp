#include "homepage.h"
#include "ui_homepage.h"

homePage::homePage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::homePage)
{
    ui->setupUi(this);
}

homePage::~homePage()
{
    delete ui;
}



void homePage::on_createFlashCardButton_clicked()
{

    flashCardCreatorWindow = new flashCardMaker(this);
    flashCardCreatorWindow->show();
}

void homePage::on_studyMultipleChoiceButton_clicked()
{
    quizWindow = new QMainWindow(this);
    quizWindow->show();
}



void homePage::on_btnStudyFlashCards_clicked()
{
    FlashCardStudy* flashCardStudy = new FlashCardStudy();

    flashCardStudy->show();
    this->close();
}

