#ifndef FLASHCARDMAKER_H
#define FLASHCARDMAKER_H

#include <QWidget>
#include <QVector>
#include <QPair>
#include <QString>

// SQLite and database-related includes
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

QT_BEGIN_NAMESPACE
namespace Ui {
class flashCardMaker;
}
QT_END_NAMESPACE

class flashCardMaker : public QWidget
{
    Q_OBJECT

public:
    explicit flashCardMaker(QWidget *parent = nullptr);
    ~flashCardMaker();

private slots:
    void on_nextQuestionButton_clicked();
    void on_saveButton_clicked();

private:
    Ui::flashCardMaker *ui;

    int cardCount = 0;
    QVector<QPair<QString, QString>> flashcards;

    // Optional: hold database instance (not strictly needed if using QSqlDatabase::database())
    QSqlDatabase db;
};

#endif // FLASHCARDMAKER_H
