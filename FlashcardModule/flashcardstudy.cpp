#include "flashcardstudy.h"
#include "ui_flashcardstudy.h"

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
