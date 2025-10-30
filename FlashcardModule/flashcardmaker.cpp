#include "flashcardmaker.h"
#include "FlashcardModule/ui_flashcardmaker.h"
#include "flashCardData.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QStandardPaths>
#include <QDir>

flashCardMaker::flashCardMaker(const QString &setName,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::flashCardMaker)
{
    ui->setupUi(this);
    ui->cardCount->setText("Card Count: 0");
    cardData=new flashCardData(setName);
}

flashCardMaker::~flashCardMaker()
{
    delete ui;
    delete cardData;
}

void flashCardMaker::on_nextQuestionButton_clicked()
{
    QString question = ui->questionEdit->toPlainText().trimmed();
    QString answer = ui->answerEdit->toPlainText().trimmed();

    if(question.isEmpty() || answer.isEmpty()){
        QMessageBox::warning(this,"incomplete","you need both question and answer"); // show warning if question or answer is empty
        return;
    }
    flashcards.append(qMakePair(question,answer));
    cardCount++;

    ui->cardCount->setText(QString("Cards: %1").arg(cardCount));
    ui->questionEdit->clear();
    ui->answerEdit->clear();
}

void flashCardMaker::on_saveButton_clicked(){
    bool saveSuccess=false;
        for (const auto& card : flashcards) {
            QString question = card.first;
            QString answer = card.second;
            if(cardData->addCard(question, answer)){
                saveSuccess=true;
            }
            else{
                saveSuccess=false;
                break;
            }

        }
        if(saveSuccess){
        flashcards.clear();
        cardCount = 0;
        ui->cardCount->setText("Card Count: 0");
        QMessageBox::critical(this,"Save Successful","cards successfully saved");
        }
        else {
        QMessageBox::critical(this, "Save Error", "Failed to save any cards.");
        }


}



void flashCardMaker::on_homeButton_clicked(){
    emit goHome();
    this->close();
}
