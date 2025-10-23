#ifndef FLASHCARDMAKER_H
#define FLASHCARDMAKER_H

#include <QWidget>
#include <QtSql/QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui {
class flashCardMaker;
}
QT_END_NAMESPACE

class flashCardMaker : public QWidget
{
    Q_OBJECT

public:
    explicit flashCardMaker(QWidget *parent = nullptr); //added explicit
    ~flashCardMaker();
private slots:
    //added
    void on_nextQuestionButton_clicked(); //added
    void on_saveButton_clicked(); //added
private:
    Ui::flashCardMaker *ui;
    int cardCount=0; //added
    QVector<QPair<QString, QString>> flashcards; //added

    QSqlDatabase db; // SQLite connection
};
#endif // FLASHCARDMAKER_H
