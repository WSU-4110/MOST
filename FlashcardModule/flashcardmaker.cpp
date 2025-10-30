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

}
void flashCardMaker::on_homeButton_clicked(){
    emit goHome();
    this->close();
}
