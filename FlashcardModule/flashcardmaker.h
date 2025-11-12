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
    void on_saveButton_clicked();
    void on_homeButton_clicked();
private:
    QString currentSetName;
    Ui::flashCardMaker *ui;
    int cardCount=0; //added
    QVector<QPair<QString, QString>> flashcards; //added
signals:
    void goHome();
};
#endif // FLASHCARDMAKER_H
