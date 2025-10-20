#include "homepage.h"
#include "./ui_homepage.h"
homePage::homePage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::homePage)
    , flashCardCreatorWindow(nullptr)
    , quizWindow(nullptr)
    , flashCardStudyWindow(nullptr)
{
    ui->setupUi(this);

    // Connect the createFlashCardButton clicked signal if needed:
    connect(ui->createFlashCardButton, &QPushButton::clicked,
            this, &homePage::on_createFlashCardButton_clicked);
    connect(ui->studyMultipleChoiceButton, &QPushButton::clicked, this,
            &homePage::on_studyMultipleChoiceButton_clicked);
}

homePage::~homePage()
{
    delete ui;
    if (flashCardCreatorWindow)
        delete flashCardCreatorWindow;
    if(quizWindow)
        delete quizWindow;
    if(flashCardStudyWindow)
        delete flashCardStudyWindow;
}

void homePage::on_createFlashCardButton_clicked()
{

    if (!flashCardCreatorWindow) {
        flashCardCreatorWindow = new flashCardMaker();
    }
    this->hide();
    flashCardCreatorWindow->show();
    flashCardCreatorWindow->raise();
    flashCardCreatorWindow->activateWindow();

}
void homePage::on_studyMultipleChoiceButton_clicked(){

    if(!quizWindow){
        quizWindow=new QMainWindow(this);
    }

    quizWindow->show();
    quizWindow->raise();
    quizWindow->activateWindow();

}
void homePage::on_studyFlashCardsButton_clicked()
{

    if (!flashCardStudyWindow) {
        flashCardStudyWindow = new FlashCardStudy();
    }
    this->hide();
    flashCardStudyWindow->show();
    flashCardStudyWindow->raise();
    flashCardStudyWindow->activateWindow();

}
