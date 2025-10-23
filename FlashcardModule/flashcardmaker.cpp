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

flashCardMaker::flashCardMaker(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::flashCardMaker)
{
    ui->setupUi(this);
    ui->cardCount->setText("Card Count: 0");

    // initialize sqlite
    // get the current project directory
    QString projectDir = QDir::currentPath();  // get the path where the program is running

    // set the database filename based on the user input
    QString dbFile = projectDir + "/flashcards.db";  // default name to test with

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName(dbFile);  // use the filename

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    qDebug() << "Database opened at:" << db.databaseName(); // debug to see where the file is saved

    // create table if it doesn't already exist
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS flashcards ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "set_name TEXT, "
                    "question TEXT, "
                    "answer TEXT)")) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
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
    // get the set name from the user input field
    QString setName = ui->setNameEdit->toPlainText().trimmed();  // get the actual input

    if(setName.isEmpty()){
        QMessageBox::warning(this, "Missing Set Name", "Please enter a name for the flash card set.");
        return;
    }

    // replace the name and fill whitespaces with valid filename characters
    QString safeName = setName;
    safeName.replace(QRegularExpression("[^a-zA-Z0-9_-]"), "_");  // replace any invalid filename characters

    // get current working directory
    QString projectDir = QDir::currentPath();  // get the path where the program is running

    // combine the set name with the database filename
    QString dbFile = projectDir + "/" + safeName + ".db";  // use sanitized set name for the filename

    // set the database file name correctly
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbFile);  // set the dynamic filename here

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    qDebug() << "Database opened at:" << db.databaseName(); // debug to see where the file is saved

    // create table if it doesn't already exist
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS flashcards ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "set_name TEXT, "
                    "question TEXT, "
                    "answer TEXT)")) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }

    // send sql queries to the database to insert flashcards
    bool success = true;
    for (const auto &card : flashcards) {
        // template to insert data into table columns
        query.prepare("INSERT INTO flashcards (set_name, question, answer) "
                      "VALUES (:set_name, :question, :answer)");

        // bind placeholders to actual values
        query.bindValue(":set_name", safeName);  // using sanitized set name
        query.bindValue(":question", card.first);
        query.bindValue(":answer", card.second);

        // execute the sql command
        if (!query.exec()) {
            qDebug() << "Insert error:" << query.lastError().text();
            success = false;
        }
    }

    if (success) {
        QMessageBox::information(this, "Saved",
                                 QString("Flashcards saved successfully under set name \"%1\".").arg(safeName));

        // clear in-memory list and reset counter
        flashcards.clear();
        cardCount = 0;
        ui->cardCount->setText("Cards: 0");

        // optionally clear text boxes
        ui->setNameEdit->clear();
        ui->questionEdit->clear();
        ui->answerEdit->clear();
    } else {
        QMessageBox::critical(this, "Error", "One or more flashcards failed to save.");
    }
}
