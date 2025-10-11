#include "flashcardmaker.h"
#include "FlashcardModule/ui_flashcardmaker.h"
#include "DatabaseManager.h"

#include <QMessageBox>
#include <QRegularExpression>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

flashCardMaker::flashCardMaker(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::flashCardMaker)
{
    ui->setupUi(this);
    ui->cardCount->setText("Card Count: 0");

    // Connect to the database using the Singleton
    QString dbPath = "flashcards.db"; // You can make this configurable or move it to AppData later
    if (!DatabaseManager::instance().connect(dbPath)) {
        QMessageBox::critical(this, "Database Error", "Could not connect to database.");
        return;
    }

    if (!DatabaseManager::instance().setupTables()) {
        QMessageBox::critical(this, "Database Error", "Could not set up database tables.");
    }
}

flashCardMaker::~flashCardMaker()
{
    delete ui;
}

void flashCardMaker::on_nextQuestionButton_clicked()
{
    QString question = ui->questionEdit->toPlainText().trimmed();
    QString answer = ui->answerEdit->toPlainText().trimmed();

    if (question.isEmpty() || answer.isEmpty()) {
        QMessageBox::warning(this, "Incomplete", "You need both a question and an answer.");
        return;
    }

    flashcards.append(qMakePair(question, answer));
    cardCount++;

    ui->cardCount->setText(QString("Cards: %1").arg(cardCount));
    ui->questionEdit->clear();
    ui->answerEdit->clear();
}

void flashCardMaker::on_saveButton_clicked()
{
    QString setName = ui->setNameEdit->toPlainText().trimmed();
    if (setName.isEmpty()) {
        QMessageBox::warning(this, "Missing Name", "Please enter a name for the flash card set.");
        return;
    }

    // Add last unsaved card if the user forgot to click "Next"
    QString question = ui->questionEdit->toPlainText().trimmed();
    QString answer = ui->answerEdit->toPlainText().trimmed();
    if (!question.isEmpty() && !answer.isEmpty()) {
        flashcards.append(qMakePair(question, answer));
        cardCount++;
        ui->cardCount->setText(QString("Cards: %1").arg(cardCount));
        ui->questionEdit->clear();
        ui->answerEdit->clear();
    }

    if (flashcards.isEmpty()) {
        QMessageBox::warning(this, "Error", "No cards to save.");
        return;
    }

    QSqlQuery query(DatabaseManager::instance().database());
    bool allSuccess = true;

    for (const auto &card : flashcards) {
        query.prepare("INSERT INTO flashcards (set_name, question, answer) VALUES (?, ?, ?)");
        query.addBindValue(setName);
        query.addBindValue(card.first);
        query.addBindValue(card.second);

        if (!query.exec()) {
            allSuccess = false;
            QMessageBox::critical(this, "Database Error", query.lastError().text());
            break;
        }
    }

    if (allSuccess) {
        QMessageBox::information(this, "Saved", QString("Flashcards saved under set '%1'.").arg(setName));
        flashcards.clear();
        cardCount = 0;
        ui->cardCount->setText("Cards: 0");
    }
}
