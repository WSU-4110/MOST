#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "databaseview.h"

#include <QSqlDatabase>
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlTableModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnGoToDb_clicked()
{
    databaseview *db = new databaseview;
    db->show();
    hide();
    qDebug() << "opening db view";
}

