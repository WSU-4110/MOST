#include "homepage.h"
#include "./ui_homepage.h"
homePage::homePage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::homePage)
    , flashCardCreatorWindow(nullptr)
{
    ui->setupUi(this);

    // Connect the createFlashCardButton clicked signal if needed:
    connect(ui->createFlashCardButton, &QPushButton::clicked,
            this, &homePage::on_createFlashCardButton_clicked);
}

homePage::~homePage()
{
    delete ui;
    if (flashCardCreatorWindow)
        delete flashCardCreatorWindow;
}

void homePage::on_createFlashCardButton_clicked()
{

    if (!flashCardCreatorWindow) {
        flashCardCreatorWindow = new flashCardMaker(this);
    }

    flashCardCreatorWindow->show();
    flashCardCreatorWindow->raise();
    flashCardCreatorWindow->activateWindow();

}
