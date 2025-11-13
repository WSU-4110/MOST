#include "homepage.h"
#include "ui_homepage.h"

homePage::homePage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::homePage)
    , flashCardCreatorWindow(nullptr)
    , quizWindow(nullptr)
{
    ui->setupUi(this);

    ui->lblQuizDescription->setWordWrap(true);
    ui->lblFlashCardDescription->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

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
}

void homePage::on_createFlashCardButton_clicked()
{

    if (!flashCardCreatorWindow) {
        flashCardCreatorWindow = new flashCardMaker();
    }
    connect(flashCardCreatorWindow, &flashCardMaker::goHome,this, &homePage::show);
    this->hide();
    flashCardCreatorWindow->show();
    flashCardCreatorWindow->raise();
    flashCardCreatorWindow->activateWindow();

}
void homePage::on_studyMultipleChoiceButton_clicked(){

    if(!quizWindow){
        quizWindow=new QuizWindow(this);
    }

    quizWindow->show();
    quizWindow->raise();
    quizWindow->activateWindow();

}



void homePage::on_btnStudyFlashCards_clicked()
{
    QString setName = "default";
    QString dbName = "flashcards_" + setName + ".db";

    FlashCardStudy* flashCardStudy = new FlashCardStudy();

    flashCardStudy->show();
    this->close();
}

