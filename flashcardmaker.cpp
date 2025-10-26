#include "flashcardmaker.h"
#include "./ui_flashcardmaker.h"
#include <QMessageBox> //added
#include <QFile> //added
#include <QTextStream> //added
#include <QRegularExpression>
flashCardMaker::flashCardMaker(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::flashCardMaker)
{
    ui->setupUi(this);
    ui->cardCount->setText("Card Count: 0");

}

flashCardMaker::~flashCardMaker()
{
    delete ui;
}

void flashCardMaker::on_nextQuestionButton_clicked()
{
    QString question = ui -> questionEdit->toPlainText().trimmed();
    QString answer = ui->answerEdit->toPlainText().trimmed();

    if(question.isEmpty() || answer.isEmpty()){
        QMessageBox::warning(this,"incomplete","you need both question and answer"); //added
        return;
    }
    flashcards.append(qMakePair(question,answer));
    cardCount++;

    ui->cardCount->setText(QString("Cards: %1").arg(cardCount));
    ui->questionEdit->clear();
    ui->answerEdit->clear();
}
void flashCardMaker::on_saveButton_clicked(){
    QString setName = ui->setNameEdit->toPlainText().trimmed();
    if(setName.isEmpty()){
        QMessageBox::warning(this, "missing Name", "please enter a name for the flash card set.");
        return;
    }
    if(flashcards.isEmpty()){
        QMessageBox::warning(this,"Error","No cards to save");
        return;
    }
    QString safeName=setName;
    safeName.replace(QRegularExpression("[^a-zA-z0-9_-]"),"_");
    QString filename=safeName +".txt";

    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QMessageBox::critical(this,"Error","Could not open file to save");
        return;
    }
    QTextStream out(&file);
    out<<"Flash card set: "<<setName<<"\n";
    out<<"Total cards: "<<flashcards.size()<<"\n\n";

    for(const auto &card : flashcards){
        out<<"Q: "<<card.first<<"\n";
        out<<"A: "<<card.second<<"\n\n";
    }
    file.close();
    QMessageBox::information(this,"Saved",QString("flash Cards saved as \"%1\"").arg(filename));
}
