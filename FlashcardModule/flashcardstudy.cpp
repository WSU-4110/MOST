#include "flashcardstudy.h"
#include "ui_flashcardstudy.h"
#include "../Homepage/homepage.h"

FlashCardStudy::FlashCardStudy(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FlashCardStudy)
{
    ui->setupUi(this);
}

FlashCardStudy::~FlashCardStudy()
{
    delete ui;
}

void FlashCardStudy::on_btnHome_clicked()
{
    homePage* home = new homePage();
    home->show();
    this->close();
}

