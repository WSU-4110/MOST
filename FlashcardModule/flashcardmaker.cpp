#include "flashcardmaker.h"
#include "FlashcardModule/ui_flashcardmaker.h"
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
#include "../Database/databaseflashcard.h"
#include <QMessageBox>
#include <QString>
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
    QString frontText = ui->questionEdit->toPlainText().trimmed();
    QString backText = ui->answerEdit->toPlainText().trimmed();
    QString currentSetName = ui->setNameEdit->toPlainText().trimmed();

    if (currentSetName.isEmpty()) {
        QMessageBox::warning(this, "Missing Set Name", "Please enter a flashcard set name before saving.");
        return;
    }
    QString dbName = "flashcards_" + currentSetName + ".db";
    DatabaseFlashcard dbFlashcard;
    if (!dbFlashcard.createFlashcardSet(currentSetName)) {
        QMessageBox::critical(this, "Error", "Failed to create or open database for this set.");
        return;
    }

    for (const auto& card : flashcards) {
        QString question = card.first.trimmed();
        QString answer   = card.second.trimmed();
        if (question.isEmpty() || answer.isEmpty()) {
            continue;
        }
        dbFlashcard.addFlashcard(dbName,question ,answer);

    }
    bool success = dbFlashcard.addFlashcard(dbName, frontText, backText);
    if (success) {
        QMessageBox::information(this, "Saved", "Flashcard saved successfully!");
        ui->questionEdit->clear();
        ui->answerEdit->clear();
    } else {
        QMessageBox::critical(this, "Error", "Failed to save flashcard. Check database connection.");
    }

}
void flashCardMaker::on_homeButton_clicked(){
    emit goHome();
    this->close();
}
