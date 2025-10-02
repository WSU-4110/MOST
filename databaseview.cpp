#include "databaseview.h"
#include "ui_databaseview.h"

#include "mainwindow.h"

#include <QSqlDatabase>
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlTableModel>

databaseview::databaseview(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::databaseview)
{
    ui->setupUi(this);

    // show table on side
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("flashcards");
    model->select();  // Load data
    ui->tableView->setModel(model);

    // displays first card in database
    QSqlQuery query("SELECT * FROM flashcards");
    query.next();
    ui->displayCard_front->setText(query.value(1).toString());
    ui->displayCard_back->setText(query.value(2).toString());
}

databaseview::~databaseview()
{
    delete ui;
}

void databaseview::on_btnShowCards_clicked()
{
    // get flashcards from db
    QSqlQuery query("SELECT * FROM flashcards");

    // print flashcard results in debug
    while (query.next()) {
        int id = query.value(0).toInt();
        QString question = query.value(1).toString();
        QString answer = query.value(2).toString();

        qDebug() << "Flashcard ID:" << id << "Question:" << question << "Answer:" << answer;
    }
}

void databaseview::on_btnInsertCard_clicked()
{
    QString cardFront = ui->ptentry_front->toPlainText();
    QString cardBack = ui->ptentry_back->toPlainText();

    QSqlQuery query;
    query.prepare("INSERT INTO flashcards (question, answer) VALUES (?, ?)");
    query.addBindValue(cardFront);
    query.addBindValue(cardBack);
    query.exec();

    qDebug() << "added front: " << cardFront;
    qDebug() << "added back: " << cardBack;

    //refresh table
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("flashcards");
    model->select();  // Load data
    ui->tableView->setModel(model);
}

void databaseview::on_btnBackMain_clicked()
{
    MainWindow *mw = new MainWindow;
    mw->show();
    hide();
    qDebug() << "Going back to main window";
}

